
// Generated from Koat.g4 by ANTLR 4.11.1


#include "KoatLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct KoatLexerStaticData final {
  KoatLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  KoatLexerStaticData(const KoatLexerStaticData&) = delete;
  KoatLexerStaticData(KoatLexerStaticData&&) = delete;
  KoatLexerStaticData& operator=(const KoatLexerStaticData&) = delete;
  KoatLexerStaticData& operator=(KoatLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag koatlexerLexerOnceFlag;
KoatLexerStaticData *koatlexerLexerStaticData = nullptr;

void koatlexerLexerInitialize() {
  assert(koatlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<KoatLexerStaticData>(
    std::vector<std::string>{
      "COM", "GOAL", "CPX", "TERM", "START", "SINK", "FS", "VAR", "RULES", 
      "PLUS", "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "RBRACK", "LBRACK", 
      "LCURL", "RCURL", "TO", "COMMA", "AND", "OR", "LT", "LEQ", "EQ", "NEQ", 
      "GEQ", "GT", "CONDSEP", "ID", "INT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'GOAL'", "'COMPLEXITY'", "'TERMINATION'", "'STARTTERM'", 
      "'SINKTERM'", "'FUNCTIONSYMBOLS'", "'VAR'", "'RULES'", "'+'", "'-'", 
      "'*'", "", "'('", "')'", "']'", "'['", "'{'", "'}'", "'->'", "','", 
      "", "", "'<'", "'<='", "", "'!='", "'>='", "'>'", "':|:'"
    },
    std::vector<std::string>{
      "", "COM", "GOAL", "CPX", "TERM", "START", "SINK", "FS", "VAR", "RULES", 
      "PLUS", "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "RBRACK", "LBRACK", 
      "LCURL", "RCURL", "TO", "COMMA", "AND", "OR", "LT", "LEQ", "EQ", "NEQ", 
      "GEQ", "GT", "CONDSEP", "ID", "INT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,34,249,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,0,1,
  	0,1,0,1,0,4,0,76,8,0,11,0,12,0,77,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,
  	1,11,1,12,1,12,1,12,3,12,162,8,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,
  	1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,21,1,21,1,21,1,21,
  	3,21,185,8,21,1,22,1,22,1,22,1,22,3,22,191,8,22,1,23,1,23,1,24,1,24,1,
  	24,1,25,1,25,1,25,3,25,201,8,25,1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,
  	28,1,29,1,29,1,29,1,29,1,30,1,30,5,30,217,8,30,10,30,12,30,220,9,30,1,
  	31,4,31,223,8,31,11,31,12,31,224,1,32,4,32,228,8,32,11,32,12,32,229,1,
  	32,1,32,1,33,1,33,5,33,236,8,33,10,33,12,33,239,9,33,1,33,3,33,242,8,
  	33,1,33,1,33,3,33,246,8,33,1,33,1,33,1,237,0,34,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,
  	37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,
  	30,61,31,63,32,65,33,67,34,1,0,3,3,0,65,90,95,95,97,122,6,0,39,39,46,
  	46,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,259,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,
  	1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,
  	0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,
  	0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,
  	1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,
  	0,0,1,69,1,0,0,0,3,79,1,0,0,0,5,84,1,0,0,0,7,95,1,0,0,0,9,107,1,0,0,0,
  	11,117,1,0,0,0,13,126,1,0,0,0,15,142,1,0,0,0,17,146,1,0,0,0,19,152,1,
  	0,0,0,21,154,1,0,0,0,23,156,1,0,0,0,25,161,1,0,0,0,27,163,1,0,0,0,29,
  	165,1,0,0,0,31,167,1,0,0,0,33,169,1,0,0,0,35,171,1,0,0,0,37,173,1,0,0,
  	0,39,175,1,0,0,0,41,178,1,0,0,0,43,184,1,0,0,0,45,190,1,0,0,0,47,192,
  	1,0,0,0,49,194,1,0,0,0,51,200,1,0,0,0,53,202,1,0,0,0,55,205,1,0,0,0,57,
  	208,1,0,0,0,59,210,1,0,0,0,61,214,1,0,0,0,63,222,1,0,0,0,65,227,1,0,0,
  	0,67,233,1,0,0,0,69,70,5,67,0,0,70,71,5,111,0,0,71,72,5,109,0,0,72,73,
  	5,95,0,0,73,75,1,0,0,0,74,76,2,48,57,0,75,74,1,0,0,0,76,77,1,0,0,0,77,
  	75,1,0,0,0,77,78,1,0,0,0,78,2,1,0,0,0,79,80,5,71,0,0,80,81,5,79,0,0,81,
  	82,5,65,0,0,82,83,5,76,0,0,83,4,1,0,0,0,84,85,5,67,0,0,85,86,5,79,0,0,
  	86,87,5,77,0,0,87,88,5,80,0,0,88,89,5,76,0,0,89,90,5,69,0,0,90,91,5,88,
  	0,0,91,92,5,73,0,0,92,93,5,84,0,0,93,94,5,89,0,0,94,6,1,0,0,0,95,96,5,
  	84,0,0,96,97,5,69,0,0,97,98,5,82,0,0,98,99,5,77,0,0,99,100,5,73,0,0,100,
  	101,5,78,0,0,101,102,5,65,0,0,102,103,5,84,0,0,103,104,5,73,0,0,104,105,
  	5,79,0,0,105,106,5,78,0,0,106,8,1,0,0,0,107,108,5,83,0,0,108,109,5,84,
  	0,0,109,110,5,65,0,0,110,111,5,82,0,0,111,112,5,84,0,0,112,113,5,84,0,
  	0,113,114,5,69,0,0,114,115,5,82,0,0,115,116,5,77,0,0,116,10,1,0,0,0,117,
  	118,5,83,0,0,118,119,5,73,0,0,119,120,5,78,0,0,120,121,5,75,0,0,121,122,
  	5,84,0,0,122,123,5,69,0,0,123,124,5,82,0,0,124,125,5,77,0,0,125,12,1,
  	0,0,0,126,127,5,70,0,0,127,128,5,85,0,0,128,129,5,78,0,0,129,130,5,67,
  	0,0,130,131,5,84,0,0,131,132,5,73,0,0,132,133,5,79,0,0,133,134,5,78,0,
  	0,134,135,5,83,0,0,135,136,5,89,0,0,136,137,5,77,0,0,137,138,5,66,0,0,
  	138,139,5,79,0,0,139,140,5,76,0,0,140,141,5,83,0,0,141,14,1,0,0,0,142,
  	143,5,86,0,0,143,144,5,65,0,0,144,145,5,82,0,0,145,16,1,0,0,0,146,147,
  	5,82,0,0,147,148,5,85,0,0,148,149,5,76,0,0,149,150,5,69,0,0,150,151,5,
  	83,0,0,151,18,1,0,0,0,152,153,5,43,0,0,153,20,1,0,0,0,154,155,5,45,0,
  	0,155,22,1,0,0,0,156,157,5,42,0,0,157,24,1,0,0,0,158,162,5,94,0,0,159,
  	160,5,42,0,0,160,162,5,42,0,0,161,158,1,0,0,0,161,159,1,0,0,0,162,26,
  	1,0,0,0,163,164,5,40,0,0,164,28,1,0,0,0,165,166,5,41,0,0,166,30,1,0,0,
  	0,167,168,5,93,0,0,168,32,1,0,0,0,169,170,5,91,0,0,170,34,1,0,0,0,171,
  	172,5,123,0,0,172,36,1,0,0,0,173,174,5,125,0,0,174,38,1,0,0,0,175,176,
  	5,45,0,0,176,177,5,62,0,0,177,40,1,0,0,0,178,179,5,44,0,0,179,42,1,0,
  	0,0,180,181,5,47,0,0,181,185,5,92,0,0,182,183,5,38,0,0,183,185,5,38,0,
  	0,184,180,1,0,0,0,184,182,1,0,0,0,185,44,1,0,0,0,186,187,5,92,0,0,187,
  	191,5,47,0,0,188,189,5,124,0,0,189,191,5,124,0,0,190,186,1,0,0,0,190,
  	188,1,0,0,0,191,46,1,0,0,0,192,193,5,60,0,0,193,48,1,0,0,0,194,195,5,
  	60,0,0,195,196,5,61,0,0,196,50,1,0,0,0,197,198,5,61,0,0,198,201,5,61,
  	0,0,199,201,5,61,0,0,200,197,1,0,0,0,200,199,1,0,0,0,201,52,1,0,0,0,202,
  	203,5,33,0,0,203,204,5,61,0,0,204,54,1,0,0,0,205,206,5,62,0,0,206,207,
  	5,61,0,0,207,56,1,0,0,0,208,209,5,62,0,0,209,58,1,0,0,0,210,211,5,58,
  	0,0,211,212,5,124,0,0,212,213,5,58,0,0,213,60,1,0,0,0,214,218,7,0,0,0,
  	215,217,7,1,0,0,216,215,1,0,0,0,217,220,1,0,0,0,218,216,1,0,0,0,218,219,
  	1,0,0,0,219,62,1,0,0,0,220,218,1,0,0,0,221,223,2,48,57,0,222,221,1,0,
  	0,0,223,224,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,64,1,0,0,0,226,
  	228,7,2,0,0,227,226,1,0,0,0,228,229,1,0,0,0,229,227,1,0,0,0,229,230,1,
  	0,0,0,230,231,1,0,0,0,231,232,6,32,0,0,232,66,1,0,0,0,233,237,5,35,0,
  	0,234,236,9,0,0,0,235,234,1,0,0,0,236,239,1,0,0,0,237,238,1,0,0,0,237,
  	235,1,0,0,0,238,245,1,0,0,0,239,237,1,0,0,0,240,242,5,13,0,0,241,240,
  	1,0,0,0,241,242,1,0,0,0,242,243,1,0,0,0,243,246,5,10,0,0,244,246,5,13,
  	0,0,245,241,1,0,0,0,245,244,1,0,0,0,246,247,1,0,0,0,247,248,6,33,0,0,
  	248,68,1,0,0,0,12,0,77,161,184,190,200,218,224,229,237,241,245,1,6,0,
  	0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  koatlexerLexerStaticData = staticData.release();
}

}

KoatLexer::KoatLexer(CharStream *input) : Lexer(input) {
  KoatLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *koatlexerLexerStaticData->atn, koatlexerLexerStaticData->decisionToDFA, koatlexerLexerStaticData->sharedContextCache);
}

KoatLexer::~KoatLexer() {
  delete _interpreter;
}

std::string KoatLexer::getGrammarFileName() const {
  return "Koat.g4";
}

const std::vector<std::string>& KoatLexer::getRuleNames() const {
  return koatlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& KoatLexer::getChannelNames() const {
  return koatlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& KoatLexer::getModeNames() const {
  return koatlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& KoatLexer::getVocabulary() const {
  return koatlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView KoatLexer::getSerializedATN() const {
  return koatlexerLexerStaticData->serializedATN;
}

const atn::ATN& KoatLexer::getATN() const {
  return *koatlexerLexerStaticData->atn;
}




void KoatLexer::initialize() {
  ::antlr4::internal::call_once(koatlexerLexerOnceFlag, koatlexerLexerInitialize);
}
