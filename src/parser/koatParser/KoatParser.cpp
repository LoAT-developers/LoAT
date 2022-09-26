
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
      "main", "fs", "var", "goal", "start", "vardecl", "transs", "trans", 
      "lhs", "com", "rhs", "to", "lb", "ub", "cond", "expr", "formula", 
      "lit", "relop"
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
  	4,1,33,214,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,3,0,40,8,0,1,0,1,0,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,5,1,5,1,5,4,5,66,8,5,11,5,12,5,67,1,5,1,5,1,6,1,6,1,6,5,6,75,8,6,
  	10,6,12,6,78,9,6,1,6,1,6,1,7,1,7,1,7,1,7,3,7,86,8,7,1,8,1,8,1,8,1,8,1,
  	8,5,8,93,8,8,10,8,12,8,96,9,8,3,8,98,8,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,
  	5,9,107,8,9,10,9,12,9,110,9,9,3,9,112,8,9,1,9,1,9,3,9,116,8,9,1,10,1,
  	10,1,10,1,10,1,10,5,10,123,8,10,10,10,12,10,126,9,10,3,10,128,8,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,3,11,147,8,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,14,1,
  	14,1,14,3,14,159,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,
  	15,170,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,5,15,184,8,15,10,15,12,15,187,9,15,1,16,1,16,1,16,1,16,1,16,1,16,3,
  	16,195,8,16,1,16,1,16,1,16,1,16,1,16,1,16,5,16,203,8,16,10,16,12,16,206,
  	9,16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,0,2,30,32,19,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,32,34,36,0,2,1,0,3,4,1,0,23,28,218,0,39,1,
  	0,0,0,2,45,1,0,0,0,4,47,1,0,0,0,6,49,1,0,0,0,8,54,1,0,0,0,10,62,1,0,0,
  	0,12,71,1,0,0,0,14,81,1,0,0,0,16,87,1,0,0,0,18,115,1,0,0,0,20,117,1,0,
  	0,0,22,146,1,0,0,0,24,148,1,0,0,0,26,150,1,0,0,0,28,158,1,0,0,0,30,169,
  	1,0,0,0,32,194,1,0,0,0,34,207,1,0,0,0,36,211,1,0,0,0,38,40,3,6,3,0,39,
  	38,1,0,0,0,39,40,1,0,0,0,40,41,1,0,0,0,41,42,3,8,4,0,42,43,3,10,5,0,43,
  	44,3,12,6,0,44,1,1,0,0,0,45,46,5,30,0,0,46,3,1,0,0,0,47,48,5,30,0,0,48,
  	5,1,0,0,0,49,50,5,13,0,0,50,51,5,2,0,0,51,52,7,0,0,0,52,53,5,14,0,0,53,
  	7,1,0,0,0,54,55,5,13,0,0,55,56,5,5,0,0,56,57,5,13,0,0,57,58,5,6,0,0,58,
  	59,3,2,1,0,59,60,5,14,0,0,60,61,5,14,0,0,61,9,1,0,0,0,62,63,5,13,0,0,
  	63,65,5,7,0,0,64,66,5,30,0,0,65,64,1,0,0,0,66,67,1,0,0,0,67,65,1,0,0,
  	0,67,68,1,0,0,0,68,69,1,0,0,0,69,70,5,14,0,0,70,11,1,0,0,0,71,72,5,13,
  	0,0,72,76,5,8,0,0,73,75,3,14,7,0,74,73,1,0,0,0,75,78,1,0,0,0,76,74,1,
  	0,0,0,76,77,1,0,0,0,77,79,1,0,0,0,78,76,1,0,0,0,79,80,5,14,0,0,80,13,
  	1,0,0,0,81,82,3,16,8,0,82,83,3,22,11,0,83,85,3,18,9,0,84,86,3,28,14,0,
  	85,84,1,0,0,0,85,86,1,0,0,0,86,15,1,0,0,0,87,88,3,2,1,0,88,97,5,13,0,
  	0,89,94,3,4,2,0,90,91,5,20,0,0,91,93,3,4,2,0,92,90,1,0,0,0,93,96,1,0,
  	0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,97,89,1,0,
  	0,0,97,98,1,0,0,0,98,99,1,0,0,0,99,100,5,14,0,0,100,17,1,0,0,0,101,102,
  	5,1,0,0,102,111,5,13,0,0,103,108,3,20,10,0,104,105,5,20,0,0,105,107,3,
  	20,10,0,106,104,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,
  	0,109,112,1,0,0,0,110,108,1,0,0,0,111,103,1,0,0,0,111,112,1,0,0,0,112,
  	113,1,0,0,0,113,116,5,14,0,0,114,116,3,20,10,0,115,101,1,0,0,0,115,114,
  	1,0,0,0,116,19,1,0,0,0,117,118,3,2,1,0,118,127,5,13,0,0,119,124,3,30,
  	15,0,120,121,5,20,0,0,121,123,3,30,15,0,122,120,1,0,0,0,123,126,1,0,0,
  	0,124,122,1,0,0,0,124,125,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,127,
  	119,1,0,0,0,127,128,1,0,0,0,128,129,1,0,0,0,129,130,5,14,0,0,130,21,1,
  	0,0,0,131,147,5,19,0,0,132,133,5,10,0,0,133,134,5,17,0,0,134,135,3,24,
  	12,0,135,136,5,20,0,0,136,137,3,26,13,0,137,138,5,18,0,0,138,139,5,28,
  	0,0,139,147,1,0,0,0,140,141,5,10,0,0,141,142,5,17,0,0,142,143,3,24,12,
  	0,143,144,5,18,0,0,144,145,5,28,0,0,145,147,1,0,0,0,146,131,1,0,0,0,146,
  	132,1,0,0,0,146,140,1,0,0,0,147,23,1,0,0,0,148,149,3,30,15,0,149,25,1,
  	0,0,0,150,151,3,30,15,0,151,27,1,0,0,0,152,153,5,29,0,0,153,159,3,32,
  	16,0,154,155,5,16,0,0,155,156,3,32,16,0,156,157,5,15,0,0,157,159,1,0,
  	0,0,158,152,1,0,0,0,158,154,1,0,0,0,159,29,1,0,0,0,160,161,6,15,-1,0,
  	161,162,5,13,0,0,162,163,3,30,15,0,163,164,5,14,0,0,164,170,1,0,0,0,165,
  	166,5,10,0,0,166,170,3,30,15,7,167,170,3,4,2,0,168,170,5,31,0,0,169,160,
  	1,0,0,0,169,165,1,0,0,0,169,167,1,0,0,0,169,168,1,0,0,0,170,185,1,0,0,
  	0,171,172,10,6,0,0,172,173,5,12,0,0,173,184,3,30,15,7,174,175,10,5,0,
  	0,175,176,5,11,0,0,176,184,3,30,15,6,177,178,10,4,0,0,178,179,5,9,0,0,
  	179,184,3,30,15,5,180,181,10,3,0,0,181,182,5,10,0,0,182,184,3,30,15,4,
  	183,171,1,0,0,0,183,174,1,0,0,0,183,177,1,0,0,0,183,180,1,0,0,0,184,187,
  	1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,31,1,0,0,0,187,185,1,0,0,
  	0,188,189,6,16,-1,0,189,190,5,13,0,0,190,191,3,32,16,0,191,192,5,14,0,
  	0,192,195,1,0,0,0,193,195,3,34,17,0,194,188,1,0,0,0,194,193,1,0,0,0,195,
  	204,1,0,0,0,196,197,10,3,0,0,197,198,5,21,0,0,198,203,3,32,16,4,199,200,
  	10,2,0,0,200,201,5,22,0,0,201,203,3,32,16,3,202,196,1,0,0,0,202,199,1,
  	0,0,0,203,206,1,0,0,0,204,202,1,0,0,0,204,205,1,0,0,0,205,33,1,0,0,0,
  	206,204,1,0,0,0,207,208,3,30,15,0,208,209,3,36,18,0,209,210,3,30,15,0,
  	210,35,1,0,0,0,211,212,7,1,0,0,212,37,1,0,0,0,19,39,67,76,85,94,97,108,
  	111,115,124,127,146,158,169,183,185,194,202,204
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
    setState(39);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(38);
      goal();
      break;
    }

    default:
      break;
    }
    setState(41);
    start();
    setState(42);
    vardecl();
    setState(43);
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
    setState(45);
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
    setState(47);
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
    setState(49);
    match(KoatParser::LPAR);
    setState(50);
    match(KoatParser::GOAL);
    setState(51);
    _la = _input->LA(1);
    if (!(_la == KoatParser::CPX

    || _la == KoatParser::TERM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(52);
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
    setState(54);
    match(KoatParser::LPAR);
    setState(55);
    match(KoatParser::START);
    setState(56);
    match(KoatParser::LPAR);
    setState(57);
    match(KoatParser::FS);
    setState(58);
    fs();
    setState(59);
    match(KoatParser::RPAR);
    setState(60);
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
  enterRule(_localctx, 10, KoatParser::RuleVardecl);
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
    setState(62);
    match(KoatParser::LPAR);
    setState(63);
    match(KoatParser::VAR);
    setState(65); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(64);
      match(KoatParser::ID);
      setState(67); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == KoatParser::ID);
    setState(69);
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
  enterRule(_localctx, 12, KoatParser::RuleTranss);
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
    setState(71);
    match(KoatParser::LPAR);
    setState(72);
    match(KoatParser::RULES);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KoatParser::ID) {
      setState(73);
      trans();
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
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
  enterRule(_localctx, 14, KoatParser::RuleTrans);
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
    setState(81);
    lhs();
    setState(82);
    to();
    setState(83);
    com();
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == KoatParser::LBRACK

    || _la == KoatParser::CONDSEP) {
      setState(84);
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
  enterRule(_localctx, 16, KoatParser::RuleLhs);
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
    setState(87);
    fs();
    setState(88);
    match(KoatParser::LPAR);
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == KoatParser::ID) {
      setState(89);
      var();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KoatParser::COMMA) {
        setState(90);
        match(KoatParser::COMMA);
        setState(91);
        var();
        setState(96);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(99);
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
  enterRule(_localctx, 18, KoatParser::RuleCom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::COM: {
        enterOuterAlt(_localctx, 1);
        setState(101);
        match(KoatParser::COM);
        setState(102);
        match(KoatParser::LPAR);
        setState(111);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == KoatParser::ID) {
          setState(103);
          rhs();
          setState(108);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == KoatParser::COMMA) {
            setState(104);
            match(KoatParser::COMMA);
            setState(105);
            rhs();
            setState(110);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(113);
        match(KoatParser::RPAR);
        break;
      }

      case KoatParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(114);
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
  enterRule(_localctx, 20, KoatParser::RuleRhs);
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
    setState(117);
    fs();
    setState(118);
    match(KoatParser::LPAR);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3221234688) != 0) {
      setState(119);
      expr(0);
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == KoatParser::COMMA) {
        setState(120);
        match(KoatParser::COMMA);
        setState(121);
        expr(0);
        setState(126);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(129);
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
  enterRule(_localctx, 22, KoatParser::RuleTo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(131);
      match(KoatParser::TO);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(132);
      match(KoatParser::MINUS);
      setState(133);
      match(KoatParser::LCURL);
      setState(134);
      lb();
      setState(135);
      match(KoatParser::COMMA);
      setState(136);
      ub();
      setState(137);
      match(KoatParser::RCURL);
      setState(138);
      match(KoatParser::GT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(140);
      match(KoatParser::MINUS);
      setState(141);
      match(KoatParser::LCURL);
      setState(142);
      lb();
      setState(143);
      match(KoatParser::RCURL);
      setState(144);
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
  enterRule(_localctx, 24, KoatParser::RuleLb);

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
  enterRule(_localctx, 26, KoatParser::RuleUb);

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
  enterRule(_localctx, 28, KoatParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::CONDSEP: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        match(KoatParser::CONDSEP);
        setState(153);
        formula(0);
        break;
      }

      case KoatParser::LBRACK: {
        enterOuterAlt(_localctx, 2);
        setState(154);
        match(KoatParser::LBRACK);
        setState(155);
        formula(0);
        setState(156);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, KoatParser::RuleExpr, precedence);

    

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
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KoatParser::LPAR: {
        setState(161);
        match(KoatParser::LPAR);
        setState(162);
        expr(0);
        setState(163);
        match(KoatParser::RPAR);
        break;
      }

      case KoatParser::MINUS: {
        setState(165);
        match(KoatParser::MINUS);
        setState(166);
        expr(7);
        break;
      }

      case KoatParser::ID: {
        setState(167);
        var();
        break;
      }

      case KoatParser::INT: {
        setState(168);
        match(KoatParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(183);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(171);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(172);
          match(KoatParser::EXP);
          setState(173);
          expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(174);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(175);
          match(KoatParser::TIMES);
          setState(176);
          expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(177);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(178);
          match(KoatParser::PLUS);
          setState(179);
          expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(180);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(181);
          match(KoatParser::MINUS);
          setState(182);
          expr(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, KoatParser::RuleFormula, precedence);

    

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
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(189);
      match(KoatParser::LPAR);
      setState(190);
      formula(0);
      setState(191);
      match(KoatParser::RPAR);
      break;
    }

    case 2: {
      setState(193);
      lit();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(204);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(202);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleFormula);
          setState(196);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(197);
          match(KoatParser::AND);
          setState(198);
          formula(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<FormulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleFormula);
          setState(199);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(200);
          match(KoatParser::OR);
          setState(201);
          formula(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(206);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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
  enterRule(_localctx, 34, KoatParser::RuleLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    expr(0);
    setState(208);
    relop();
    setState(209);
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
  enterRule(_localctx, 36, KoatParser::RuleRelop);
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
    setState(211);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 528482304) != 0)) {
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
    case 15: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 16: return formulaSempred(antlrcpp::downCast<FormulaContext *>(context), predicateIndex);

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
