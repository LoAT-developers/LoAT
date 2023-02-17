
// Generated from redlog.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  redlogLexer : public antlr4::Lexer {
public:
  enum {
    PLUS = 1, MINUS = 2, TIMES = 3, EXP = 4, LPAR = 5, RPAR = 6, AND = 7, 
    OR = 8, LT = 9, LEQ = 10, EQ = 11, NEQ = 12, GEQ = 13, GT = 14, TRUE = 15, 
    FALSE = 16, VAR = 17, INT = 18, WS = 19
  };

  explicit redlogLexer(antlr4::CharStream *input);

  ~redlogLexer() override;


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

