
// Generated from CINT.g4 by ANTLR 4.11.1


#include "CINTListener.h"
#include "CINTVisitor.h"

#include "CINTParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CINTParserStaticData final {
  CINTParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CINTParserStaticData(const CINTParserStaticData&) = delete;
  CINTParserStaticData(CINTParserStaticData&&) = delete;
  CINTParserStaticData& operator=(const CINTParserStaticData&) = delete;
  CINTParserStaticData& operator=(CINTParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag cintParserOnceFlag;
CINTParserStaticData *cintParserStaticData = nullptr;

void cintParserInitialize() {
  assert(cintParserStaticData == nullptr);
  auto staticData = std::make_unique<CINTParserStaticData>(
    std::vector<std::string>{
      "nondet", "num_atom", "mult_expr", "pm_mult_expr", "num_expr", "bool_atom", 
      "and_expr", "bool_expr", "loop", "condition", "assignment", "instruction", 
      "declaration", "declarations", "instructions", "pre", "post", "main"
    },
    std::vector<std::string>{
      "", "'int'", "'if'", "'while'", "'else'", "';'", "'('", "')'", "'{'", 
      "'}'", "'*'", "'-'", "'+'", "", "'='", "'__VERIFIER_nondet_int'", 
      "'||'", "'&&'", "'!'", "'true'", "'false'", "'typedef'", "'enum'", 
      "','", "'bool'", "'extern'", "'void'", "'main'", "'return'", "'0'"
    },
    std::vector<std::string>{
      "", "INT", "IF", "WHILE", "ELSE", "TERMINATOR", "OPENP", "CLOSEP", 
      "OPENC", "CLOSEC", "MULT", "MINUS", "PLUS", "BO", "ASSIGN", "NONDETNAME", 
      "OR", "AND", "NOT", "TRUE", "FALSE", "TYPEDEF", "ENUM", "COMMA", "BOOL", 
      "EXTERN", "VOID", "MAIN", "RETURN", "ZERO", "POS", "V", "W", "BLOCKCOMMENT", 
      "LINECOMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,34,607,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,1,0,1,0,5,0,39,8,0,10,0,12,0,42,9,0,
  	1,0,1,0,5,0,46,8,0,10,0,12,0,49,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,59,8,1,10,1,12,1,62,9,1,1,1,1,1,5,1,66,8,1,10,1,12,1,69,9,1,1,1,1,1,
  	3,1,73,8,1,1,2,1,2,5,2,77,8,2,10,2,12,2,80,9,2,1,2,1,2,5,2,84,8,2,10,
  	2,12,2,87,9,2,1,2,5,2,90,8,2,10,2,12,2,93,9,2,1,3,5,3,96,8,3,10,3,12,
  	3,99,9,3,1,3,1,3,5,3,103,8,3,10,3,12,3,106,9,3,1,3,1,3,1,4,1,4,5,4,112,
  	8,4,10,4,12,4,115,9,4,1,4,1,4,5,4,119,8,4,10,4,12,4,122,9,4,1,4,1,4,5,
  	4,126,8,4,10,4,12,4,129,9,4,3,4,131,8,4,1,5,1,5,1,5,1,5,5,5,137,8,5,10,
  	5,12,5,140,9,5,1,5,1,5,5,5,144,8,5,10,5,12,5,147,9,5,1,5,3,5,150,8,5,
  	3,5,152,8,5,1,6,1,6,5,6,156,8,6,10,6,12,6,159,9,6,1,6,1,6,5,6,163,8,6,
  	10,6,12,6,166,9,6,1,6,5,6,169,8,6,10,6,12,6,172,9,6,1,7,1,7,5,7,176,8,
  	7,10,7,12,7,179,9,7,1,7,1,7,5,7,183,8,7,10,7,12,7,186,9,7,1,7,5,7,189,
  	8,7,10,7,12,7,192,9,7,1,7,1,7,5,7,196,8,7,10,7,12,7,199,9,7,1,7,3,7,202,
  	8,7,1,8,1,8,5,8,206,8,8,10,8,12,8,209,9,8,1,8,1,8,5,8,213,8,8,10,8,12,
  	8,216,9,8,1,8,1,8,5,8,220,8,8,10,8,12,8,223,9,8,1,8,1,8,5,8,227,8,8,10,
  	8,12,8,230,9,8,1,8,1,8,5,8,234,8,8,10,8,12,8,237,9,8,1,8,1,8,5,8,241,
  	8,8,10,8,12,8,244,9,8,3,8,246,8,8,1,8,1,8,1,9,1,9,5,9,252,8,9,10,9,12,
  	9,255,9,9,1,9,1,9,5,9,259,8,9,10,9,12,9,262,9,9,1,9,1,9,5,9,266,8,9,10,
  	9,12,9,269,9,9,1,9,1,9,5,9,273,8,9,10,9,12,9,276,9,9,1,9,1,9,5,9,280,
  	8,9,10,9,12,9,283,9,9,1,9,1,9,5,9,287,8,9,10,9,12,9,290,9,9,3,9,292,8,
  	9,1,9,1,9,5,9,296,8,9,10,9,12,9,299,9,9,1,9,1,9,5,9,303,8,9,10,9,12,9,
  	306,9,9,1,9,1,9,5,9,310,8,9,10,9,12,9,313,9,9,1,9,1,9,5,9,317,8,9,10,
  	9,12,9,320,9,9,3,9,322,8,9,1,9,3,9,325,8,9,1,10,1,10,5,10,329,8,10,10,
  	10,12,10,332,9,10,1,10,1,10,5,10,336,8,10,10,10,12,10,339,9,10,1,10,1,
  	10,5,10,343,8,10,10,10,12,10,346,9,10,1,10,1,10,1,11,1,11,1,11,3,11,353,
  	8,11,1,12,1,12,4,12,357,8,12,11,12,12,12,358,1,12,1,12,5,12,363,8,12,
  	10,12,12,12,366,9,12,1,12,1,12,5,12,370,8,12,10,12,12,12,373,9,12,1,12,
  	5,12,376,8,12,10,12,12,12,379,9,12,1,12,5,12,382,8,12,10,12,12,12,385,
  	9,12,1,12,1,12,1,13,1,13,5,13,391,8,13,10,13,12,13,394,9,13,1,13,3,13,
  	397,8,13,1,14,1,14,5,14,401,8,14,10,14,12,14,404,9,14,1,14,3,14,407,8,
  	14,1,15,5,15,410,8,15,10,15,12,15,413,9,15,1,15,1,15,4,15,417,8,15,11,
  	15,12,15,418,1,15,1,15,5,15,423,8,15,10,15,12,15,426,9,15,1,15,1,15,5,
  	15,430,8,15,10,15,12,15,433,9,15,1,15,1,15,5,15,437,8,15,10,15,12,15,
  	440,9,15,1,15,1,15,5,15,444,8,15,10,15,12,15,447,9,15,1,15,1,15,5,15,
  	451,8,15,10,15,12,15,454,9,15,1,15,1,15,5,15,458,8,15,10,15,12,15,461,
  	9,15,1,15,1,15,5,15,465,8,15,10,15,12,15,468,9,15,1,15,1,15,5,15,472,
  	8,15,10,15,12,15,475,9,15,1,15,1,15,4,15,479,8,15,11,15,12,15,480,1,15,
  	1,15,4,15,485,8,15,11,15,12,15,486,1,15,1,15,5,15,491,8,15,10,15,12,15,
  	494,9,15,1,15,1,15,5,15,498,8,15,10,15,12,15,501,9,15,1,15,1,15,5,15,
  	505,8,15,10,15,12,15,508,9,15,1,15,1,15,5,15,512,8,15,10,15,12,15,515,
  	9,15,1,15,1,15,5,15,519,8,15,10,15,12,15,522,9,15,1,15,1,15,4,15,526,
  	8,15,11,15,12,15,527,1,15,1,15,5,15,532,8,15,10,15,12,15,535,9,15,1,15,
  	1,15,5,15,539,8,15,10,15,12,15,542,9,15,1,15,1,15,5,15,546,8,15,10,15,
  	12,15,549,9,15,1,15,1,15,1,16,1,16,4,16,555,8,16,11,16,12,16,556,1,16,
  	1,16,5,16,561,8,16,10,16,12,16,564,9,16,1,16,1,16,5,16,568,8,16,10,16,
  	12,16,571,9,16,1,16,1,16,5,16,575,8,16,10,16,12,16,578,9,16,1,17,1,17,
  	5,17,582,8,17,10,17,12,17,585,9,17,1,17,3,17,588,8,17,1,17,5,17,591,8,
  	17,10,17,12,17,594,9,17,1,17,3,17,597,8,17,1,17,5,17,600,8,17,10,17,12,
  	17,603,9,17,1,17,1,17,1,17,0,0,18,0,2,4,6,8,10,12,14,16,18,20,22,24,26,
  	28,30,32,34,0,1,1,0,11,12,682,0,36,1,0,0,0,2,72,1,0,0,0,4,74,1,0,0,0,
  	6,97,1,0,0,0,8,130,1,0,0,0,10,151,1,0,0,0,12,153,1,0,0,0,14,201,1,0,0,
  	0,16,203,1,0,0,0,18,249,1,0,0,0,20,326,1,0,0,0,22,352,1,0,0,0,24,354,
  	1,0,0,0,26,388,1,0,0,0,28,398,1,0,0,0,30,411,1,0,0,0,32,552,1,0,0,0,34,
  	579,1,0,0,0,36,40,5,15,0,0,37,39,5,32,0,0,38,37,1,0,0,0,39,42,1,0,0,0,
  	40,38,1,0,0,0,40,41,1,0,0,0,41,43,1,0,0,0,42,40,1,0,0,0,43,47,5,6,0,0,
  	44,46,5,32,0,0,45,44,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,
  	0,48,50,1,0,0,0,49,47,1,0,0,0,50,51,5,7,0,0,51,1,1,0,0,0,52,73,5,29,0,
  	0,53,73,5,30,0,0,54,73,3,0,0,0,55,73,5,31,0,0,56,60,5,6,0,0,57,59,5,32,
  	0,0,58,57,1,0,0,0,59,62,1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,61,63,1,0,
  	0,0,62,60,1,0,0,0,63,67,3,14,7,0,64,66,5,32,0,0,65,64,1,0,0,0,66,69,1,
  	0,0,0,67,65,1,0,0,0,67,68,1,0,0,0,68,70,1,0,0,0,69,67,1,0,0,0,70,71,5,
  	7,0,0,71,73,1,0,0,0,72,52,1,0,0,0,72,53,1,0,0,0,72,54,1,0,0,0,72,55,1,
  	0,0,0,72,56,1,0,0,0,73,3,1,0,0,0,74,91,3,2,1,0,75,77,5,32,0,0,76,75,1,
  	0,0,0,77,80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,81,1,0,0,0,80,78,1,
  	0,0,0,81,85,5,10,0,0,82,84,5,32,0,0,83,82,1,0,0,0,84,87,1,0,0,0,85,83,
  	1,0,0,0,85,86,1,0,0,0,86,88,1,0,0,0,87,85,1,0,0,0,88,90,3,2,1,0,89,78,
  	1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,5,1,0,0,0,93,91,
  	1,0,0,0,94,96,5,32,0,0,95,94,1,0,0,0,96,99,1,0,0,0,97,95,1,0,0,0,97,98,
  	1,0,0,0,98,100,1,0,0,0,99,97,1,0,0,0,100,104,7,0,0,0,101,103,5,32,0,0,
  	102,101,1,0,0,0,103,106,1,0,0,0,104,102,1,0,0,0,104,105,1,0,0,0,105,107,
  	1,0,0,0,106,104,1,0,0,0,107,108,3,4,2,0,108,7,1,0,0,0,109,113,3,4,2,0,
  	110,112,3,6,3,0,111,110,1,0,0,0,112,115,1,0,0,0,113,111,1,0,0,0,113,114,
  	1,0,0,0,114,131,1,0,0,0,115,113,1,0,0,0,116,120,5,11,0,0,117,119,5,32,
  	0,0,118,117,1,0,0,0,119,122,1,0,0,0,120,118,1,0,0,0,120,121,1,0,0,0,121,
  	123,1,0,0,0,122,120,1,0,0,0,123,127,3,4,2,0,124,126,3,6,3,0,125,124,1,
  	0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,131,1,0,0,0,
  	129,127,1,0,0,0,130,109,1,0,0,0,130,116,1,0,0,0,131,9,1,0,0,0,132,152,
  	5,19,0,0,133,152,5,20,0,0,134,149,3,8,4,0,135,137,5,32,0,0,136,135,1,
  	0,0,0,137,140,1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,0,139,141,1,0,0,0,
  	140,138,1,0,0,0,141,145,5,13,0,0,142,144,5,32,0,0,143,142,1,0,0,0,144,
  	147,1,0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,148,1,0,0,0,147,145,1,
  	0,0,0,148,150,3,8,4,0,149,138,1,0,0,0,149,150,1,0,0,0,150,152,1,0,0,0,
  	151,132,1,0,0,0,151,133,1,0,0,0,151,134,1,0,0,0,152,11,1,0,0,0,153,170,
  	3,10,5,0,154,156,5,32,0,0,155,154,1,0,0,0,156,159,1,0,0,0,157,155,1,0,
  	0,0,157,158,1,0,0,0,158,160,1,0,0,0,159,157,1,0,0,0,160,164,5,17,0,0,
  	161,163,5,32,0,0,162,161,1,0,0,0,163,166,1,0,0,0,164,162,1,0,0,0,164,
  	165,1,0,0,0,165,167,1,0,0,0,166,164,1,0,0,0,167,169,3,10,5,0,168,157,
  	1,0,0,0,169,172,1,0,0,0,170,168,1,0,0,0,170,171,1,0,0,0,171,13,1,0,0,
  	0,172,170,1,0,0,0,173,190,3,12,6,0,174,176,5,32,0,0,175,174,1,0,0,0,176,
  	179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,
  	0,0,0,180,184,5,16,0,0,181,183,5,32,0,0,182,181,1,0,0,0,183,186,1,0,0,
  	0,184,182,1,0,0,0,184,185,1,0,0,0,185,187,1,0,0,0,186,184,1,0,0,0,187,
  	189,3,12,6,0,188,177,1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,191,
  	1,0,0,0,191,202,1,0,0,0,192,190,1,0,0,0,193,197,5,18,0,0,194,196,5,32,
  	0,0,195,194,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,
  	200,1,0,0,0,199,197,1,0,0,0,200,202,3,10,5,0,201,173,1,0,0,0,201,193,
  	1,0,0,0,202,15,1,0,0,0,203,207,5,3,0,0,204,206,5,32,0,0,205,204,1,0,0,
  	0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,210,1,0,0,0,209,
  	207,1,0,0,0,210,214,5,6,0,0,211,213,5,32,0,0,212,211,1,0,0,0,213,216,
  	1,0,0,0,214,212,1,0,0,0,214,215,1,0,0,0,215,217,1,0,0,0,216,214,1,0,0,
  	0,217,221,3,14,7,0,218,220,5,32,0,0,219,218,1,0,0,0,220,223,1,0,0,0,221,
  	219,1,0,0,0,221,222,1,0,0,0,222,224,1,0,0,0,223,221,1,0,0,0,224,228,5,
  	7,0,0,225,227,5,32,0,0,226,225,1,0,0,0,227,230,1,0,0,0,228,226,1,0,0,
  	0,228,229,1,0,0,0,229,231,1,0,0,0,230,228,1,0,0,0,231,235,5,8,0,0,232,
  	234,5,32,0,0,233,232,1,0,0,0,234,237,1,0,0,0,235,233,1,0,0,0,235,236,
  	1,0,0,0,236,245,1,0,0,0,237,235,1,0,0,0,238,242,3,28,14,0,239,241,5,32,
  	0,0,240,239,1,0,0,0,241,244,1,0,0,0,242,240,1,0,0,0,242,243,1,0,0,0,243,
  	246,1,0,0,0,244,242,1,0,0,0,245,238,1,0,0,0,245,246,1,0,0,0,246,247,1,
  	0,0,0,247,248,5,9,0,0,248,17,1,0,0,0,249,253,5,2,0,0,250,252,5,32,0,0,
  	251,250,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,256,
  	1,0,0,0,255,253,1,0,0,0,256,260,5,6,0,0,257,259,5,32,0,0,258,257,1,0,
  	0,0,259,262,1,0,0,0,260,258,1,0,0,0,260,261,1,0,0,0,261,263,1,0,0,0,262,
  	260,1,0,0,0,263,267,3,14,7,0,264,266,5,32,0,0,265,264,1,0,0,0,266,269,
  	1,0,0,0,267,265,1,0,0,0,267,268,1,0,0,0,268,270,1,0,0,0,269,267,1,0,0,
  	0,270,274,5,7,0,0,271,273,5,32,0,0,272,271,1,0,0,0,273,276,1,0,0,0,274,
  	272,1,0,0,0,274,275,1,0,0,0,275,277,1,0,0,0,276,274,1,0,0,0,277,281,5,
  	8,0,0,278,280,5,32,0,0,279,278,1,0,0,0,280,283,1,0,0,0,281,279,1,0,0,
  	0,281,282,1,0,0,0,282,291,1,0,0,0,283,281,1,0,0,0,284,288,3,28,14,0,285,
  	287,5,32,0,0,286,285,1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,
  	1,0,0,0,289,292,1,0,0,0,290,288,1,0,0,0,291,284,1,0,0,0,291,292,1,0,0,
  	0,292,293,1,0,0,0,293,324,5,9,0,0,294,296,5,32,0,0,295,294,1,0,0,0,296,
  	299,1,0,0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,300,1,0,0,0,299,297,1,
  	0,0,0,300,304,5,4,0,0,301,303,5,32,0,0,302,301,1,0,0,0,303,306,1,0,0,
  	0,304,302,1,0,0,0,304,305,1,0,0,0,305,307,1,0,0,0,306,304,1,0,0,0,307,
  	311,5,8,0,0,308,310,5,32,0,0,309,308,1,0,0,0,310,313,1,0,0,0,311,309,
  	1,0,0,0,311,312,1,0,0,0,312,321,1,0,0,0,313,311,1,0,0,0,314,318,3,28,
  	14,0,315,317,5,32,0,0,316,315,1,0,0,0,317,320,1,0,0,0,318,316,1,0,0,0,
  	318,319,1,0,0,0,319,322,1,0,0,0,320,318,1,0,0,0,321,314,1,0,0,0,321,322,
  	1,0,0,0,322,323,1,0,0,0,323,325,5,9,0,0,324,297,1,0,0,0,324,325,1,0,0,
  	0,325,19,1,0,0,0,326,330,5,31,0,0,327,329,5,32,0,0,328,327,1,0,0,0,329,
  	332,1,0,0,0,330,328,1,0,0,0,330,331,1,0,0,0,331,333,1,0,0,0,332,330,1,
  	0,0,0,333,337,5,14,0,0,334,336,5,32,0,0,335,334,1,0,0,0,336,339,1,0,0,
  	0,337,335,1,0,0,0,337,338,1,0,0,0,338,340,1,0,0,0,339,337,1,0,0,0,340,
  	344,3,8,4,0,341,343,5,32,0,0,342,341,1,0,0,0,343,346,1,0,0,0,344,342,
  	1,0,0,0,344,345,1,0,0,0,345,347,1,0,0,0,346,344,1,0,0,0,347,348,5,5,0,
  	0,348,21,1,0,0,0,349,353,3,16,8,0,350,353,3,18,9,0,351,353,3,20,10,0,
  	352,349,1,0,0,0,352,350,1,0,0,0,352,351,1,0,0,0,353,23,1,0,0,0,354,356,
  	5,1,0,0,355,357,5,32,0,0,356,355,1,0,0,0,357,358,1,0,0,0,358,356,1,0,
  	0,0,358,359,1,0,0,0,359,360,1,0,0,0,360,377,5,31,0,0,361,363,5,32,0,0,
  	362,361,1,0,0,0,363,366,1,0,0,0,364,362,1,0,0,0,364,365,1,0,0,0,365,367,
  	1,0,0,0,366,364,1,0,0,0,367,371,5,23,0,0,368,370,5,32,0,0,369,368,1,0,
  	0,0,370,373,1,0,0,0,371,369,1,0,0,0,371,372,1,0,0,0,372,374,1,0,0,0,373,
  	371,1,0,0,0,374,376,5,31,0,0,375,364,1,0,0,0,376,379,1,0,0,0,377,375,
  	1,0,0,0,377,378,1,0,0,0,378,383,1,0,0,0,379,377,1,0,0,0,380,382,5,32,
  	0,0,381,380,1,0,0,0,382,385,1,0,0,0,383,381,1,0,0,0,383,384,1,0,0,0,384,
  	386,1,0,0,0,385,383,1,0,0,0,386,387,5,5,0,0,387,25,1,0,0,0,388,396,3,
  	24,12,0,389,391,5,32,0,0,390,389,1,0,0,0,391,394,1,0,0,0,392,390,1,0,
  	0,0,392,393,1,0,0,0,393,395,1,0,0,0,394,392,1,0,0,0,395,397,3,26,13,0,
  	396,392,1,0,0,0,396,397,1,0,0,0,397,27,1,0,0,0,398,406,3,22,11,0,399,
  	401,5,32,0,0,400,399,1,0,0,0,401,404,1,0,0,0,402,400,1,0,0,0,402,403,
  	1,0,0,0,403,405,1,0,0,0,404,402,1,0,0,0,405,407,3,28,14,0,406,402,1,0,
  	0,0,406,407,1,0,0,0,407,29,1,0,0,0,408,410,5,32,0,0,409,408,1,0,0,0,410,
  	413,1,0,0,0,411,409,1,0,0,0,411,412,1,0,0,0,412,414,1,0,0,0,413,411,1,
  	0,0,0,414,416,5,21,0,0,415,417,5,32,0,0,416,415,1,0,0,0,417,418,1,0,0,
  	0,418,416,1,0,0,0,418,419,1,0,0,0,419,420,1,0,0,0,420,424,5,22,0,0,421,
  	423,5,32,0,0,422,421,1,0,0,0,423,426,1,0,0,0,424,422,1,0,0,0,424,425,
  	1,0,0,0,425,427,1,0,0,0,426,424,1,0,0,0,427,431,5,8,0,0,428,430,5,32,
  	0,0,429,428,1,0,0,0,430,433,1,0,0,0,431,429,1,0,0,0,431,432,1,0,0,0,432,
  	434,1,0,0,0,433,431,1,0,0,0,434,438,5,20,0,0,435,437,5,32,0,0,436,435,
  	1,0,0,0,437,440,1,0,0,0,438,436,1,0,0,0,438,439,1,0,0,0,439,441,1,0,0,
  	0,440,438,1,0,0,0,441,445,5,23,0,0,442,444,5,32,0,0,443,442,1,0,0,0,444,
  	447,1,0,0,0,445,443,1,0,0,0,445,446,1,0,0,0,446,448,1,0,0,0,447,445,1,
  	0,0,0,448,452,5,19,0,0,449,451,5,32,0,0,450,449,1,0,0,0,451,454,1,0,0,
  	0,452,450,1,0,0,0,452,453,1,0,0,0,453,455,1,0,0,0,454,452,1,0,0,0,455,
  	459,5,9,0,0,456,458,5,32,0,0,457,456,1,0,0,0,458,461,1,0,0,0,459,457,
  	1,0,0,0,459,460,1,0,0,0,460,462,1,0,0,0,461,459,1,0,0,0,462,466,5,24,
  	0,0,463,465,5,32,0,0,464,463,1,0,0,0,465,468,1,0,0,0,466,464,1,0,0,0,
  	466,467,1,0,0,0,467,469,1,0,0,0,468,466,1,0,0,0,469,473,5,5,0,0,470,472,
  	5,32,0,0,471,470,1,0,0,0,472,475,1,0,0,0,473,471,1,0,0,0,473,474,1,0,
  	0,0,474,476,1,0,0,0,475,473,1,0,0,0,476,478,5,25,0,0,477,479,5,32,0,0,
  	478,477,1,0,0,0,479,480,1,0,0,0,480,478,1,0,0,0,480,481,1,0,0,0,481,482,
  	1,0,0,0,482,484,5,1,0,0,483,485,5,32,0,0,484,483,1,0,0,0,485,486,1,0,
  	0,0,486,484,1,0,0,0,486,487,1,0,0,0,487,488,1,0,0,0,488,492,5,15,0,0,
  	489,491,5,32,0,0,490,489,1,0,0,0,491,494,1,0,0,0,492,490,1,0,0,0,492,
  	493,1,0,0,0,493,495,1,0,0,0,494,492,1,0,0,0,495,499,5,6,0,0,496,498,5,
  	32,0,0,497,496,1,0,0,0,498,501,1,0,0,0,499,497,1,0,0,0,499,500,1,0,0,
  	0,500,502,1,0,0,0,501,499,1,0,0,0,502,506,5,26,0,0,503,505,5,32,0,0,504,
  	503,1,0,0,0,505,508,1,0,0,0,506,504,1,0,0,0,506,507,1,0,0,0,507,509,1,
  	0,0,0,508,506,1,0,0,0,509,513,5,7,0,0,510,512,5,32,0,0,511,510,1,0,0,
  	0,512,515,1,0,0,0,513,511,1,0,0,0,513,514,1,0,0,0,514,516,1,0,0,0,515,
  	513,1,0,0,0,516,520,5,5,0,0,517,519,5,32,0,0,518,517,1,0,0,0,519,522,
  	1,0,0,0,520,518,1,0,0,0,520,521,1,0,0,0,521,523,1,0,0,0,522,520,1,0,0,
  	0,523,525,5,1,0,0,524,526,5,32,0,0,525,524,1,0,0,0,526,527,1,0,0,0,527,
  	525,1,0,0,0,527,528,1,0,0,0,528,529,1,0,0,0,529,533,5,27,0,0,530,532,
  	5,32,0,0,531,530,1,0,0,0,532,535,1,0,0,0,533,531,1,0,0,0,533,534,1,0,
  	0,0,534,536,1,0,0,0,535,533,1,0,0,0,536,540,5,6,0,0,537,539,5,32,0,0,
  	538,537,1,0,0,0,539,542,1,0,0,0,540,538,1,0,0,0,540,541,1,0,0,0,541,543,
  	1,0,0,0,542,540,1,0,0,0,543,547,5,7,0,0,544,546,5,32,0,0,545,544,1,0,
  	0,0,546,549,1,0,0,0,547,545,1,0,0,0,547,548,1,0,0,0,548,550,1,0,0,0,549,
  	547,1,0,0,0,550,551,5,8,0,0,551,31,1,0,0,0,552,554,5,28,0,0,553,555,5,
  	32,0,0,554,553,1,0,0,0,555,556,1,0,0,0,556,554,1,0,0,0,556,557,1,0,0,
  	0,557,558,1,0,0,0,558,562,5,29,0,0,559,561,5,32,0,0,560,559,1,0,0,0,561,
  	564,1,0,0,0,562,560,1,0,0,0,562,563,1,0,0,0,563,565,1,0,0,0,564,562,1,
  	0,0,0,565,569,5,5,0,0,566,568,5,32,0,0,567,566,1,0,0,0,568,571,1,0,0,
  	0,569,567,1,0,0,0,569,570,1,0,0,0,570,572,1,0,0,0,571,569,1,0,0,0,572,
  	576,5,9,0,0,573,575,5,32,0,0,574,573,1,0,0,0,575,578,1,0,0,0,576,574,
  	1,0,0,0,576,577,1,0,0,0,577,33,1,0,0,0,578,576,1,0,0,0,579,587,3,30,15,
  	0,580,582,5,32,0,0,581,580,1,0,0,0,582,585,1,0,0,0,583,581,1,0,0,0,583,
  	584,1,0,0,0,584,586,1,0,0,0,585,583,1,0,0,0,586,588,3,26,13,0,587,583,
  	1,0,0,0,587,588,1,0,0,0,588,596,1,0,0,0,589,591,5,32,0,0,590,589,1,0,
  	0,0,591,594,1,0,0,0,592,590,1,0,0,0,592,593,1,0,0,0,593,595,1,0,0,0,594,
  	592,1,0,0,0,595,597,3,28,14,0,596,592,1,0,0,0,596,597,1,0,0,0,597,601,
  	1,0,0,0,598,600,5,32,0,0,599,598,1,0,0,0,600,603,1,0,0,0,601,599,1,0,
  	0,0,601,602,1,0,0,0,602,604,1,0,0,0,603,601,1,0,0,0,604,605,3,32,16,0,
  	605,35,1,0,0,0,89,40,47,60,67,72,78,85,91,97,104,113,120,127,130,138,
  	145,149,151,157,164,170,177,184,190,197,201,207,214,221,228,235,242,245,
  	253,260,267,274,281,288,291,297,304,311,318,321,324,330,337,344,352,358,
  	364,371,377,383,392,396,402,406,411,418,424,431,438,445,452,459,466,473,
  	480,486,492,499,506,513,520,527,533,540,547,556,562,569,576,583,587,592,
  	596,601
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  cintParserStaticData = staticData.release();
}

}

CINTParser::CINTParser(TokenStream *input) : CINTParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CINTParser::CINTParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CINTParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *cintParserStaticData->atn, cintParserStaticData->decisionToDFA, cintParserStaticData->sharedContextCache, options);
}

CINTParser::~CINTParser() {
  delete _interpreter;
}

const atn::ATN& CINTParser::getATN() const {
  return *cintParserStaticData->atn;
}

std::string CINTParser::getGrammarFileName() const {
  return "CINT.g4";
}

const std::vector<std::string>& CINTParser::getRuleNames() const {
  return cintParserStaticData->ruleNames;
}

const dfa::Vocabulary& CINTParser::getVocabulary() const {
  return cintParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CINTParser::getSerializedATN() const {
  return cintParserStaticData->serializedATN;
}


//----------------- NondetContext ------------------------------------------------------------------

CINTParser::NondetContext::NondetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::NondetContext::NONDETNAME() {
  return getToken(CINTParser::NONDETNAME, 0);
}

tree::TerminalNode* CINTParser::NondetContext::OPENP() {
  return getToken(CINTParser::OPENP, 0);
}

tree::TerminalNode* CINTParser::NondetContext::CLOSEP() {
  return getToken(CINTParser::CLOSEP, 0);
}

std::vector<tree::TerminalNode *> CINTParser::NondetContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::NondetContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::NondetContext::getRuleIndex() const {
  return CINTParser::RuleNondet;
}

void CINTParser::NondetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNondet(this);
}

void CINTParser::NondetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNondet(this);
}


std::any CINTParser::NondetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitNondet(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::NondetContext* CINTParser::nondet() {
  NondetContext *_localctx = _tracker.createInstance<NondetContext>(_ctx, getState());
  enterRule(_localctx, 0, CINTParser::RuleNondet);
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
    setState(36);
    match(CINTParser::NONDETNAME);
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(37);
      match(CINTParser::W);
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(43);
    match(CINTParser::OPENP);
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(44);
      match(CINTParser::W);
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(50);
    match(CINTParser::CLOSEP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Num_atomContext ------------------------------------------------------------------

CINTParser::Num_atomContext::Num_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::Num_atomContext::ZERO() {
  return getToken(CINTParser::ZERO, 0);
}

tree::TerminalNode* CINTParser::Num_atomContext::POS() {
  return getToken(CINTParser::POS, 0);
}

CINTParser::NondetContext* CINTParser::Num_atomContext::nondet() {
  return getRuleContext<CINTParser::NondetContext>(0);
}

tree::TerminalNode* CINTParser::Num_atomContext::V() {
  return getToken(CINTParser::V, 0);
}

tree::TerminalNode* CINTParser::Num_atomContext::OPENP() {
  return getToken(CINTParser::OPENP, 0);
}

CINTParser::Bool_exprContext* CINTParser::Num_atomContext::bool_expr() {
  return getRuleContext<CINTParser::Bool_exprContext>(0);
}

tree::TerminalNode* CINTParser::Num_atomContext::CLOSEP() {
  return getToken(CINTParser::CLOSEP, 0);
}

std::vector<tree::TerminalNode *> CINTParser::Num_atomContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::Num_atomContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::Num_atomContext::getRuleIndex() const {
  return CINTParser::RuleNum_atom;
}

void CINTParser::Num_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNum_atom(this);
}

void CINTParser::Num_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNum_atom(this);
}


std::any CINTParser::Num_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitNum_atom(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::Num_atomContext* CINTParser::num_atom() {
  Num_atomContext *_localctx = _tracker.createInstance<Num_atomContext>(_ctx, getState());
  enterRule(_localctx, 2, CINTParser::RuleNum_atom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CINTParser::ZERO: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        match(CINTParser::ZERO);
        break;
      }

      case CINTParser::POS: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        match(CINTParser::POS);
        break;
      }

      case CINTParser::NONDETNAME: {
        enterOuterAlt(_localctx, 3);
        setState(54);
        nondet();
        break;
      }

      case CINTParser::V: {
        enterOuterAlt(_localctx, 4);
        setState(55);
        match(CINTParser::V);
        break;
      }

      case CINTParser::OPENP: {
        enterOuterAlt(_localctx, 5);
        setState(56);
        match(CINTParser::OPENP);
        setState(60);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(57);
          match(CINTParser::W);
          setState(62);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(63);
        bool_expr();
        setState(67);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(64);
          match(CINTParser::W);
          setState(69);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(70);
        match(CINTParser::CLOSEP);
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

//----------------- Mult_exprContext ------------------------------------------------------------------

CINTParser::Mult_exprContext::Mult_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CINTParser::Num_atomContext *> CINTParser::Mult_exprContext::num_atom() {
  return getRuleContexts<CINTParser::Num_atomContext>();
}

CINTParser::Num_atomContext* CINTParser::Mult_exprContext::num_atom(size_t i) {
  return getRuleContext<CINTParser::Num_atomContext>(i);
}

std::vector<tree::TerminalNode *> CINTParser::Mult_exprContext::MULT() {
  return getTokens(CINTParser::MULT);
}

tree::TerminalNode* CINTParser::Mult_exprContext::MULT(size_t i) {
  return getToken(CINTParser::MULT, i);
}

std::vector<tree::TerminalNode *> CINTParser::Mult_exprContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::Mult_exprContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::Mult_exprContext::getRuleIndex() const {
  return CINTParser::RuleMult_expr;
}

void CINTParser::Mult_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult_expr(this);
}

void CINTParser::Mult_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult_expr(this);
}


std::any CINTParser::Mult_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitMult_expr(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::Mult_exprContext* CINTParser::mult_expr() {
  Mult_exprContext *_localctx = _tracker.createInstance<Mult_exprContext>(_ctx, getState());
  enterRule(_localctx, 4, CINTParser::RuleMult_expr);
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
    setState(74);
    num_atom();
    setState(91);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(75);
          match(CINTParser::W);
          setState(80);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(81);
        match(CINTParser::MULT);
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(82);
          match(CINTParser::W);
          setState(87);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(88);
        num_atom(); 
      }
      setState(93);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pm_mult_exprContext ------------------------------------------------------------------

CINTParser::Pm_mult_exprContext::Pm_mult_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CINTParser::Mult_exprContext* CINTParser::Pm_mult_exprContext::mult_expr() {
  return getRuleContext<CINTParser::Mult_exprContext>(0);
}

tree::TerminalNode* CINTParser::Pm_mult_exprContext::PLUS() {
  return getToken(CINTParser::PLUS, 0);
}

tree::TerminalNode* CINTParser::Pm_mult_exprContext::MINUS() {
  return getToken(CINTParser::MINUS, 0);
}

std::vector<tree::TerminalNode *> CINTParser::Pm_mult_exprContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::Pm_mult_exprContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::Pm_mult_exprContext::getRuleIndex() const {
  return CINTParser::RulePm_mult_expr;
}

void CINTParser::Pm_mult_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPm_mult_expr(this);
}

void CINTParser::Pm_mult_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPm_mult_expr(this);
}


std::any CINTParser::Pm_mult_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitPm_mult_expr(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::Pm_mult_exprContext* CINTParser::pm_mult_expr() {
  Pm_mult_exprContext *_localctx = _tracker.createInstance<Pm_mult_exprContext>(_ctx, getState());
  enterRule(_localctx, 6, CINTParser::RulePm_mult_expr);
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
    setState(97);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(94);
      match(CINTParser::W);
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(100);
    _la = _input->LA(1);
    if (!(_la == CINTParser::MINUS

    || _la == CINTParser::PLUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(104);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(101);
      match(CINTParser::W);
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(107);
    mult_expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Num_exprContext ------------------------------------------------------------------

CINTParser::Num_exprContext::Num_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CINTParser::Mult_exprContext* CINTParser::Num_exprContext::mult_expr() {
  return getRuleContext<CINTParser::Mult_exprContext>(0);
}

std::vector<CINTParser::Pm_mult_exprContext *> CINTParser::Num_exprContext::pm_mult_expr() {
  return getRuleContexts<CINTParser::Pm_mult_exprContext>();
}

CINTParser::Pm_mult_exprContext* CINTParser::Num_exprContext::pm_mult_expr(size_t i) {
  return getRuleContext<CINTParser::Pm_mult_exprContext>(i);
}

tree::TerminalNode* CINTParser::Num_exprContext::MINUS() {
  return getToken(CINTParser::MINUS, 0);
}

std::vector<tree::TerminalNode *> CINTParser::Num_exprContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::Num_exprContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::Num_exprContext::getRuleIndex() const {
  return CINTParser::RuleNum_expr;
}

void CINTParser::Num_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNum_expr(this);
}

void CINTParser::Num_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNum_expr(this);
}


std::any CINTParser::Num_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitNum_expr(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::Num_exprContext* CINTParser::num_expr() {
  Num_exprContext *_localctx = _tracker.createInstance<Num_exprContext>(_ctx, getState());
  enterRule(_localctx, 8, CINTParser::RuleNum_expr);
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
    setState(130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CINTParser::OPENP:
      case CINTParser::NONDETNAME:
      case CINTParser::ZERO:
      case CINTParser::POS:
      case CINTParser::V: {
        enterOuterAlt(_localctx, 1);
        setState(109);
        mult_expr();
        setState(113);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(110);
            pm_mult_expr(); 
          }
          setState(115);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
        }
        break;
      }

      case CINTParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(116);
        match(CINTParser::MINUS);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(117);
          match(CINTParser::W);
          setState(122);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(123);
        mult_expr();
        setState(127);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(124);
            pm_mult_expr(); 
          }
          setState(129);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
        }
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

//----------------- Bool_atomContext ------------------------------------------------------------------

CINTParser::Bool_atomContext::Bool_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::Bool_atomContext::TRUE() {
  return getToken(CINTParser::TRUE, 0);
}

tree::TerminalNode* CINTParser::Bool_atomContext::FALSE() {
  return getToken(CINTParser::FALSE, 0);
}

std::vector<CINTParser::Num_exprContext *> CINTParser::Bool_atomContext::num_expr() {
  return getRuleContexts<CINTParser::Num_exprContext>();
}

CINTParser::Num_exprContext* CINTParser::Bool_atomContext::num_expr(size_t i) {
  return getRuleContext<CINTParser::Num_exprContext>(i);
}

tree::TerminalNode* CINTParser::Bool_atomContext::BO() {
  return getToken(CINTParser::BO, 0);
}

std::vector<tree::TerminalNode *> CINTParser::Bool_atomContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::Bool_atomContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::Bool_atomContext::getRuleIndex() const {
  return CINTParser::RuleBool_atom;
}

void CINTParser::Bool_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_atom(this);
}

void CINTParser::Bool_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_atom(this);
}


std::any CINTParser::Bool_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitBool_atom(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::Bool_atomContext* CINTParser::bool_atom() {
  Bool_atomContext *_localctx = _tracker.createInstance<Bool_atomContext>(_ctx, getState());
  enterRule(_localctx, 10, CINTParser::RuleBool_atom);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CINTParser::TRUE: {
        enterOuterAlt(_localctx, 1);
        setState(132);
        match(CINTParser::TRUE);
        break;
      }

      case CINTParser::FALSE: {
        enterOuterAlt(_localctx, 2);
        setState(133);
        match(CINTParser::FALSE);
        break;
      }

      case CINTParser::OPENP:
      case CINTParser::MINUS:
      case CINTParser::NONDETNAME:
      case CINTParser::ZERO:
      case CINTParser::POS:
      case CINTParser::V: {
        enterOuterAlt(_localctx, 3);
        setState(134);
        num_expr();
        setState(149);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          setState(138);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CINTParser::W) {
            setState(135);
            match(CINTParser::W);
            setState(140);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(141);
          match(CINTParser::BO);
          setState(145);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == CINTParser::W) {
            setState(142);
            match(CINTParser::W);
            setState(147);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(148);
          num_expr();
          break;
        }

        default:
          break;
        }
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

//----------------- And_exprContext ------------------------------------------------------------------

CINTParser::And_exprContext::And_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CINTParser::Bool_atomContext *> CINTParser::And_exprContext::bool_atom() {
  return getRuleContexts<CINTParser::Bool_atomContext>();
}

CINTParser::Bool_atomContext* CINTParser::And_exprContext::bool_atom(size_t i) {
  return getRuleContext<CINTParser::Bool_atomContext>(i);
}

std::vector<tree::TerminalNode *> CINTParser::And_exprContext::AND() {
  return getTokens(CINTParser::AND);
}

tree::TerminalNode* CINTParser::And_exprContext::AND(size_t i) {
  return getToken(CINTParser::AND, i);
}

std::vector<tree::TerminalNode *> CINTParser::And_exprContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::And_exprContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::And_exprContext::getRuleIndex() const {
  return CINTParser::RuleAnd_expr;
}

void CINTParser::And_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_expr(this);
}

void CINTParser::And_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_expr(this);
}


std::any CINTParser::And_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitAnd_expr(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::And_exprContext* CINTParser::and_expr() {
  And_exprContext *_localctx = _tracker.createInstance<And_exprContext>(_ctx, getState());
  enterRule(_localctx, 12, CINTParser::RuleAnd_expr);
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
    setState(153);
    bool_atom();
    setState(170);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(157);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(154);
          match(CINTParser::W);
          setState(159);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(160);
        match(CINTParser::AND);
        setState(164);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(161);
          match(CINTParser::W);
          setState(166);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(167);
        bool_atom(); 
      }
      setState(172);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_exprContext ------------------------------------------------------------------

CINTParser::Bool_exprContext::Bool_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CINTParser::And_exprContext *> CINTParser::Bool_exprContext::and_expr() {
  return getRuleContexts<CINTParser::And_exprContext>();
}

CINTParser::And_exprContext* CINTParser::Bool_exprContext::and_expr(size_t i) {
  return getRuleContext<CINTParser::And_exprContext>(i);
}

std::vector<tree::TerminalNode *> CINTParser::Bool_exprContext::OR() {
  return getTokens(CINTParser::OR);
}

tree::TerminalNode* CINTParser::Bool_exprContext::OR(size_t i) {
  return getToken(CINTParser::OR, i);
}

std::vector<tree::TerminalNode *> CINTParser::Bool_exprContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::Bool_exprContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}

tree::TerminalNode* CINTParser::Bool_exprContext::NOT() {
  return getToken(CINTParser::NOT, 0);
}

CINTParser::Bool_atomContext* CINTParser::Bool_exprContext::bool_atom() {
  return getRuleContext<CINTParser::Bool_atomContext>(0);
}


size_t CINTParser::Bool_exprContext::getRuleIndex() const {
  return CINTParser::RuleBool_expr;
}

void CINTParser::Bool_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_expr(this);
}

void CINTParser::Bool_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_expr(this);
}


std::any CINTParser::Bool_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitBool_expr(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::Bool_exprContext* CINTParser::bool_expr() {
  Bool_exprContext *_localctx = _tracker.createInstance<Bool_exprContext>(_ctx, getState());
  enterRule(_localctx, 14, CINTParser::RuleBool_expr);
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
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CINTParser::OPENP:
      case CINTParser::MINUS:
      case CINTParser::NONDETNAME:
      case CINTParser::TRUE:
      case CINTParser::FALSE:
      case CINTParser::ZERO:
      case CINTParser::POS:
      case CINTParser::V: {
        enterOuterAlt(_localctx, 1);
        setState(173);
        and_expr();
        setState(190);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(177);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == CINTParser::W) {
              setState(174);
              match(CINTParser::W);
              setState(179);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(180);
            match(CINTParser::OR);
            setState(184);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == CINTParser::W) {
              setState(181);
              match(CINTParser::W);
              setState(186);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(187);
            and_expr(); 
          }
          setState(192);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
        }
        break;
      }

      case CINTParser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(193);
        match(CINTParser::NOT);
        setState(197);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(194);
          match(CINTParser::W);
          setState(199);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(200);
        bool_atom();
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

//----------------- LoopContext ------------------------------------------------------------------

CINTParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::LoopContext::WHILE() {
  return getToken(CINTParser::WHILE, 0);
}

tree::TerminalNode* CINTParser::LoopContext::OPENP() {
  return getToken(CINTParser::OPENP, 0);
}

CINTParser::Bool_exprContext* CINTParser::LoopContext::bool_expr() {
  return getRuleContext<CINTParser::Bool_exprContext>(0);
}

tree::TerminalNode* CINTParser::LoopContext::CLOSEP() {
  return getToken(CINTParser::CLOSEP, 0);
}

tree::TerminalNode* CINTParser::LoopContext::OPENC() {
  return getToken(CINTParser::OPENC, 0);
}

tree::TerminalNode* CINTParser::LoopContext::CLOSEC() {
  return getToken(CINTParser::CLOSEC, 0);
}

std::vector<tree::TerminalNode *> CINTParser::LoopContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::LoopContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}

CINTParser::InstructionsContext* CINTParser::LoopContext::instructions() {
  return getRuleContext<CINTParser::InstructionsContext>(0);
}


size_t CINTParser::LoopContext::getRuleIndex() const {
  return CINTParser::RuleLoop;
}

void CINTParser::LoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoop(this);
}

void CINTParser::LoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoop(this);
}


std::any CINTParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::LoopContext* CINTParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 16, CINTParser::RuleLoop);
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
    setState(203);
    match(CINTParser::WHILE);
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(204);
      match(CINTParser::W);
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(210);
    match(CINTParser::OPENP);
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(211);
      match(CINTParser::W);
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(217);
    bool_expr();
    setState(221);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(218);
      match(CINTParser::W);
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(224);
    match(CINTParser::CLOSEP);
    setState(228);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(225);
      match(CINTParser::W);
      setState(230);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(231);
    match(CINTParser::OPENC);
    setState(235);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(232);
      match(CINTParser::W);
      setState(237);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2147483660) != 0) {
      setState(238);
      instructions();
      setState(242);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(239);
        match(CINTParser::W);
        setState(244);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(247);
    match(CINTParser::CLOSEC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

CINTParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::ConditionContext::IF() {
  return getToken(CINTParser::IF, 0);
}

tree::TerminalNode* CINTParser::ConditionContext::OPENP() {
  return getToken(CINTParser::OPENP, 0);
}

CINTParser::Bool_exprContext* CINTParser::ConditionContext::bool_expr() {
  return getRuleContext<CINTParser::Bool_exprContext>(0);
}

tree::TerminalNode* CINTParser::ConditionContext::CLOSEP() {
  return getToken(CINTParser::CLOSEP, 0);
}

std::vector<tree::TerminalNode *> CINTParser::ConditionContext::OPENC() {
  return getTokens(CINTParser::OPENC);
}

tree::TerminalNode* CINTParser::ConditionContext::OPENC(size_t i) {
  return getToken(CINTParser::OPENC, i);
}

std::vector<tree::TerminalNode *> CINTParser::ConditionContext::CLOSEC() {
  return getTokens(CINTParser::CLOSEC);
}

tree::TerminalNode* CINTParser::ConditionContext::CLOSEC(size_t i) {
  return getToken(CINTParser::CLOSEC, i);
}

std::vector<tree::TerminalNode *> CINTParser::ConditionContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::ConditionContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}

std::vector<CINTParser::InstructionsContext *> CINTParser::ConditionContext::instructions() {
  return getRuleContexts<CINTParser::InstructionsContext>();
}

CINTParser::InstructionsContext* CINTParser::ConditionContext::instructions(size_t i) {
  return getRuleContext<CINTParser::InstructionsContext>(i);
}

tree::TerminalNode* CINTParser::ConditionContext::ELSE() {
  return getToken(CINTParser::ELSE, 0);
}


size_t CINTParser::ConditionContext::getRuleIndex() const {
  return CINTParser::RuleCondition;
}

void CINTParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void CINTParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


std::any CINTParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::ConditionContext* CINTParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 18, CINTParser::RuleCondition);
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
    setState(249);
    match(CINTParser::IF);
    setState(253);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(250);
      match(CINTParser::W);
      setState(255);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(256);
    match(CINTParser::OPENP);
    setState(260);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(257);
      match(CINTParser::W);
      setState(262);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(263);
    bool_expr();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(264);
      match(CINTParser::W);
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(270);
    match(CINTParser::CLOSEP);
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(271);
      match(CINTParser::W);
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(277);
    match(CINTParser::OPENC);
    setState(281);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(278);
      match(CINTParser::W);
      setState(283);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2147483660) != 0) {
      setState(284);
      instructions();
      setState(288);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(285);
        match(CINTParser::W);
        setState(290);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(293);
    match(CINTParser::CLOSEC);
    setState(324);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(294);
        match(CINTParser::W);
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(300);
      match(CINTParser::ELSE);
      setState(304);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(301);
        match(CINTParser::W);
        setState(306);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(307);
      match(CINTParser::OPENC);
      setState(311);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(308);
        match(CINTParser::W);
        setState(313);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(321);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2147483660) != 0) {
        setState(314);
        instructions();
        setState(318);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(315);
          match(CINTParser::W);
          setState(320);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(323);
      match(CINTParser::CLOSEC);
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

//----------------- AssignmentContext ------------------------------------------------------------------

CINTParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::AssignmentContext::V() {
  return getToken(CINTParser::V, 0);
}

tree::TerminalNode* CINTParser::AssignmentContext::ASSIGN() {
  return getToken(CINTParser::ASSIGN, 0);
}

CINTParser::Num_exprContext* CINTParser::AssignmentContext::num_expr() {
  return getRuleContext<CINTParser::Num_exprContext>(0);
}

tree::TerminalNode* CINTParser::AssignmentContext::TERMINATOR() {
  return getToken(CINTParser::TERMINATOR, 0);
}

std::vector<tree::TerminalNode *> CINTParser::AssignmentContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::AssignmentContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::AssignmentContext::getRuleIndex() const {
  return CINTParser::RuleAssignment;
}

void CINTParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void CINTParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any CINTParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::AssignmentContext* CINTParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, CINTParser::RuleAssignment);
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
    setState(326);
    match(CINTParser::V);
    setState(330);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(327);
      match(CINTParser::W);
      setState(332);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(333);
    match(CINTParser::ASSIGN);
    setState(337);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(334);
      match(CINTParser::W);
      setState(339);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(340);
    num_expr();
    setState(344);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(341);
      match(CINTParser::W);
      setState(346);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(347);
    match(CINTParser::TERMINATOR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

CINTParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CINTParser::LoopContext* CINTParser::InstructionContext::loop() {
  return getRuleContext<CINTParser::LoopContext>(0);
}

CINTParser::ConditionContext* CINTParser::InstructionContext::condition() {
  return getRuleContext<CINTParser::ConditionContext>(0);
}

CINTParser::AssignmentContext* CINTParser::InstructionContext::assignment() {
  return getRuleContext<CINTParser::AssignmentContext>(0);
}


size_t CINTParser::InstructionContext::getRuleIndex() const {
  return CINTParser::RuleInstruction;
}

void CINTParser::InstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction(this);
}

void CINTParser::InstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction(this);
}


std::any CINTParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::InstructionContext* CINTParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 22, CINTParser::RuleInstruction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CINTParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(349);
        loop();
        break;
      }

      case CINTParser::IF: {
        enterOuterAlt(_localctx, 2);
        setState(350);
        condition();
        break;
      }

      case CINTParser::V: {
        enterOuterAlt(_localctx, 3);
        setState(351);
        assignment();
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

//----------------- DeclarationContext ------------------------------------------------------------------

CINTParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::DeclarationContext::INT() {
  return getToken(CINTParser::INT, 0);
}

std::vector<tree::TerminalNode *> CINTParser::DeclarationContext::V() {
  return getTokens(CINTParser::V);
}

tree::TerminalNode* CINTParser::DeclarationContext::V(size_t i) {
  return getToken(CINTParser::V, i);
}

tree::TerminalNode* CINTParser::DeclarationContext::TERMINATOR() {
  return getToken(CINTParser::TERMINATOR, 0);
}

std::vector<tree::TerminalNode *> CINTParser::DeclarationContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::DeclarationContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}

std::vector<tree::TerminalNode *> CINTParser::DeclarationContext::COMMA() {
  return getTokens(CINTParser::COMMA);
}

tree::TerminalNode* CINTParser::DeclarationContext::COMMA(size_t i) {
  return getToken(CINTParser::COMMA, i);
}


size_t CINTParser::DeclarationContext::getRuleIndex() const {
  return CINTParser::RuleDeclaration;
}

void CINTParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void CINTParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


std::any CINTParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::DeclarationContext* CINTParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 24, CINTParser::RuleDeclaration);
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
    setState(354);
    match(CINTParser::INT);
    setState(356); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(355);
      match(CINTParser::W);
      setState(358); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CINTParser::W);
    setState(360);
    match(CINTParser::V);
    setState(377);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(364);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(361);
          match(CINTParser::W);
          setState(366);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(367);
        match(CINTParser::COMMA);
        setState(371);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CINTParser::W) {
          setState(368);
          match(CINTParser::W);
          setState(373);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(374);
        match(CINTParser::V); 
      }
      setState(379);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    }
    setState(383);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(380);
      match(CINTParser::W);
      setState(385);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(386);
    match(CINTParser::TERMINATOR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

CINTParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CINTParser::DeclarationContext* CINTParser::DeclarationsContext::declaration() {
  return getRuleContext<CINTParser::DeclarationContext>(0);
}

CINTParser::DeclarationsContext* CINTParser::DeclarationsContext::declarations() {
  return getRuleContext<CINTParser::DeclarationsContext>(0);
}

std::vector<tree::TerminalNode *> CINTParser::DeclarationsContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::DeclarationsContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::DeclarationsContext::getRuleIndex() const {
  return CINTParser::RuleDeclarations;
}

void CINTParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void CINTParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}


std::any CINTParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::DeclarationsContext* CINTParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 26, CINTParser::RuleDeclarations);
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
    setState(388);
    declaration();
    setState(396);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      setState(392);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(389);
        match(CINTParser::W);
        setState(394);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(395);
      declarations();
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

//----------------- InstructionsContext ------------------------------------------------------------------

CINTParser::InstructionsContext::InstructionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CINTParser::InstructionContext* CINTParser::InstructionsContext::instruction() {
  return getRuleContext<CINTParser::InstructionContext>(0);
}

CINTParser::InstructionsContext* CINTParser::InstructionsContext::instructions() {
  return getRuleContext<CINTParser::InstructionsContext>(0);
}

std::vector<tree::TerminalNode *> CINTParser::InstructionsContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::InstructionsContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::InstructionsContext::getRuleIndex() const {
  return CINTParser::RuleInstructions;
}

void CINTParser::InstructionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstructions(this);
}

void CINTParser::InstructionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstructions(this);
}


std::any CINTParser::InstructionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitInstructions(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::InstructionsContext* CINTParser::instructions() {
  InstructionsContext *_localctx = _tracker.createInstance<InstructionsContext>(_ctx, getState());
  enterRule(_localctx, 28, CINTParser::RuleInstructions);
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
    setState(398);
    instruction();
    setState(406);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(399);
        match(CINTParser::W);
        setState(404);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(405);
      instructions();
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

//----------------- PreContext ------------------------------------------------------------------

CINTParser::PreContext::PreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::PreContext::TYPEDEF() {
  return getToken(CINTParser::TYPEDEF, 0);
}

tree::TerminalNode* CINTParser::PreContext::ENUM() {
  return getToken(CINTParser::ENUM, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PreContext::OPENC() {
  return getTokens(CINTParser::OPENC);
}

tree::TerminalNode* CINTParser::PreContext::OPENC(size_t i) {
  return getToken(CINTParser::OPENC, i);
}

tree::TerminalNode* CINTParser::PreContext::FALSE() {
  return getToken(CINTParser::FALSE, 0);
}

tree::TerminalNode* CINTParser::PreContext::COMMA() {
  return getToken(CINTParser::COMMA, 0);
}

tree::TerminalNode* CINTParser::PreContext::TRUE() {
  return getToken(CINTParser::TRUE, 0);
}

tree::TerminalNode* CINTParser::PreContext::CLOSEC() {
  return getToken(CINTParser::CLOSEC, 0);
}

tree::TerminalNode* CINTParser::PreContext::BOOL() {
  return getToken(CINTParser::BOOL, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PreContext::TERMINATOR() {
  return getTokens(CINTParser::TERMINATOR);
}

tree::TerminalNode* CINTParser::PreContext::TERMINATOR(size_t i) {
  return getToken(CINTParser::TERMINATOR, i);
}

tree::TerminalNode* CINTParser::PreContext::EXTERN() {
  return getToken(CINTParser::EXTERN, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PreContext::INT() {
  return getTokens(CINTParser::INT);
}

tree::TerminalNode* CINTParser::PreContext::INT(size_t i) {
  return getToken(CINTParser::INT, i);
}

tree::TerminalNode* CINTParser::PreContext::NONDETNAME() {
  return getToken(CINTParser::NONDETNAME, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PreContext::OPENP() {
  return getTokens(CINTParser::OPENP);
}

tree::TerminalNode* CINTParser::PreContext::OPENP(size_t i) {
  return getToken(CINTParser::OPENP, i);
}

tree::TerminalNode* CINTParser::PreContext::VOID() {
  return getToken(CINTParser::VOID, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PreContext::CLOSEP() {
  return getTokens(CINTParser::CLOSEP);
}

tree::TerminalNode* CINTParser::PreContext::CLOSEP(size_t i) {
  return getToken(CINTParser::CLOSEP, i);
}

tree::TerminalNode* CINTParser::PreContext::MAIN() {
  return getToken(CINTParser::MAIN, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PreContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::PreContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::PreContext::getRuleIndex() const {
  return CINTParser::RulePre;
}

void CINTParser::PreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPre(this);
}

void CINTParser::PreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPre(this);
}


std::any CINTParser::PreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitPre(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::PreContext* CINTParser::pre() {
  PreContext *_localctx = _tracker.createInstance<PreContext>(_ctx, getState());
  enterRule(_localctx, 30, CINTParser::RulePre);
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
    setState(411);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(408);
      match(CINTParser::W);
      setState(413);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(414);
    match(CINTParser::TYPEDEF);
    setState(416); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(415);
      match(CINTParser::W);
      setState(418); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CINTParser::W);
    setState(420);
    match(CINTParser::ENUM);
    setState(424);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(421);
      match(CINTParser::W);
      setState(426);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(427);
    match(CINTParser::OPENC);
    setState(431);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(428);
      match(CINTParser::W);
      setState(433);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(434);
    match(CINTParser::FALSE);
    setState(438);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(435);
      match(CINTParser::W);
      setState(440);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(441);
    match(CINTParser::COMMA);
    setState(445);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(442);
      match(CINTParser::W);
      setState(447);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(448);
    match(CINTParser::TRUE);
    setState(452);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(449);
      match(CINTParser::W);
      setState(454);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(455);
    match(CINTParser::CLOSEC);
    setState(459);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(456);
      match(CINTParser::W);
      setState(461);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(462);
    match(CINTParser::BOOL);
    setState(466);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(463);
      match(CINTParser::W);
      setState(468);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(469);
    match(CINTParser::TERMINATOR);
    setState(473);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(470);
      match(CINTParser::W);
      setState(475);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(476);
    match(CINTParser::EXTERN);
    setState(478); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(477);
      match(CINTParser::W);
      setState(480); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CINTParser::W);
    setState(482);
    match(CINTParser::INT);
    setState(484); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(483);
      match(CINTParser::W);
      setState(486); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CINTParser::W);
    setState(488);
    match(CINTParser::NONDETNAME);
    setState(492);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(489);
      match(CINTParser::W);
      setState(494);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(495);
    match(CINTParser::OPENP);
    setState(499);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(496);
      match(CINTParser::W);
      setState(501);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(502);
    match(CINTParser::VOID);
    setState(506);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(503);
      match(CINTParser::W);
      setState(508);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(509);
    match(CINTParser::CLOSEP);
    setState(513);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(510);
      match(CINTParser::W);
      setState(515);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(516);
    match(CINTParser::TERMINATOR);
    setState(520);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(517);
      match(CINTParser::W);
      setState(522);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(523);
    match(CINTParser::INT);
    setState(525); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(524);
      match(CINTParser::W);
      setState(527); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CINTParser::W);
    setState(529);
    match(CINTParser::MAIN);
    setState(533);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(530);
      match(CINTParser::W);
      setState(535);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(536);
    match(CINTParser::OPENP);
    setState(540);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(537);
      match(CINTParser::W);
      setState(542);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(543);
    match(CINTParser::CLOSEP);
    setState(547);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(544);
      match(CINTParser::W);
      setState(549);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(550);
    match(CINTParser::OPENC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostContext ------------------------------------------------------------------

CINTParser::PostContext::PostContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CINTParser::PostContext::RETURN() {
  return getToken(CINTParser::RETURN, 0);
}

tree::TerminalNode* CINTParser::PostContext::ZERO() {
  return getToken(CINTParser::ZERO, 0);
}

tree::TerminalNode* CINTParser::PostContext::TERMINATOR() {
  return getToken(CINTParser::TERMINATOR, 0);
}

tree::TerminalNode* CINTParser::PostContext::CLOSEC() {
  return getToken(CINTParser::CLOSEC, 0);
}

std::vector<tree::TerminalNode *> CINTParser::PostContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::PostContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::PostContext::getRuleIndex() const {
  return CINTParser::RulePost;
}

void CINTParser::PostContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPost(this);
}

void CINTParser::PostContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPost(this);
}


std::any CINTParser::PostContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitPost(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::PostContext* CINTParser::post() {
  PostContext *_localctx = _tracker.createInstance<PostContext>(_ctx, getState());
  enterRule(_localctx, 32, CINTParser::RulePost);
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
    setState(552);
    match(CINTParser::RETURN);
    setState(554); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(553);
      match(CINTParser::W);
      setState(556); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CINTParser::W);
    setState(558);
    match(CINTParser::ZERO);
    setState(562);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(559);
      match(CINTParser::W);
      setState(564);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(565);
    match(CINTParser::TERMINATOR);
    setState(569);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(566);
      match(CINTParser::W);
      setState(571);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(572);
    match(CINTParser::CLOSEC);
    setState(576);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(573);
      match(CINTParser::W);
      setState(578);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

CINTParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CINTParser::PreContext* CINTParser::MainContext::pre() {
  return getRuleContext<CINTParser::PreContext>(0);
}

CINTParser::PostContext* CINTParser::MainContext::post() {
  return getRuleContext<CINTParser::PostContext>(0);
}

CINTParser::DeclarationsContext* CINTParser::MainContext::declarations() {
  return getRuleContext<CINTParser::DeclarationsContext>(0);
}

CINTParser::InstructionsContext* CINTParser::MainContext::instructions() {
  return getRuleContext<CINTParser::InstructionsContext>(0);
}

std::vector<tree::TerminalNode *> CINTParser::MainContext::W() {
  return getTokens(CINTParser::W);
}

tree::TerminalNode* CINTParser::MainContext::W(size_t i) {
  return getToken(CINTParser::W, i);
}


size_t CINTParser::MainContext::getRuleIndex() const {
  return CINTParser::RuleMain;
}

void CINTParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void CINTParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CINTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any CINTParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CINTVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

CINTParser::MainContext* CINTParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 34, CINTParser::RuleMain);
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
    setState(579);
    pre();
    setState(587);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      setState(583);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(580);
        match(CINTParser::W);
        setState(585);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(586);
      declarations();
      break;
    }

    default:
      break;
    }
    setState(596);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CINTParser::W) {
        setState(589);
        match(CINTParser::W);
        setState(594);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(595);
      instructions();
      break;
    }

    default:
      break;
    }
    setState(601);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CINTParser::W) {
      setState(598);
      match(CINTParser::W);
      setState(603);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(604);
    post();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CINTParser::initialize() {
  ::antlr4::internal::call_once(cintParserOnceFlag, cintParserInitialize);
}
