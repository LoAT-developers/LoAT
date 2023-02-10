
// Generated from CINT.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CINTParser : public antlr4::Parser {
public:
  enum {
    INT = 1, IF = 2, WHILE = 3, ELSE = 4, TERMINATOR = 5, OPENP = 6, CLOSEP = 7, 
    OPENC = 8, CLOSEC = 9, MULT = 10, MINUS = 11, PLUS = 12, BO = 13, ASSIGN = 14, 
    NONDETNAME = 15, OR = 16, AND = 17, NOT = 18, TRUE = 19, FALSE = 20, 
    TYPEDEF = 21, ENUM = 22, COMMA = 23, BOOL = 24, EXTERN = 25, VOID = 26, 
    MAIN = 27, RETURN = 28, ZERO = 29, POS = 30, V = 31, W = 32, BLOCKCOMMENT = 33, 
    LINECOMMENT = 34
  };

  enum {
    RuleNondet = 0, RuleNum_atom = 1, RuleMult_expr = 2, RulePm_mult_expr = 3, 
    RuleNum_expr = 4, RuleBool_atom = 5, RuleAnd_expr = 6, RuleBool_expr = 7, 
    RuleLoop = 8, RuleCondition = 9, RuleAssignment = 10, RuleInstruction = 11, 
    RuleDeclaration = 12, RuleDeclarations = 13, RuleInstructions = 14, 
    RulePre = 15, RulePost = 16, RuleMain = 17
  };

  explicit CINTParser(antlr4::TokenStream *input);

  CINTParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CINTParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class NondetContext;
  class Num_atomContext;
  class Mult_exprContext;
  class Pm_mult_exprContext;
  class Num_exprContext;
  class Bool_atomContext;
  class And_exprContext;
  class Bool_exprContext;
  class LoopContext;
  class ConditionContext;
  class AssignmentContext;
  class InstructionContext;
  class DeclarationContext;
  class DeclarationsContext;
  class InstructionsContext;
  class PreContext;
  class PostContext;
  class MainContext; 

  class  NondetContext : public antlr4::ParserRuleContext {
  public:
    NondetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NONDETNAME();
    antlr4::tree::TerminalNode *OPENP();
    antlr4::tree::TerminalNode *CLOSEP();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NondetContext* nondet();

  class  Num_atomContext : public antlr4::ParserRuleContext {
  public:
    Num_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZERO();
    antlr4::tree::TerminalNode *POS();
    NondetContext *nondet();
    antlr4::tree::TerminalNode *V();
    antlr4::tree::TerminalNode *OPENP();
    Bool_exprContext *bool_expr();
    antlr4::tree::TerminalNode *CLOSEP();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Num_atomContext* num_atom();

  class  Mult_exprContext : public antlr4::ParserRuleContext {
  public:
    Mult_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Num_atomContext *> num_atom();
    Num_atomContext* num_atom(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MULT();
    antlr4::tree::TerminalNode* MULT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mult_exprContext* mult_expr();

  class  Pm_mult_exprContext : public antlr4::ParserRuleContext {
  public:
    Pm_mult_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mult_exprContext *mult_expr();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pm_mult_exprContext* pm_mult_expr();

  class  Num_exprContext : public antlr4::ParserRuleContext {
  public:
    Num_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mult_exprContext *mult_expr();
    std::vector<Pm_mult_exprContext *> pm_mult_expr();
    Pm_mult_exprContext* pm_mult_expr(size_t i);
    antlr4::tree::TerminalNode *MINUS();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Num_exprContext* num_expr();

  class  Bool_atomContext : public antlr4::ParserRuleContext {
  public:
    Bool_atomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    std::vector<Num_exprContext *> num_expr();
    Num_exprContext* num_expr(size_t i);
    antlr4::tree::TerminalNode *BO();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_atomContext* bool_atom();

  class  And_exprContext : public antlr4::ParserRuleContext {
  public:
    And_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Bool_atomContext *> bool_atom();
    Bool_atomContext* bool_atom(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  And_exprContext* and_expr();

  class  Bool_exprContext : public antlr4::ParserRuleContext {
  public:
    Bool_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<And_exprContext *> and_expr();
    And_exprContext* and_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);
    antlr4::tree::TerminalNode *NOT();
    Bool_atomContext *bool_atom();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_exprContext* bool_expr();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPENP();
    Bool_exprContext *bool_expr();
    antlr4::tree::TerminalNode *CLOSEP();
    antlr4::tree::TerminalNode *OPENC();
    antlr4::tree::TerminalNode *CLOSEC();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);
    InstructionsContext *instructions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopContext* loop();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *OPENP();
    Bool_exprContext *bool_expr();
    antlr4::tree::TerminalNode *CLOSEP();
    std::vector<antlr4::tree::TerminalNode *> OPENC();
    antlr4::tree::TerminalNode* OPENC(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CLOSEC();
    antlr4::tree::TerminalNode* CLOSEC(size_t i);
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);
    std::vector<InstructionsContext *> instructions();
    InstructionsContext* instructions(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *V();
    antlr4::tree::TerminalNode *ASSIGN();
    Num_exprContext *num_expr();
    antlr4::tree::TerminalNode *TERMINATOR();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LoopContext *loop();
    ConditionContext *condition();
    AssignmentContext *assignment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionContext* instruction();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    std::vector<antlr4::tree::TerminalNode *> V();
    antlr4::tree::TerminalNode* V(size_t i);
    antlr4::tree::TerminalNode *TERMINATOR();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    DeclarationsContext *declarations();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationsContext* declarations();

  class  InstructionsContext : public antlr4::ParserRuleContext {
  public:
    InstructionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstructionContext *instruction();
    InstructionsContext *instructions();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionsContext* instructions();

  class  PreContext : public antlr4::ParserRuleContext {
  public:
    PreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPEDEF();
    antlr4::tree::TerminalNode *ENUM();
    std::vector<antlr4::tree::TerminalNode *> OPENC();
    antlr4::tree::TerminalNode* OPENC(size_t i);
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *CLOSEC();
    antlr4::tree::TerminalNode *BOOL();
    std::vector<antlr4::tree::TerminalNode *> TERMINATOR();
    antlr4::tree::TerminalNode* TERMINATOR(size_t i);
    antlr4::tree::TerminalNode *EXTERN();
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);
    antlr4::tree::TerminalNode *NONDETNAME();
    std::vector<antlr4::tree::TerminalNode *> OPENP();
    antlr4::tree::TerminalNode* OPENP(size_t i);
    antlr4::tree::TerminalNode *VOID();
    std::vector<antlr4::tree::TerminalNode *> CLOSEP();
    antlr4::tree::TerminalNode* CLOSEP(size_t i);
    antlr4::tree::TerminalNode *MAIN();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PreContext* pre();

  class  PostContext : public antlr4::ParserRuleContext {
  public:
    PostContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *ZERO();
    antlr4::tree::TerminalNode *TERMINATOR();
    antlr4::tree::TerminalNode *CLOSEC();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostContext* post();

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PreContext *pre();
    PostContext *post();
    DeclarationsContext *declarations();
    InstructionsContext *instructions();
    std::vector<antlr4::tree::TerminalNode *> W();
    antlr4::tree::TerminalNode* W(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

