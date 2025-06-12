/**
 * This file was copied from SMT-RAT (https://github.com/ths-rwth/smtrat) and modified.
 * See the LICENCE file in this folder for further information.
 */

#include "eliminate.h"
#include <iostream>
#include <fstream>


namespace fmplex {

template<typename Var>
struct VariableIndex {
    std::vector<Var> m_vars;

    VariableIndex() {}

    explicit VariableIndex(const std::vector<Var>& vs) : m_vars(vs) {}

    std::size_t add_variable(const Var v) {
        if (std::find(m_vars.begin(), m_vars.end(), v) == m_vars.end()) {
            m_vars.push_back(v);
        }
        return m_vars.size() - 1;
    }

    std::size_t index(Var v) const {
        auto it = std::find(m_vars.begin(), m_vars.end(), v);
        assert(it != m_vars.end());
        return std::distance(m_vars.begin(), it);
    }

    Var var(std::size_t i) const {
        assert(i < m_vars.size());
        return m_vars[i];
    }

    std::size_t size() const { return m_vars.size(); }
};


using Poly = Arith::Expr;


void eliminate_variables(Formula& constraints, const linked_hash_set<Arith::Var>& vars) {
    // transform formula to matrix
    // TODO: equality substitution, filtering
    linked_hash_set<Arith::Var> vs;
    for (const auto &c: constraints) {
        c->collectVars(vs);
    }
    std::vector<Arith::Var> var_idx {vars.begin(), vars.end()};
    for (const auto &x: vs) {
        if (!vars.contains(x)) {
            var_idx.emplace_back(x);
        }
    }
    std::unordered_map<Arith::Var, size_t> var_pos;
    size_t i = 0;
    for (const auto &x: var_idx) {
        var_pos.emplace(x, i);
        ++i;
    }

    // reserve enough space for the matrix
    std::size_t constant_col = var_idx.size();
    std::size_t delta_col = constant_col + 1;
    Matrix m(constraints.size(), var_idx.size() + constraints.size() + 2); // +2 : delta & rhs.
    std::size_t non_zeros = 2*constraints.size(); // one origin & at most one delta for each row
    for (const auto& f : constraints) {
        if (const auto add {f->lhs()->isAdd()}) {
            non_zeros += (*add)->getArgs().size();
        } else {
            non_zeros += 1;
        }
    }
    m.reserve(non_zeros);

    // transform each constraint into a row
    auto it = constraints.begin();
    for (std::size_t r = 0; it != constraints.end(); ++r, ++it) {
        auto rel = *it;

        assert(!rel->isNeq());
        // TODO adjiust to support weak relations
        std::vector<Arith::Expr> lhss = rel->isEq() ? std::vector{rel->lhs(), -rel->lhs()} : std::vector{-rel->lhs() + arith::mkConst(1)};
        // smtrat automatically converts constraints to < or <=
        for (auto &lhs: lhss) {
            std::vector<Matrix::RowEntry> entries; // TODO: make it so that the contents of the row are actually already in the matrix data
            if (const auto &x {lhs->isVar()}) {
                entries.emplace_back(var_pos.at(*x), 1);
            } else {
                std::vector<ArithMultPtr> muls;
                if (const auto mul{lhs->isMult()}) {
                    muls.emplace_back(*mul);
                } else if (const auto add{lhs->isAdd()}) {
                    for (const auto &arg: (*add)->getArgs()) {
                        if (const auto &x {arg->isVar()}) {
                            entries.emplace_back(var_pos.at(*x), 1);
                        } else if (const auto &mul {arg->isMult()}) {
                            muls.emplace_back(*mul);
                        } else {
                            assert(arg->isRational());
                        }
                    }
                } else {
                    assert(lhs->isRational());
                }
                for (const auto &mul : muls) {
                    const auto &args{mul->getArgs()};
                    assert(args.size() == 2);
                    std::optional<Arith::Var> x;
                    std::optional<Rational> coeff;
                    for (const auto &arg : args) {
                        if (const auto y{arg->isVar()}) {
                            x = *y;
                        } else if (const auto c{arg->isRational()}) {
                            coeff = ***c;
                        } else {
                            assert(false);
                        }
                    }
                    assert(x && coeff);
                    entries.emplace_back(var_pos.at(*x), *coeff);
                }
            }
            // the order in the polynomial may be different from the order in the var index
            std::sort(entries.begin(), entries.end(),
                      [](const auto &lhs, const auto &rhs) { return lhs.col_index < rhs.col_index; });

            const auto constant_part = lhs->getConstantAddend();
            // constant part, delta, and origin
            if (constant_part != 0) {
                entries.emplace_back(constant_col, constant_part);
            }
            // TODO adjust to support weak relations
            // if (rel->isGt()) {
            //    entries.emplace_back(delta_col, Rational(1));
            // }
            entries.emplace_back(delta_col + r + 1, Rational(1));

            m.append_row(entries.begin(), entries.end());
        }
    }

    Matrix res = FMplexElimination(m, vars.size(), var_idx.size() - vars.size()).apply();

    // transform Matrix back to formula
    constraints.clear();
    for (std::size_t i = 0; i < res.n_rows(); ++i) {
        auto it = res.row_begin(i);
        auto row_end = res.row_end(i);
        std::vector<Arith::Expr> addends;
        for (; it !=row_end && it->col_index < constant_col; ++it) {
            addends.emplace_back(arith::mkConst(it->value) * var_idx.at(it->col_index));
        }
        if (it != row_end && it->col_index == constant_col) {
            addends.emplace_back(arith::mkConst(it->value));
            ++it;
        }
        const auto lhs = arith::mkPlus(std::move(addends));
        // TODO adjust to support weak relations
        // This method is only applied to pos.lin. combinations, so the delta coeff will be >=0
        // if (it != row_end && it->col_index == delta_col) conjuncts.emplace(arith::mkLt(lhs, arith::mkConst(0)));
        // else conjuncts.emplace(arith::mkLeq(lhs, arith::mkConst(0)));
        constraints.emplace(arith::mkLeq(lhs, arith::mkConst(0)));
    }

}



std::pair<EigenMat, EigenVec> eliminate_cols(const EigenMat& constraints,
                                             const EigenVec& constants,
                                             const std::vector<std::size_t>& cols) {
    // convert to internal matrix type
    Matrix m(constraints.rows(), constraints.cols() + 2 + constraints.rows());
    std::size_t quantified_cols = cols.size();
    VariableIndex<std::size_t> var_idx(cols);
    for (std::size_t i = 0, q = 0; i < constraints.rows(); ++i) {
        if (q < cols.size() && i == cols[q]) ++q;
        else var_idx.add_variable(i);
    }

    for (std::size_t i = 0; i < constraints.rows(); ++i) {
        std::vector<Matrix::RowEntry> row;
        for (std::size_t j = 0; j < constraints.cols(); ++j) {
            if (constraints(i,var_idx.var(j)) != 0) {
                row.emplace_back(j, constraints(i,var_idx.var(j)));
            }
        }
        if (constants(i) != 0) row.emplace_back(constraints.cols(), -constants(i));
        row.emplace_back(constraints.cols() + 1 + i, Rational(1)); // TODO: maybe this transformation should be done by fmplex internally?
        m.append_row(row.begin(), row.end());
    }

    Matrix res = FMplexElimination(m, quantified_cols, constraints.cols() - quantified_cols).apply();

    EigenMat res_mat = EigenMat::Zero(res.n_rows(), constraints.cols());
    EigenVec res_const = EigenVec::Zero(res.n_rows());
    // convert back to original format
    for (std::size_t i = 0; i < res.n_rows(); ++i) {
        for (const auto& e : res.row_entries(i)) {
            if (e.col_index == constraints.cols()) {
                res_const(i) = -e.value;
                break;
            }
            if (e.col_index > constraints.cols()) break;
            res_mat(i, var_idx.var(e.col_index)) = e.value;
        }
    }

    return {res_mat, res_const};
}

}
