
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
  	4,1,34,330,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,1,0,4,0,55,8,0,11,0,12,0,
  	56,1,0,1,0,1,0,1,0,1,0,5,0,64,8,0,10,0,12,0,67,9,0,1,0,1,0,1,0,1,0,1,
  	0,5,0,74,8,0,10,0,12,0,77,9,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,85,8,0,1,1,
  	1,1,1,1,1,1,1,1,5,1,92,8,1,10,1,12,1,95,9,1,1,1,1,1,1,1,1,1,1,2,1,2,1,
  	2,1,2,1,2,1,3,1,3,1,3,4,3,109,8,3,11,3,12,3,110,1,3,1,3,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,3,4,122,8,4,1,5,1,5,1,5,4,5,127,8,5,11,5,12,5,128,1,5,5,
  	5,132,8,5,10,5,12,5,135,9,5,1,5,1,5,1,5,1,5,1,5,3,5,142,8,5,1,6,1,6,1,
  	7,1,7,1,7,1,7,4,7,150,8,7,11,7,12,7,151,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,3,9,169,8,9,1,10,1,10,1,10,5,10,174,8,10,
  	10,10,12,10,177,9,10,1,10,1,10,1,10,3,10,182,8,10,1,11,1,11,1,11,1,11,
  	1,11,3,11,189,8,11,1,11,1,11,1,12,1,12,1,12,4,12,196,8,12,11,12,12,12,
  	197,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,3,13,219,8,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,4,14,235,8,14,11,14,12,14,
  	236,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,259,8,14,1,15,1,15,1,16,1,16,
  	1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,4,18,276,8,18,
  	11,18,12,18,277,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,301,8,18,1,19,
  	1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	3,20,318,8,20,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,
  	0,0,25,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,0,5,2,0,14,14,16,17,2,0,13,13,15,15,2,0,20,21,26,27,1,0,24,29,1,
  	0,6,7,345,0,50,1,0,0,0,2,86,1,0,0,0,4,100,1,0,0,0,6,105,1,0,0,0,8,121,
  	1,0,0,0,10,141,1,0,0,0,12,143,1,0,0,0,14,145,1,0,0,0,16,161,1,0,0,0,18,
  	168,1,0,0,0,20,181,1,0,0,0,22,183,1,0,0,0,24,192,1,0,0,0,26,218,1,0,0,
  	0,28,258,1,0,0,0,30,260,1,0,0,0,32,262,1,0,0,0,34,264,1,0,0,0,36,300,
  	1,0,0,0,38,302,1,0,0,0,40,304,1,0,0,0,42,321,1,0,0,0,44,323,1,0,0,0,46,
  	325,1,0,0,0,48,327,1,0,0,0,50,51,5,18,0,0,51,52,5,1,0,0,52,54,5,19,0,
  	0,53,55,3,2,1,0,54,53,1,0,0,0,55,56,1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,
  	0,57,65,1,0,0,0,58,59,5,18,0,0,59,60,5,2,0,0,60,61,3,4,2,0,61,62,5,19,
  	0,0,62,64,1,0,0,0,63,58,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,
  	0,0,66,75,1,0,0,0,67,65,1,0,0,0,68,69,5,18,0,0,69,70,5,2,0,0,70,71,3,
  	14,7,0,71,72,5,19,0,0,72,74,1,0,0,0,73,68,1,0,0,0,74,77,1,0,0,0,75,73,
  	1,0,0,0,75,76,1,0,0,0,76,78,1,0,0,0,77,75,1,0,0,0,78,79,5,18,0,0,79,80,
  	5,3,0,0,80,84,5,19,0,0,81,82,5,18,0,0,82,83,5,4,0,0,83,85,5,19,0,0,84,
  	81,1,0,0,0,84,85,1,0,0,0,85,1,1,0,0,0,86,87,5,18,0,0,87,88,5,5,0,0,88,
  	89,3,44,22,0,89,93,5,18,0,0,90,92,3,46,23,0,91,90,1,0,0,0,92,95,1,0,0,
  	0,93,91,1,0,0,0,93,94,1,0,0,0,94,96,1,0,0,0,95,93,1,0,0,0,96,97,5,19,
  	0,0,97,98,5,6,0,0,98,99,5,19,0,0,99,3,1,0,0,0,100,101,5,18,0,0,101,102,
  	3,6,3,0,102,103,3,8,4,0,103,104,5,19,0,0,104,5,1,0,0,0,105,106,5,8,0,
  	0,106,108,5,18,0,0,107,109,3,16,8,0,108,107,1,0,0,0,109,110,1,0,0,0,110,
  	108,1,0,0,0,110,111,1,0,0,0,111,112,1,0,0,0,112,113,5,19,0,0,113,7,1,
  	0,0,0,114,115,5,18,0,0,115,116,5,10,0,0,116,117,3,10,5,0,117,118,3,12,
  	6,0,118,119,5,19,0,0,119,122,1,0,0,0,120,122,3,12,6,0,121,114,1,0,0,0,
  	121,120,1,0,0,0,122,9,1,0,0,0,123,124,5,18,0,0,124,126,5,20,0,0,125,127,
  	3,18,9,0,126,125,1,0,0,0,127,128,1,0,0,0,128,126,1,0,0,0,128,129,1,0,
  	0,0,129,133,1,0,0,0,130,132,3,36,18,0,131,130,1,0,0,0,132,135,1,0,0,0,
  	133,131,1,0,0,0,133,134,1,0,0,0,134,136,1,0,0,0,135,133,1,0,0,0,136,137,
  	5,19,0,0,137,142,1,0,0,0,138,142,3,18,9,0,139,142,3,36,18,0,140,142,3,
  	20,10,0,141,123,1,0,0,0,141,138,1,0,0,0,141,139,1,0,0,0,141,140,1,0,0,
  	0,142,11,1,0,0,0,143,144,3,20,10,0,144,13,1,0,0,0,145,146,5,18,0,0,146,
  	147,5,8,0,0,147,149,5,18,0,0,148,150,3,16,8,0,149,148,1,0,0,0,150,151,
  	1,0,0,0,151,149,1,0,0,0,151,152,1,0,0,0,152,153,1,0,0,0,153,154,5,19,
  	0,0,154,155,5,18,0,0,155,156,5,10,0,0,156,157,3,10,5,0,157,158,5,11,0,
  	0,158,159,5,19,0,0,159,160,5,19,0,0,160,15,1,0,0,0,161,162,5,18,0,0,162,
  	163,3,48,24,0,163,164,3,46,23,0,164,165,5,19,0,0,165,17,1,0,0,0,166,169,
  	3,48,24,0,167,169,3,20,10,0,168,166,1,0,0,0,168,167,1,0,0,0,169,19,1,
  	0,0,0,170,171,5,18,0,0,171,175,3,44,22,0,172,174,3,48,24,0,173,172,1,
  	0,0,0,174,177,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,178,1,0,0,0,
  	177,175,1,0,0,0,178,179,5,19,0,0,179,182,1,0,0,0,180,182,3,44,22,0,181,
  	170,1,0,0,0,181,180,1,0,0,0,182,21,1,0,0,0,183,184,5,18,0,0,184,188,3,
  	48,24,0,185,189,3,26,13,0,186,189,3,36,18,0,187,189,3,28,14,0,188,185,
  	1,0,0,0,188,186,1,0,0,0,188,187,1,0,0,0,189,190,1,0,0,0,190,191,5,19,
  	0,0,191,23,1,0,0,0,192,193,5,9,0,0,193,195,5,18,0,0,194,196,3,22,11,0,
  	195,194,1,0,0,0,196,197,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,199,
  	1,0,0,0,199,200,5,19,0,0,200,25,1,0,0,0,201,219,3,48,24,0,202,203,5,18,
  	0,0,203,204,3,26,13,0,204,205,5,19,0,0,205,219,1,0,0,0,206,207,5,18,0,
  	0,207,208,3,24,12,0,208,209,3,26,13,0,209,210,5,19,0,0,210,219,1,0,0,
  	0,211,212,5,18,0,0,212,213,5,23,0,0,213,214,3,36,18,0,214,215,3,26,13,
  	0,215,216,3,26,13,0,216,217,5,19,0,0,217,219,1,0,0,0,218,201,1,0,0,0,
  	218,202,1,0,0,0,218,206,1,0,0,0,218,211,1,0,0,0,219,27,1,0,0,0,220,221,
  	5,18,0,0,221,222,3,30,15,0,222,223,3,28,14,0,223,224,5,19,0,0,224,259,
  	1,0,0,0,225,226,5,18,0,0,226,227,3,32,16,0,227,228,3,28,14,0,228,229,
  	3,28,14,0,229,230,5,19,0,0,230,259,1,0,0,0,231,232,5,18,0,0,232,234,3,
  	34,17,0,233,235,3,28,14,0,234,233,1,0,0,0,235,236,1,0,0,0,236,234,1,0,
  	0,0,236,237,1,0,0,0,237,238,1,0,0,0,238,239,5,19,0,0,239,259,1,0,0,0,
  	240,241,5,18,0,0,241,242,5,23,0,0,242,243,3,36,18,0,243,244,3,28,14,0,
  	244,245,3,28,14,0,245,246,5,19,0,0,246,259,1,0,0,0,247,259,3,48,24,0,
  	248,259,5,31,0,0,249,250,5,18,0,0,250,251,3,28,14,0,251,252,5,19,0,0,
  	252,259,1,0,0,0,253,254,5,18,0,0,254,255,3,24,12,0,255,256,3,28,14,0,
  	256,257,5,19,0,0,257,259,1,0,0,0,258,220,1,0,0,0,258,225,1,0,0,0,258,
  	231,1,0,0,0,258,240,1,0,0,0,258,247,1,0,0,0,258,248,1,0,0,0,258,249,1,
  	0,0,0,258,253,1,0,0,0,259,29,1,0,0,0,260,261,5,14,0,0,261,31,1,0,0,0,
  	262,263,7,0,0,0,263,33,1,0,0,0,264,265,7,1,0,0,265,35,1,0,0,0,266,267,
  	5,18,0,0,267,268,5,22,0,0,268,269,3,36,18,0,269,270,5,19,0,0,270,301,
  	1,0,0,0,271,301,3,40,20,0,272,273,5,18,0,0,273,275,3,38,19,0,274,276,
  	3,36,18,0,275,274,1,0,0,0,276,277,1,0,0,0,277,275,1,0,0,0,277,278,1,0,
  	0,0,278,279,1,0,0,0,279,280,5,19,0,0,280,301,1,0,0,0,281,282,5,18,0,0,
  	282,283,5,23,0,0,283,284,3,36,18,0,284,285,3,36,18,0,285,286,3,36,18,
  	0,286,287,5,19,0,0,287,301,1,0,0,0,288,289,5,18,0,0,289,290,3,24,12,0,
  	290,291,3,36,18,0,291,292,5,19,0,0,292,301,1,0,0,0,293,294,5,18,0,0,294,
  	295,3,36,18,0,295,296,5,19,0,0,296,301,1,0,0,0,297,301,5,12,0,0,298,301,
  	5,11,0,0,299,301,3,48,24,0,300,266,1,0,0,0,300,271,1,0,0,0,300,272,1,
  	0,0,0,300,281,1,0,0,0,300,288,1,0,0,0,300,293,1,0,0,0,300,297,1,0,0,0,
  	300,298,1,0,0,0,300,299,1,0,0,0,301,37,1,0,0,0,302,303,7,2,0,0,303,39,
  	1,0,0,0,304,317,5,18,0,0,305,306,5,26,0,0,306,307,3,48,24,0,307,308,3,
  	48,24,0,308,318,1,0,0,0,309,310,5,27,0,0,310,311,3,48,24,0,311,312,3,
  	48,24,0,312,318,1,0,0,0,313,314,3,42,21,0,314,315,3,28,14,0,315,316,3,
  	28,14,0,316,318,1,0,0,0,317,305,1,0,0,0,317,309,1,0,0,0,317,313,1,0,0,
  	0,318,319,1,0,0,0,319,320,5,19,0,0,320,41,1,0,0,0,321,322,7,3,0,0,322,
  	43,1,0,0,0,323,324,5,30,0,0,324,45,1,0,0,0,325,326,7,4,0,0,326,47,1,0,
  	0,0,327,328,5,30,0,0,328,49,1,0,0,0,22,56,65,75,84,93,110,121,128,133,
  	141,151,168,175,181,188,197,218,236,258,277,300,317
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

    _la = _input->LA(1);
    if (_la == CHCParser::LPAR) {
      setState(81);
      match(CHCParser::LPAR);
      setState(82);
      match(CHCParser::EXIT);
      setState(83);
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
    setState(86);
    match(CHCParser::LPAR);
    setState(87);
    match(CHCParser::DECLARE_FUN);
    setState(88);
    symbol();
    setState(89);
    match(CHCParser::LPAR);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CHCParser::BOOL_SORT

    || _la == CHCParser::INT_SORT) {
      setState(90);
      sort();
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(96);
    match(CHCParser::RPAR);
    setState(97);
    match(CHCParser::BOOL_SORT);
    setState(98);
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
    setState(100);
    match(CHCParser::LPAR);
    setState(101);
    chc_assert_head();
    setState(102);
    chc_assert_body();
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
    setState(105);
    match(CHCParser::FORALL);
    setState(106);
    match(CHCParser::LPAR);
    setState(108); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(107);
      var_decl();
      setState(110); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(112);
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
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(114);
      match(CHCParser::LPAR);
      setState(115);
      match(CHCParser::IMPLIES);
      setState(116);
      chc_tail();
      setState(117);
      chc_head();
      setState(118);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
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
    setState(141);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(123);
      match(CHCParser::LPAR);
      setState(124);
      match(CHCParser::AND);
      setState(126); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(125);
                var_or_atom();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(128); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(133);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1074010112) != 0) {
        setState(130);
        i_formula();
        setState(135);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(136);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(138);
      var_or_atom();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(139);
      i_formula();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(140);
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
    setState(143);
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
    setState(145);
    match(CHCParser::LPAR);
    setState(146);
    match(CHCParser::FORALL);
    setState(147);
    match(CHCParser::LPAR);
    setState(149); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(148);
      var_decl();
      setState(151); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(153);
    match(CHCParser::RPAR);
    setState(154);
    match(CHCParser::LPAR);
    setState(155);
    match(CHCParser::IMPLIES);
    setState(156);
    chc_tail();
    setState(157);
    match(CHCParser::FALSE);
    setState(158);
    match(CHCParser::RPAR);
    setState(159);
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
    setState(161);
    match(CHCParser::LPAR);
    setState(162);
    var();
    setState(163);
    sort();
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
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      var();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
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
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CHCParser::LPAR: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        match(CHCParser::LPAR);
        setState(171);
        symbol();
        setState(175);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CHCParser::ID) {
          setState(172);
          var();
          setState(177);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(178);
        match(CHCParser::RPAR);
        break;
      }

      case CHCParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(180);
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
    setState(183);
    match(CHCParser::LPAR);
    setState(184);
    var();
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(185);
      formula_or_expr();
      break;
    }

    case 2: {
      setState(186);
      i_formula();
      break;
    }

    case 3: {
      setState(187);
      expr();
      break;
    }

    default:
      break;
    }
    setState(190);
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
    setState(192);
    match(CHCParser::LET);
    setState(193);
    match(CHCParser::LPAR);
    setState(195); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(194);
      let();
      setState(197); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(199);
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
    setState(218);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(201);
      var();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(202);
      match(CHCParser::LPAR);
      setState(203);
      formula_or_expr();
      setState(204);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(206);
      match(CHCParser::LPAR);
      setState(207);
      lets();
      setState(208);
      formula_or_expr();
      setState(209);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(211);
      match(CHCParser::LPAR);
      setState(212);
      match(CHCParser::ITE);
      setState(213);
      i_formula();
      setState(214);
      formula_or_expr();
      setState(215);
      formula_or_expr();
      setState(216);
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
    setState(258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(220);
      match(CHCParser::LPAR);
      setState(221);
      unaryop();
      setState(222);
      expr();
      setState(223);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(225);
      match(CHCParser::LPAR);
      setState(226);
      binaryop();
      setState(227);
      expr();
      setState(228);
      expr();
      setState(229);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(231);
      match(CHCParser::LPAR);
      setState(232);
      naryop();
      setState(234); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(233);
        expr();
        setState(236); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3221487616) != 0);
      setState(238);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(240);
      match(CHCParser::LPAR);
      setState(241);
      match(CHCParser::ITE);
      setState(242);
      i_formula();
      setState(243);
      expr();
      setState(244);
      expr();
      setState(245);
      match(CHCParser::RPAR);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(247);
      var();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(248);
      match(CHCParser::INT);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(249);
      match(CHCParser::LPAR);
      setState(250);
      expr();
      setState(251);
      match(CHCParser::RPAR);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(253);
      match(CHCParser::LPAR);
      setState(254);
      lets();
      setState(255);
      expr();
      setState(256);
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
    setState(260);
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
    setState(262);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 212992) != 0)) {
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
    setState(264);
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
    setState(300);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(266);
      match(CHCParser::LPAR);
      setState(267);
      match(CHCParser::NOT);
      setState(268);
      i_formula();
      setState(269);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(271);
      lit();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(272);
      match(CHCParser::LPAR);
      setState(273);
      boolop();
      setState(275); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(274);
        i_formula();
        setState(277); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1074010112) != 0);
      setState(279);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(281);
      match(CHCParser::LPAR);
      setState(282);
      match(CHCParser::ITE);
      setState(283);
      i_formula();
      setState(284);
      i_formula();
      setState(285);
      i_formula();
      setState(286);
      match(CHCParser::RPAR);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(288);
      match(CHCParser::LPAR);
      setState(289);
      lets();
      setState(290);
      i_formula();
      setState(291);
      match(CHCParser::RPAR);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(293);
      match(CHCParser::LPAR);
      setState(294);
      i_formula();
      setState(295);
      match(CHCParser::RPAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(297);
      match(CHCParser::TRUE);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(298);
      match(CHCParser::FALSE);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(299);
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
    setState(302);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 204472320) != 0)) {
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

std::vector<CHCParser::VarContext *> CHCParser::LitContext::var() {
  return getRuleContexts<CHCParser::VarContext>();
}

CHCParser::VarContext* CHCParser::LitContext::var(size_t i) {
  return getRuleContext<CHCParser::VarContext>(i);
}

tree::TerminalNode* CHCParser::LitContext::NEQ() {
  return getToken(CHCParser::NEQ, 0);
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
    setState(304);
    match(CHCParser::LPAR);
    setState(317);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(305);
      match(CHCParser::EQ);
      setState(306);
      var();
      setState(307);
      var();
      break;
    }

    case 2: {
      setState(309);
      match(CHCParser::NEQ);
      setState(310);
      var();
      setState(311);
      var();
      break;
    }

    case 3: {
      setState(313);
      relop();
      setState(314);
      expr();
      setState(315);
      expr();
      break;
    }

    default:
      break;
    }
    setState(319);
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
    setState(321);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056964608) != 0)) {
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
    setState(323);
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
    setState(325);
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
    setState(327);
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
