
// Generated from CHC.g4 by ANTLR 4.7.2


#include "CHCListener.h"
#include "CHCVisitor.h"

#include "CHCParser.h"


using namespace antlrcpp;
using namespace antlr4;

CHCParser::CHCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CHCParser::~CHCParser() {
  delete _interpreter;
}

std::string CHCParser::getGrammarFileName() const {
  return "CHC.g4";
}

const std::vector<std::string>& CHCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CHCParser::getVocabulary() const {
  return _vocabulary;
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


antlrcpp::Any CHCParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::MainContext* CHCParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, CHCParser::RuleMain);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(CHCParser::LPAR);
    setState(47);
    match(CHCParser::LOGIC);
    setState(48);
    match(CHCParser::RPAR);
    setState(50); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(49);
              fun_decl();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(52); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(54);
        match(CHCParser::LPAR);
        setState(55);
        match(CHCParser::ASSERT);
        setState(56);
        chc_assert();
        setState(57);
        match(CHCParser::RPAR); 
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(71);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(64);
        match(CHCParser::LPAR);
        setState(65);
        match(CHCParser::ASSERT);
        setState(66);
        chc_query();
        setState(67);
        match(CHCParser::RPAR); 
      }
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(74);
    match(CHCParser::LPAR);
    setState(75);
    match(CHCParser::CHECK_SAT);
    setState(76);
    match(CHCParser::RPAR);
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CHCParser::LPAR) {
      setState(77);
      match(CHCParser::LPAR);
      setState(78);
      match(CHCParser::EXIT);
      setState(79);
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

tree::TerminalNode* CHCParser::Fun_declContext::BOOL() {
  return getToken(CHCParser::BOOL, 0);
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


antlrcpp::Any CHCParser::Fun_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitFun_decl(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Fun_declContext* CHCParser::fun_decl() {
  Fun_declContext *_localctx = _tracker.createInstance<Fun_declContext>(_ctx, getState());
  enterRule(_localctx, 2, CHCParser::RuleFun_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(CHCParser::LPAR);
    setState(83);
    match(CHCParser::DECLARE_FUN);
    setState(84);
    symbol();
    setState(85);
    match(CHCParser::LPAR);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CHCParser::ID) {
      setState(86);
      sort();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(CHCParser::RPAR);
    setState(93);
    match(CHCParser::BOOL);
    setState(94);
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


antlrcpp::Any CHCParser::Chc_assertContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_assert(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_assertContext* CHCParser::chc_assert() {
  Chc_assertContext *_localctx = _tracker.createInstance<Chc_assertContext>(_ctx, getState());
  enterRule(_localctx, 4, CHCParser::RuleChc_assert);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(CHCParser::LPAR);
    setState(97);
    chc_assert_head();
    setState(98);
    chc_assert_body();
    setState(99);
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


antlrcpp::Any CHCParser::Chc_assert_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_assert_head(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_assert_headContext* CHCParser::chc_assert_head() {
  Chc_assert_headContext *_localctx = _tracker.createInstance<Chc_assert_headContext>(_ctx, getState());
  enterRule(_localctx, 6, CHCParser::RuleChc_assert_head);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(CHCParser::FORALL);
    setState(102);
    match(CHCParser::LPAR);
    setState(104); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(103);
      var_decl();
      setState(106); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
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


antlrcpp::Any CHCParser::Chc_assert_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_assert_body(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_assert_bodyContext* CHCParser::chc_assert_body() {
  Chc_assert_bodyContext *_localctx = _tracker.createInstance<Chc_assert_bodyContext>(_ctx, getState());
  enterRule(_localctx, 8, CHCParser::RuleChc_assert_body);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      match(CHCParser::LPAR);
      setState(111);
      match(CHCParser::IMPLIES);
      setState(112);
      chc_tail();
      setState(113);
      chc_head();
      setState(114);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      chc_head();
      break;
    }

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

std::vector<CHCParser::I_formulaContext *> CHCParser::Chc_tailContext::i_formula() {
  return getRuleContexts<CHCParser::I_formulaContext>();
}

CHCParser::I_formulaContext* CHCParser::Chc_tailContext::i_formula(size_t i) {
  return getRuleContext<CHCParser::I_formulaContext>(i);
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

std::vector<CHCParser::U_pred_atomContext *> CHCParser::Chc_tailContext::u_pred_atom() {
  return getRuleContexts<CHCParser::U_pred_atomContext>();
}

CHCParser::U_pred_atomContext* CHCParser::Chc_tailContext::u_pred_atom(size_t i) {
  return getRuleContext<CHCParser::U_pred_atomContext>(i);
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


antlrcpp::Any CHCParser::Chc_tailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_tail(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_tailContext* CHCParser::chc_tail() {
  Chc_tailContext *_localctx = _tracker.createInstance<Chc_tailContext>(_ctx, getState());
  enterRule(_localctx, 10, CHCParser::RuleChc_tail);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(119);
      i_formula();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
      match(CHCParser::LPAR);
      setState(121);
      match(CHCParser::AND);
      setState(123); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(122);
                u_pred_atom();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(125); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CHCParser::LPAR

      || _la == CHCParser::ID) {
        setState(127);
        i_formula();
        setState(132);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(133);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(135);
      u_pred_atom();
      break;
    }

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


antlrcpp::Any CHCParser::Chc_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_head(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_headContext* CHCParser::chc_head() {
  Chc_headContext *_localctx = _tracker.createInstance<Chc_headContext>(_ctx, getState());
  enterRule(_localctx, 12, CHCParser::RuleChc_head);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
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


antlrcpp::Any CHCParser::Chc_queryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitChc_query(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Chc_queryContext* CHCParser::chc_query() {
  Chc_queryContext *_localctx = _tracker.createInstance<Chc_queryContext>(_ctx, getState());
  enterRule(_localctx, 14, CHCParser::RuleChc_query);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(CHCParser::LPAR);
    setState(141);
    match(CHCParser::FORALL);
    setState(142);
    match(CHCParser::LPAR);
    setState(144); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(143);
      var_decl();
      setState(146); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(148);
    match(CHCParser::RPAR);
    setState(149);
    match(CHCParser::LPAR);
    setState(150);
    match(CHCParser::IMPLIES);
    setState(151);
    chc_tail();
    setState(152);
    match(CHCParser::FALSE);
    setState(153);
    match(CHCParser::RPAR);
    setState(154);
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


antlrcpp::Any CHCParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::Var_declContext* CHCParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 16, CHCParser::RuleVar_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(CHCParser::LPAR);
    setState(157);
    var();
    setState(158);
    sort();
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


antlrcpp::Any CHCParser::U_pred_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitU_pred_atom(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::U_pred_atomContext* CHCParser::u_pred_atom() {
  U_pred_atomContext *_localctx = _tracker.createInstance<U_pred_atomContext>(_ctx, getState());
  enterRule(_localctx, 18, CHCParser::RuleU_pred_atom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CHCParser::LPAR: {
        enterOuterAlt(_localctx, 1);
        setState(161);
        match(CHCParser::LPAR);
        setState(162);
        symbol();
        setState(166);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CHCParser::ID) {
          setState(163);
          var();
          setState(168);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(169);
        match(CHCParser::RPAR);
        break;
      }

      case CHCParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(171);
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


antlrcpp::Any CHCParser::LetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitLet(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::LetContext* CHCParser::let() {
  LetContext *_localctx = _tracker.createInstance<LetContext>(_ctx, getState());
  enterRule(_localctx, 20, CHCParser::RuleLet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(CHCParser::LPAR);
    setState(175);
    var();
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(176);
      i_formula();
      break;
    }

    case 2: {
      setState(177);
      expr();
      break;
    }

    }
    setState(180);
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


antlrcpp::Any CHCParser::LetsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitLets(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::LetsContext* CHCParser::lets() {
  LetsContext *_localctx = _tracker.createInstance<LetsContext>(_ctx, getState());
  enterRule(_localctx, 22, CHCParser::RuleLets);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(CHCParser::LET);
    setState(183);
    match(CHCParser::LPAR);
    setState(185); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(184);
      let();
      setState(187); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CHCParser::LPAR);
    setState(189);
    match(CHCParser::RPAR);
   
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

CHCParser::BoolopContext* CHCParser::I_formulaContext::boolop() {
  return getRuleContext<CHCParser::BoolopContext>(0);
}

tree::TerminalNode* CHCParser::I_formulaContext::ITE() {
  return getToken(CHCParser::ITE, 0);
}

CHCParser::LitContext* CHCParser::I_formulaContext::lit() {
  return getRuleContext<CHCParser::LitContext>(0);
}

CHCParser::LetsContext* CHCParser::I_formulaContext::lets() {
  return getRuleContext<CHCParser::LetsContext>(0);
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


antlrcpp::Any CHCParser::I_formulaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitI_formula(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::I_formulaContext* CHCParser::i_formula() {
  I_formulaContext *_localctx = _tracker.createInstance<I_formulaContext>(_ctx, getState());
  enterRule(_localctx, 24, CHCParser::RuleI_formula);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(191);
      match(CHCParser::LPAR);
      setState(192);
      match(CHCParser::NOT);
      setState(193);
      i_formula();
      setState(194);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(196);
      match(CHCParser::LPAR);
      setState(197);
      boolop();
      setState(199); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(198);
        i_formula();
        setState(201); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == CHCParser::LPAR

      || _la == CHCParser::ID);
      setState(203);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(205);
      match(CHCParser::LPAR);
      setState(206);
      match(CHCParser::ITE);
      setState(207);
      i_formula();
      setState(208);
      i_formula();
      setState(209);
      i_formula();
      setState(210);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(212);
      lit();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(213);
      match(CHCParser::LPAR);
      setState(214);
      lets();
      setState(215);
      i_formula();
      setState(216);
      match(CHCParser::RPAR);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(218);
      match(CHCParser::LPAR);
      setState(219);
      i_formula();
      setState(220);
      match(CHCParser::RPAR);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(222);
      var();
      break;
    }

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


antlrcpp::Any CHCParser::BoolopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitBoolop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::BoolopContext* CHCParser::boolop() {
  BoolopContext *_localctx = _tracker.createInstance<BoolopContext>(_ctx, getState());
  enterRule(_localctx, 26, CHCParser::RuleBoolop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CHCParser::AND)
      | (1ULL << CHCParser::OR)
      | (1ULL << CHCParser::EQ))) != 0))) {
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

CHCParser::RelopContext* CHCParser::LitContext::relop() {
  return getRuleContext<CHCParser::RelopContext>(0);
}

std::vector<CHCParser::ExprContext *> CHCParser::LitContext::expr() {
  return getRuleContexts<CHCParser::ExprContext>();
}

CHCParser::ExprContext* CHCParser::LitContext::expr(size_t i) {
  return getRuleContext<CHCParser::ExprContext>(i);
}

tree::TerminalNode* CHCParser::LitContext::RPAR() {
  return getToken(CHCParser::RPAR, 0);
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


antlrcpp::Any CHCParser::LitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitLit(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::LitContext* CHCParser::lit() {
  LitContext *_localctx = _tracker.createInstance<LitContext>(_ctx, getState());
  enterRule(_localctx, 28, CHCParser::RuleLit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(CHCParser::LPAR);
    setState(228);
    relop();
    setState(229);
    expr();
    setState(230);
    expr();
    setState(231);
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


antlrcpp::Any CHCParser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::RelopContext* CHCParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 30, CHCParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CHCParser::LT)
      | (1ULL << CHCParser::LEQ)
      | (1ULL << CHCParser::EQ)
      | (1ULL << CHCParser::NEQ)
      | (1ULL << CHCParser::GEQ)
      | (1ULL << CHCParser::GT))) != 0))) {
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


antlrcpp::Any CHCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::ExprContext* CHCParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 32, CHCParser::RuleExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(235);
      match(CHCParser::LPAR);
      setState(236);
      unaryop();
      setState(237);
      expr();
      setState(238);
      match(CHCParser::RPAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(240);
      match(CHCParser::LPAR);
      setState(241);
      binaryop();
      setState(242);
      expr();
      setState(243);
      expr();
      setState(244);
      match(CHCParser::RPAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(246);
      match(CHCParser::LPAR);
      setState(247);
      naryop();
      setState(249); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(248);
        expr();
        setState(251); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CHCParser::LPAR)
        | (1ULL << CHCParser::ID)
        | (1ULL << CHCParser::INT))) != 0));
      setState(253);
      match(CHCParser::RPAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(255);
      match(CHCParser::LPAR);
      setState(256);
      match(CHCParser::ITE);
      setState(257);
      i_formula();
      setState(258);
      expr();
      setState(259);
      expr();
      setState(260);
      match(CHCParser::RPAR);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(262);
      var();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(263);
      match(CHCParser::INT);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(264);
      match(CHCParser::LPAR);
      setState(265);
      expr();
      setState(266);
      match(CHCParser::RPAR);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(268);
      match(CHCParser::LPAR);
      setState(269);
      lets();
      setState(270);
      expr();
      setState(271);
      match(CHCParser::RPAR);
      break;
    }

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


antlrcpp::Any CHCParser::UnaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitUnaryop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::UnaryopContext* CHCParser::unaryop() {
  UnaryopContext *_localctx = _tracker.createInstance<UnaryopContext>(_ctx, getState());
  enterRule(_localctx, 34, CHCParser::RuleUnaryop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
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


antlrcpp::Any CHCParser::BinaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitBinaryop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::BinaryopContext* CHCParser::binaryop() {
  BinaryopContext *_localctx = _tracker.createInstance<BinaryopContext>(_ctx, getState());
  enterRule(_localctx, 36, CHCParser::RuleBinaryop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CHCParser::MINUS)
      | (1ULL << CHCParser::MOD)
      | (1ULL << CHCParser::DIV))) != 0))) {
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


antlrcpp::Any CHCParser::NaryopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitNaryop(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::NaryopContext* CHCParser::naryop() {
  NaryopContext *_localctx = _tracker.createInstance<NaryopContext>(_ctx, getState());
  enterRule(_localctx, 38, CHCParser::RuleNaryop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
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


antlrcpp::Any CHCParser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::SymbolContext* CHCParser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 40, CHCParser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
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

tree::TerminalNode* CHCParser::SortContext::ID() {
  return getToken(CHCParser::ID, 0);
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


antlrcpp::Any CHCParser::SortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitSort(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::SortContext* CHCParser::sort() {
  SortContext *_localctx = _tracker.createInstance<SortContext>(_ctx, getState());
  enterRule(_localctx, 42, CHCParser::RuleSort);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(CHCParser::ID);
   
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


antlrcpp::Any CHCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CHCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

CHCParser::VarContext* CHCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 44, CHCParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    match(CHCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> CHCParser::_decisionToDFA;
atn::PredictionContextCache CHCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CHCParser::_atn;
std::vector<uint16_t> CHCParser::_serializedATN;

std::vector<std::string> CHCParser::_ruleNames = {
  "main", "fun_decl", "chc_assert", "chc_assert_head", "chc_assert_body", 
  "chc_tail", "chc_head", "chc_query", "var_decl", "u_pred_atom", "let", 
  "lets", "i_formula", "boolop", "lit", "relop", "expr", "unaryop", "binaryop", 
  "naryop", "symbol", "sort", "var"
};

std::vector<std::string> CHCParser::_literalNames = {
  "", "'set-logic HORN'", "'assert'", "'check-sat'", "'exit'", "'declare-fun'", 
  "'Bool'", "'forall'", "'let'", "'=>'", "'false'", "'+'", "'-'", "'*'", 
  "'mod'", "'div'", "'('", "')'", "'and'", "'or'", "'not'", "'ite'", "'<'", 
  "'<='", "'='", "'!='", "'>='", "'>'"
};

std::vector<std::string> CHCParser::_symbolicNames = {
  "", "LOGIC", "ASSERT", "CHECK_SAT", "EXIT", "DECLARE_FUN", "BOOL", "FORALL", 
  "LET", "IMPLIES", "FALSE", "PLUS", "MINUS", "TIMES", "MOD", "DIV", "LPAR", 
  "RPAR", "AND", "OR", "NOT", "ITE", "LT", "LEQ", "EQ", "NEQ", "GEQ", "GT", 
  "ID", "INT", "WS", "COMMENT", "OTHER"
};

dfa::Vocabulary CHCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CHCParser::_tokenNames;

CHCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x22, 0x122, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x35, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x36, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x7, 0x2, 0x3e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x41, 0xb, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x48, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x4b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x53, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x5a, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x5d, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x6, 0x5, 0x6b, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x6c, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x78, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 
    0x7, 0x7e, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x7f, 0x3, 0x7, 0x7, 0x7, 0x83, 
    0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x86, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x8b, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x93, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x94, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xa7, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xaa, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xaf, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb5, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x6, 0xd, 0xbc, 0xa, 0xd, 0xd, 
    0xd, 0xe, 0xd, 0xbd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x6, 0xe, 0xca, 0xa, 
    0xe, 0xd, 0xe, 0xe, 0xe, 0xcb, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xe2, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x6, 0x12, 0xfc, 0xa, 0x12, 0xd, 0x12, 0xe, 0x12, 
    0xfd, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0x114, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x2, 0x2, 0x19, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x2, 0x6, 0x4, 0x2, 
    0x14, 0x15, 0x1a, 0x1a, 0x3, 0x2, 0x18, 0x1d, 0x4, 0x2, 0xe, 0xe, 0x10, 
    0x11, 0x4, 0x2, 0xd, 0xd, 0xf, 0xf, 0x2, 0x129, 0x2, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x54, 0x3, 0x2, 0x2, 0x2, 0x6, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x67, 0x3, 0x2, 0x2, 0x2, 0xa, 0x77, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x8e, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x14, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb8, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x24, 0x115, 0x3, 0x2, 0x2, 0x2, 0x26, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x119, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x11b, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x7, 0x12, 0x2, 0x2, 0x31, 0x32, 0x7, 0x3, 0x2, 
    0x2, 0x32, 0x34, 0x7, 0x13, 0x2, 0x2, 0x33, 0x35, 0x5, 0x4, 0x3, 0x2, 
    0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x12, 0x2, 0x2, 0x39, 0x3a, 0x7, 
    0x4, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x6, 0x4, 0x2, 0x3b, 0x3c, 0x7, 0x13, 
    0x2, 0x2, 0x3c, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x49, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x12, 0x2, 0x2, 0x43, 0x44, 
    0x7, 0x4, 0x2, 0x2, 0x44, 0x45, 0x5, 0x10, 0x9, 0x2, 0x45, 0x46, 0x7, 
    0x13, 0x2, 0x2, 0x46, 0x48, 0x3, 0x2, 0x2, 0x2, 0x47, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x12, 0x2, 0x2, 0x4d, 
    0x4e, 0x7, 0x5, 0x2, 0x2, 0x4e, 0x52, 0x7, 0x13, 0x2, 0x2, 0x4f, 0x50, 
    0x7, 0x12, 0x2, 0x2, 0x50, 0x51, 0x7, 0x6, 0x2, 0x2, 0x51, 0x53, 0x7, 
    0x13, 0x2, 0x2, 0x52, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x3, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x12, 0x2, 
    0x2, 0x55, 0x56, 0x7, 0x7, 0x2, 0x2, 0x56, 0x57, 0x5, 0x2a, 0x16, 0x2, 
    0x57, 0x5b, 0x7, 0x12, 0x2, 0x2, 0x58, 0x5a, 0x5, 0x2c, 0x17, 0x2, 0x59, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x13, 
    0x2, 0x2, 0x5f, 0x60, 0x7, 0x8, 0x2, 0x2, 0x60, 0x61, 0x7, 0x13, 0x2, 
    0x2, 0x61, 0x5, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x12, 0x2, 0x2, 
    0x63, 0x64, 0x5, 0x8, 0x5, 0x2, 0x64, 0x65, 0x5, 0xa, 0x6, 0x2, 0x65, 
    0x66, 0x7, 0x13, 0x2, 0x2, 0x66, 0x7, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x7, 0x9, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x12, 0x2, 0x2, 0x69, 0x6b, 0x5, 
    0x12, 0xa, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x13, 0x2, 0x2, 
    0x6f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x12, 0x2, 0x2, 0x71, 
    0x72, 0x7, 0xb, 0x2, 0x2, 0x72, 0x73, 0x5, 0xc, 0x7, 0x2, 0x73, 0x74, 
    0x5, 0xe, 0x8, 0x2, 0x74, 0x75, 0x7, 0x13, 0x2, 0x2, 0x75, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x78, 0x5, 0xe, 0x8, 0x2, 0x77, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x8b, 0x5, 0x1a, 0xe, 0x2, 0x7a, 0x7b, 0x7, 0x12, 0x2, 0x2, 
    0x7b, 0x7d, 0x7, 0x14, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x14, 0xb, 0x2, 0x7d, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x83, 0x5, 0x1a, 0xe, 0x2, 0x82, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x13, 0x2, 0x2, 0x88, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x5, 0x14, 0xb, 0x2, 0x8a, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x14, 
    0xb, 0x2, 0x8d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x12, 0x2, 
    0x2, 0x8f, 0x90, 0x7, 0x9, 0x2, 0x2, 0x90, 0x92, 0x7, 0x12, 0x2, 0x2, 
    0x91, 0x93, 0x5, 0x12, 0xa, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 
    0x13, 0x2, 0x2, 0x97, 0x98, 0x7, 0x12, 0x2, 0x2, 0x98, 0x99, 0x7, 0xb, 
    0x2, 0x2, 0x99, 0x9a, 0x5, 0xc, 0x7, 0x2, 0x9a, 0x9b, 0x7, 0xc, 0x2, 
    0x2, 0x9b, 0x9c, 0x7, 0x13, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x13, 0x2, 0x2, 
    0x9d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x12, 0x2, 0x2, 0x9f, 
    0xa0, 0x5, 0x2e, 0x18, 0x2, 0xa0, 0xa1, 0x5, 0x2c, 0x17, 0x2, 0xa1, 
    0xa2, 0x7, 0x13, 0x2, 0x2, 0xa2, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 
    0x7, 0x12, 0x2, 0x2, 0xa4, 0xa8, 0x5, 0x2a, 0x16, 0x2, 0xa5, 0xa7, 0x5, 
    0x2e, 0x18, 0x2, 0xa6, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0xa9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x7, 0x13, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xaf, 0x5, 0x2a, 0x16, 0x2, 0xae, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xae, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 
    0x12, 0x2, 0x2, 0xb1, 0xb4, 0x5, 0x2e, 0x18, 0x2, 0xb2, 0xb5, 0x5, 0x1a, 
    0xe, 0x2, 0xb3, 0xb5, 0x5, 0x22, 0x12, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb7, 0x7, 0x13, 0x2, 0x2, 0xb7, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xb9, 0x7, 0xa, 0x2, 0x2, 0xb9, 0xbb, 0x7, 0x12, 0x2, 0x2, 0xba, 0xbc, 
    0x5, 0x16, 0xc, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x13, 0x2, 
    0x2, 0xc0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x12, 0x2, 0x2, 
    0xc2, 0xc3, 0x7, 0x16, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x1a, 0xe, 0x2, 0xc4, 
    0xc5, 0x7, 0x13, 0x2, 0x2, 0xc5, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 
    0x7, 0x12, 0x2, 0x2, 0xc7, 0xc9, 0x5, 0x1c, 0xf, 0x2, 0xc8, 0xca, 0x5, 
    0x1a, 0xe, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x13, 0x2, 0x2, 
    0xce, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x12, 0x2, 0x2, 0xd0, 
    0xd1, 0x7, 0x17, 0x2, 0x2, 0xd1, 0xd2, 0x5, 0x1a, 0xe, 0x2, 0xd2, 0xd3, 
    0x5, 0x1a, 0xe, 0x2, 0xd3, 0xd4, 0x5, 0x1a, 0xe, 0x2, 0xd4, 0xd5, 0x7, 
    0x13, 0x2, 0x2, 0xd5, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xe2, 0x5, 0x1e, 
    0x10, 0x2, 0xd7, 0xd8, 0x7, 0x12, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x18, 0xd, 
    0x2, 0xd9, 0xda, 0x5, 0x1a, 0xe, 0x2, 0xda, 0xdb, 0x7, 0x13, 0x2, 0x2, 
    0xdb, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x12, 0x2, 0x2, 0xdd, 
    0xde, 0x5, 0x1a, 0xe, 0x2, 0xde, 0xdf, 0x7, 0x13, 0x2, 0x2, 0xdf, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x5, 0x2e, 0x18, 0x2, 0xe1, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xe1, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x9, 0x2, 0x2, 0x2, 0xe4, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x12, 0x2, 0x2, 0xe6, 0xe7, 
    0x5, 0x20, 0x11, 0x2, 0xe7, 0xe8, 0x5, 0x22, 0x12, 0x2, 0xe8, 0xe9, 
    0x5, 0x22, 0x12, 0x2, 0xe9, 0xea, 0x7, 0x13, 0x2, 0x2, 0xea, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xec, 0x9, 0x3, 0x2, 0x2, 0xec, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xee, 0x7, 0x12, 0x2, 0x2, 0xee, 0xef, 0x5, 0x24, 0x13, 
    0x2, 0xef, 0xf0, 0x5, 0x22, 0x12, 0x2, 0xf0, 0xf1, 0x7, 0x13, 0x2, 0x2, 
    0xf1, 0x114, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0x12, 0x2, 0x2, 0xf3, 
    0xf4, 0x5, 0x26, 0x14, 0x2, 0xf4, 0xf5, 0x5, 0x22, 0x12, 0x2, 0xf5, 
    0xf6, 0x5, 0x22, 0x12, 0x2, 0xf6, 0xf7, 0x7, 0x13, 0x2, 0x2, 0xf7, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x12, 0x2, 0x2, 0xf9, 0xfb, 0x5, 
    0x28, 0x15, 0x2, 0xfa, 0xfc, 0x5, 0x22, 0x12, 0x2, 0xfb, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 
    0x2, 0xff, 0x100, 0x7, 0x13, 0x2, 0x2, 0x100, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0x102, 0x7, 0x12, 0x2, 0x2, 0x102, 0x103, 0x7, 0x17, 0x2, 
    0x2, 0x103, 0x104, 0x5, 0x1a, 0xe, 0x2, 0x104, 0x105, 0x5, 0x22, 0x12, 
    0x2, 0x105, 0x106, 0x5, 0x22, 0x12, 0x2, 0x106, 0x107, 0x7, 0x13, 0x2, 
    0x2, 0x107, 0x114, 0x3, 0x2, 0x2, 0x2, 0x108, 0x114, 0x5, 0x2e, 0x18, 
    0x2, 0x109, 0x114, 0x7, 0x1f, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x12, 0x2, 
    0x2, 0x10b, 0x10c, 0x5, 0x22, 0x12, 0x2, 0x10c, 0x10d, 0x7, 0x13, 0x2, 
    0x2, 0x10d, 0x114, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x12, 0x2, 
    0x2, 0x10f, 0x110, 0x5, 0x18, 0xd, 0x2, 0x110, 0x111, 0x5, 0x22, 0x12, 
    0x2, 0x111, 0x112, 0x7, 0x13, 0x2, 0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0xed, 0x3, 0x2, 0x2, 0x2, 0x113, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x113, 0x101, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x113, 0x109, 0x3, 0x2, 0x2, 0x2, 0x113, 
    0x10a, 0x3, 0x2, 0x2, 0x2, 0x113, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x7, 0xe, 0x2, 0x2, 0x116, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x9, 0x4, 0x2, 0x2, 0x118, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x119, 0x11a, 0x9, 0x5, 0x2, 0x2, 0x11a, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x11c, 0x7, 0x1e, 0x2, 0x2, 0x11c, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x11d, 0x11e, 0x7, 0x1e, 0x2, 0x2, 0x11e, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x11f, 0x120, 0x7, 0x1e, 0x2, 0x2, 0x120, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x15, 0x36, 0x3f, 0x49, 0x52, 0x5b, 0x6c, 0x77, 0x7f, 0x84, 
    0x8a, 0x94, 0xa8, 0xae, 0xb4, 0xbd, 0xcb, 0xe1, 0xfd, 0x113, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CHCParser::Initializer CHCParser::_init;
