
// Generated from CHC.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CHCParser : public antlr4::Parser {
public:
  enum {
    LOGIC = 1, ASSERT = 2, CHECK_SAT = 3, EXIT = 4, DECLARE_FUN = 5, BOOL = 6, 
    FORALL = 7, IMPLIES = 8, FALSE = 9, PIPE = 10, PLUS = 11, MINUS = 12, 
    TIMES = 13, MOD = 14, LPAR = 15, RPAR = 16, AND = 17, OR = 18, NOT = 19, 
    ITE = 20, LT = 21, LEQ = 22, EQ = 23, NEQ = 24, GEQ = 25, GT = 26, SC = 27, 
    LETTER = 28, INT = 29, WS = 30, COMMENT = 31, OTHER = 32
  };

  enum {
    RuleMain = 0, RuleFun_decl = 1, RuleChc_assert = 2, RuleChc_assert_head = 3, 
    RuleChc_assert_body = 4, RuleChc_tail = 5, RuleChc_head = 6, RuleChc_query = 7, 
    RuleVar_decl = 8, RuleU_pred_atom = 9, RuleI_formula = 10, RuleBoolop = 11, 
    RuleLit = 12, RuleRelop = 13, RuleExpr = 14, RuleUnaryop = 15, RuleBinaryop = 16, 
    RuleNaryop = 17, RuleSymbol = 18, RuleSort = 19, RuleVar = 20, RuleId = 21
  };

  CHCParser(antlr4::TokenStream *input);
  ~CHCParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class MainContext;
  class Fun_declContext;
  class Chc_assertContext;
  class Chc_assert_headContext;
  class Chc_assert_bodyContext;
  class Chc_tailContext;
  class Chc_headContext;
  class Chc_queryContext;
  class Var_declContext;
  class U_pred_atomContext;
  class I_formulaContext;
  class BoolopContext;
  class LitContext;
  class RelopContext;
  class ExprContext;
  class UnaryopContext;
  class BinaryopContext;
  class NaryopContext;
  class SymbolContext;
  class SortContext;
  class VarContext;
  class IdContext; 

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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    antlr4::tree::TerminalNode *BOOL();
    std::vector<SortContext *> sort();
    SortContext* sort(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_assert_bodyContext* chc_assert_body();

  class  Chc_tailContext : public antlr4::ParserRuleContext {
  public:
    Chc_tailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<I_formulaContext *> i_formula();
    I_formulaContext* i_formula(size_t i);
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<U_pred_atomContext *> u_pred_atom();
    U_pred_atomContext* u_pred_atom(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_tailContext* chc_tail();

  class  Chc_headContext : public antlr4::ParserRuleContext {
  public:
    Chc_headContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    U_pred_atomContext *u_pred_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Chc_queryContext* chc_query();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    SymbolContext *symbol();
    SortContext *sort();
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  U_pred_atomContext* u_pred_atom();

  class  I_formulaContext : public antlr4::ParserRuleContext {
  public:
    I_formulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *NOT();
    std::vector<I_formulaContext *> i_formula();
    I_formulaContext* i_formula(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    BoolopContext *boolop();
    antlr4::tree::TerminalNode *ITE();
    LitContext *lit();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  I_formulaContext* i_formula();

  class  BoolopContext : public antlr4::ParserRuleContext {
  public:
    BoolopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *EQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolopContext* boolop();

  class  LitContext : public antlr4::ParserRuleContext {
  public:
    LitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    RelopContext *relop();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RPAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelopContext* relop();

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
    VarContext *var();
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  UnaryopContext : public antlr4::ParserRuleContext {
  public:
    UnaryopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryopContext* unaryop();

  class  BinaryopContext : public antlr4::ParserRuleContext {
  public:
    BinaryopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NaryopContext* naryop();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();

  class  SortContext : public antlr4::ParserRuleContext {
  public:
    SortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortContext* sort();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();

  class  IdContext : public antlr4::ParserRuleContext {
  public:
    IdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LETTER();
    antlr4::tree::TerminalNode* LETTER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PIPE();
    antlr4::tree::TerminalNode* PIPE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdContext* id();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

