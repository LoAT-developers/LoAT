
// Generated from redlog.g4 by ANTLR 4.11.1


#include "redlogListener.h"
#include "redlogVisitor.h"

#include "redlogParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct RedlogParserStaticData final {
  RedlogParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RedlogParserStaticData(const RedlogParserStaticData&) = delete;
  RedlogParserStaticData(RedlogParserStaticData&&) = delete;
  RedlogParserStaticData& operator=(const RedlogParserStaticData&) = delete;
  RedlogParserStaticData& operator=(RedlogParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag redlogParserOnceFlag;
RedlogParserStaticData *redlogParserStaticData = nullptr;

void redlogParserInitialize() {
  assert(redlogParserStaticData == nullptr);
  auto staticData = std::make_unique<RedlogParserStaticData>(
    std::vector<std::string>{
      "main", "expr", "caop", "binop", "formula", "lit", "boolop", "relop"
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
  	4,1,19,73,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,5,1,35,8,1,10,1,12,1,38,9,1,1,1,1,1,3,1,42,8,1,1,2,1,2,1,3,1,3,
  	1,4,1,4,1,4,1,4,1,4,1,4,5,4,54,8,4,10,4,12,4,57,9,4,1,4,1,4,3,4,61,8,
  	4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,7,1,7,1,7,0,0,8,0,2,4,6,8,10,12,14,
  	0,4,2,0,1,1,3,3,2,0,2,2,4,4,1,0,7,8,1,0,9,14,73,0,16,1,0,0,0,2,41,1,0,
  	0,0,4,43,1,0,0,0,6,45,1,0,0,0,8,60,1,0,0,0,10,62,1,0,0,0,12,68,1,0,0,
  	0,14,70,1,0,0,0,16,17,3,8,4,0,17,1,1,0,0,0,18,42,5,17,0,0,19,42,5,18,
  	0,0,20,21,5,5,0,0,21,22,5,2,0,0,22,23,3,2,1,0,23,24,5,6,0,0,24,42,1,0,
  	0,0,25,26,5,5,0,0,26,27,3,6,3,0,27,28,3,2,1,0,28,29,3,2,1,0,29,30,5,6,
  	0,0,30,42,1,0,0,0,31,32,5,5,0,0,32,36,3,4,2,0,33,35,3,2,1,0,34,33,1,0,
  	0,0,35,38,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,39,1,0,0,0,38,36,1,0,
  	0,0,39,40,5,6,0,0,40,42,1,0,0,0,41,18,1,0,0,0,41,19,1,0,0,0,41,20,1,0,
  	0,0,41,25,1,0,0,0,41,31,1,0,0,0,42,3,1,0,0,0,43,44,7,0,0,0,44,5,1,0,0,
  	0,45,46,7,1,0,0,46,7,1,0,0,0,47,61,5,15,0,0,48,61,5,16,0,0,49,61,3,10,
  	5,0,50,51,5,5,0,0,51,55,3,12,6,0,52,54,3,8,4,0,53,52,1,0,0,0,54,57,1,
  	0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,58,1,0,0,0,57,55,1,0,0,0,58,59,5,
  	6,0,0,59,61,1,0,0,0,60,47,1,0,0,0,60,48,1,0,0,0,60,49,1,0,0,0,60,50,1,
  	0,0,0,61,9,1,0,0,0,62,63,5,5,0,0,63,64,3,14,7,0,64,65,3,2,1,0,65,66,3,
  	2,1,0,66,67,5,6,0,0,67,11,1,0,0,0,68,69,7,2,0,0,69,13,1,0,0,0,70,71,7,
  	3,0,0,71,15,1,0,0,0,4,36,41,55,60
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  redlogParserStaticData = staticData.release();
}

}

redlogParser::redlogParser(TokenStream *input) : redlogParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

redlogParser::redlogParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  redlogParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *redlogParserStaticData->atn, redlogParserStaticData->decisionToDFA, redlogParserStaticData->sharedContextCache, options);
}

redlogParser::~redlogParser() {
  delete _interpreter;
}

const atn::ATN& redlogParser::getATN() const {
  return *redlogParserStaticData->atn;
}

std::string redlogParser::getGrammarFileName() const {
  return "redlog.g4";
}

const std::vector<std::string>& redlogParser::getRuleNames() const {
  return redlogParserStaticData->ruleNames;
}

const dfa::Vocabulary& redlogParser::getVocabulary() const {
  return redlogParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView redlogParser::getSerializedATN() const {
  return redlogParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

redlogParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

redlogParser::FormulaContext* redlogParser::MainContext::formula() {
  return getRuleContext<redlogParser::FormulaContext>(0);
}


size_t redlogParser::MainContext::getRuleIndex() const {
  return redlogParser::RuleMain;
}

void redlogParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void redlogParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any redlogParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::MainContext* redlogParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, redlogParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    formula();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

redlogParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::ExprContext::VAR() {
  return getToken(redlogParser::VAR, 0);
}

tree::TerminalNode* redlogParser::ExprContext::INT() {
  return getToken(redlogParser::INT, 0);
}

tree::TerminalNode* redlogParser::ExprContext::LPAR() {
  return getToken(redlogParser::LPAR, 0);
}

tree::TerminalNode* redlogParser::ExprContext::MINUS() {
  return getToken(redlogParser::MINUS, 0);
}

std::vector<redlogParser::ExprContext *> redlogParser::ExprContext::expr() {
  return getRuleContexts<redlogParser::ExprContext>();
}

redlogParser::ExprContext* redlogParser::ExprContext::expr(size_t i) {
  return getRuleContext<redlogParser::ExprContext>(i);
}

tree::TerminalNode* redlogParser::ExprContext::RPAR() {
  return getToken(redlogParser::RPAR, 0);
}

redlogParser::BinopContext* redlogParser::ExprContext::binop() {
  return getRuleContext<redlogParser::BinopContext>(0);
}

redlogParser::CaopContext* redlogParser::ExprContext::caop() {
  return getRuleContext<redlogParser::CaopContext>(0);
}


size_t redlogParser::ExprContext::getRuleIndex() const {
  return redlogParser::RuleExpr;
}

void redlogParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void redlogParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any redlogParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::ExprContext* redlogParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, redlogParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(18);
      match(redlogParser::VAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(19);
      match(redlogParser::INT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(20);
      match(redlogParser::LPAR);
      setState(21);
      match(redlogParser::MINUS);
      setState(22);
      expr();
      setState(23);
      match(redlogParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(25);
      match(redlogParser::LPAR);
      setState(26);
      binop();
      setState(27);
      expr();
      setState(28);
      expr();
      setState(29);
      match(redlogParser::RPAR);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(31);
      match(redlogParser::LPAR);
      setState(32);
      caop();
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 393248) != 0) {
        setState(33);
        expr();
        setState(38);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(39);
      match(redlogParser::RPAR);
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

//----------------- CaopContext ------------------------------------------------------------------

redlogParser::CaopContext::CaopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::CaopContext::TIMES() {
  return getToken(redlogParser::TIMES, 0);
}

tree::TerminalNode* redlogParser::CaopContext::PLUS() {
  return getToken(redlogParser::PLUS, 0);
}


size_t redlogParser::CaopContext::getRuleIndex() const {
  return redlogParser::RuleCaop;
}

void redlogParser::CaopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaop(this);
}

void redlogParser::CaopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaop(this);
}


std::any redlogParser::CaopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitCaop(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::CaopContext* redlogParser::caop() {
  CaopContext *_localctx = _tracker.createInstance<CaopContext>(_ctx, getState());
  enterRule(_localctx, 4, redlogParser::RuleCaop);
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
    setState(43);
    _la = _input->LA(1);
    if (!(_la == redlogParser::PLUS

    || _la == redlogParser::TIMES)) {
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

//----------------- BinopContext ------------------------------------------------------------------

redlogParser::BinopContext::BinopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::BinopContext::EXP() {
  return getToken(redlogParser::EXP, 0);
}

tree::TerminalNode* redlogParser::BinopContext::MINUS() {
  return getToken(redlogParser::MINUS, 0);
}


size_t redlogParser::BinopContext::getRuleIndex() const {
  return redlogParser::RuleBinop;
}

void redlogParser::BinopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinop(this);
}

void redlogParser::BinopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinop(this);
}


std::any redlogParser::BinopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitBinop(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::BinopContext* redlogParser::binop() {
  BinopContext *_localctx = _tracker.createInstance<BinopContext>(_ctx, getState());
  enterRule(_localctx, 6, redlogParser::RuleBinop);
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
    setState(45);
    _la = _input->LA(1);
    if (!(_la == redlogParser::MINUS

    || _la == redlogParser::EXP)) {
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

//----------------- FormulaContext ------------------------------------------------------------------

redlogParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::FormulaContext::TRUE() {
  return getToken(redlogParser::TRUE, 0);
}

tree::TerminalNode* redlogParser::FormulaContext::FALSE() {
  return getToken(redlogParser::FALSE, 0);
}

redlogParser::LitContext* redlogParser::FormulaContext::lit() {
  return getRuleContext<redlogParser::LitContext>(0);
}

tree::TerminalNode* redlogParser::FormulaContext::LPAR() {
  return getToken(redlogParser::LPAR, 0);
}

redlogParser::BoolopContext* redlogParser::FormulaContext::boolop() {
  return getRuleContext<redlogParser::BoolopContext>(0);
}

tree::TerminalNode* redlogParser::FormulaContext::RPAR() {
  return getToken(redlogParser::RPAR, 0);
}

std::vector<redlogParser::FormulaContext *> redlogParser::FormulaContext::formula() {
  return getRuleContexts<redlogParser::FormulaContext>();
}

redlogParser::FormulaContext* redlogParser::FormulaContext::formula(size_t i) {
  return getRuleContext<redlogParser::FormulaContext>(i);
}


size_t redlogParser::FormulaContext::getRuleIndex() const {
  return redlogParser::RuleFormula;
}

void redlogParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void redlogParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}


std::any redlogParser::FormulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitFormula(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::FormulaContext* redlogParser::formula() {
  FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, getState());
  enterRule(_localctx, 8, redlogParser::RuleFormula);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(60);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(47);
      match(redlogParser::TRUE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(48);
      match(redlogParser::FALSE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(49);
      lit();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(50);
      match(redlogParser::LPAR);
      setState(51);
      boolop();
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 98336) != 0) {
        setState(52);
        formula();
        setState(57);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(58);
      match(redlogParser::RPAR);
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

//----------------- LitContext ------------------------------------------------------------------

redlogParser::LitContext::LitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::LitContext::LPAR() {
  return getToken(redlogParser::LPAR, 0);
}

redlogParser::RelopContext* redlogParser::LitContext::relop() {
  return getRuleContext<redlogParser::RelopContext>(0);
}

std::vector<redlogParser::ExprContext *> redlogParser::LitContext::expr() {
  return getRuleContexts<redlogParser::ExprContext>();
}

redlogParser::ExprContext* redlogParser::LitContext::expr(size_t i) {
  return getRuleContext<redlogParser::ExprContext>(i);
}

tree::TerminalNode* redlogParser::LitContext::RPAR() {
  return getToken(redlogParser::RPAR, 0);
}


size_t redlogParser::LitContext::getRuleIndex() const {
  return redlogParser::RuleLit;
}

void redlogParser::LitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLit(this);
}

void redlogParser::LitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLit(this);
}


std::any redlogParser::LitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitLit(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::LitContext* redlogParser::lit() {
  LitContext *_localctx = _tracker.createInstance<LitContext>(_ctx, getState());
  enterRule(_localctx, 10, redlogParser::RuleLit);

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
    match(redlogParser::LPAR);
    setState(63);
    relop();
    setState(64);
    expr();
    setState(65);
    expr();
    setState(66);
    match(redlogParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolopContext ------------------------------------------------------------------

redlogParser::BoolopContext::BoolopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::BoolopContext::AND() {
  return getToken(redlogParser::AND, 0);
}

tree::TerminalNode* redlogParser::BoolopContext::OR() {
  return getToken(redlogParser::OR, 0);
}


size_t redlogParser::BoolopContext::getRuleIndex() const {
  return redlogParser::RuleBoolop;
}

void redlogParser::BoolopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolop(this);
}

void redlogParser::BoolopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolop(this);
}


std::any redlogParser::BoolopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitBoolop(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::BoolopContext* redlogParser::boolop() {
  BoolopContext *_localctx = _tracker.createInstance<BoolopContext>(_ctx, getState());
  enterRule(_localctx, 12, redlogParser::RuleBoolop);
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
    setState(68);
    _la = _input->LA(1);
    if (!(_la == redlogParser::AND

    || _la == redlogParser::OR)) {
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

//----------------- RelopContext ------------------------------------------------------------------

redlogParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* redlogParser::RelopContext::LT() {
  return getToken(redlogParser::LT, 0);
}

tree::TerminalNode* redlogParser::RelopContext::LEQ() {
  return getToken(redlogParser::LEQ, 0);
}

tree::TerminalNode* redlogParser::RelopContext::EQ() {
  return getToken(redlogParser::EQ, 0);
}

tree::TerminalNode* redlogParser::RelopContext::GT() {
  return getToken(redlogParser::GT, 0);
}

tree::TerminalNode* redlogParser::RelopContext::GEQ() {
  return getToken(redlogParser::GEQ, 0);
}

tree::TerminalNode* redlogParser::RelopContext::NEQ() {
  return getToken(redlogParser::NEQ, 0);
}


size_t redlogParser::RelopContext::getRuleIndex() const {
  return redlogParser::RuleRelop;
}

void redlogParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void redlogParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<redlogListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}


std::any redlogParser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<redlogVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

redlogParser::RelopContext* redlogParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 14, redlogParser::RuleRelop);
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
    setState(70);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32256) != 0)) {
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

void redlogParser::initialize() {
  ::antlr4::internal::call_once(redlogParserOnceFlag, redlogParserInitialize);
}
