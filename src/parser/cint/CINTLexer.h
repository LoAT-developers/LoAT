
// Generated from CINT.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CINTLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, IF = 2, WHILE = 3, ELSE = 4, TERMINATOR = 5, OPENP = 6, CLOSEP = 7, 
    OPENC = 8, CLOSEC = 9, MULT = 10, MINUS = 11, PLUS = 12, LT = 13, LEQ = 14, 
    EQ = 15, NEQ = 16, GEQ = 17, GT = 18, ASSIGN = 19, NONDETNAME = 20, 
    OR = 21, AND = 22, NOT = 23, TRUE = 24, FALSE = 25, TYPEDEF = 26, ENUM = 27, 
    COMMA = 28, BOOL = 29, EXTERN = 30, VOID = 31, MAIN = 32, RETURN = 33, 
    ZERO = 34, POS = 35, V = 36, W = 37, BLOCKCOMMENT = 38, LINECOMMENT = 39
  };

  explicit CINTLexer(antlr4::CharStream *input);

  ~CINTLexer() override;


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

