
// Generated from CHC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CHCParser : public antlr4::Parser {
public:
  enum {
    LOGIC = 1, ASSERT = 2, CHECK_SAT = 3, EXIT = 4, DECLARE_FUN = 5, BOOL_SORT = 6, 
    INT_SORT = 7, FORALL = 8, LET = 9, IMPLIES = 10, FALSE = 11, TRUE = 12, 
    PLUS = 13, MINUS = 14, TIMES = 15, MOD = 16, DIV = 17, LPAR = 18, RPAR = 19, 
    AND = 20, OR = 21, NOT = 22, ITE = 23, LT = 24, LEQ = 25, EQ = 26, NEQ = 27, 
    GEQ = 28, GT = 29, ID = 30, INT = 31, WS = 32, COMMENT = 33, OTHER = 34
  };

  enum {
    RuleMain = 0, RuleFun_decl = 1, RuleChc_assert = 2, RuleChc_assert_head = 3, 
    RuleChc_assert_body = 4, RuleChc_tail = 5, RuleChc_head = 6, RuleChc_query = 7, 
    RuleVar_decl = 8, RuleVar_or_atom = 9, RuleU_pred_atom = 10, RuleLet = 11, 
    RuleLets = 12, RuleFormula_or_expr = 13, RuleExpr = 14, RuleUnaryop = 15, 
    RuleBinaryop = 16, RuleNaryop = 17, RuleI_formula = 18, RuleBoolop = 19, 
    RuleLit = 20, RuleRelop = 21, RuleSymbol = 22, RuleSort = 23, RuleVar = 24
  };

  explicit CHCParser(antlr4::TokenStream *input);

  CHCParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CHCParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MainContext;
  class Fun_declContext;
  class Chc_assertContext;
  class Chc_assert_headContext;
  class Chc_assert_bodyContext;
  class Chc_tailContext;
  class Chc_headContext;
  class Chc_queryContext;
  class Var_declContext;
  class Var_or_atomContext;
  class U_pred_atomContext;
  class LetContext;
  class LetsContext;
  class Formula_or_exprContext;
  class ExprContext;
  class UnaryopContext;
  class BinaryopContext;
  class NaryopContext;
  class I_formulaContext;
  class BoolopContext;
  class LitContext;
  class RelopContext;
  class SymbolContext;
  class SortContext;
  class VarContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *LOGIC();
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    antlr4::tree::TerminalNode *CHECK_SAT();
    std::vector<Fun_declContext *> fun_decl();
    Fun_declContext* fun_decl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ASSERT();
    antlr4::tree::TerminalNode* ASSERT(size_t i);
    std::vector<Chc_assertContext *> chc_assert();
    Chc_assertContext* chc_assert(size_t i);
    std::vector<Chc_queryContext *> chc_query();
    Chc_queryContext* chc_query(size_t i);
    antlr4::tree::TerminalNode *EXIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

  class  Fun_declContext : public antlr4::ParserRuleContext {
  public:
    Fun_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *DECLARE_FUN();
    SymbolContext *symbol();
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    antlr4::tree::TerminalNode *BOOL_SORT();
    std::vector<SortContext *> sort();
    SortContext* sort(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fun_declContext* fun_decl();

  class  Chc_assertContext : public antlr4::ParserRuleContext {
  public:
    Chc_assertContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    Chc_assert_headContext *chc_assert_head();
    Chc_assert_bodyContext *chc_assert_body();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_assertContext* chc_assert();

  class  Chc_assert_headContext : public antlr4::ParserRuleContext {
  public:
    Chc_assert_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORALL();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<Var_declContext *> var_decl();
    Var_declContext* var_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_assert_headContext* chc_assert_head();

  class  Chc_assert_bodyContext : public antlr4::ParserRuleContext {
  public:
    Chc_assert_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *IMPLIES();
    Chc_tailContext *chc_tail();
    Chc_headContext *chc_head();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_assert_bodyContext* chc_assert_body();

  class  Chc_tailContext : public antlr4::ParserRuleContext {
  public:
    Chc_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<Var_or_atomContext *> var_or_atom();
    Var_or_atomContext* var_or_atom(size_t i);
    std::vector<I_formulaContext *> i_formula();
    I_formulaContext* i_formula(size_t i);
    U_pred_atomContext *u_pred_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_tailContext* chc_tail();

  class  Chc_headContext : public antlr4::ParserRuleContext {
  public:
    Chc_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    U_pred_atomContext *u_pred_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_headContext* chc_head();

  class  Chc_queryContext : public antlr4::ParserRuleContext {
  public:
    Chc_queryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *FORALL();
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);
    antlr4::tree::TerminalNode *IMPLIES();
    Chc_tailContext *chc_tail();
    antlr4::tree::TerminalNode *FALSE();
    std::vector<Var_declContext *> var_decl();
    Var_declContext* var_decl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_queryContext* chc_query();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    VarContext *var();
    SortContext *sort();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  Var_or_atomContext : public antlr4::ParserRuleContext {
  public:
    Var_or_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    U_pred_atomContext *u_pred_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_or_atomContext* var_or_atom();

  class  U_pred_atomContext : public antlr4::ParserRuleContext {
  public:
    U_pred_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    SymbolContext *symbol();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<VarContext *> var();
    VarContext* var(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  U_pred_atomContext* u_pred_atom();

  class  LetContext : public antlr4::ParserRuleContext {
  public:
    LetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    VarContext *var();
    antlr4::tree::TerminalNode *RPAR();
    Formula_or_exprContext *formula_or_expr();
    I_formulaContext *i_formula();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetContext* let();

  class  LetsContext : public antlr4::ParserRuleContext {
  public:
    LetsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<LetContext *> let();
    LetContext* let(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetsContext* lets();

  class  Formula_or_exprContext : public antlr4::ParserRuleContext {
  public:
    Formula_or_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarContext *var();
    antlr4::tree::TerminalNode *LPAR();
    std::vector<Formula_or_exprContext *> formula_or_expr();
    Formula_or_exprContext* formula_or_expr(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    LetsContext *lets();
    antlr4::tree::TerminalNode *ITE();
    I_formulaContext *i_formula();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formula_or_exprContext* formula_or_expr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    UnaryopContext *unaryop();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    BinaryopContext *binaryop();
    NaryopContext *naryop();
    antlr4::tree::TerminalNode *ITE();
    I_formulaContext *i_formula();
    VarContext *var();
    antlr4::tree::TerminalNode *INT();
    LetsContext *lets();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  UnaryopContext : public antlr4::ParserRuleContext {
  public:
    UnaryopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryopContext* unaryop();

  class  BinaryopContext : public antlr4::ParserRuleContext {
  public:
    BinaryopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinaryopContext* binaryop();

  class  NaryopContext : public antlr4::ParserRuleContext {
  public:
    NaryopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *PLUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NaryopContext* naryop();

  class  I_formulaContext : public antlr4::ParserRuleContext {
  public:
    I_formulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *NOT();
    std::vector<I_formulaContext *> i_formula();
    I_formulaContext* i_formula(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    LitContext *lit();
    BoolopContext *boolop();
    antlr4::tree::TerminalNode *ITE();
    LetsContext *lets();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    VarContext *var();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  I_formulaContext* i_formula();

  class  BoolopContext : public antlr4::ParserRuleContext {
  public:
    BoolopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolopContext* boolop();

  class  LitContext : public antlr4::ParserRuleContext {
  public:
    LitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *EQ();
    std::vector<VarContext *> var();
    VarContext* var(size_t i);
    antlr4::tree::TerminalNode *NEQ();
    RelopContext *relop();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LitContext* lit();

  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GEQ();
    antlr4::tree::TerminalNode *NEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelopContext* relop();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();

  class  SortContext : public antlr4::ParserRuleContext {
  public:
    SortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_SORT();
    antlr4::tree::TerminalNode *BOOL_SORT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortContext* sort();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

