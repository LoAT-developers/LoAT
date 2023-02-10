
// Generated from CINT.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  CINTLexer : public antlr4::Lexer {
public:
  enum {
    INT = 1, IF = 2, WHILE = 3, ELSE = 4, TERMINATOR = 5, OPENP = 6, CLOSEP = 7, 
    OPENC = 8, CLOSEC = 9, MULT = 10, MINUS = 11, PLUS = 12, BO = 13, ASSIGN = 14, 
    NONDETNAME = 15, OR = 16, AND = 17, NOT = 18, TRUE = 19, FALSE = 20, 
    TYPEDEF = 21, ENUM = 22, COMMA = 23, BOOL = 24, EXTERN = 25, VOID = 26, 
    MAIN = 27, RETURN = 28, ZERO = 29, POS = 30, V = 31, W = 32, BLOCKCOMMENT = 33, 
    LINECOMMENT = 34
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

