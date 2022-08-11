
// Generated from CHC.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CHCLexer : public antlr4::Lexer {
public:
  enum {
    LOGIC = 1, ASSERT = 2, CHECK_SAT = 3, EXIT = 4, DECLARE_FUN = 5, BOOL = 6, 
    FORALL = 7, IMPLIES = 8, FALSE = 9, PIPE = 10, PLUS = 11, MINUS = 12, 
    TIMES = 13, MOD = 14, LPAR = 15, RPAR = 16, AND = 17, OR = 18, NOT = 19, 
    ITE = 20, LT = 21, LEQ = 22, EQ = 23, NEQ = 24, GEQ = 25, GT = 26, SC = 27, 
    LETTER = 28, INT = 29, WS = 30, COMMENT = 31, OTHER = 32
  };

  CHCLexer(antlr4::CharStream *input);
  ~CHCLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

