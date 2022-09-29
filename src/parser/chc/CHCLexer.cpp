
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
      "LOGIC", "ASSERT", "CHECK_SAT", "EXIT", "DECLARE_FUN", "BOOL_SORT", 
      "INT_SORT", "FORALL", "LET", "IMPLIES", "FALSE", "TRUE", "PLUS", "MINUS", 
      "TIMES", "MOD", "DIV", "LPAR", "RPAR", "AND", "OR", "NOT", "ITE", 
      "LT", "LEQ", "EQ", "NEQ", "GEQ", "GT", "ID", "SC", "LETTER", "INT", 
      "WS", "COMMENT", "OTHER"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'set-logic HORN'", "'assert'", "'check-sat'", "'exit'", "'declare-fun'", 
      "'Bool'", "'Int'", "'forall'", "'let'", "'=>'", "'false'", "'true'", 
      "'+'", "'-'", "'*'", "'mod'", "'div'", "'('", "')'", "'and'", "'or'", 
      "'not'", "'ite'", "'<'", "'<='", "'='", "'!='", "'>='", "'>'"
    },
    std::vector<std::string>{
      "", "LOGIC", "ASSERT", "CHECK_SAT", "EXIT", "DECLARE_FUN", "BOOL_SORT", 
      "INT_SORT", "FORALL", "LET", "IMPLIES", "FALSE", "TRUE", "PLUS", "MINUS", 
      "TIMES", "MOD", "DIV", "LPAR", "RPAR", "AND", "OR", "NOT", "ITE", 
      "LT", "LEQ", "EQ", "NEQ", "GEQ", "GT", "ID", "INT", "WS", "COMMENT", 
      "OTHER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,34,259,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,
  	3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,
  	1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
  	1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,
  	1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,
  	1,21,1,22,1,22,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,26,1,26,
  	1,26,1,27,1,27,1,27,1,28,1,28,1,29,1,29,3,29,207,8,29,1,29,1,29,1,29,
  	5,29,212,8,29,10,29,12,29,215,9,29,1,29,1,29,4,29,219,8,29,11,29,12,29,
  	220,1,29,3,29,224,8,29,1,30,1,30,1,31,1,31,1,32,4,32,231,8,32,11,32,12,
  	32,232,1,33,4,33,236,8,33,11,33,12,33,237,1,33,1,33,1,34,1,34,5,34,244,
  	8,34,10,34,12,34,247,9,34,1,34,3,34,250,8,34,1,34,1,34,3,34,254,8,34,
  	1,34,1,34,1,35,1,35,1,245,0,36,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,0,63,0,65,
  	31,67,32,69,33,71,34,1,0,4,1,0,124,124,7,0,33,33,36,38,42,43,45,47,60,
  	64,94,95,126,126,2,0,65,90,97,122,3,0,9,10,13,13,32,32,267,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,
  	0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,
  	0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,
  	35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,
  	0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,
  	0,0,57,1,0,0,0,0,59,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,
  	71,1,0,0,0,1,73,1,0,0,0,3,88,1,0,0,0,5,95,1,0,0,0,7,105,1,0,0,0,9,110,
  	1,0,0,0,11,122,1,0,0,0,13,127,1,0,0,0,15,131,1,0,0,0,17,138,1,0,0,0,19,
  	142,1,0,0,0,21,145,1,0,0,0,23,151,1,0,0,0,25,156,1,0,0,0,27,158,1,0,0,
  	0,29,160,1,0,0,0,31,162,1,0,0,0,33,166,1,0,0,0,35,170,1,0,0,0,37,172,
  	1,0,0,0,39,174,1,0,0,0,41,178,1,0,0,0,43,181,1,0,0,0,45,185,1,0,0,0,47,
  	189,1,0,0,0,49,191,1,0,0,0,51,194,1,0,0,0,53,196,1,0,0,0,55,199,1,0,0,
  	0,57,202,1,0,0,0,59,223,1,0,0,0,61,225,1,0,0,0,63,227,1,0,0,0,65,230,
  	1,0,0,0,67,235,1,0,0,0,69,241,1,0,0,0,71,257,1,0,0,0,73,74,5,115,0,0,
  	74,75,5,101,0,0,75,76,5,116,0,0,76,77,5,45,0,0,77,78,5,108,0,0,78,79,
  	5,111,0,0,79,80,5,103,0,0,80,81,5,105,0,0,81,82,5,99,0,0,82,83,5,32,0,
  	0,83,84,5,72,0,0,84,85,5,79,0,0,85,86,5,82,0,0,86,87,5,78,0,0,87,2,1,
  	0,0,0,88,89,5,97,0,0,89,90,5,115,0,0,90,91,5,115,0,0,91,92,5,101,0,0,
  	92,93,5,114,0,0,93,94,5,116,0,0,94,4,1,0,0,0,95,96,5,99,0,0,96,97,5,104,
  	0,0,97,98,5,101,0,0,98,99,5,99,0,0,99,100,5,107,0,0,100,101,5,45,0,0,
  	101,102,5,115,0,0,102,103,5,97,0,0,103,104,5,116,0,0,104,6,1,0,0,0,105,
  	106,5,101,0,0,106,107,5,120,0,0,107,108,5,105,0,0,108,109,5,116,0,0,109,
  	8,1,0,0,0,110,111,5,100,0,0,111,112,5,101,0,0,112,113,5,99,0,0,113,114,
  	5,108,0,0,114,115,5,97,0,0,115,116,5,114,0,0,116,117,5,101,0,0,117,118,
  	5,45,0,0,118,119,5,102,0,0,119,120,5,117,0,0,120,121,5,110,0,0,121,10,
  	1,0,0,0,122,123,5,66,0,0,123,124,5,111,0,0,124,125,5,111,0,0,125,126,
  	5,108,0,0,126,12,1,0,0,0,127,128,5,73,0,0,128,129,5,110,0,0,129,130,5,
  	116,0,0,130,14,1,0,0,0,131,132,5,102,0,0,132,133,5,111,0,0,133,134,5,
  	114,0,0,134,135,5,97,0,0,135,136,5,108,0,0,136,137,5,108,0,0,137,16,1,
  	0,0,0,138,139,5,108,0,0,139,140,5,101,0,0,140,141,5,116,0,0,141,18,1,
  	0,0,0,142,143,5,61,0,0,143,144,5,62,0,0,144,20,1,0,0,0,145,146,5,102,
  	0,0,146,147,5,97,0,0,147,148,5,108,0,0,148,149,5,115,0,0,149,150,5,101,
  	0,0,150,22,1,0,0,0,151,152,5,116,0,0,152,153,5,114,0,0,153,154,5,117,
  	0,0,154,155,5,101,0,0,155,24,1,0,0,0,156,157,5,43,0,0,157,26,1,0,0,0,
  	158,159,5,45,0,0,159,28,1,0,0,0,160,161,5,42,0,0,161,30,1,0,0,0,162,163,
  	5,109,0,0,163,164,5,111,0,0,164,165,5,100,0,0,165,32,1,0,0,0,166,167,
  	5,100,0,0,167,168,5,105,0,0,168,169,5,118,0,0,169,34,1,0,0,0,170,171,
  	5,40,0,0,171,36,1,0,0,0,172,173,5,41,0,0,173,38,1,0,0,0,174,175,5,97,
  	0,0,175,176,5,110,0,0,176,177,5,100,0,0,177,40,1,0,0,0,178,179,5,111,
  	0,0,179,180,5,114,0,0,180,42,1,0,0,0,181,182,5,110,0,0,182,183,5,111,
  	0,0,183,184,5,116,0,0,184,44,1,0,0,0,185,186,5,105,0,0,186,187,5,116,
  	0,0,187,188,5,101,0,0,188,46,1,0,0,0,189,190,5,60,0,0,190,48,1,0,0,0,
  	191,192,5,60,0,0,192,193,5,61,0,0,193,50,1,0,0,0,194,195,5,61,0,0,195,
  	52,1,0,0,0,196,197,5,33,0,0,197,198,5,61,0,0,198,54,1,0,0,0,199,200,5,
  	62,0,0,200,201,5,61,0,0,201,56,1,0,0,0,202,203,5,62,0,0,203,58,1,0,0,
  	0,204,207,3,61,30,0,205,207,3,63,31,0,206,204,1,0,0,0,206,205,1,0,0,0,
  	207,213,1,0,0,0,208,212,3,61,30,0,209,212,3,63,31,0,210,212,2,48,57,0,
  	211,208,1,0,0,0,211,209,1,0,0,0,211,210,1,0,0,0,212,215,1,0,0,0,213,211,
  	1,0,0,0,213,214,1,0,0,0,214,224,1,0,0,0,215,213,1,0,0,0,216,218,5,124,
  	0,0,217,219,8,0,0,0,218,217,1,0,0,0,219,220,1,0,0,0,220,218,1,0,0,0,220,
  	221,1,0,0,0,221,222,1,0,0,0,222,224,5,124,0,0,223,206,1,0,0,0,223,216,
  	1,0,0,0,224,60,1,0,0,0,225,226,7,1,0,0,226,62,1,0,0,0,227,228,7,2,0,0,
  	228,64,1,0,0,0,229,231,2,48,57,0,230,229,1,0,0,0,231,232,1,0,0,0,232,
  	230,1,0,0,0,232,233,1,0,0,0,233,66,1,0,0,0,234,236,7,3,0,0,235,234,1,
  	0,0,0,236,237,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,239,1,0,0,0,
  	239,240,6,33,0,0,240,68,1,0,0,0,241,245,5,59,0,0,242,244,9,0,0,0,243,
  	242,1,0,0,0,244,247,1,0,0,0,245,246,1,0,0,0,245,243,1,0,0,0,246,253,1,
  	0,0,0,247,245,1,0,0,0,248,250,5,13,0,0,249,248,1,0,0,0,249,250,1,0,0,
  	0,250,251,1,0,0,0,251,254,5,10,0,0,252,254,5,13,0,0,253,249,1,0,0,0,253,
  	252,1,0,0,0,254,255,1,0,0,0,255,256,6,34,0,0,256,70,1,0,0,0,257,258,8,
  	0,0,0,258,72,1,0,0,0,11,0,206,211,213,220,223,232,237,245,249,253,1,6,
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
