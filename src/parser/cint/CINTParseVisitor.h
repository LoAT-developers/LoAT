#include "CINTVisitor.h"
#include "numvar.hpp"
#include "itsproblem.hpp"

#include <map>

class  CINTParseVisitor : public CINTVisitor {

private:

    std::map<std::string, NumVar> vars;
    ITSProblem its;
    LocationIdx current;

public:

    CINTParseVisitor();

    virtual std::any visitNondet(CINTParser::NondetContext *ctx) override;
    virtual std::any visitNum_atom(CINTParser::Num_atomContext *ctx) override;
    virtual std::any visitPm_mult_expr(CINTParser::Pm_mult_exprContext *ctx) override;
    virtual std::any visitMult_expr(CINTParser::Mult_exprContext *ctx) override;
    virtual std::any visitNum_expr(CINTParser::Num_exprContext *ctx) override;
    virtual std::any visitBool_atom(CINTParser::Bool_atomContext *ctx) override;
    virtual std::any visitAnd_expr(CINTParser::And_exprContext *ctx) override;
    virtual std::any visitBool_expr(CINTParser::Bool_exprContext *ctx) override;
    virtual std::any visitLoop(CINTParser::LoopContext *ctx) override;
    virtual std::any visitCondition(CINTParser::ConditionContext *ctx) override;
    virtual std::any visitAssignment(CINTParser::AssignmentContext *ctx) override;
    virtual std::any visitInstruction(CINTParser::InstructionContext *ctx) override;
    virtual std::any visitDeclaration(CINTParser::DeclarationContext *ctx) override;
    virtual std::any visitDeclarations(CINTParser::DeclarationsContext *ctx) override;
    virtual std::any visitInstructions(CINTParser::InstructionsContext *ctx) override;
    virtual std::any visitPre(CINTParser::PreContext *ctx) override;
    virtual std::any visitPost(CINTParser::PostContext *ctx) override;
    virtual std::any visitMain(CINTParser::MainContext *ctx) override;

};

