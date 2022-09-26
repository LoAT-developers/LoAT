
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  KoatLexer : public antlr4::Lexer {
public:
  enum {
    COM = 1, GOAL = 2, CPX = 3, TERM = 4, START = 5, FS = 6, VAR = 7, RULES = 8, 
    PLUS = 9, MINUS = 10, TIMES = 11, EXP = 12, LPAR = 13, RPAR = 14, RBRACK = 15, 
    LBRACK = 16, LCURL = 17, RCURL = 18, TO = 19, COMMA = 20, AND = 21, 
    OR = 22, LT = 23, LEQ = 24, EQ = 25, NEQ = 26, GEQ = 27, GT = 28, CONDSEP = 29, 
    ID = 30, INT = 31, WS = 32, COMMENT = 33
  };

  explicit KoatLexer(antlr4::CharStream *input);

  ~KoatLexer() override;


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

