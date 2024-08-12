
// Generated from CHC.g4 by ANTLR 4.11.1


#include "CHCListener.h"
#include "CHCVisitor.h"

#include "CHCParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CHCParserStaticData final {
  CHCParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CHCParserStaticData(const CHCParserStaticData&) = delete;
  CHCParserStaticData(CHCParserStaticData&&) = delete;
  CHCParserStaticData& operator=(const CHCParserStaticData&) = delete;
  CHCParserStaticData& operator=(CHCParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag chcParserOnceFlag;
CHCParserStaticData *chcParserStaticData = nullptr;

void chcParserInitialize() {
  assert(chcParserStaticData == nullptr);
  auto staticData = std::make_unique<CHCParserStaticData>(
    std::vector<std::string>{
      "main", "fun_decl", "chc_assert", "chc_assert_head", "chc_assert_body", 
      "chc_tail", "chc_head", "chc_query", "var_decl", "var_or_atom", "u_pred_atom", 
      "let", "lets", "formula_or_expr", "expr", "unaryop", "binaryop", "naryop", 
      "i_formula", "boolop", "lit", "relop", "symbol", "sort", "var"
    },
    std::vector<std::string>{
      "", "'set-logic HORN'", "'assert'", "'check-sat'", "'get-model'", 
      "'exit'", "'declare-fun'", "'Bool'", "'Int'", "'forall'", "'let'", 
      "'=>'", "'false'", "'true'", "'+'", "'-'", "'*'", "'mod'", "'div'", 
      "'('", "')'", "'and'", "'or'", "'not'", "'ite'", "'<'", "'<='", "'='", 
      "'!='", "'>='", "'>'"
    },
    std::vector<std::string>{
      "", "LOGIC", "ASSERT", "CHECK_SAT", "GET_MODEL", "EXIT", "DECLARE_FUN", 
      "BOOL_SORT", "INT_SORT", "FORALL", "LET", "IMPLIES", "FALSE", "TRUE", 
      "PLUS", "MINUS", "TIMES", "MOD", "DIV", "LPAR", "RPAR", "AND", "OR", 
      "NOT", "ITE", "LT", "LEQ", "EQ", "NEQ", "GEQ", "GT", "ID", "INT", 
      "WS", "COMMENT", "OTHER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,35,343,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,0,4,0,55,8,0,11,0,12,0,
  	56,1,0,1,0,1,0,1,0,1,0,5,0,64,8,0,10,0,12,0,67,9,0,1,0,1,0,1,0,1,0,1,
  	0,5,0,74,8,0,10,0,12,0,77,9,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,85,8,0,1,0,
  	1,0,1,0,3,0,90,8,0,1,1,1,1,1,1,1,1,1,1,5,1,97,8,1,10,1,12,1,100,9,1,1,
  	1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,4,3,114,8,3,11,3,12,3,115,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,127,8,4,1,5,1,5,1,5,4,5,132,8,
  	5,11,5,12,5,133,1,5,5,5,137,8,5,10,5,12,5,140,9,5,1,5,1,5,1,5,1,5,1,5,
  	3,5,147,8,5,1,6,1,6,1,7,1,7,1,7,1,7,4,7,155,8,7,11,7,12,7,156,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,3,9,174,8,9,1,10,
  	1,10,1,10,5,10,179,8,10,10,10,12,10,182,9,10,1,10,1,10,1,10,3,10,187,
  	8,10,1,11,1,11,1,11,1,11,1,11,3,11,194,8,11,1,11,1,11,1,12,1,12,1,12,
  	4,12,201,8,12,11,12,12,12,202,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,224,8,13,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	4,14,240,8,14,11,14,12,14,241,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,264,
  	8,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,4,18,281,8,18,11,18,12,18,282,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,3,18,306,8,18,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	331,8,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,0,0,25,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,
  	0,5,2,0,15,15,17,18,2,0,14,14,16,16,2,0,21,22,27,28,1,0,25,30,1,0,7,8,
  	361,0,50,1,0,0,0,2,91,1,0,0,0,4,105,1,0,0,0,6,110,1,0,0,0,8,126,1,0,0,
  	0,10,146,1,0,0,0,12,148,1,0,0,0,14,150,1,0,0,0,16,166,1,0,0,0,18,173,
  	1,0,0,0,20,186,1,0,0,0,22,188,1,0,0,0,24,197,1,0,0,0,26,223,1,0,0,0,28,
  	263,1,0,0,0,30,265,1,0,0,0,32,267,1,0,0,0,34,269,1,0,0,0,36,305,1,0,0,
  	0,38,307,1,0,0,0,40,309,1,0,0,0,42,334,1,0,0,0,44,336,1,0,0,0,46,338,
  	1,0,0,0,48,340,1,0,0,0,50,51,5,19,0,0,51,52,5,1,0,0,52,54,5,20,0,0,53,
  	55,3,2,1,0,54,53,1,0,0,0,55,56,1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,
  	65,1,0,0,0,58,59,5,19,0,0,59,60,5,2,0,0,60,61,3,4,2,0,61,62,5,20,0,0,
  	62,64,1,0,0,0,63,58,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,
  	66,75,1,0,0,0,67,65,1,0,0,0,68,69,5,19,0,0,69,70,5,2,0,0,70,71,3,14,7,
  	0,71,72,5,20,0,0,72,74,1,0,0,0,73,68,1,0,0,0,74,77,1,0,0,0,75,73,1,0,
  	0,0,75,76,1,0,0,0,76,78,1,0,0,0,77,75,1,0,0,0,78,79,5,19,0,0,79,80,5,
  	3,0,0,80,84,5,20,0,0,81,82,5,19,0,0,82,83,5,4,0,0,83,85,5,20,0,0,84,81,
  	1,0,0,0,84,85,1,0,0,0,85,89,1,0,0,0,86,87,5,19,0,0,87,88,5,5,0,0,88,90,
  	5,20,0,0,89,86,1,0,0,0,89,90,1,0,0,0,90,1,1,0,0,0,91,92,5,19,0,0,92,93,
  	5,6,0,0,93,94,3,44,22,0,94,98,5,19,0,0,95,97,3,46,23,0,96,95,1,0,0,0,
  	97,100,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,101,1,0,0,0,100,98,1,0,
  	0,0,101,102,5,20,0,0,102,103,5,7,0,0,103,104,5,20,0,0,104,3,1,0,0,0,105,
  	106,5,19,0,0,106,107,3,6,3,0,107,108,3,8,4,0,108,109,5,20,0,0,109,5,1,
  	0,0,0,110,111,5,9,0,0,111,113,5,19,0,0,112,114,3,16,8,0,113,112,1,0,0,
  	0,114,115,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,117,1,0,0,0,117,
  	118,5,20,0,0,118,7,1,0,0,0,119,120,5,19,0,0,120,121,5,11,0,0,121,122,
  	3,10,5,0,122,123,3,12,6,0,123,124,5,20,0,0,124,127,1,0,0,0,125,127,3,
  	12,6,0,126,119,1,0,0,0,126,125,1,0,0,0,127,9,1,0,0,0,128,129,5,19,0,0,
  	129,131,5,21,0,0,130,132,3,18,9,0,131,130,1,0,0,0,132,133,1,0,0,0,133,
  	131,1,0,0,0,133,134,1,0,0,0,134,138,1,0,0,0,135,137,3,36,18,0,136,135,
  	1,0,0,0,137,140,1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,0,139,141,1,0,0,
  	0,140,138,1,0,0,0,141,142,5,20,0,0,142,147,1,0,0,0,143,147,3,18,9,0,144,
  	147,3,36,18,0,145,147,3,20,10,0,146,128,1,0,0,0,146,143,1,0,0,0,146,144,
  	1,0,0,0,146,145,1,0,0,0,147,11,1,0,0,0,148,149,3,20,10,0,149,13,1,0,0,
  	0,150,151,5,19,0,0,151,152,5,9,0,0,152,154,5,19,0,0,153,155,3,16,8,0,
  	154,153,1,0,0,0,155,156,1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,158,
  	1,0,0,0,158,159,5,20,0,0,159,160,5,19,0,0,160,161,5,11,0,0,161,162,3,
  	10,5,0,162,163,5,12,0,0,163,164,5,20,0,0,164,165,5,20,0,0,165,15,1,0,
  	0,0,166,167,5,19,0,0,167,168,3,48,24,0,168,169,3,46,23,0,169,170,5,20,
  	0,0,170,17,1,0,0,0,171,174,3,48,24,0,172,174,3,20,10,0,173,171,1,0,0,
  	0,173,172,1,0,0,0,174,19,1,0,0,0,175,176,5,19,0,0,176,180,3,44,22,0,177,
  	179,3,48,24,0,178,177,1,0,0,0,179,182,1,0,0,0,180,178,1,0,0,0,180,181,
  	1,0,0,0,181,183,1,0,0,0,182,180,1,0,0,0,183,184,5,20,0,0,184,187,1,0,
  	0,0,185,187,3,44,22,0,186,175,1,0,0,0,186,185,1,0,0,0,187,21,1,0,0,0,
  	188,189,5,19,0,0,189,193,3,48,24,0,190,194,3,26,13,0,191,194,3,36,18,
  	0,192,194,3,28,14,0,193,190,1,0,0,0,193,191,1,0,0,0,193,192,1,0,0,0,194,
  	195,1,0,0,0,195,196,5,20,0,0,196,23,1,0,0,0,197,198,5,10,0,0,198,200,
  	5,19,0,0,199,201,3,22,11,0,200,199,1,0,0,0,201,202,1,0,0,0,202,200,1,
  	0,0,0,202,203,1,0,0,0,203,204,1,0,0,0,204,205,5,20,0,0,205,25,1,0,0,0,
  	206,224,3,48,24,0,207,208,5,19,0,0,208,209,3,26,13,0,209,210,5,20,0,0,
  	210,224,1,0,0,0,211,212,5,19,0,0,212,213,3,24,12,0,213,214,3,26,13,0,
  	214,215,5,20,0,0,215,224,1,0,0,0,216,217,5,19,0,0,217,218,5,24,0,0,218,
  	219,3,36,18,0,219,220,3,26,13,0,220,221,3,26,13,0,221,222,5,20,0,0,222,
  	224,1,0,0,0,223,206,1,0,0,0,223,207,1,0,0,0,223,211,1,0,0,0,223,216,1,
  	0,0,0,224,27,1,0,0,0,225,226,5,19,0,0,226,227,3,30,15,0,227,228,3,28,
  	14,0,228,229,5,20,0,0,229,264,1,0,0,0,230,231,5,19,0,0,231,232,3,32,16,
  	0,232,233,3,28,14,0,233,234,3,28,14,0,234,235,5,20,0,0,235,264,1,0,0,
  	0,236,237,5,19,0,0,237,239,3,34,17,0,238,240,3,28,14,0,239,238,1,0,0,
  	0,240,241,1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,243,1,0,0,0,243,
  	244,5,20,0,0,244,264,1,0,0,0,245,246,5,19,0,0,246,247,5,24,0,0,247,248,
  	3,36,18,0,248,249,3,28,14,0,249,250,3,28,14,0,250,251,5,20,0,0,251,264,
  	1,0,0,0,252,264,3,48,24,0,253,264,5,32,0,0,254,255,5,19,0,0,255,256,3,
  	28,14,0,256,257,5,20,0,0,257,264,1,0,0,0,258,259,5,19,0,0,259,260,3,24,
  	12,0,260,261,3,28,14,0,261,262,5,20,0,0,262,264,1,0,0,0,263,225,1,0,0,
  	0,263,230,1,0,0,0,263,236,1,0,0,0,263,245,1,0,0,0,263,252,1,0,0,0,263,
  	253,1,0,0,0,263,254,1,0,0,0,263,258,1,0,0,0,264,29,1,0,0,0,265,266,5,
  	15,0,0,266,31,1,0,0,0,267,268,7,0,0,0,268,33,1,0,0,0,269,270,7,1,0,0,
  	270,35,1,0,0,0,271,272,5,19,0,0,272,273,5,23,0,0,273,274,3,36,18,0,274,
  	275,5,20,0,0,275,306,1,0,0,0,276,306,3,40,20,0,277,278,5,19,0,0,278,280,
  	3,38,19,0,279,281,3,36,18,0,280,279,1,0,0,0,281,282,1,0,0,0,282,280,1,
  	0,0,0,282,283,1,0,0,0,283,284,1,0,0,0,284,285,5,20,0,0,285,306,1,0,0,
  	0,286,287,5,19,0,0,287,288,5,24,0,0,288,289,3,36,18,0,289,290,3,36,18,
  	0,290,291,3,36,18,0,291,292,5,20,0,0,292,306,1,0,0,0,293,294,5,19,0,0,
  	294,295,3,24,12,0,295,296,3,36,18,0,296,297,5,20,0,0,297,306,1,0,0,0,
  	298,299,5,19,0,0,299,300,3,36,18,0,300,301,5,20,0,0,301,306,1,0,0,0,302,
  	306,5,13,0,0,303,306,5,12,0,0,304,306,3,48,24,0,305,271,1,0,0,0,305,276,
  	1,0,0,0,305,277,1,0,0,0,305,286,1,0,0,0,305,293,1,0,0,0,305,298,1,0,0,
  	0,305,302,1,0,0,0,305,303,1,0,0,0,305,304,1,0,0,0,306,37,1,0,0,0,307,
  	308,7,2,0,0,308,39,1,0,0,0,309,330,5,19,0,0,310,311,5,27,0,0,311,312,
  	3,26,13,0,312,313,3,26,13,0,313,331,1,0,0,0,314,315,5,28,0,0,315,316,
  	3,26,13,0,316,317,3,26,13,0,317,331,1,0,0,0,318,319,5,27,0,0,319,320,
  	3,36,18,0,320,321,3,36,18,0,321,331,1,0,0,0,322,323,5,28,0,0,323,324,
  	3,36,18,0,324,325,3,36,18,0,325,331,1,0,0,0,326,327,3,42,21,0,327,328,
  	3,28,14,0,328,329,3,28,14,0,329,331,1,0,0,0,330,310,1,0,0,0,330,314,1,
  	0,0,0,330,318,1,0,0,0,330,322,1,0,0,0,330,326,1,0,0,0,331,332,1,0,0,0,
  	332,333,5,20,0,0,333,41,1,0,0,0,334,335,7,3,0,0,335,43,1,0,0,0,336,337,
  	5,31,0,0,337,45,1,0,0,0,338,339,7,4,0,0,339,47,1,0,0,0,340,341,5,31,0,
  	0,341,49,1,0,0,0,23,56,65,75,84,89,98,115,126,133,138,146,156,173,180,
  	186,193,202,223,241,263,282,305,330
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  chcParserStaticData = staticData.release();
}

}

CHCParser::CHCParser(TokenStream *input) : CHCParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CHCParser::CHCParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CHCParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *chcParserStaticData->atn, chcParserStaticData->decisionToDFA, chcParserStaticData->sharedContextCache, options);
}

CHCParser::~CHCParser() {
  delete _interpreter;
}

const atn::ATN& CHCParser::getATN() const {
  return *chcParserStaticData->atn;
}

std::string CHCParser::getGrammarFileName() const {
  return "CHC.g4";
}

const std::vector<std::string>& CHCParser::getRuleNames() const {
  return chcParserStaticData->ruleNames;
}

const dfa::Vocabulary& CHCParser::getVocabulary() const {
  return chcParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CHCParser::getSerializedATN() const {
  return chcParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

CHCParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CHCParser::MainContext::LPAR() {
  return getTokens(CHCParser::LPAR);
}

tree::TerminalNode* CHCParser::MainContext::LPAR(size_t i) {
  return getToken(CHCParser::LPAR, i);
}

tree::TerminalNode* CHCParser::MainContext::LOGIC() {
  return getToken(CHCParser::LOGIC, 0);
}

std::vector<tree::TerminalNode *> CHCParser::MainContext::RPAR() {
  return getTokens(CHCParser::RPAR);
}

tree::TerminalNode* CHCParser::MainContext::RPAR(size_t i) {
  return getToken(CHCParser::RPAR, i);
}

tree::TerminalNode* CHCParser::MainContext::CHECK_SAT() {
  return getToken(CHCParser::CHECK_SAT, 0);
}

std::vector<CHCParser::Fun_declContext *> CHCParser::MainContext::fun_decl() {
  return getRuleContexts<CHCParser::Fun_declContext>();
}

CHCParser::Fun_declContext* CHCParser::MainContext::fun_decl(size_t i) {
  return getRuleContext<CHCParser::Fun_declContext>(i);
}

std::vector<tree::TerminalNode *> CHCParser::MainContext::ASSERT() {
  return getTokens(CHCParser::ASSERT);
}

tree::TerminalNode* CHCParser::MainContext::ASSERT(size_t i) {
  return getToken(CHCParser::ASSERT, i);
}

std::vector<CHCParser::Chc_assertContext *> CHCParser::MainContext::chc_assert() {
  return getRuleContexts<CHCParser::Chc_assertContext>();
}

CHCParser::Chc_assertContext* CHCParser::MainContext::chc_assert(size_t i) {
  return getRuleContext<CHCParser::Chc_assertContext>(i);
}

std::vector<CHCParser::Chc_queryContext *> CHCParser::MainContext::chc_query() {
  return getRuleContexts<CHCParser::Chc_queryContext>();
}

CHCParser::Chc_queryContext* CHCParser::MainContext::chc_query(size_t i) {
  return getRuleContext<CHCParser::Chc_queryContext>(i);
}

tree::TerminalNode* CHCParser::MainContext::GET_MODEL() {
  return getToken(CHCParser::GET_MODEL, 0);
}

tree::TerminalNode* CHCParser::MainContext::EXIT() {
  return getToken(CHCParser::EXIT, 0);
}


size_t CHCParser::MainContext::getRuleIndex() const {
  return CHCParser::RuleMain;
}

void CHCParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void CHCParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any CHCParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::MainContext* CHCParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, CHCParser::RuleMain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(CHCParser::LPAR);
    setState(51);
    match(CHCParser::LOGIC);
    setState(52);
    match(CHCParser::RPAR);
    setState(54); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(53);
              fun_decl();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(56); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(65);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(58);
        match(CHCParser::LPAR);
        setState(59);
        match(CHCParser::ASSERT);
        setState(60);
        chc_assert();
        setState(61);
        match(CHCParser::RPAR); 
      }
      setState(67);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(75);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(68);
        match(CHCParser::LPAR);
        setState(69);
        match(CHCParser::ASSERT);
        setState(70);
        chc_query();
        setState(71);
        match(CHCParser::RPAR); 
      }
      setState(77);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(78);
    match(CHCParser::LPAR);
    setState(79);
    match(CHCParser::CHECK_SAT);
    setState(80);
    match(CHCParser::RPAR);
    setState(84);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(81);
      match(CHCParser::LPAR);
      setState(82);
      match(CHCParser::GET_MODEL);
      setState(83);
      match(CHCParser::RPAR);
      break;
    }

    default:
      break;
    }
    setState(89);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CHCParser::LPAR) {
      setState(86);
      match(CHCParser::LPAR);
      setState(87);
      match(CHCParser::EXIT);
      setState(88);
      match(CHCParser::RPAR);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_declContext ------------------------------------------------------------------

CHCParser::Fun_declContext::Fun_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CHCParser::Fun_declContext::LPAR() {
  return getTokens(CHCParser::LPAR);
}

tree::TerminalNode* CHCParser::Fun_declContext::LPAR(size_t i) {
  return getToken(CHCParser::LPAR, i);
}

tree::TerminalNode* CHCParser::Fun_declContext::DECLARE_FUN() {
  return getToken(CHCParser::DECLARE_FUN, 0);
}

CHCParser::SymbolContext* CHCParser::Fun_declContext::symbol() {
  return getRuleContext<CHCParser::SymbolContext>(0);
}

std::vector<tree::TerminalNode *> CHCParser::Fun_declContext::RPAR() {
  return getTokens(CHCParser::RPAR);
}

tree::TerminalNode* CHCParser::Fun_declContext::RPAR(size_t i) {
  return getToken(CHCParser::RPAR, i);
}

tree::TerminalNode* CHCParser::Fun_declContext::BOOL_SORT() {
  return getToken(CHCParser::BOOL_SORT, 0);
}

std::vector<CHCParser::SortContext *> CHCParser::Fun_declContext::sort() {
  return getRuleContexts<CHCParser::SortContext>();
}

CHCParser::SortContext* CHCParser::Fun_declContext::sort(size_t i) {
  return getRuleContext<CHCParser::SortContext>(i);
}


size_t CHCParser::Fun_declContext::getRuleIndex() const {
  return CHCParser::RuleFun_decl;
}

void CHCParser::Fun_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFun_decl(this);
}

void CHCParser::Fun_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFun_decl(this);
}


std::any CHCParser::Fun_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitFun_decl(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Fun_declContext* CHCParser::fun_decl() {
  Fun_declContext *_localctx = _tracker.createInstance<Fun_declContext>(_ctx, getState());
  enterRule(_localctx, 2, CHCParser::RuleFun_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(CHCParser::LPAR);
    setState(92);
    match(CHCParser::DECLARE_FUN);
    setState(93);
    symbol();
    setState(94);
    match(CHCParser::LPAR);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CHCParser::BOOL_SORT

    || _la == CHCParser::INT_SORT) {
      setState(95);
      sort();
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    match(CHCParser::RPAR);
    setState(102);
    match(CHCParser::BOOL_SORT);
    setState(103);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chc_assertContext ------------------------------------------------------------------

CHCParser::Chc_assertContext::Chc_assertContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::Chc_assertContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

CHCParser::Chc_assert_headContext* CHCParser::Chc_assertContext::chc_assert_head() {
  return getRuleContext<CHCParser::Chc_assert_headContext>(0);
}

CHCParser::Chc_assert_bodyContext* CHCParser::Chc_assertContext::chc_assert_body() {
  return getRuleContext<CHCParser::Chc_assert_bodyContext>(0);
}

tree::TerminalNode* CHCParser::Chc_assertContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}


size_t CHCParser::Chc_assertContext::getRuleIndex() const {
  return CHCParser::RuleChc_assert;
}

void CHCParser::Chc_assertContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChc_assert(this);
}

void CHCParser::Chc_assertContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChc_assert(this);
}


std::any CHCParser::Chc_assertContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_assert(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_assertContext* CHCParser::chc_assert() {
  Chc_assertContext *_localctx = _tracker.createInstance<Chc_assertContext>(_ctx, getState());
  enterRule(_localctx, 4, CHCParser::RuleChc_assert);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(CHCParser::LPAR);
    setState(106);
    chc_assert_head();
    setState(107);
    chc_assert_body();
    setState(108);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chc_assert_headContext ------------------------------------------------------------------

CHCParser::Chc_assert_headContext::Chc_assert_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::Chc_assert_headContext::FORALL() {
  return getToken(CHCParser::FORALL, 0);
}

tree::TerminalNode* CHCParser::Chc_assert_headContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

tree::TerminalNode* CHCParser::Chc_assert_headContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

std::vector<CHCParser::Var_declContext *> CHCParser::Chc_assert_headContext::var_decl() {
  return getRuleContexts<CHCParser::Var_declContext>();
}

CHCParser::Var_declContext* CHCParser::Chc_assert_headContext::var_decl(size_t i) {
  return getRuleContext<CHCParser::Var_declContext>(i);
}


size_t CHCParser::Chc_assert_headContext::getRuleIndex() const {
  return CHCParser::RuleChc_assert_head;
}

void CHCParser::Chc_assert_headContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChc_assert_head(this);
}

void CHCParser::Chc_assert_headContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChc_assert_head(this);
}


std::any CHCParser::Chc_assert_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_assert_head(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_assert_headContext* CHCParser::chc_assert_head() {
  Chc_assert_headContext *_localctx = _tracker.createInstance<Chc_assert_headContext>(_ctx, getState());
  enterRule(_localctx, 6, CHCParser::RuleChc_assert_head);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(CHCParser::FORALL);
    setState(111);
    match(CHCParser::LPAR);
    setState(113); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(112);
      var_decl();
      setState(115); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(117);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chc_assert_bodyContext ------------------------------------------------------------------

CHCParser::Chc_assert_bodyContext::Chc_assert_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::Chc_assert_bodyContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

tree::TerminalNode* CHCParser::Chc_assert_bodyContext::IMPLIES() {
  return getToken(CHCParser::IMPLIES, 0);
}

CHCParser::Chc_tailContext* CHCParser::Chc_assert_bodyContext::chc_tail() {
  return getRuleContext<CHCParser::Chc_tailContext>(0);
}

CHCParser::Chc_headContext* CHCParser::Chc_assert_bodyContext::chc_head() {
  return getRuleContext<CHCParser::Chc_headContext>(0);
}

tree::TerminalNode* CHCParser::Chc_assert_bodyContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}


size_t CHCParser::Chc_assert_bodyContext::getRuleIndex() const {
  return CHCParser::RuleChc_assert_body;
}

void CHCParser::Chc_assert_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChc_assert_body(this);
}

void CHCParser::Chc_assert_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChc_assert_body(this);
}


std::any CHCParser::Chc_assert_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_assert_body(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_assert_bodyContext* CHCParser::chc_assert_body() {
  Chc_assert_bodyContext *_localctx = _tracker.createInstance<Chc_assert_bodyContext>(_ctx, getState());
  enterRule(_localctx, 8, CHCParser::RuleChc_assert_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(119);
      match(CHCParser::LPAR);
      setState(120);
      match(CHCParser::IMPLIES);
      setState(121);
      chc_tail();
      setState(122);
      chc_head();
      setState(123);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(125);
      chc_head();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chc_tailContext ------------------------------------------------------------------

CHCParser::Chc_tailContext::Chc_tailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::Chc_tailContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

tree::TerminalNode* CHCParser::Chc_tailContext::AND() {
  return getToken(CHCParser::AND, 0);
}

tree::TerminalNode* CHCParser::Chc_tailContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

std::vector<CHCParser::Var_or_atomContext *> CHCParser::Chc_tailContext::var_or_atom() {
  return getRuleContexts<CHCParser::Var_or_atomContext>();
}

CHCParser::Var_or_atomContext* CHCParser::Chc_tailContext::var_or_atom(size_t i) {
  return getRuleContext<CHCParser::Var_or_atomContext>(i);
}

std::vector<CHCParser::I_formulaContext *> CHCParser::Chc_tailContext::i_formula() {
  return getRuleContexts<CHCParser::I_formulaContext>();
}

CHCParser::I_formulaContext* CHCParser::Chc_tailContext::i_formula(size_t i) {
  return getRuleContext<CHCParser::I_formulaContext>(i);
}

CHCParser::U_pred_atomContext* CHCParser::Chc_tailContext::u_pred_atom() {
  return getRuleContext<CHCParser::U_pred_atomContext>(0);
}


size_t CHCParser::Chc_tailContext::getRuleIndex() const {
  return CHCParser::RuleChc_tail;
}

void CHCParser::Chc_tailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChc_tail(this);
}

void CHCParser::Chc_tailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChc_tail(this);
}


std::any CHCParser::Chc_tailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_tail(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_tailContext* CHCParser::chc_tail() {
  Chc_tailContext *_localctx = _tracker.createInstance<Chc_tailContext>(_ctx, getState());
  enterRule(_localctx, 10, CHCParser::RuleChc_tail);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(128);
      match(CHCParser::LPAR);
      setState(129);
      match(CHCParser::AND);
      setState(131); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(130);
                var_or_atom();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(133); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2148020224) != 0) {
        setState(135);
        i_formula();
        setState(140);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(141);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(143);
      var_or_atom();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(144);
      i_formula();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(145);
      u_pred_atom();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chc_headContext ------------------------------------------------------------------

CHCParser::Chc_headContext::Chc_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CHCParser::U_pred_atomContext* CHCParser::Chc_headContext::u_pred_atom() {
  return getRuleContext<CHCParser::U_pred_atomContext>(0);
}


size_t CHCParser::Chc_headContext::getRuleIndex() const {
  return CHCParser::RuleChc_head;
}

void CHCParser::Chc_headContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChc_head(this);
}

void CHCParser::Chc_headContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChc_head(this);
}


std::any CHCParser::Chc_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_head(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_headContext* CHCParser::chc_head() {
  Chc_headContext *_localctx = _tracker.createInstance<Chc_headContext>(_ctx, getState());
  enterRule(_localctx, 12, CHCParser::RuleChc_head);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    u_pred_atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chc_queryContext ------------------------------------------------------------------

CHCParser::Chc_queryContext::Chc_queryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CHCParser::Chc_queryContext::LPAR() {
  return getTokens(CHCParser::LPAR);
}

tree::TerminalNode* CHCParser::Chc_queryContext::LPAR(size_t i) {
  return getToken(CHCParser::LPAR, i);
}

tree::TerminalNode* CHCParser::Chc_queryContext::FORALL() {
  return getToken(CHCParser::FORALL, 0);
}

std::vector<tree::TerminalNode *> CHCParser::Chc_queryContext::RPAR() {
  return getTokens(CHCParser::RPAR);
}

tree::TerminalNode* CHCParser::Chc_queryContext::RPAR(size_t i) {
  return getToken(CHCParser::RPAR, i);
}

tree::TerminalNode* CHCParser::Chc_queryContext::IMPLIES() {
  return getToken(CHCParser::IMPLIES, 0);
}

CHCParser::Chc_tailContext* CHCParser::Chc_queryContext::chc_tail() {
  return getRuleContext<CHCParser::Chc_tailContext>(0);
}

tree::TerminalNode* CHCParser::Chc_queryContext::FALSE() {
  return getToken(CHCParser::FALSE, 0);
}

std::vector<CHCParser::Var_declContext *> CHCParser::Chc_queryContext::var_decl() {
  return getRuleContexts<CHCParser::Var_declContext>();
}

CHCParser::Var_declContext* CHCParser::Chc_queryContext::var_decl(size_t i) {
  return getRuleContext<CHCParser::Var_declContext>(i);
}


size_t CHCParser::Chc_queryContext::getRuleIndex() const {
  return CHCParser::RuleChc_query;
}

void CHCParser::Chc_queryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChc_query(this);
}

void CHCParser::Chc_queryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChc_query(this);
}


std::any CHCParser::Chc_queryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_query(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_queryContext* CHCParser::chc_query() {
  Chc_queryContext *_localctx = _tracker.createInstance<Chc_queryContext>(_ctx, getState());
  enterRule(_localctx, 14, CHCParser::RuleChc_query);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(CHCParser::LPAR);
    setState(151);
    match(CHCParser::FORALL);
    setState(152);
    match(CHCParser::LPAR);
    setState(154); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(153);
      var_decl();
      setState(156); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(158);
    match(CHCParser::RPAR);
    setState(159);
    match(CHCParser::LPAR);
    setState(160);
    match(CHCParser::IMPLIES);
    setState(161);
    chc_tail();
    setState(162);
    match(CHCParser::FALSE);
    setState(163);
    match(CHCParser::RPAR);
    setState(164);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

CHCParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::Var_declContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

CHCParser::VarContext* CHCParser::Var_declContext::var() {
  return getRuleContext<CHCParser::VarContext>(0);
}

CHCParser::SortContext* CHCParser::Var_declContext::sort() {
  return getRuleContext<CHCParser::SortContext>(0);
}

tree::TerminalNode* CHCParser::Var_declContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}


size_t CHCParser::Var_declContext::getRuleIndex() const {
  return CHCParser::RuleVar_decl;
}

void CHCParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}

void CHCParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}


std::any CHCParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Var_declContext* CHCParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 16, CHCParser::RuleVar_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(CHCParser::LPAR);
    setState(167);
    var();
    setState(168);
    sort();
    setState(169);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_or_atomContext ------------------------------------------------------------------

CHCParser::Var_or_atomContext::Var_or_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CHCParser::VarContext* CHCParser::Var_or_atomContext::var() {
  return getRuleContext<CHCParser::VarContext>(0);
}

CHCParser::U_pred_atomContext* CHCParser::Var_or_atomContext::u_pred_atom() {
  return getRuleContext<CHCParser::U_pred_atomContext>(0);
}


size_t CHCParser::Var_or_atomContext::getRuleIndex() const {
  return CHCParser::RuleVar_or_atom;
}

void CHCParser::Var_or_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_or_atom(this);
}

void CHCParser::Var_or_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_or_atom(this);
}


std::any CHCParser::Var_or_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitVar_or_atom(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Var_or_atomContext* CHCParser::var_or_atom() {
  Var_or_atomContext *_localctx = _tracker.createInstance<Var_or_atomContext>(_ctx, getState());
  enterRule(_localctx, 18, CHCParser::RuleVar_or_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      var();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      u_pred_atom();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- U_pred_atomContext ------------------------------------------------------------------

CHCParser::U_pred_atomContext::U_pred_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::U_pred_atomContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

CHCParser::SymbolContext* CHCParser::U_pred_atomContext::symbol() {
  return getRuleContext<CHCParser::SymbolContext>(0);
}

tree::TerminalNode* CHCParser::U_pred_atomContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

std::vector<CHCParser::VarContext *> CHCParser::U_pred_atomContext::var() {
  return getRuleContexts<CHCParser::VarContext>();
}

CHCParser::VarContext* CHCParser::U_pred_atomContext::var(size_t i) {
  return getRuleContext<CHCParser::VarContext>(i);
}


size_t CHCParser::U_pred_atomContext::getRuleIndex() const {
  return CHCParser::RuleU_pred_atom;
}

void CHCParser::U_pred_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterU_pred_atom(this);
}

void CHCParser::U_pred_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitU_pred_atom(this);
}


std::any CHCParser::U_pred_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitU_pred_atom(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::U_pred_atomContext* CHCParser::u_pred_atom() {
  U_pred_atomContext *_localctx = _tracker.createInstance<U_pred_atomContext>(_ctx, getState());
  enterRule(_localctx, 20, CHCParser::RuleU_pred_atom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CHCParser::LPAR: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        match(CHCParser::LPAR);
        setState(176);
        symbol();
        setState(180);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CHCParser::ID) {
          setState(177);
          var();
          setState(182);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(183);
        match(CHCParser::RPAR);
        break;
      }

      case CHCParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(185);
        symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LetContext ------------------------------------------------------------------

CHCParser::LetContext::LetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::LetContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

CHCParser::VarContext* CHCParser::LetContext::var() {
  return getRuleContext<CHCParser::VarContext>(0);
}

tree::TerminalNode* CHCParser::LetContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

CHCParser::Formula_or_exprContext* CHCParser::LetContext::formula_or_expr() {
  return getRuleContext<CHCParser::Formula_or_exprContext>(0);
}

CHCParser::I_formulaContext* CHCParser::LetContext::i_formula() {
  return getRuleContext<CHCParser::I_formulaContext>(0);
}

CHCParser::ExprContext* CHCParser::LetContext::expr() {
  return getRuleContext<CHCParser::ExprContext>(0);
}


size_t CHCParser::LetContext::getRuleIndex() const {
  return CHCParser::RuleLet;
}

void CHCParser::LetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLet(this);
}

void CHCParser::LetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLet(this);
}


std::any CHCParser::LetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitLet(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::LetContext* CHCParser::let() {
  LetContext *_localctx = _tracker.createInstance<LetContext>(_ctx, getState());
  enterRule(_localctx, 22, CHCParser::RuleLet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(CHCParser::LPAR);
    setState(189);
    var();
    setState(193);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(190);
      formula_or_expr();
      break;
    }

    case 2: {
      setState(191);
      i_formula();
      break;
    }

    case 3: {
      setState(192);
      expr();
      break;
    }

    default:
      break;
    }
    setState(195);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LetsContext ------------------------------------------------------------------

CHCParser::LetsContext::LetsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::LetsContext::LET() {
  return getToken(CHCParser::LET, 0);
}

tree::TerminalNode* CHCParser::LetsContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

tree::TerminalNode* CHCParser::LetsContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

std::vector<CHCParser::LetContext *> CHCParser::LetsContext::let() {
  return getRuleContexts<CHCParser::LetContext>();
}

CHCParser::LetContext* CHCParser::LetsContext::let(size_t i) {
  return getRuleContext<CHCParser::LetContext>(i);
}


size_t CHCParser::LetsContext::getRuleIndex() const {
  return CHCParser::RuleLets;
}

void CHCParser::LetsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLets(this);
}

void CHCParser::LetsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLets(this);
}


std::any CHCParser::LetsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitLets(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::LetsContext* CHCParser::lets() {
  LetsContext *_localctx = _tracker.createInstance<LetsContext>(_ctx, getState());
  enterRule(_localctx, 24, CHCParser::RuleLets);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(CHCParser::LET);
    setState(198);
    match(CHCParser::LPAR);
    setState(200); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(199);
      let();
      setState(202); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(204);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Formula_or_exprContext ------------------------------------------------------------------

CHCParser::Formula_or_exprContext::Formula_or_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CHCParser::VarContext* CHCParser::Formula_or_exprContext::var() {
  return getRuleContext<CHCParser::VarContext>(0);
}

tree::TerminalNode* CHCParser::Formula_or_exprContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

std::vector<CHCParser::Formula_or_exprContext *> CHCParser::Formula_or_exprContext::formula_or_expr() {
  return getRuleContexts<CHCParser::Formula_or_exprContext>();
}

CHCParser::Formula_or_exprContext* CHCParser::Formula_or_exprContext::formula_or_expr(size_t i) {
  return getRuleContext<CHCParser::Formula_or_exprContext>(i);
}

tree::TerminalNode* CHCParser::Formula_or_exprContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

CHCParser::LetsContext* CHCParser::Formula_or_exprContext::lets() {
  return getRuleContext<CHCParser::LetsContext>(0);
}

tree::TerminalNode* CHCParser::Formula_or_exprContext::ITE() {
  return getToken(CHCParser::ITE, 0);
}

CHCParser::I_formulaContext* CHCParser::Formula_or_exprContext::i_formula() {
  return getRuleContext<CHCParser::I_formulaContext>(0);
}


size_t CHCParser::Formula_or_exprContext::getRuleIndex() const {
  return CHCParser::RuleFormula_or_expr;
}

void CHCParser::Formula_or_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula_or_expr(this);
}

void CHCParser::Formula_or_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula_or_expr(this);
}


std::any CHCParser::Formula_or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitFormula_or_expr(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Formula_or_exprContext* CHCParser::formula_or_expr() {
  Formula_or_exprContext *_localctx = _tracker.createInstance<Formula_or_exprContext>(_ctx, getState());
  enterRule(_localctx, 26, CHCParser::RuleFormula_or_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(206);
      var();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(207);
      match(CHCParser::LPAR);
      setState(208);
      formula_or_expr();
      setState(209);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(211);
      match(CHCParser::LPAR);
      setState(212);
      lets();
      setState(213);
      formula_or_expr();
      setState(214);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(216);
      match(CHCParser::LPAR);
      setState(217);
      match(CHCParser::ITE);
      setState(218);
      i_formula();
      setState(219);
      formula_or_expr();
      setState(220);
      formula_or_expr();
      setState(221);
      match(CHCParser::RPAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CHCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::ExprContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

CHCParser::UnaryopContext* CHCParser::ExprContext::unaryop() {
  return getRuleContext<CHCParser::UnaryopContext>(0);
}

std::vector<CHCParser::ExprContext *> CHCParser::ExprContext::expr() {
  return getRuleContexts<CHCParser::ExprContext>();
}

CHCParser::ExprContext* CHCParser::ExprContext::expr(size_t i) {
  return getRuleContext<CHCParser::ExprContext>(i);
}

tree::TerminalNode* CHCParser::ExprContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

CHCParser::BinaryopContext* CHCParser::ExprContext::binaryop() {
  return getRuleContext<CHCParser::BinaryopContext>(0);
}

CHCParser::NaryopContext* CHCParser::ExprContext::naryop() {
  return getRuleContext<CHCParser::NaryopContext>(0);
}

tree::TerminalNode* CHCParser::ExprContext::ITE() {
  return getToken(CHCParser::ITE, 0);
}

CHCParser::I_formulaContext* CHCParser::ExprContext::i_formula() {
  return getRuleContext<CHCParser::I_formulaContext>(0);
}

CHCParser::VarContext* CHCParser::ExprContext::var() {
  return getRuleContext<CHCParser::VarContext>(0);
}

tree::TerminalNode* CHCParser::ExprContext::INT() {
  return getToken(CHCParser::INT, 0);
}

CHCParser::LetsContext* CHCParser::ExprContext::lets() {
  return getRuleContext<CHCParser::LetsContext>(0);
}


size_t CHCParser::ExprContext::getRuleIndex() const {
  return CHCParser::RuleExpr;
}

void CHCParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void CHCParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any CHCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::ExprContext* CHCParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 28, CHCParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(263);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(225);
      match(CHCParser::LPAR);
      setState(226);
      unaryop();
      setState(227);
      expr();
      setState(228);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(230);
      match(CHCParser::LPAR);
      setState(231);
      binaryop();
      setState(232);
      expr();
      setState(233);
      expr();
      setState(234);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(236);
      match(CHCParser::LPAR);
      setState(237);
      naryop();
      setState(239); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(238);
        expr();
        setState(241); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 6442975232) != 0);
      setState(243);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(245);
      match(CHCParser::LPAR);
      setState(246);
      match(CHCParser::ITE);
      setState(247);
      i_formula();
      setState(248);
      expr();
      setState(249);
      expr();
      setState(250);
      match(CHCParser::RPAR);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(252);
      var();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(253);
      match(CHCParser::INT);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(254);
      match(CHCParser::LPAR);
      setState(255);
      expr();
      setState(256);
      match(CHCParser::RPAR);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(258);
      match(CHCParser::LPAR);
      setState(259);
      lets();
      setState(260);
      expr();
      setState(261);
      match(CHCParser::RPAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryopContext ------------------------------------------------------------------

CHCParser::UnaryopContext::UnaryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::UnaryopContext::MINUS() {
  return getToken(CHCParser::MINUS, 0);
}


size_t CHCParser::UnaryopContext::getRuleIndex() const {
  return CHCParser::RuleUnaryop;
}

void CHCParser::UnaryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryop(this);
}

void CHCParser::UnaryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryop(this);
}


std::any CHCParser::UnaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitUnaryop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::UnaryopContext* CHCParser::unaryop() {
  UnaryopContext *_localctx = _tracker.createInstance<UnaryopContext>(_ctx, getState());
  enterRule(_localctx, 30, CHCParser::RuleUnaryop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(CHCParser::MINUS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryopContext ------------------------------------------------------------------

CHCParser::BinaryopContext::BinaryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::BinaryopContext::MOD() {
  return getToken(CHCParser::MOD, 0);
}

tree::TerminalNode* CHCParser::BinaryopContext::DIV() {
  return getToken(CHCParser::DIV, 0);
}

tree::TerminalNode* CHCParser::BinaryopContext::MINUS() {
  return getToken(CHCParser::MINUS, 0);
}


size_t CHCParser::BinaryopContext::getRuleIndex() const {
  return CHCParser::RuleBinaryop;
}

void CHCParser::BinaryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryop(this);
}

void CHCParser::BinaryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryop(this);
}


std::any CHCParser::BinaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitBinaryop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::BinaryopContext* CHCParser::binaryop() {
  BinaryopContext *_localctx = _tracker.createInstance<BinaryopContext>(_ctx, getState());
  enterRule(_localctx, 32, CHCParser::RuleBinaryop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 425984) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NaryopContext ------------------------------------------------------------------

CHCParser::NaryopContext::NaryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::NaryopContext::TIMES() {
  return getToken(CHCParser::TIMES, 0);
}

tree::TerminalNode* CHCParser::NaryopContext::PLUS() {
  return getToken(CHCParser::PLUS, 0);
}


size_t CHCParser::NaryopContext::getRuleIndex() const {
  return CHCParser::RuleNaryop;
}

void CHCParser::NaryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNaryop(this);
}

void CHCParser::NaryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNaryop(this);
}


std::any CHCParser::NaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitNaryop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::NaryopContext* CHCParser::naryop() {
  NaryopContext *_localctx = _tracker.createInstance<NaryopContext>(_ctx, getState());
  enterRule(_localctx, 34, CHCParser::RuleNaryop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    _la = _input->LA(1);
    if (!(_la == CHCParser::PLUS

    || _la == CHCParser::TIMES)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- I_formulaContext ------------------------------------------------------------------

CHCParser::I_formulaContext::I_formulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::I_formulaContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

tree::TerminalNode* CHCParser::I_formulaContext::NOT() {
  return getToken(CHCParser::NOT, 0);
}

std::vector<CHCParser::I_formulaContext *> CHCParser::I_formulaContext::i_formula() {
  return getRuleContexts<CHCParser::I_formulaContext>();
}

CHCParser::I_formulaContext* CHCParser::I_formulaContext::i_formula(size_t i) {
  return getRuleContext<CHCParser::I_formulaContext>(i);
}

tree::TerminalNode* CHCParser::I_formulaContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

CHCParser::LitContext* CHCParser::I_formulaContext::lit() {
  return getRuleContext<CHCParser::LitContext>(0);
}

CHCParser::BoolopContext* CHCParser::I_formulaContext::boolop() {
  return getRuleContext<CHCParser::BoolopContext>(0);
}

tree::TerminalNode* CHCParser::I_formulaContext::ITE() {
  return getToken(CHCParser::ITE, 0);
}

CHCParser::LetsContext* CHCParser::I_formulaContext::lets() {
  return getRuleContext<CHCParser::LetsContext>(0);
}

tree::TerminalNode* CHCParser::I_formulaContext::TRUE() {
  return getToken(CHCParser::TRUE, 0);
}

tree::TerminalNode* CHCParser::I_formulaContext::FALSE() {
  return getToken(CHCParser::FALSE, 0);
}

CHCParser::VarContext* CHCParser::I_formulaContext::var() {
  return getRuleContext<CHCParser::VarContext>(0);
}


size_t CHCParser::I_formulaContext::getRuleIndex() const {
  return CHCParser::RuleI_formula;
}

void CHCParser::I_formulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterI_formula(this);
}

void CHCParser::I_formulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitI_formula(this);
}


std::any CHCParser::I_formulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitI_formula(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::I_formulaContext* CHCParser::i_formula() {
  I_formulaContext *_localctx = _tracker.createInstance<I_formulaContext>(_ctx, getState());
  enterRule(_localctx, 36, CHCParser::RuleI_formula);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(271);
      match(CHCParser::LPAR);
      setState(272);
      match(CHCParser::NOT);
      setState(273);
      i_formula();
      setState(274);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(276);
      lit();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(277);
      match(CHCParser::LPAR);
      setState(278);
      boolop();
      setState(280); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(279);
        i_formula();
        setState(282); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2148020224) != 0);
      setState(284);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(286);
      match(CHCParser::LPAR);
      setState(287);
      match(CHCParser::ITE);
      setState(288);
      i_formula();
      setState(289);
      i_formula();
      setState(290);
      i_formula();
      setState(291);
      match(CHCParser::RPAR);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(293);
      match(CHCParser::LPAR);
      setState(294);
      lets();
      setState(295);
      i_formula();
      setState(296);
      match(CHCParser::RPAR);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(298);
      match(CHCParser::LPAR);
      setState(299);
      i_formula();
      setState(300);
      match(CHCParser::RPAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(302);
      match(CHCParser::TRUE);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(303);
      match(CHCParser::FALSE);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(304);
      var();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolopContext ------------------------------------------------------------------

CHCParser::BoolopContext::BoolopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::BoolopContext::AND() {
  return getToken(CHCParser::AND, 0);
}

tree::TerminalNode* CHCParser::BoolopContext::OR() {
  return getToken(CHCParser::OR, 0);
}

tree::TerminalNode* CHCParser::BoolopContext::EQ() {
  return getToken(CHCParser::EQ, 0);
}

tree::TerminalNode* CHCParser::BoolopContext::NEQ() {
  return getToken(CHCParser::NEQ, 0);
}


size_t CHCParser::BoolopContext::getRuleIndex() const {
  return CHCParser::RuleBoolop;
}

void CHCParser::BoolopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolop(this);
}

void CHCParser::BoolopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolop(this);
}


std::any CHCParser::BoolopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitBoolop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::BoolopContext* CHCParser::boolop() {
  BoolopContext *_localctx = _tracker.createInstance<BoolopContext>(_ctx, getState());
  enterRule(_localctx, 38, CHCParser::RuleBoolop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 408944640) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LitContext ------------------------------------------------------------------

CHCParser::LitContext::LitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::LitContext::LPAR() {
  return getToken(CHCParser::LPAR, 0);
}

tree::TerminalNode* CHCParser::LitContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
}

tree::TerminalNode* CHCParser::LitContext::EQ() {
  return getToken(CHCParser::EQ, 0);
}

std::vector<CHCParser::Formula_or_exprContext *> CHCParser::LitContext::formula_or_expr() {
  return getRuleContexts<CHCParser::Formula_or_exprContext>();
}

CHCParser::Formula_or_exprContext* CHCParser::LitContext::formula_or_expr(size_t i) {
  return getRuleContext<CHCParser::Formula_or_exprContext>(i);
}

tree::TerminalNode* CHCParser::LitContext::NEQ() {
  return getToken(CHCParser::NEQ, 0);
}

std::vector<CHCParser::I_formulaContext *> CHCParser::LitContext::i_formula() {
  return getRuleContexts<CHCParser::I_formulaContext>();
}

CHCParser::I_formulaContext* CHCParser::LitContext::i_formula(size_t i) {
  return getRuleContext<CHCParser::I_formulaContext>(i);
}

CHCParser::RelopContext* CHCParser::LitContext::relop() {
  return getRuleContext<CHCParser::RelopContext>(0);
}

std::vector<CHCParser::ExprContext *> CHCParser::LitContext::expr() {
  return getRuleContexts<CHCParser::ExprContext>();
}

CHCParser::ExprContext* CHCParser::LitContext::expr(size_t i) {
  return getRuleContext<CHCParser::ExprContext>(i);
}


size_t CHCParser::LitContext::getRuleIndex() const {
  return CHCParser::RuleLit;
}

void CHCParser::LitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLit(this);
}

void CHCParser::LitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLit(this);
}


std::any CHCParser::LitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitLit(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::LitContext* CHCParser::lit() {
  LitContext *_localctx = _tracker.createInstance<LitContext>(_ctx, getState());
  enterRule(_localctx, 40, CHCParser::RuleLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(CHCParser::LPAR);
    setState(330);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(310);
      match(CHCParser::EQ);
      setState(311);
      formula_or_expr();
      setState(312);
      formula_or_expr();
      break;
    }

    case 2: {
      setState(314);
      match(CHCParser::NEQ);
      setState(315);
      formula_or_expr();
      setState(316);
      formula_or_expr();
      break;
    }

    case 3: {
      setState(318);
      match(CHCParser::EQ);
      setState(319);
      i_formula();
      setState(320);
      i_formula();
      break;
    }

    case 4: {
      setState(322);
      match(CHCParser::NEQ);
      setState(323);
      i_formula();
      setState(324);
      i_formula();
      break;
    }

    case 5: {
      setState(326);
      relop();
      setState(327);
      expr();
      setState(328);
      expr();
      break;
    }

    default:
      break;
    }
    setState(332);
    match(CHCParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

CHCParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::RelopContext::LT() {
  return getToken(CHCParser::LT, 0);
}

tree::TerminalNode* CHCParser::RelopContext::LEQ() {
  return getToken(CHCParser::LEQ, 0);
}

tree::TerminalNode* CHCParser::RelopContext::EQ() {
  return getToken(CHCParser::EQ, 0);
}

tree::TerminalNode* CHCParser::RelopContext::GT() {
  return getToken(CHCParser::GT, 0);
}

tree::TerminalNode* CHCParser::RelopContext::GEQ() {
  return getToken(CHCParser::GEQ, 0);
}

tree::TerminalNode* CHCParser::RelopContext::NEQ() {
  return getToken(CHCParser::NEQ, 0);
}


size_t CHCParser::RelopContext::getRuleIndex() const {
  return CHCParser::RuleRelop;
}

void CHCParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void CHCParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}


std::any CHCParser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::RelopContext* CHCParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 42, CHCParser::RuleRelop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(334);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2113929216) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolContext ------------------------------------------------------------------

CHCParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::SymbolContext::ID() {
  return getToken(CHCParser::ID, 0);
}


size_t CHCParser::SymbolContext::getRuleIndex() const {
  return CHCParser::RuleSymbol;
}

void CHCParser::SymbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbol(this);
}

void CHCParser::SymbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbol(this);
}


std::any CHCParser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::SymbolContext* CHCParser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 44, CHCParser::RuleSymbol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(CHCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortContext ------------------------------------------------------------------

CHCParser::SortContext::SortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::SortContext::INT_SORT() {
  return getToken(CHCParser::INT_SORT, 0);
}

tree::TerminalNode* CHCParser::SortContext::BOOL_SORT() {
  return getToken(CHCParser::BOOL_SORT, 0);
}


size_t CHCParser::SortContext::getRuleIndex() const {
  return CHCParser::RuleSort;
}

void CHCParser::SortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSort(this);
}

void CHCParser::SortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSort(this);
}


std::any CHCParser::SortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitSort(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::SortContext* CHCParser::sort() {
  SortContext *_localctx = _tracker.createInstance<SortContext>(_ctx, getState());
  enterRule(_localctx, 46, CHCParser::RuleSort);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    _la = _input->LA(1);
    if (!(_la == CHCParser::BOOL_SORT

    || _la == CHCParser::INT_SORT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

CHCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CHCParser::VarContext::ID() {
  return getToken(CHCParser::ID, 0);
}


size_t CHCParser::VarContext::getRuleIndex() const {
  return CHCParser::RuleVar;
}

void CHCParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void CHCParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CHCListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any CHCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::VarContext* CHCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 48, CHCParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    match(CHCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CHCParser::initialize() {
  ::antlr4::internal::call_once(chcParserOnceFlag, chcParserInitialize);
}
