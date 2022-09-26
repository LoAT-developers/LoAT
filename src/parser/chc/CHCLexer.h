
// Generated from CHC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CHCLexer : public antlr4::Lexer {
public:
  enum {
    LOGIC = 1, ASSERT = 2, CHECK_SAT = 3, EXIT = 4, DECLARE_FUN = 5, BOOL = 6, 
    FORALL = 7, LET = 8, IMPLIES = 9, FALSE = 10, TRUE = 11, PLUS = 12, 
    MINUS = 13, TIMES = 14, MOD = 15, DIV = 16, LPAR = 17, RPAR = 18, AND = 19, 
    OR = 20, NOT = 21, ITE = 22, LT = 23, LEQ = 24, EQ = 25, NEQ = 26, GEQ = 27, 
    GT = 28, ID = 29, INT = 30, WS = 31, COMMENT = 32, OTHER = 33
  };

  explicit CHCLexer(antlr4::CharStream *input);

  ~CHCLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

