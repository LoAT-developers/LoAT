
// Generated from redlog.g4 by ANTLR 4.11.1


#include "redlogLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct RedlogLexerStaticData final {
  RedlogLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RedlogLexerStaticData(const RedlogLexerStaticData&) = delete;
  RedlogLexerStaticData(RedlogLexerStaticData&&) = delete;
  RedlogLexerStaticData& operator=(const RedlogLexerStaticData&) = delete;
  RedlogLexerStaticData& operator=(RedlogLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag redloglexerLexerOnceFlag;
RedlogLexerStaticData *redloglexerLexerStaticData = nullptr;

void redloglexerLexerInitialize() {
  assert(redloglexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<RedlogLexerStaticData>(
    std::vector<std::string>{
      "PLUS", "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "AND", "OR", "LT", 
      "LEQ", "EQ", "NEQ", "GEQ", "GT", "TRUE", "FALSE", "VAR", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'plus'", "'minus'", "'times'", "'expt'", "'('", "')'", "'and'", 
      "'or'", "'lessp'", "'leq'", "'equal'", "'neq'", "'geq'", "'greaterp'", 
      "'true'", "'false'"
    },
    std::vector<std::string>{
      "", "PLUS", "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "AND", "OR", 
      "LT", "LEQ", "EQ", "NEQ", "GEQ", "GT", "TRUE", "FALSE", "VAR", "INT", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,19,135,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,
  	4,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,
  	1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,
  	14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,5,16,119,8,16,10,16,12,
  	16,122,9,16,1,17,4,17,125,8,17,11,17,12,17,126,1,18,4,18,130,8,18,11,
  	18,12,18,131,1,18,1,18,0,0,19,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,
  	19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,1,0,3,3,0,
  	65,90,95,95,97,122,6,0,39,39,46,46,48,57,65,90,95,95,97,122,3,0,9,10,
  	13,13,32,32,137,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,
  	0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,
  	0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,
  	31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,44,1,
  	0,0,0,5,50,1,0,0,0,7,56,1,0,0,0,9,61,1,0,0,0,11,63,1,0,0,0,13,65,1,0,
  	0,0,15,69,1,0,0,0,17,72,1,0,0,0,19,78,1,0,0,0,21,82,1,0,0,0,23,88,1,0,
  	0,0,25,92,1,0,0,0,27,96,1,0,0,0,29,105,1,0,0,0,31,110,1,0,0,0,33,116,
  	1,0,0,0,35,124,1,0,0,0,37,129,1,0,0,0,39,40,5,112,0,0,40,41,5,108,0,0,
  	41,42,5,117,0,0,42,43,5,115,0,0,43,2,1,0,0,0,44,45,5,109,0,0,45,46,5,
  	105,0,0,46,47,5,110,0,0,47,48,5,117,0,0,48,49,5,115,0,0,49,4,1,0,0,0,
  	50,51,5,116,0,0,51,52,5,105,0,0,52,53,5,109,0,0,53,54,5,101,0,0,54,55,
  	5,115,0,0,55,6,1,0,0,0,56,57,5,101,0,0,57,58,5,120,0,0,58,59,5,112,0,
  	0,59,60,5,116,0,0,60,8,1,0,0,0,61,62,5,40,0,0,62,10,1,0,0,0,63,64,5,41,
  	0,0,64,12,1,0,0,0,65,66,5,97,0,0,66,67,5,110,0,0,67,68,5,100,0,0,68,14,
  	1,0,0,0,69,70,5,111,0,0,70,71,5,114,0,0,71,16,1,0,0,0,72,73,5,108,0,0,
  	73,74,5,101,0,0,74,75,5,115,0,0,75,76,5,115,0,0,76,77,5,112,0,0,77,18,
  	1,0,0,0,78,79,5,108,0,0,79,80,5,101,0,0,80,81,5,113,0,0,81,20,1,0,0,0,
  	82,83,5,101,0,0,83,84,5,113,0,0,84,85,5,117,0,0,85,86,5,97,0,0,86,87,
  	5,108,0,0,87,22,1,0,0,0,88,89,5,110,0,0,89,90,5,101,0,0,90,91,5,113,0,
  	0,91,24,1,0,0,0,92,93,5,103,0,0,93,94,5,101,0,0,94,95,5,113,0,0,95,26,
  	1,0,0,0,96,97,5,103,0,0,97,98,5,114,0,0,98,99,5,101,0,0,99,100,5,97,0,
  	0,100,101,5,116,0,0,101,102,5,101,0,0,102,103,5,114,0,0,103,104,5,112,
  	0,0,104,28,1,0,0,0,105,106,5,116,0,0,106,107,5,114,0,0,107,108,5,117,
  	0,0,108,109,5,101,0,0,109,30,1,0,0,0,110,111,5,102,0,0,111,112,5,97,0,
  	0,112,113,5,108,0,0,113,114,5,115,0,0,114,115,5,101,0,0,115,32,1,0,0,
  	0,116,120,7,0,0,0,117,119,7,1,0,0,118,117,1,0,0,0,119,122,1,0,0,0,120,
  	118,1,0,0,0,120,121,1,0,0,0,121,34,1,0,0,0,122,120,1,0,0,0,123,125,2,
  	48,57,0,124,123,1,0,0,0,125,126,1,0,0,0,126,124,1,0,0,0,126,127,1,0,0,
  	0,127,36,1,0,0,0,128,130,7,2,0,0,129,128,1,0,0,0,130,131,1,0,0,0,131,
  	129,1,0,0,0,131,132,1,0,0,0,132,133,1,0,0,0,133,134,6,18,0,0,134,38,1,
  	0,0,0,4,0,120,126,131,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  redloglexerLexerStaticData = staticData.release();
}

}

redlogLexer::redlogLexer(CharStream *input) : Lexer(input) {
  redlogLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *redloglexerLexerStaticData->atn, redloglexerLexerStaticData->decisionToDFA, redloglexerLexerStaticData->sharedContextCache);
}

redlogLexer::~redlogLexer() {
  delete _interpreter;
}

std::string redlogLexer::getGrammarFileName() const {
  return "redlog.g4";
}

const std::vector<std::string>& redlogLexer::getRuleNames() const {
  return redloglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& redlogLexer::getChannelNames() const {
  return redloglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& redlogLexer::getModeNames() const {
  return redloglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& redlogLexer::getVocabulary() const {
  return redloglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView redlogLexer::getSerializedATN() const {
  return redloglexerLexerStaticData->serializedATN;
}

const atn::ATN& redlogLexer::getATN() const {
  return *redloglexerLexerStaticData->atn;
}




void redlogLexer::initialize() {
  ::antlr4::internal::call_once(redloglexerLexerOnceFlag, redloglexerLexerInitialize);
}
