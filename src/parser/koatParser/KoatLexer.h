
// Generated from Koat.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  KoatLexer : public antlr4::Lexer {
public:
  enum {
    COM = 1, GOAL = 2, CPX = 3, TERM = 4, START = 5, SINK = 6, FS = 7, VAR = 8, 
    RULES = 9, PLUS = 10, MINUS = 11, TIMES = 12, EXP = 13, LPAR = 14, RPAR = 15, 
    RBRACK = 16, LBRACK = 17, LCURL = 18, RCURL = 19, TO = 20, COMMA = 21, 
    AND = 22, OR = 23, LT = 24, LEQ = 25, EQ = 26, NEQ = 27, GEQ = 28, GT = 29, 
    CONDSEP = 30, ID = 31, INT = 32, WS = 33, COMMENT = 34
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

