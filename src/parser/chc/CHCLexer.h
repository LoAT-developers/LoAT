
// Generated from CHC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CHCLexer : public antlr4::Lexer {
public:
  enum {
    LOGIC = 1, ASSERT = 2, CHECK_SAT = 3, EXIT = 4, DECLARE_FUN = 5, BOOL_SORT = 6, 
    INT_SORT = 7, FORALL = 8, LET = 9, IMPLIES = 10, FALSE = 11, TRUE = 12, 
    PLUS = 13, MINUS = 14, TIMES = 15, MOD = 16, DIV = 17, LPAR = 18, RPAR = 19, 
    AND = 20, OR = 21, NOT = 22, ITE = 23, LT = 24, LEQ = 25, EQ = 26, NEQ = 27, 
    GEQ = 28, GT = 29, ID = 30, INT = 31, WS = 32, COMMENT = 33, OTHER = 34
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

