#include "redlogparsevisitor.h"
#include "expression.hpp"
#include "exceptions.hpp"
#include "redlogLexer.h"
#include "redlogParser.h"

using expr_type = Expr;
using binop_type = BinOp;
using caop_type = CAOp;
using lit_type = Rel;
using formula_type = BExpr<IntTheory>;
using boolop_type = ConcatOperator;
using relop_type = Rel::RelOp;

antlrcpp::Any RedlogParseVisitor::visitMain(redlogParser::MainContext *ctx) {
  return visitFormula(ctx->formula());
}

antlrcpp::Any RedlogParseVisitor::visitExpr(redlogParser::ExprContext *ctx) {
  if (ctx->VAR()) {
      return Expr(std::get<NumVar>(*varMan.getVar(ctx->getText())));
  } else if (ctx->INT()) {
      return Expr(stoi(ctx->getText()));
  } else if (ctx->MINUS()) {
      const auto child = any_cast<expr_type>(visit(ctx->expr(0)));
      return -child;
  } else if (ctx->binop()) {
      const auto binop = any_cast<binop_type>(visit(ctx->binop()));
      const auto arg1 = any_cast<expr_type>(visit(ctx->expr(0)));
      const auto arg2 = any_cast<expr_type>(visit(ctx->expr(1)));
      switch (binop) {
      case Exp: return arg1 ^ arg2;
      case Minus: return arg1 - arg2;
      }
  } else if (ctx->caop()) {
      const auto op = any_cast<caop_type>(visit(ctx->caop()));
      Expr res;
      switch (op) {
      case Times: res = 1;
          break;
      case Plus: res = 0;
          break;
      }
      for (const auto &e: ctx->expr()) {
          switch (op) {
          case Times: res = res * any_cast<expr_type>(visit(e));
              break;
          case Plus: res = res + any_cast<expr_type>(visit(e));
              break;
          }
      }
      return res;
  }
  throw ParseError("failed to parse redlog expression: " + ctx->getText());
}

antlrcpp::Any RedlogParseVisitor::visitCaop(redlogParser::CaopContext *ctx) {
  if (ctx->PLUS()) return Plus;
  else if (ctx->TIMES()) return Times;
  else throw ParseError("failed to parse redlog operator: " + ctx->getText());
}

antlrcpp::Any RedlogParseVisitor::visitBinop(redlogParser::BinopContext *ctx) {
    if (ctx->EXP()) return Exp;
    else if (ctx->MINUS()) return Minus;
    else throw ParseError("failed to parse redlog operator: " + ctx->getText());
}

antlrcpp::Any RedlogParseVisitor::visitFormula(redlogParser::FormulaContext *ctx) {
  if (ctx->lit()) {
      return buildTheoryLit<IntTheory>(any_cast<lit_type>(visit(ctx->lit())));
  } else if (ctx->TRUE()) {
      return True;
  } else if (ctx->FALSE()) {
      return False;
  } else if (ctx->boolop()) {
      const auto op = any_cast<boolop_type>(visit(ctx->boolop()));
      std::vector<BExpr<IntTheory>> args;
      for (auto const &f: ctx->formula()) {
          args.push_back(any_cast<formula_type>(visit(f)));
      }
      switch (op) {
      case ConcatAnd: return buildAnd(args);
      case ConcatOr: return buildOr(args);
      }
  }
  throw ParseError("failed to parse redlog formula: " + ctx->getText());
}

antlrcpp::Any RedlogParseVisitor::visitLit(redlogParser::LitContext *ctx) {
    const auto arg1 = any_cast<expr_type>(visit(ctx->expr(0)));
    const auto op = any_cast<relop_type>(visit(ctx->relop()));
    const auto arg2 = any_cast<expr_type>(visit(ctx->expr(1)));
    return Rel(arg1, op, arg2);
}

antlrcpp::Any RedlogParseVisitor::visitBoolop(redlogParser::BoolopContext *ctx) {
    if (ctx->AND()) {
        return ConcatAnd;
    } else if (ctx->OR()) {
        return ConcatOr;
    } else {
        throw ParseError("failed to parse boolean redlog operator: " + ctx->getText());
    }
}

antlrcpp::Any RedlogParseVisitor::visitRelop(redlogParser::RelopContext *ctx) {
    if (ctx->LT()) {
        return Rel::lt;
    } else if (ctx->LEQ()) {
        return Rel::leq;
    } else if (ctx->EQ()) {
        return Rel::eq;
    } else if (ctx->GEQ()) {
        return Rel::geq;
    } else if (ctx->GT()) {
        return Rel::gt;
    } else if (ctx->NEQ()) {
        return Rel::neq;
    } else {
        throw ParseError("failed to parse redlog relation: " + ctx->getText());
    }
}

RedlogParseVisitor::RedlogParseVisitor(VariableManager &varMan): varMan(varMan) {}

BExpr<IntTheory> RedlogParseVisitor::parse(std::string str, VariableManager &varMan) {
    antlr4::ANTLRInputStream input(str);
    redlogLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    redlogParser parser(&tokens);
    parser.setBuildParseTree(true);
    RedlogParseVisitor vis(varMan);
    auto ctx = parser.main();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        throw ParseError("parsing redlog formula failed");
    } else {
        return any_cast<BExpr<IntTheory>>(vis.visit(ctx));
    }
}
