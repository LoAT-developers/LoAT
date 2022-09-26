
// Generated from CHC.g4 by ANTLR 4.11.1


#include "CHCLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CHCLexerStaticData final {
  CHCLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CHCLexerStaticData(const CHCLexerStaticData&) = delete;
  CHCLexerStaticData(CHCLexerStaticData&&) = delete;
  CHCLexerStaticData& operator=(const CHCLexerStaticData&) = delete;
  CHCLexerStaticData& operator=(CHCLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag chclexerLexerOnceFlag;
CHCLexerStaticData *chclexerLexerStaticData = nullptr;

void chclexerLexerInitialize() {
  assert(chclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CHCLexerStaticData>(
    std::vector<std::string>{
      "LOGIC", "ASSERT", "CHECK_SAT", "EXIT", "DECLARE_FUN", "BOOL", "FORALL", 
      "LET", "IMPLIES", "FALSE", "TRUE", "PLUS", "MINUS", "TIMES", "MOD", 
      "DIV", "LPAR", "RPAR", "AND", "OR", "NOT", "ITE", "LT", "LEQ", "EQ", 
      "NEQ", "GEQ", "GT", "ID", "SC", "LETTER", "INT", "WS", "COMMENT", 
      "OTHER"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'set-logic HORN'", "'assert'", "'check-sat'", "'exit'", "'declare-fun'", 
      "'Bool'", "'forall'", "'let'", "'=>'", "'false'", "'true'", "'+'", 
      "'-'", "'*'", "'mod'", "'div'", "'('", "')'", "'and'", "'or'", "'not'", 
      "'ite'", "'<'", "'<='", "'='", "'!='", "'>='", "'>'"
    },
    std::vector<std::string>{
      "", "LOGIC", "ASSERT", "CHECK_SAT", "EXIT", "DECLARE_FUN", "BOOL", 
      "FORALL", "LET", "IMPLIES", "FALSE", "TRUE", "PLUS", "MINUS", "TIMES", 
      "MOD", "DIV", "LPAR", "RPAR", "AND", "OR", "NOT", "ITE", "LT", "LEQ", 
      "EQ", "NEQ", "GEQ", "GT", "ID", "INT", "WS", "COMMENT", "OTHER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,33,253,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,
  	14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,
  	18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,
  	22,1,23,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,
  	28,1,28,3,28,201,8,28,1,28,1,28,1,28,5,28,206,8,28,10,28,12,28,209,9,
  	28,1,28,1,28,4,28,213,8,28,11,28,12,28,214,1,28,3,28,218,8,28,1,29,1,
  	29,1,30,1,30,1,31,4,31,225,8,31,11,31,12,31,226,1,32,4,32,230,8,32,11,
  	32,12,32,231,1,32,1,32,1,33,1,33,5,33,238,8,33,10,33,12,33,241,9,33,1,
  	33,3,33,244,8,33,1,33,1,33,3,33,248,8,33,1,33,1,33,1,34,1,34,1,239,0,
  	35,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,
  	14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,
  	51,26,53,27,55,28,57,29,59,0,61,0,63,30,65,31,67,32,69,33,1,0,4,1,0,124,
  	124,7,0,33,33,36,38,42,43,45,47,60,64,94,95,126,126,2,0,65,90,97,122,
  	3,0,9,10,13,13,32,32,261,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,
  	0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,
  	19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,
  	0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,
  	0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,
  	51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,63,1,0,0,0,0,65,1,
  	0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,1,71,1,0,0,0,3,86,1,0,0,0,5,93,1,0,0,
  	0,7,103,1,0,0,0,9,108,1,0,0,0,11,120,1,0,0,0,13,125,1,0,0,0,15,132,1,
  	0,0,0,17,136,1,0,0,0,19,139,1,0,0,0,21,145,1,0,0,0,23,150,1,0,0,0,25,
  	152,1,0,0,0,27,154,1,0,0,0,29,156,1,0,0,0,31,160,1,0,0,0,33,164,1,0,0,
  	0,35,166,1,0,0,0,37,168,1,0,0,0,39,172,1,0,0,0,41,175,1,0,0,0,43,179,
  	1,0,0,0,45,183,1,0,0,0,47,185,1,0,0,0,49,188,1,0,0,0,51,190,1,0,0,0,53,
  	193,1,0,0,0,55,196,1,0,0,0,57,217,1,0,0,0,59,219,1,0,0,0,61,221,1,0,0,
  	0,63,224,1,0,0,0,65,229,1,0,0,0,67,235,1,0,0,0,69,251,1,0,0,0,71,72,5,
  	115,0,0,72,73,5,101,0,0,73,74,5,116,0,0,74,75,5,45,0,0,75,76,5,108,0,
  	0,76,77,5,111,0,0,77,78,5,103,0,0,78,79,5,105,0,0,79,80,5,99,0,0,80,81,
  	5,32,0,0,81,82,5,72,0,0,82,83,5,79,0,0,83,84,5,82,0,0,84,85,5,78,0,0,
  	85,2,1,0,0,0,86,87,5,97,0,0,87,88,5,115,0,0,88,89,5,115,0,0,89,90,5,101,
  	0,0,90,91,5,114,0,0,91,92,5,116,0,0,92,4,1,0,0,0,93,94,5,99,0,0,94,95,
  	5,104,0,0,95,96,5,101,0,0,96,97,5,99,0,0,97,98,5,107,0,0,98,99,5,45,0,
  	0,99,100,5,115,0,0,100,101,5,97,0,0,101,102,5,116,0,0,102,6,1,0,0,0,103,
  	104,5,101,0,0,104,105,5,120,0,0,105,106,5,105,0,0,106,107,5,116,0,0,107,
  	8,1,0,0,0,108,109,5,100,0,0,109,110,5,101,0,0,110,111,5,99,0,0,111,112,
  	5,108,0,0,112,113,5,97,0,0,113,114,5,114,0,0,114,115,5,101,0,0,115,116,
  	5,45,0,0,116,117,5,102,0,0,117,118,5,117,0,0,118,119,5,110,0,0,119,10,
  	1,0,0,0,120,121,5,66,0,0,121,122,5,111,0,0,122,123,5,111,0,0,123,124,
  	5,108,0,0,124,12,1,0,0,0,125,126,5,102,0,0,126,127,5,111,0,0,127,128,
  	5,114,0,0,128,129,5,97,0,0,129,130,5,108,0,0,130,131,5,108,0,0,131,14,
  	1,0,0,0,132,133,5,108,0,0,133,134,5,101,0,0,134,135,5,116,0,0,135,16,
  	1,0,0,0,136,137,5,61,0,0,137,138,5,62,0,0,138,18,1,0,0,0,139,140,5,102,
  	0,0,140,141,5,97,0,0,141,142,5,108,0,0,142,143,5,115,0,0,143,144,5,101,
  	0,0,144,20,1,0,0,0,145,146,5,116,0,0,146,147,5,114,0,0,147,148,5,117,
  	0,0,148,149,5,101,0,0,149,22,1,0,0,0,150,151,5,43,0,0,151,24,1,0,0,0,
  	152,153,5,45,0,0,153,26,1,0,0,0,154,155,5,42,0,0,155,28,1,0,0,0,156,157,
  	5,109,0,0,157,158,5,111,0,0,158,159,5,100,0,0,159,30,1,0,0,0,160,161,
  	5,100,0,0,161,162,5,105,0,0,162,163,5,118,0,0,163,32,1,0,0,0,164,165,
  	5,40,0,0,165,34,1,0,0,0,166,167,5,41,0,0,167,36,1,0,0,0,168,169,5,97,
  	0,0,169,170,5,110,0,0,170,171,5,100,0,0,171,38,1,0,0,0,172,173,5,111,
  	0,0,173,174,5,114,0,0,174,40,1,0,0,0,175,176,5,110,0,0,176,177,5,111,
  	0,0,177,178,5,116,0,0,178,42,1,0,0,0,179,180,5,105,0,0,180,181,5,116,
  	0,0,181,182,5,101,0,0,182,44,1,0,0,0,183,184,5,60,0,0,184,46,1,0,0,0,
  	185,186,5,60,0,0,186,187,5,61,0,0,187,48,1,0,0,0,188,189,5,61,0,0,189,
  	50,1,0,0,0,190,191,5,33,0,0,191,192,5,61,0,0,192,52,1,0,0,0,193,194,5,
  	62,0,0,194,195,5,61,0,0,195,54,1,0,0,0,196,197,5,62,0,0,197,56,1,0,0,
  	0,198,201,3,59,29,0,199,201,3,61,30,0,200,198,1,0,0,0,200,199,1,0,0,0,
  	201,207,1,0,0,0,202,206,3,59,29,0,203,206,3,61,30,0,204,206,2,48,57,0,
  	205,202,1,0,0,0,205,203,1,0,0,0,205,204,1,0,0,0,206,209,1,0,0,0,207,205,
  	1,0,0,0,207,208,1,0,0,0,208,218,1,0,0,0,209,207,1,0,0,0,210,212,5,124,
  	0,0,211,213,8,0,0,0,212,211,1,0,0,0,213,214,1,0,0,0,214,212,1,0,0,0,214,
  	215,1,0,0,0,215,216,1,0,0,0,216,218,5,124,0,0,217,200,1,0,0,0,217,210,
  	1,0,0,0,218,58,1,0,0,0,219,220,7,1,0,0,220,60,1,0,0,0,221,222,7,2,0,0,
  	222,62,1,0,0,0,223,225,2,48,57,0,224,223,1,0,0,0,225,226,1,0,0,0,226,
  	224,1,0,0,0,226,227,1,0,0,0,227,64,1,0,0,0,228,230,7,3,0,0,229,228,1,
  	0,0,0,230,231,1,0,0,0,231,229,1,0,0,0,231,232,1,0,0,0,232,233,1,0,0,0,
  	233,234,6,32,0,0,234,66,1,0,0,0,235,239,5,59,0,0,236,238,9,0,0,0,237,
  	236,1,0,0,0,238,241,1,0,0,0,239,240,1,0,0,0,239,237,1,0,0,0,240,247,1,
  	0,0,0,241,239,1,0,0,0,242,244,5,13,0,0,243,242,1,0,0,0,243,244,1,0,0,
  	0,244,245,1,0,0,0,245,248,5,10,0,0,246,248,5,13,0,0,247,243,1,0,0,0,247,
  	246,1,0,0,0,248,249,1,0,0,0,249,250,6,33,0,0,250,68,1,0,0,0,251,252,8,
  	0,0,0,252,70,1,0,0,0,11,0,200,205,207,214,217,226,231,239,243,247,1,6,
  	0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  chclexerLexerStaticData = staticData.release();
}

}

CHCLexer::CHCLexer(CharStream *input) : Lexer(input) {
  CHCLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *chclexerLexerStaticData->atn, chclexerLexerStaticData->decisionToDFA, chclexerLexerStaticData->sharedContextCache);
}

CHCLexer::~CHCLexer() {
  delete _interpreter;
}

std::string CHCLexer::getGrammarFileName() const {
  return "CHC.g4";
}

const std::vector<std::string>& CHCLexer::getRuleNames() const {
  return chclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CHCLexer::getChannelNames() const {
  return chclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CHCLexer::getModeNames() const {
  return chclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CHCLexer::getVocabulary() const {
  return chclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CHCLexer::getSerializedATN() const {
  return chclexerLexerStaticData->serializedATN;
}

const atn::ATN& CHCLexer::getATN() const {
  return *chclexerLexerStaticData->atn;
}




void CHCLexer::initialize() {
  ::antlr4::internal::call_once(chclexerLexerOnceFlag, chclexerLexerInitialize);
}
