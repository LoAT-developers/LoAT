
// Generated from CINT.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "CINTParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CINTParser.
 */
class  CINTVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CINTParser.
   */
    virtual std::any visitNondet(CINTParser::NondetContext *context) = 0;

    virtual std::any visitNum_expr(CINTParser::Num_exprContext *context) = 0;

    virtual std::any visitBool_expr(CINTParser::Bool_exprContext *context) = 0;

    virtual std::any visitLit(CINTParser::LitContext *context) = 0;

    virtual std::any visitRelop(CINTParser::RelopContext *context) = 0;

    virtual std::any visitLoop(CINTParser::LoopContext *context) = 0;

    virtual std::any visitCondition(CINTParser::ConditionContext *context) = 0;

    virtual std::any visitThen(CINTParser::ThenContext *context) = 0;

    virtual std::any visitElse(CINTParser::ElseContext *context) = 0;

    virtual std::any visitAssignment(CINTParser::AssignmentContext *context) = 0;

    virtual std::any visitInstruction(CINTParser::InstructionContext *context) = 0;

    virtual std::any visitDeclaration(CINTParser::DeclarationContext *context) = 0;

    virtual std::any visitDeclarations(CINTParser::DeclarationsContext *context) = 0;

    virtual std::any visitInstructions(CINTParser::InstructionsContext *context) = 0;

    virtual std::any visitPre(CINTParser::PreContext *context) = 0;

    virtual std::any visitPost(CINTParser::PostContext *context) = 0;

    virtual std::any visitMain(CINTParser::MainContext *context) = 0;


};

