
// Generated from CHC.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CHCLexer : public antlr4::Lexer {
public:
  enum {
    LOGIC = 1, ASSERT = 2, CHECK_SAT = 3, GET_MODEL = 4, EXIT = 5, DECLARE_FUN = 6, 
    BOOL_SORT = 7, INT_SORT = 8, FORALL = 9, LET = 10, IMPLIES = 11, FALSE = 12, 
    TRUE = 13, PLUS = 14, MINUS = 15, TIMES = 16, MOD = 17, DIV = 18, LPAR = 19, 
    RPAR = 20, AND = 21, OR = 22, NOT = 23, ITE = 24, LT = 25, LEQ = 26, 
    EQ = 27, NEQ = 28, GEQ = 29, GT = 30, ID = 31, INT = 32, WS = 33, COMMENT = 34, 
    OTHER = 35
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

