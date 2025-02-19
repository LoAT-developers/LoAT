
// Generated from Koat.g4 by ANTLR 4.11.1


#include "KoatListener.h"
#include "KoatVisitor.h"

#include "KoatParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct KoatParserStaticData final {
  KoatParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  KoatParserStaticData(const KoatParserStaticData&) = delete;
  KoatParserStaticData(KoatParserStaticData&&) = delete;
  KoatParserStaticData& operator=(const KoatParserStaticData&) = delete;
  KoatParserStaticData& operator=(KoatParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag koatParserOnceFlag;
KoatParserStaticData *koatParserStaticData = nullptr;

void koatParserInitialize() {
  assert(koatParserStaticData == nullptr);
  auto staticData = std::make_unique<KoatParserStaticData>(
    std::vector<std::string>{
      "main", "fs", "var", "goal", "start", "sink", "vardecl", "transs", 
      "trans", "lhs", "com", "rhs", "to", "lb", "ub", "cond", "expr", "formula", 
      "lit", "relop"
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
  	4,1,34,227,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,3,0,42,8,0,1,
  	0,1,0,3,0,46,8,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,
  	6,4,6,79,8,6,11,6,12,6,80,1,6,1,6,1,7,1,7,1,7,5,7,88,8,7,10,7,12,7,91,
  	9,7,1,7,1,7,1,8,1,8,1,8,1,8,3,8,99,8,8,1,9,1,9,1,9,1,9,1,9,5,9,106,8,
  	9,10,9,12,9,109,9,9,3,9,111,8,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,5,10,
  	120,8,10,10,10,12,10,123,9,10,3,10,125,8,10,1,10,1,10,3,10,129,8,10,1,
  	11,1,11,1,11,1,11,1,11,5,11,136,8,11,10,11,12,11,139,9,11,3,11,141,8,
  	11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,3,12,160,8,12,1,13,1,13,1,14,1,14,1,15,1,15,1,15,1,
  	15,1,15,1,15,3,15,172,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,3,16,183,8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,5,16,197,8,16,10,16,12,16,200,9,16,1,17,1,17,1,17,1,17,1,17,1,
  	17,3,17,208,8,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,216,8,17,10,17,12,
  	17,219,9,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,0,2,32,34,20,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,2,1,0,3,4,1,0,24,29,231,
  	0,41,1,0,0,0,2,50,1,0,0,0,4,52,1,0,0,0,6,54,1,0,0,0,8,59,1,0,0,0,10,67,
  	1,0,0,0,12,75,1,0,0,0,14,84,1,0,0,0,16,94,1,0,0,0,18,100,1,0,0,0,20,128,
  	1,0,0,0,22,130,1,0,0,0,24,159,1,0,0,0,26,161,1,0,0,0,28,163,1,0,0,0,30,
  	171,1,0,0,0,32,182,1,0,0,0,34,207,1,0,0,0,36,220,1,0,0,0,38,224,1,0,0,
  	0,40,42,3,6,3,0,41,40,1,0,0,0,41,42,1,0,0,0,42,43,1,0,0,0,43,45,3,8,4,
  	0,44,46,3,10,5,0,45,44,1,0,0,0,45,46,1,0,0,0,46,47,1,0,0,0,47,48,3,12,
  	6,0,48,49,3,14,7,0,49,1,1,0,0,0,50,51,5,31,0,0,51,3,1,0,0,0,52,53,5,31,
  	0,0,53,5,1,0,0,0,54,55,5,14,0,0,55,56,5,2,0,0,56,57,7,0,0,0,57,58,5,15,
  	0,0,58,7,1,0,0,0,59,60,5,14,0,0,60,61,5,5,0,0,61,62,5,14,0,0,62,63,5,
  	7,0,0,63,64,3,2,1,0,64,65,5,15,0,0,65,66,5,15,0,0,66,9,1,0,0,0,67,68,
  	5,14,0,0,68,69,5,6,0,0,69,70,5,14,0,0,70,71,5,7,0,0,71,72,3,2,1,0,72,
  	73,5,15,0,0,73,74,5,15,0,0,74,11,1,0,0,0,75,76,5,14,0,0,76,78,5,8,0,0,
  	77,79,5,31,0,0,78,77,1,0,0,0,79,80,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,
  	0,81,82,1,0,0,0,82,83,5,15,0,0,83,13,1,0,0,0,84,85,5,14,0,0,85,89,5,9,
  	0,0,86,88,3,16,8,0,87,86,1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,90,1,
  	0,0,0,90,92,1,0,0,0,91,89,1,0,0,0,92,93,5,15,0,0,93,15,1,0,0,0,94,95,
  	3,18,9,0,95,96,3,24,12,0,96,98,3,20,10,0,97,99,3,30,15,0,98,97,1,0,0,
  	0,98,99,1,0,0,0,99,17,1,0,0,0,100,101,3,2,1,0,101,110,5,14,0,0,102,107,
  	3,4,2,0,103,104,5,21,0,0,104,106,3,4,2,0,105,103,1,0,0,0,106,109,1,0,
  	0,0,107,105,1,0,0,0,107,108,1,0,0,0,108,111,1,0,0,0,109,107,1,0,0,0,110,
  	102,1,0,0,0,110,111,1,0,0,0,111,112,1,0,0,0,112,113,5,15,0,0,113,19,1,
  	0,0,0,114,115,5,1,0,0,115,124,5,14,0,0,116,121,3,22,11,0,117,118,5,21,
  	0,0,118,120,3,22,11,0,119,117,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,
  	121,122,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,124,116,1,0,0,0,124,125,
  	1,0,0,0,125,126,1,0,0,0,126,129,5,15,0,0,127,129,3,22,11,0,128,114,1,
  	0,0,0,128,127,1,0,0,0,129,21,1,0,0,0,130,131,3,2,1,0,131,140,5,14,0,0,
  	132,137,3,32,16,0,133,134,5,21,0,0,134,136,3,32,16,0,135,133,1,0,0,0,
  	136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,141,1,0,0,0,139,137,
  	1,0,0,0,140,132,1,0,0,0,140,141,1,0,0,0,141,142,1,0,0,0,142,143,5,15,
  	0,0,143,23,1,0,0,0,144,160,5,20,0,0,145,146,5,11,0,0,146,147,5,18,0,0,
  	147,148,3,26,13,0,148,149,5,21,0,0,149,150,3,28,14,0,150,151,5,19,0,0,
  	151,152,5,29,0,0,152,160,1,0,0,0,153,154,5,11,0,0,154,155,5,18,0,0,155,
  	156,3,26,13,0,156,157,5,19,0,0,157,158,5,29,0,0,158,160,1,0,0,0,159,144,
  	1,0,0,0,159,145,1,0,0,0,159,153,1,0,0,0,160,25,1,0,0,0,161,162,3,32,16,
  	0,162,27,1,0,0,0,163,164,3,32,16,0,164,29,1,0,0,0,165,166,5,30,0,0,166,
  	172,3,34,17,0,167,168,5,17,0,0,168,169,3,34,17,0,169,170,5,16,0,0,170,
  	172,1,0,0,0,171,165,1,0,0,0,171,167,1,0,0,0,172,31,1,0,0,0,173,174,6,
  	16,-1,0,174,175,5,14,0,0,175,176,3,32,16,0,176,177,5,15,0,0,177,183,1,
  	0,0,0,178,179,5,11,0,0,179,183,3,32,16,7,180,183,3,4,2,0,181,183,5,32,
  	0,0,182,173,1,0,0,0,182,178,1,0,0,0,182,180,1,0,0,0,182,181,1,0,0,0,183,
  	198,1,0,0,0,184,185,10,6,0,0,185,186,5,13,0,0,186,197,3,32,16,7,187,188,
  	10,5,0,0,188,189,5,12,0,0,189,197,3,32,16,6,190,191,10,4,0,0,191,192,
  	5,10,0,0,192,197,3,32,16,5,193,194,10,3,0,0,194,195,5,11,0,0,195,197,
  	3,32,16,4,196,184,1,0,0,0,196,187,1,0,0,0,196,190,1,0,0,0,196,193,1,0,
  	0,0,197,200,1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,33,1,0,0,0,200,
  	198,1,0,0,0,201,202,6,17,-1,0,202,203,5,14,0,0,203,204,3,34,17,0,204,
  	205,5,15,0,0,205,208,1,0,0,0,206,208,3,36,18,0,207,201,1,0,0,0,207,206,
  	1,0,0,0,208,217,1,0,0,0,209,210,10,3,0,0,210,211,5,22,0,0,211,216,3,34,
  	17,4,212,213,10,2,0,0,213,214,5,23,0,0,214,216,3,34,17,3,215,209,1,0,
  	0,0,215,212,1,0,0,0,216,219,1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,
  	35,1,0,0,0,219,217,1,0,0,0,220,221,3,32,16,0,221,222,3,38,19,0,222,223,
  	3,32,16,0,223,37,1,0,0,0,224,225,7,1,0,0,225,39,1,0,0,0,20,41,45,80,89,
  	98,107,110,121,124,128,137,140,159,171,182,196,198,207,215,217
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  koatParserStaticData = staticData.release();
}

}

KoatParser::KoatParser(TokenStream *input) : KoatParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

KoatParser::KoatParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  KoatParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *koatParserStaticData->atn, koatParserStaticData->decisionToDFA, koatParserStaticData->sharedContextCache, options);
}

KoatParser::~KoatParser() {
  delete _interpreter;
}

const atn::ATN& KoatParser::getATN() const {
  return *koatParserStaticData->atn;
}

std::string KoatParser::getGrammarFileName() const {
  return "Koat.g4";
}

const std::vector<std::string>& KoatParser::getRuleNames() const {
  return koatParserStaticData->ruleNames;
}

const dfa::Vocabulary& KoatParser::getVocabulary() const {
  return koatParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView KoatParser::getSerializedATN() const {
  return koatParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

KoatParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::StartContext* KoatParser::MainContext::start() {
  return getRuleContext<KoatParser::StartContext>(0);
}

KoatParser::VardeclContext* KoatParser::MainContext::vardecl() {
  return getRuleContext<KoatParser::VardeclContext>(0);
}

KoatParser::TranssContext* KoatParser::MainContext::transs() {
  return getRuleContext<KoatParser::TranssContext>(0);
}

KoatParser::GoalContext* KoatParser::MainContext::goal() {
  return getRuleContext<KoatParser::GoalContext>(0);
}

KoatParser::SinkContext* KoatParser::MainContext::sink() {
  return getRuleContext<KoatParser::SinkContext>(0);
}


size_t KoatParser::MainContext::getRuleIndex() const {
  return KoatParser::RuleMain;
}

void KoatParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void KoatParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any KoatParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::MainContext* KoatParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, KoatParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(40);
      goal();
      break;
    }

    default:
      break;
    }
    setState(43);
    start();
    setState(45);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(44);
      sink();
      break;
    }

    default:
      break;
    }
    setState(47);
    vardecl();
    setState(48);
    transs();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FsContext ------------------------------------------------------------------

KoatParser::FsContext::FsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::FsContext::ID() {
  return getToken(KoatParser::ID, 0);
}


size_t KoatParser::FsContext::getRuleIndex() const {
  return KoatParser::RuleFs;
}

void KoatParser::FsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFs(this);
}

void KoatParser::FsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFs(this);
}


std::any KoatParser::FsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitFs(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::FsContext* KoatParser::fs() {
  FsContext *_localctx = _tracker.createInstance<FsContext>(_ctx, getState());
  enterRule(_localctx, 2, KoatParser::RuleFs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(KoatParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

KoatParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::VarContext::ID() {
  return getToken(KoatParser::ID, 0);
}


size_t KoatParser::VarContext::getRuleIndex() const {
  return KoatParser::RuleVar;
}

void KoatParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void KoatParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any KoatParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::VarContext* KoatParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 4, KoatParser::RuleVar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(KoatParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GoalContext ------------------------------------------------------------------

KoatParser::GoalContext::GoalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::GoalContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::GoalContext::GOAL() {
  return getToken(KoatParser::GOAL, 0);
}

tree::TerminalNode* KoatParser::GoalContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

tree::TerminalNode* KoatParser::GoalContext::CPX() {
  return getToken(KoatParser::CPX, 0);
}

tree::TerminalNode* KoatParser::GoalContext::TERM() {
  return getToken(KoatParser::TERM, 0);
}


size_t KoatParser::GoalContext::getRuleIndex() const {
  return KoatParser::RuleGoal;
}

void KoatParser::GoalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoal(this);
}

void KoatParser::GoalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoal(this);
}


std::any KoatParser::GoalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitGoal(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::GoalContext* KoatParser::goal() {
  GoalContext *_localctx = _tracker.createInstance<GoalContext>(_ctx, getState());
  enterRule(_localctx, 6, KoatParser::RuleGoal);
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
    setState(54);
    match(KoatParser::LPAR);
    setState(55);
    match(KoatParser::GOAL);
    setState(56);
    _la = _input->LA(1);
    if (!(_la == KoatParser::CPX

    || _la == KoatParser::TERM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(57);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

KoatParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KoatParser::StartContext::LPAR() {
  return getTokens(KoatParser::LPAR);
}

tree::TerminalNode* KoatParser::StartContext::LPAR(size_t i) {
  return getToken(KoatParser::LPAR, i);
}

tree::TerminalNode* KoatParser::StartContext::START() {
  return getToken(KoatParser::START, 0);
}

tree::TerminalNode* KoatParser::StartContext::FS() {
  return getToken(KoatParser::FS, 0);
}

KoatParser::FsContext* KoatParser::StartContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

std::vector<tree::TerminalNode *> KoatParser::StartContext::RPAR() {
  return getTokens(KoatParser::RPAR);
}

tree::TerminalNode* KoatParser::StartContext::RPAR(size_t i) {
  return getToken(KoatParser::RPAR, i);
}


size_t KoatParser::StartContext::getRuleIndex() const {
  return KoatParser::RuleStart;
}

void KoatParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void KoatParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


std::any KoatParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::StartContext* KoatParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 8, KoatParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(KoatParser::LPAR);
    setState(60);
    match(KoatParser::START);
    setState(61);
    match(KoatParser::LPAR);
    setState(62);
    match(KoatParser::FS);
    setState(63);
    fs();
    setState(64);
    match(KoatParser::RPAR);
    setState(65);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SinkContext ------------------------------------------------------------------

KoatParser::SinkContext::SinkContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KoatParser::SinkContext::LPAR() {
  return getTokens(KoatParser::LPAR);
}

tree::TerminalNode* KoatParser::SinkContext::LPAR(size_t i) {
  return getToken(KoatParser::LPAR, i);
}

tree::TerminalNode* KoatParser::SinkContext::SINK() {
  return getToken(KoatParser::SINK, 0);
}

tree::TerminalNode* KoatParser::SinkContext::FS() {
  return getToken(KoatParser::FS, 0);
}

KoatParser::FsContext* KoatParser::SinkContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

std::vector<tree::TerminalNode *> KoatParser::SinkContext::RPAR() {
  return getTokens(KoatParser::RPAR);
}

tree::TerminalNode* KoatParser::SinkContext::RPAR(size_t i) {
  return getToken(KoatParser::RPAR, i);
}


size_t KoatParser::SinkContext::getRuleIndex() const {
  return KoatParser::RuleSink;
}

void KoatParser::SinkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSink(this);
}

void KoatParser::SinkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSink(this);
}


std::any KoatParser::SinkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitSink(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::SinkContext* KoatParser::sink() {
  SinkContext *_localctx = _tracker.createInstance<SinkContext>(_ctx, getState());
  enterRule(_localctx, 10, KoatParser::RuleSink);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(KoatParser::LPAR);
    setState(68);
    match(KoatParser::SINK);
    setState(69);
    match(KoatParser::LPAR);
    setState(70);
    match(KoatParser::FS);
    setState(71);
    fs();
    setState(72);
    match(KoatParser::RPAR);
    setState(73);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

KoatParser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::VardeclContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::VardeclContext::VAR() {
  return getToken(KoatParser::VAR, 0);
}

tree::TerminalNode* KoatParser::VardeclContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<tree::TerminalNode *> KoatParser::VardeclContext::ID() {
  return getTokens(KoatParser::ID);
}

tree::TerminalNode* KoatParser::VardeclContext::ID(size_t i) {
  return getToken(KoatParser::ID, i);
}


size_t KoatParser::VardeclContext::getRuleIndex() const {
  return KoatParser::RuleVardecl;
}

void KoatParser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void KoatParser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


std::any KoatParser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::VardeclContext* KoatParser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 12, KoatParser::RuleVardecl);
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
    setState(75);
    match(KoatParser::LPAR);
    setState(76);
    match(KoatParser::VAR);
    setState(78); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(77);
      match(KoatParser::ID);
      setState(80); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == KoatParser::ID);
    setState(82);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranssContext ------------------------------------------------------------------

KoatParser::TranssContext::TranssContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::TranssContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::TranssContext::RULES() {
  return getToken(KoatParser::RULES, 0);
}

tree::TerminalNode* KoatParser::TranssContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::TransContext *> KoatParser::TranssContext::trans() {
  return getRuleContexts<KoatParser::TransContext>();
}

KoatParser::TransContext* KoatParser::TranssContext::trans(size_t i) {
  return getRuleContext<KoatParser::TransContext>(i);
}


size_t KoatParser::TranssContext::getRuleIndex() const {
  return KoatParser::RuleTranss;
}

void KoatParser::TranssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranss(this);
}

void KoatParser::TranssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranss(this);
}


std::any KoatParser::TranssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitTranss(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::TranssContext* KoatParser::transs() {
  TranssContext *_localctx = _tracker.createInstance<TranssContext>(_ctx, getState());
  enterRule(_localctx, 14, KoatParser::RuleTranss);
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
    setState(84);
    match(KoatParser::LPAR);
    setState(85);
    match(KoatParser::RULES);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KoatParser::ID) {
      setState(86);
      trans();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransContext ------------------------------------------------------------------

KoatParser::TransContext::TransContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::LhsContext* KoatParser::TransContext::lhs() {
  return getRuleContext<KoatParser::LhsContext>(0);
}

KoatParser::ToContext* KoatParser::TransContext::to() {
  return getRuleContext<KoatParser::ToContext>(0);
}

KoatParser::ComContext* KoatParser::TransContext::com() {
  return getRuleContext<KoatParser::ComContext>(0);
}

KoatParser::CondContext* KoatParser::TransContext::cond() {
  return getRuleContext<KoatParser::CondContext>(0);
}


size_t KoatParser::TransContext::getRuleIndex() const {
  return KoatParser::RuleTrans;
}

void KoatParser::TransContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrans(this);
}

void KoatParser::TransContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrans(this);
}


std::any KoatParser::TransContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitTrans(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::TransContext* KoatParser::trans() {
  TransContext *_localctx = _tracker.createInstance<TransContext>(_ctx, getState());
  enterRule(_localctx, 16, KoatParser::RuleTrans);
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
    setState(94);
    lhs();
    setState(95);
    to();
    setState(96);
    com();
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == KoatParser::LBRACK

    || _la == KoatParser::CONDSEP) {
      setState(97);
      cond();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

KoatParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::FsContext* KoatParser::LhsContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

tree::TerminalNode* KoatParser::LhsContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::LhsContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::VarContext *> KoatParser::LhsContext::var() {
  return getRuleContexts<KoatParser::VarContext>();
}

KoatParser::VarContext* KoatParser::LhsContext::var(size_t i) {
  return getRuleContext<KoatParser::VarContext>(i);
}

std::vector<tree::TerminalNode *> KoatParser::LhsContext::COMMA() {
  return getTokens(KoatParser::COMMA);
}

tree::TerminalNode* KoatParser::LhsContext::COMMA(size_t i) {
  return getToken(KoatParser::COMMA, i);
}


size_t KoatParser::LhsContext::getRuleIndex() const {
  return KoatParser::RuleLhs;
}

void KoatParser::LhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLhs(this);
}

void KoatParser::LhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLhs(this);
}


std::any KoatParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::LhsContext* KoatParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 18, KoatParser::RuleLhs);
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
    setState(100);
    fs();
    setState(101);
    match(KoatParser::LPAR);
    setState(110);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == KoatParser::ID) {
      setState(102);
      var();
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KoatParser::COMMA) {
        setState(103);
        match(KoatParser::COMMA);
        setState(104);
        var();
        setState(109);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(112);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComContext ------------------------------------------------------------------

KoatParser::ComContext::ComContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::ComContext::COM() {
  return getToken(KoatParser::COM, 0);
}

tree::TerminalNode* KoatParser::ComContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::ComContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::RhsContext *> KoatParser::ComContext::rhs() {
  return getRuleContexts<KoatParser::RhsContext>();
}

KoatParser::RhsContext* KoatParser::ComContext::rhs(size_t i) {
  return getRuleContext<KoatParser::RhsContext>(i);
}

std::vector<tree::TerminalNode *> KoatParser::ComContext::COMMA() {
  return getTokens(KoatParser::COMMA);
}

tree::TerminalNode* KoatParser::ComContext::COMMA(size_t i) {
  return getToken(KoatParser::COMMA, i);
}


size_t KoatParser::ComContext::getRuleIndex() const {
  return KoatParser::RuleCom;
}

void KoatParser::ComContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCom(this);
}

void KoatParser::ComContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCom(this);
}


std::any KoatParser::ComContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitCom(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::ComContext* KoatParser::com() {
  ComContext *_localctx = _tracker.createInstance<ComContext>(_ctx, getState());
  enterRule(_localctx, 20, KoatParser::RuleCom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::COM: {
        enterOuterAlt(_localctx, 1);
        setState(114);
        match(KoatParser::COM);
        setState(115);
        match(KoatParser::LPAR);
        setState(124);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KoatParser::ID) {
          setState(116);
          rhs();
          setState(121);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KoatParser::COMMA) {
            setState(117);
            match(KoatParser::COMMA);
            setState(118);
            rhs();
            setState(123);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(126);
        match(KoatParser::RPAR);
        break;
      }

      case KoatParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(127);
        rhs();
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

//----------------- RhsContext ------------------------------------------------------------------

KoatParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::FsContext* KoatParser::RhsContext::fs() {
  return getRuleContext<KoatParser::FsContext>(0);
}

tree::TerminalNode* KoatParser::RhsContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

tree::TerminalNode* KoatParser::RhsContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

std::vector<KoatParser::ExprContext *> KoatParser::RhsContext::expr() {
  return getRuleContexts<KoatParser::ExprContext>();
}

KoatParser::ExprContext* KoatParser::RhsContext::expr(size_t i) {
  return getRuleContext<KoatParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> KoatParser::RhsContext::COMMA() {
  return getTokens(KoatParser::COMMA);
}

tree::TerminalNode* KoatParser::RhsContext::COMMA(size_t i) {
  return getToken(KoatParser::COMMA, i);
}


size_t KoatParser::RhsContext::getRuleIndex() const {
  return KoatParser::RuleRhs;
}

void KoatParser::RhsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRhs(this);
}

void KoatParser::RhsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRhs(this);
}


std::any KoatParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::RhsContext* KoatParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 22, KoatParser::RuleRhs);
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
    setState(130);
    fs();
    setState(131);
    match(KoatParser::LPAR);
    setState(140);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 6442469376) != 0) {
      setState(132);
      expr(0);
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KoatParser::COMMA) {
        setState(133);
        match(KoatParser::COMMA);
        setState(134);
        expr(0);
        setState(139);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(142);
    match(KoatParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToContext ------------------------------------------------------------------

KoatParser::ToContext::ToContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::ToContext::TO() {
  return getToken(KoatParser::TO, 0);
}

tree::TerminalNode* KoatParser::ToContext::MINUS() {
  return getToken(KoatParser::MINUS, 0);
}

tree::TerminalNode* KoatParser::ToContext::LCURL() {
  return getToken(KoatParser::LCURL, 0);
}

KoatParser::LbContext* KoatParser::ToContext::lb() {
  return getRuleContext<KoatParser::LbContext>(0);
}

tree::TerminalNode* KoatParser::ToContext::COMMA() {
  return getToken(KoatParser::COMMA, 0);
}

KoatParser::UbContext* KoatParser::ToContext::ub() {
  return getRuleContext<KoatParser::UbContext>(0);
}

tree::TerminalNode* KoatParser::ToContext::RCURL() {
  return getToken(KoatParser::RCURL, 0);
}

tree::TerminalNode* KoatParser::ToContext::GT() {
  return getToken(KoatParser::GT, 0);
}


size_t KoatParser::ToContext::getRuleIndex() const {
  return KoatParser::RuleTo;
}

void KoatParser::ToContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTo(this);
}

void KoatParser::ToContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTo(this);
}


std::any KoatParser::ToContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitTo(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::ToContext* KoatParser::to() {
  ToContext *_localctx = _tracker.createInstance<ToContext>(_ctx, getState());
  enterRule(_localctx, 24, KoatParser::RuleTo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(144);
      match(KoatParser::TO);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      match(KoatParser::MINUS);
      setState(146);
      match(KoatParser::LCURL);
      setState(147);
      lb();
      setState(148);
      match(KoatParser::COMMA);
      setState(149);
      ub();
      setState(150);
      match(KoatParser::RCURL);
      setState(151);
      match(KoatParser::GT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(153);
      match(KoatParser::MINUS);
      setState(154);
      match(KoatParser::LCURL);
      setState(155);
      lb();
      setState(156);
      match(KoatParser::RCURL);
      setState(157);
      match(KoatParser::GT);
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

//----------------- LbContext ------------------------------------------------------------------

KoatParser::LbContext::LbContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::ExprContext* KoatParser::LbContext::expr() {
  return getRuleContext<KoatParser::ExprContext>(0);
}


size_t KoatParser::LbContext::getRuleIndex() const {
  return KoatParser::RuleLb;
}

void KoatParser::LbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLb(this);
}

void KoatParser::LbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLb(this);
}


std::any KoatParser::LbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitLb(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::LbContext* KoatParser::lb() {
  LbContext *_localctx = _tracker.createInstance<LbContext>(_ctx, getState());
  enterRule(_localctx, 26, KoatParser::RuleLb);

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
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UbContext ------------------------------------------------------------------

KoatParser::UbContext::UbContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KoatParser::ExprContext* KoatParser::UbContext::expr() {
  return getRuleContext<KoatParser::ExprContext>(0);
}


size_t KoatParser::UbContext::getRuleIndex() const {
  return KoatParser::RuleUb;
}

void KoatParser::UbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUb(this);
}

void KoatParser::UbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUb(this);
}


std::any KoatParser::UbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitUb(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::UbContext* KoatParser::ub() {
  UbContext *_localctx = _tracker.createInstance<UbContext>(_ctx, getState());
  enterRule(_localctx, 28, KoatParser::RuleUb);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

KoatParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::CondContext::CONDSEP() {
  return getToken(KoatParser::CONDSEP, 0);
}

KoatParser::FormulaContext* KoatParser::CondContext::formula() {
  return getRuleContext<KoatParser::FormulaContext>(0);
}

tree::TerminalNode* KoatParser::CondContext::LBRACK() {
  return getToken(KoatParser::LBRACK, 0);
}

tree::TerminalNode* KoatParser::CondContext::RBRACK() {
  return getToken(KoatParser::RBRACK, 0);
}


size_t KoatParser::CondContext::getRuleIndex() const {
  return KoatParser::RuleCond;
}

void KoatParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void KoatParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


std::any KoatParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::CondContext* KoatParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 30, KoatParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::CONDSEP: {
        enterOuterAlt(_localctx, 1);
        setState(165);
        match(KoatParser::CONDSEP);
        setState(166);
        formula(0);
        break;
      }

      case KoatParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(167);
        match(KoatParser::LBRACK);
        setState(168);
        formula(0);
        setState(169);
        match(KoatParser::RBRACK);
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

//----------------- ExprContext ------------------------------------------------------------------

KoatParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::ExprContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

std::vector<KoatParser::ExprContext *> KoatParser::ExprContext::expr() {
  return getRuleContexts<KoatParser::ExprContext>();
}

KoatParser::ExprContext* KoatParser::ExprContext::expr(size_t i) {
  return getRuleContext<KoatParser::ExprContext>(i);
}

tree::TerminalNode* KoatParser::ExprContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

tree::TerminalNode* KoatParser::ExprContext::MINUS() {
  return getToken(KoatParser::MINUS, 0);
}

KoatParser::VarContext* KoatParser::ExprContext::var() {
  return getRuleContext<KoatParser::VarContext>(0);
}

tree::TerminalNode* KoatParser::ExprContext::INT() {
  return getToken(KoatParser::INT, 0);
}

tree::TerminalNode* KoatParser::ExprContext::EXP() {
  return getToken(KoatParser::EXP, 0);
}

tree::TerminalNode* KoatParser::ExprContext::TIMES() {
  return getToken(KoatParser::TIMES, 0);
}

tree::TerminalNode* KoatParser::ExprContext::PLUS() {
  return getToken(KoatParser::PLUS, 0);
}


size_t KoatParser::ExprContext::getRuleIndex() const {
  return KoatParser::RuleExpr;
}

void KoatParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void KoatParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any KoatParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


KoatParser::ExprContext* KoatParser::expr() {
   return expr(0);
}

KoatParser::ExprContext* KoatParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KoatParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  KoatParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, KoatParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::LPAR: {
        setState(174);
        match(KoatParser::LPAR);
        setState(175);
        expr(0);
        setState(176);
        match(KoatParser::RPAR);
        break;
      }

      case KoatParser::MINUS: {
        setState(178);
        match(KoatParser::MINUS);
        setState(179);
        expr(7);
        break;
      }

      case KoatParser::ID: {
        setState(180);
        var();
        break;
      }

      case KoatParser::INT: {
        setState(181);
        match(KoatParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(198);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(196);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(184);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(185);
          match(KoatParser::EXP);
          setState(186);
          expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(187);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(188);
          match(KoatParser::TIMES);
          setState(189);
          expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(191);
          match(KoatParser::PLUS);
          setState(192);
          expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(193);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(194);
          match(KoatParser::MINUS);
          setState(195);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(200);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FormulaContext ------------------------------------------------------------------

KoatParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::FormulaContext::LPAR() {
  return getToken(KoatParser::LPAR, 0);
}

std::vector<KoatParser::FormulaContext *> KoatParser::FormulaContext::formula() {
  return getRuleContexts<KoatParser::FormulaContext>();
}

KoatParser::FormulaContext* KoatParser::FormulaContext::formula(size_t i) {
  return getRuleContext<KoatParser::FormulaContext>(i);
}

tree::TerminalNode* KoatParser::FormulaContext::RPAR() {
  return getToken(KoatParser::RPAR, 0);
}

KoatParser::LitContext* KoatParser::FormulaContext::lit() {
  return getRuleContext<KoatParser::LitContext>(0);
}

tree::TerminalNode* KoatParser::FormulaContext::AND() {
  return getToken(KoatParser::AND, 0);
}

tree::TerminalNode* KoatParser::FormulaContext::OR() {
  return getToken(KoatParser::OR, 0);
}


size_t KoatParser::FormulaContext::getRuleIndex() const {
  return KoatParser::RuleFormula;
}

void KoatParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void KoatParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}


std::any KoatParser::FormulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitFormula(this);
  else
    return visitor->visitChildren(this);
}


KoatParser::FormulaContext* KoatParser::formula() {
   return formula(0);
}

KoatParser::FormulaContext* KoatParser::formula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KoatParser::FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, parentState);
  KoatParser::FormulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, KoatParser::RuleFormula, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(202);
      match(KoatParser::LPAR);
      setState(203);
      formula(0);
      setState(204);
      match(KoatParser::RPAR);
      break;
    }

    case 2: {
      setState(206);
      lit();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(215);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleFormula);
          setState(209);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(210);
          match(KoatParser::AND);
          setState(211);
          formula(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleFormula);
          setState(212);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(213);
          match(KoatParser::OR);
          setState(214);
          formula(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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

KoatParser::LitContext::LitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<KoatParser::ExprContext *> KoatParser::LitContext::expr() {
  return getRuleContexts<KoatParser::ExprContext>();
}

KoatParser::ExprContext* KoatParser::LitContext::expr(size_t i) {
  return getRuleContext<KoatParser::ExprContext>(i);
}

KoatParser::RelopContext* KoatParser::LitContext::relop() {
  return getRuleContext<KoatParser::RelopContext>(0);
}


size_t KoatParser::LitContext::getRuleIndex() const {
  return KoatParser::RuleLit;
}

void KoatParser::LitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLit(this);
}

void KoatParser::LitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLit(this);
}


std::any KoatParser::LitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitLit(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::LitContext* KoatParser::lit() {
  LitContext *_localctx = _tracker.createInstance<LitContext>(_ctx, getState());
  enterRule(_localctx, 36, KoatParser::RuleLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    expr(0);
    setState(221);
    relop();
    setState(222);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

KoatParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KoatParser::RelopContext::LT() {
  return getToken(KoatParser::LT, 0);
}

tree::TerminalNode* KoatParser::RelopContext::LEQ() {
  return getToken(KoatParser::LEQ, 0);
}

tree::TerminalNode* KoatParser::RelopContext::EQ() {
  return getToken(KoatParser::EQ, 0);
}

tree::TerminalNode* KoatParser::RelopContext::GT() {
  return getToken(KoatParser::GT, 0);
}

tree::TerminalNode* KoatParser::RelopContext::GEQ() {
  return getToken(KoatParser::GEQ, 0);
}

tree::TerminalNode* KoatParser::RelopContext::NEQ() {
  return getToken(KoatParser::NEQ, 0);
}


size_t KoatParser::RelopContext::getRuleIndex() const {
  return KoatParser::RuleRelop;
}

void KoatParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void KoatParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<KoatListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}


std::any KoatParser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KoatVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

KoatParser::RelopContext* KoatParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 38, KoatParser::RuleRelop);
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
    setState(224);
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

bool KoatParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 16: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 17: return formulaSempred(antlrcpp::downCast<FormulaContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool KoatParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool KoatParser::formulaSempred(FormulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void KoatParser::initialize() {
  ::antlr4::internal::call_once(koatParserOnceFlag, koatParserInitialize);
}
