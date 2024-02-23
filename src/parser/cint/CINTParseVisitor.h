#include "CINTVisitor.h"
#include "itsproblem.hpp"

class  CINTParseVisitor : public CINTVisitor {

private:

    std::unordered_map<std::string, IntTheory::Var> vars {};
    ITSPtr its {std::make_shared<ITSProblem>()};
    LocationIdx current {};

public:

    CINTParseVisitor();

    virtual std::any visitNondet(CINTParser::NondetContext *ctx) override;
    virtual std::any visitNum_expr(CINTParser::Num_exprContext*ctx) override;
    virtual std::any visitBool_expr(CINTParser::Bool_exprContext *ctx) override;
    virtual std::any visitLit(CINTParser::LitContext *ctx) override;
    virtual std::any visitRelop(CINTParser::RelopContext *ctx) override;
    virtual std::any visitLoop(CINTParser::LoopContext *ctx) override;
    virtual std::any visitCondition(CINTParser::ConditionContext *ctx) override;
    virtual std::any visitThen(CINTParser::ThenContext *ctx) override;
    virtual std::any visitElse(CINTParser::ElseContext *ctx) override;
    virtual std::any visitAssignment(CINTParser::AssignmentContext *ctx) override;
    virtual std::any visitInstruction(CINTParser::InstructionContext *ctx) override;
    virtual std::any visitDeclaration(CINTParser::DeclarationContext *ctx) override;
    virtual std::any visitDeclarations(CINTParser::DeclarationsContext *ctx) override;
    virtual std::any visitInstructions(CINTParser::InstructionsContext *ctx) override;
    virtual std::any visitPre(CINTParser::PreContext *ctx) override;
    virtual std::any visitPost(CINTParser::PostContext *ctx) override;
    virtual std::any visitMain(CINTParser::MainContext *ctx) override;

};

