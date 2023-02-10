#include "cintparser.hpp"
#include "CINTLexer.h"
#include "CINTParser.h"
#include "CINTParseVisitor.h"

using namespace antlr4;

using namespace cintParser;

ITSProblem CIntParser::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Unable to open file: " + filename);
    }
    ANTLRInputStream input(file);
    CINTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CINTParser parser(&tokens);
    parser.setBuildParseTree(true);
    CINTParseVisitor vis;
    auto ctx = parser.main();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        throw std::invalid_argument("parsing failed");
    } else {
        return any_cast<ITSProblem>(vis.visit(ctx));
    }
}
