#include "redlogparsevisitor.h"
#include "expression.hpp"

#include "redlogLexer.h"
#include "redlogParser.h"

antlrcpp::Any RedlogParseVisitor::visitMain(redlogParser::MainContext *ctx) {
  return visitFormula(ctx->formula());
}

antlrcpp::Any RedlogParseVisitor::visitExpr(redlogParser::ExprContext *ctx) {
  if (ctx->VAR()) {
      return Expr(varMan.getVar(ctx->getText()).get());
  } else if (ctx->INT()) {
      return Expr(stoi(ctx->getText()));
  } else if (ctx->MINUS()) {
      const Expr child = visit(ctx->expr(0));
      return -child;
  } else if (ctx->binop()) {
      const BinOp binop = visit(ctx->binop());
      const Expr arg1 = visit(ctx->expr(0));
      const Expr arg2 = visit(ctx->expr(1));
      switch (binop) {
      case Exp: return arg1 ^ arg2;
      case Minus: return arg1 - arg2;
      }
  } else if (ctx->caop()) {
      const CAOp op = visit(ctx->caop());
      Expr res;
      switch (op) {
      case Times: res = 1;
          break;
      case Plus: res = 0;
          break;
      }
      for (const auto &e: ctx->expr()) {
          switch (op) {
          case Times: res = res * visit(e);
              break;
          case Plus: res = res + visit(e);
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
      return buildLit(visit(ctx->lit()));
  } else if (ctx->TRUE()) {
      return True;
  } else if (ctx->FALSE()) {
      return False;
  } else if (ctx->boolop()) {
      ConcatOperator op = visit(ctx->boolop());
      std::vector<BoolExpr> args;
      for (auto const &f: ctx->formula()) {
          args.push_back(visit(f));
      }
      switch (op) {
      case ConcatAnd: return buildAnd(args);
      case ConcatOr: return buildOr(args);
      }
  }
  throw ParseError("failed to parse redlog formula: " + ctx->getText());
}

antlrcpp::Any RedlogParseVisitor::visitLit(redlogParser::LitContext *ctx) {
    Expr arg1 = visit(ctx->expr(0));
    Rel::RelOp op = visit(ctx->relop());
    Expr arg2 = visit(ctx->expr(1));
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

BoolExpr RedlogParseVisitor::parse(std::string str, VariableManager &varMan) {
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
        return vis.visit(ctx);
    }
}
