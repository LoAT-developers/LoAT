
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
      "COM", "GOAL", "CPX", "TERM", "START", "FS", "VAR", "RULES", "PLUS", 
      "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "RBRACK", "LBRACK", "LCURL", 
      "RCURL", "TO", "COMMA", "AND", "OR", "LT", "LEQ", "EQ", "NEQ", "GEQ", 
      "GT", "CONDSEP", "ID", "INT", "WS", "COMMENT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'GOAL'", "'COMPLEXITY'", "'TERMINATION'", "'STARTTERM'", 
      "'FUNCTIONSYMBOLS'", "'VAR'", "'RULES'", "'+'", "'-'", "'*'", "", 
      "'('", "')'", "']'", "'['", "'{'", "'}'", "'->'", "','", "", "", "'<'", 
      "'<='", "", "'!='", "'>='", "'>'", "':|:'"
    },
    std::vector<std::string>{
      "", "COM", "GOAL", "CPX", "TERM", "START", "FS", "VAR", "RULES", "PLUS", 
      "MINUS", "TIMES", "EXP", "LPAR", "RPAR", "RBRACK", "LBRACK", "LCURL", 
      "RCURL", "TO", "COMMA", "AND", "OR", "LT", "LEQ", "EQ", "NEQ", "GEQ", 
      "GT", "CONDSEP", "ID", "INT", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,33,238,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,1,0,1,0,1,0,1,0,
  	4,0,74,8,0,11,0,12,0,75,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,11,3,11,151,8,11,1,12,1,12,1,13,
  	1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,19,1,19,
  	1,20,1,20,1,20,1,20,3,20,174,8,20,1,21,1,21,1,21,1,21,3,21,180,8,21,1,
  	22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,3,24,190,8,24,1,25,1,25,1,25,1,
  	26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,28,1,29,1,29,5,29,206,8,29,10,
  	29,12,29,209,9,29,1,30,4,30,212,8,30,11,30,12,30,213,1,31,4,31,217,8,
  	31,11,31,12,31,218,1,31,1,31,1,32,1,32,5,32,225,8,32,10,32,12,32,228,
  	9,32,1,32,3,32,231,8,32,1,32,1,32,3,32,235,8,32,1,32,1,32,1,226,0,33,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,
  	26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,1,0,3,3,0,65,90,95,95,97,
  	122,6,0,39,39,46,46,48,57,65,90,95,95,97,122,3,0,9,10,13,13,32,32,248,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,
  	1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,
  	0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,
  	0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,
  	1,0,0,0,1,67,1,0,0,0,3,77,1,0,0,0,5,82,1,0,0,0,7,93,1,0,0,0,9,105,1,0,
  	0,0,11,115,1,0,0,0,13,131,1,0,0,0,15,135,1,0,0,0,17,141,1,0,0,0,19,143,
  	1,0,0,0,21,145,1,0,0,0,23,150,1,0,0,0,25,152,1,0,0,0,27,154,1,0,0,0,29,
  	156,1,0,0,0,31,158,1,0,0,0,33,160,1,0,0,0,35,162,1,0,0,0,37,164,1,0,0,
  	0,39,167,1,0,0,0,41,173,1,0,0,0,43,179,1,0,0,0,45,181,1,0,0,0,47,183,
  	1,0,0,0,49,189,1,0,0,0,51,191,1,0,0,0,53,194,1,0,0,0,55,197,1,0,0,0,57,
  	199,1,0,0,0,59,203,1,0,0,0,61,211,1,0,0,0,63,216,1,0,0,0,65,222,1,0,0,
  	0,67,68,5,67,0,0,68,69,5,111,0,0,69,70,5,109,0,0,70,71,5,95,0,0,71,73,
  	1,0,0,0,72,74,2,48,57,0,73,72,1,0,0,0,74,75,1,0,0,0,75,73,1,0,0,0,75,
  	76,1,0,0,0,76,2,1,0,0,0,77,78,5,71,0,0,78,79,5,79,0,0,79,80,5,65,0,0,
  	80,81,5,76,0,0,81,4,1,0,0,0,82,83,5,67,0,0,83,84,5,79,0,0,84,85,5,77,
  	0,0,85,86,5,80,0,0,86,87,5,76,0,0,87,88,5,69,0,0,88,89,5,88,0,0,89,90,
  	5,73,0,0,90,91,5,84,0,0,91,92,5,89,0,0,92,6,1,0,0,0,93,94,5,84,0,0,94,
  	95,5,69,0,0,95,96,5,82,0,0,96,97,5,77,0,0,97,98,5,73,0,0,98,99,5,78,0,
  	0,99,100,5,65,0,0,100,101,5,84,0,0,101,102,5,73,0,0,102,103,5,79,0,0,
  	103,104,5,78,0,0,104,8,1,0,0,0,105,106,5,83,0,0,106,107,5,84,0,0,107,
  	108,5,65,0,0,108,109,5,82,0,0,109,110,5,84,0,0,110,111,5,84,0,0,111,112,
  	5,69,0,0,112,113,5,82,0,0,113,114,5,77,0,0,114,10,1,0,0,0,115,116,5,70,
  	0,0,116,117,5,85,0,0,117,118,5,78,0,0,118,119,5,67,0,0,119,120,5,84,0,
  	0,120,121,5,73,0,0,121,122,5,79,0,0,122,123,5,78,0,0,123,124,5,83,0,0,
  	124,125,5,89,0,0,125,126,5,77,0,0,126,127,5,66,0,0,127,128,5,79,0,0,128,
  	129,5,76,0,0,129,130,5,83,0,0,130,12,1,0,0,0,131,132,5,86,0,0,132,133,
  	5,65,0,0,133,134,5,82,0,0,134,14,1,0,0,0,135,136,5,82,0,0,136,137,5,85,
  	0,0,137,138,5,76,0,0,138,139,5,69,0,0,139,140,5,83,0,0,140,16,1,0,0,0,
  	141,142,5,43,0,0,142,18,1,0,0,0,143,144,5,45,0,0,144,20,1,0,0,0,145,146,
  	5,42,0,0,146,22,1,0,0,0,147,151,5,94,0,0,148,149,5,42,0,0,149,151,5,42,
  	0,0,150,147,1,0,0,0,150,148,1,0,0,0,151,24,1,0,0,0,152,153,5,40,0,0,153,
  	26,1,0,0,0,154,155,5,41,0,0,155,28,1,0,0,0,156,157,5,93,0,0,157,30,1,
  	0,0,0,158,159,5,91,0,0,159,32,1,0,0,0,160,161,5,123,0,0,161,34,1,0,0,
  	0,162,163,5,125,0,0,163,36,1,0,0,0,164,165,5,45,0,0,165,166,5,62,0,0,
  	166,38,1,0,0,0,167,168,5,44,0,0,168,40,1,0,0,0,169,170,5,47,0,0,170,174,
  	5,92,0,0,171,172,5,38,0,0,172,174,5,38,0,0,173,169,1,0,0,0,173,171,1,
  	0,0,0,174,42,1,0,0,0,175,176,5,92,0,0,176,180,5,47,0,0,177,178,5,124,
  	0,0,178,180,5,124,0,0,179,175,1,0,0,0,179,177,1,0,0,0,180,44,1,0,0,0,
  	181,182,5,60,0,0,182,46,1,0,0,0,183,184,5,60,0,0,184,185,5,61,0,0,185,
  	48,1,0,0,0,186,187,5,61,0,0,187,190,5,61,0,0,188,190,5,61,0,0,189,186,
  	1,0,0,0,189,188,1,0,0,0,190,50,1,0,0,0,191,192,5,33,0,0,192,193,5,61,
  	0,0,193,52,1,0,0,0,194,195,5,62,0,0,195,196,5,61,0,0,196,54,1,0,0,0,197,
  	198,5,62,0,0,198,56,1,0,0,0,199,200,5,58,0,0,200,201,5,124,0,0,201,202,
  	5,58,0,0,202,58,1,0,0,0,203,207,7,0,0,0,204,206,7,1,0,0,205,204,1,0,0,
  	0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,60,1,0,0,0,209,
  	207,1,0,0,0,210,212,2,48,57,0,211,210,1,0,0,0,212,213,1,0,0,0,213,211,
  	1,0,0,0,213,214,1,0,0,0,214,62,1,0,0,0,215,217,7,2,0,0,216,215,1,0,0,
  	0,217,218,1,0,0,0,218,216,1,0,0,0,218,219,1,0,0,0,219,220,1,0,0,0,220,
  	221,6,31,0,0,221,64,1,0,0,0,222,226,5,35,0,0,223,225,9,0,0,0,224,223,
  	1,0,0,0,225,228,1,0,0,0,226,227,1,0,0,0,226,224,1,0,0,0,227,234,1,0,0,
  	0,228,226,1,0,0,0,229,231,5,13,0,0,230,229,1,0,0,0,230,231,1,0,0,0,231,
  	232,1,0,0,0,232,235,5,10,0,0,233,235,5,13,0,0,234,230,1,0,0,0,234,233,
  	1,0,0,0,235,236,1,0,0,0,236,237,6,32,0,0,237,66,1,0,0,0,12,0,75,150,173,
  	179,189,207,213,218,226,230,234,1,6,0,0
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
