
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  KoatParser : public antlr4::Parser {
public:
  enum {
    COM = 1, GOAL = 2, CPX = 3, TERM = 4, START = 5, SINK = 6, FS = 7, VAR = 8, 
    RULES = 9, PLUS = 10, MINUS = 11, TIMES = 12, EXP = 13, LPAR = 14, RPAR = 15, 
    RBRACK = 16, LBRACK = 17, LCURL = 18, RCURL = 19, TO = 20, COMMA = 21, 
    AND = 22, OR = 23, LT = 24, LEQ = 25, EQ = 26, NEQ = 27, GEQ = 28, GT = 29, 
    CONDSEP = 30, ID = 31, INT = 32, WS = 33, COMMENT = 34
  };

  enum {
    RuleMain = 0, RuleFs = 1, RuleVar = 2, RuleGoal = 3, RuleStart = 4, 
    RuleSink = 5, RuleVardecl = 6, RuleTranss = 7, RuleTrans = 8, RuleLhs = 9, 
    RuleCom = 10, RuleRhs = 11, RuleTo = 12, RuleLb = 13, RuleUb = 14, RuleCond = 15, 
    RuleExpr = 16, RuleFormula = 17, RuleLit = 18, RuleRelop = 19
  };

  explicit KoatParser(antlr4::TokenStream *input);

  KoatParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~KoatParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MainContext;
  class FsContext;
  class VarContext;
  class GoalContext;
  class StartContext;
  class SinkContext;
  class VardeclContext;
  class TranssContext;
  class TransContext;
  class LhsContext;
  class ComContext;
  class RhsContext;
  class ToContext;
  class LbContext;
  class UbContext;
  class CondContext;
  class ExprContext;
  class FormulaContext;
  class LitContext;
  class RelopContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StartContext *start();
    VardeclContext *vardecl();
    TranssContext *transs();
    GoalContext *goal();
    SinkContext *sink();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

  class  FsContext : public antlr4::ParserRuleContext {
  public:
    FsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FsContext* fs();

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

  class  GoalContext : public antlr4::ParserRuleContext {
  public:
    GoalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *GOAL();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *CPX();
    antlr4::tree::TerminalNode *TERM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GoalContext* goal();

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *FS();
    FsContext *fs();
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  SinkContext : public antlr4::ParserRuleContext {
  public:
    SinkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LPAR();
    antlr4::tree::TerminalNode* LPAR(size_t i);
    antlr4::tree::TerminalNode *SINK();
    antlr4::tree::TerminalNode *FS();
    FsContext *fs();
    std::vector<antlr4::tree::TerminalNode *> RPAR();
    antlr4::tree::TerminalNode* RPAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SinkContext* sink();

  class  VardeclContext : public antlr4::ParserRuleContext {
  public:
    VardeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VardeclContext* vardecl();

  class  TranssContext : public antlr4::ParserRuleContext {
  public:
    TranssContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RULES();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<TransContext *> trans();
    TransContext* trans(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TranssContext* transs();

  class  TransContext : public antlr4::ParserRuleContext {
  public:
    TransContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LhsContext *lhs();
    ToContext *to();
    ComContext *com();
    CondContext *cond();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TransContext* trans();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FsContext *fs();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<VarContext *> var();
    VarContext* var(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LhsContext* lhs();

  class  ComContext : public antlr4::ParserRuleContext {
  public:
    ComContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COM();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<RhsContext *> rhs();
    RhsContext* rhs(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComContext* com();

  class  RhsContext : public antlr4::ParserRuleContext {
  public:
    RhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FsContext *fs();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RhsContext* rhs();

  class  ToContext : public antlr4::ParserRuleContext {
  public:
    ToContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LCURL();
    LbContext *lb();
    antlr4::tree::TerminalNode *COMMA();
    UbContext *ub();
    antlr4::tree::TerminalNode *RCURL();
    antlr4::tree::TerminalNode *GT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToContext* to();

  class  LbContext : public antlr4::ParserRuleContext {
  public:
    LbContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LbContext* lb();

  class  UbContext : public antlr4::ParserRuleContext {
  public:
    UbContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UbContext* ub();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONDSEP();
    FormulaContext *formula();
    antlr4::tree::TerminalNode *LBRACK();
    antlr4::tree::TerminalNode *RBRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondContext* cond();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *MINUS();
    VarContext *var();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *EXP();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *PLUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    std::vector<FormulaContext *> formula();
    FormulaContext* formula(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    LitContext *lit();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormulaContext* formula();
  FormulaContext* formula(int precedence);
  class  LitContext : public antlr4::ParserRuleContext {
  public:
    LitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    RelopContext *relop();

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


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);
  bool formulaSempred(FormulaContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

