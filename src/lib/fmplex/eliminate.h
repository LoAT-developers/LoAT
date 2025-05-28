/**
 * This file was copied from SMT-RAT (https://github.com/ths-rwth/smtrat) and modified.
 * See the LICENCE file in this folder for further information.
 */

#pragma once

#include <vector>

#include "theory.hpp"

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/StdVector>

#include "fmplex.h"

namespace fmplex {

using Formula  = Bools::Expr;
using EigenMat = Eigen::Matrix<Rational, Eigen::Dynamic, Eigen::Dynamic>;
using EigenVec = Eigen::Matrix<Rational, Eigen::Dynamic, 1>;

Formula eliminate_variables(const Formula& f, const linked_hash_set<Arith::Var>& vars);

std::pair<EigenMat, EigenVec> eliminate_cols(const EigenMat& constraints,
                                             const EigenVec& constants,
                                             const std::vector<std::size_t>& cols);

}
