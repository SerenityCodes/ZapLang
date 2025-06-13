
// Generated from zap.g4 by ANTLR 4.13.2


#include "zapVisitor.h"

#include "zapParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ZapParserStaticData final {
  ZapParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ZapParserStaticData(const ZapParserStaticData&) = delete;
  ZapParserStaticData(ZapParserStaticData&&) = delete;
  ZapParserStaticData& operator=(const ZapParserStaticData&) = delete;
  ZapParserStaticData& operator=(ZapParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag zapParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ZapParserStaticData> zapParserStaticData = nullptr;

void zapParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (zapParserStaticData != nullptr) {
    return;
  }
#else
  assert(zapParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ZapParserStaticData>(
    std::vector<std::string>{
      "program", "declaration", "statement", "functionDecl", "attributeBlock", 
      "attributeList", "attribute", "attributeArgs", "attributeArg", "returnType", 
      "parameterList", "parameter", "type", "structDecl", "structField", 
      "componentDecl", "moduleDecl", "block", "variableDecl", "ifStmt", 
      "whileStmt", "forStmt", "returnStmt", "yieldStmt", "deferStmt", "expressionStmt", 
      "expression", "assignment", "logicOr", "logicAnd", "equality", "comparison", 
      "term", "factor", "unary", "call", "argumentList", "primary", "aotBlock"
    },
    std::vector<std::string>{
      "", "';'", "'('", "')'", "'@'", "'['", "']'", "','", "':'", "'{'", 
      "'}'", "'='", "'.'", "", "'if'", "'else'", "'while'", "'for'", "'return'", 
      "'yield'", "'defer'", "'let'", "'func'", "'struct'", "'component'", 
      "'readonly'", "'module'", "'aot'", "'ref'", "'void'", "'->'", "'use'", 
      "'||'", "'&&'", "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", "'%'", 
      "'<'", "'<='", "'>'", "'>='", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", "IF", 
      "ELSE", "WHILE", "FOR", "RETURN", "YIELD", "DEFER", "LET", "FUNC", 
      "STRUCT", "COMPONENT", "READONLY", "MODULE", "AOT", "REF", "VOID", 
      "ARROW", "USE", "OR", "AND", "EQ", "NEQ", "ADD", "SUB", "MUL", "DIV", 
      "MOD", "LT", "LTE", "GT", "GTE", "NOT", "INT", "FLOAT", "STRING", 
      "IDENTIFIER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,52,383,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,1,0,5,0,80,8,0,10,0,12,0,83,9,0,1,0,
  	1,0,1,1,1,1,1,1,1,1,3,1,91,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,3,2,104,8,2,1,3,3,3,107,8,3,1,3,1,3,1,3,1,3,3,3,113,8,3,1,3,1,3,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,127,8,5,10,5,12,5,130,9,5,
  	1,6,1,6,1,6,3,6,135,8,6,1,6,3,6,138,8,6,1,7,1,7,1,7,5,7,143,8,7,10,7,
  	12,7,146,9,7,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,5,10,156,8,10,10,10,12,
  	10,159,9,10,1,11,1,11,1,11,3,11,164,8,11,1,11,1,11,1,12,1,12,1,12,1,12,
  	1,12,3,12,173,8,12,1,12,1,12,3,12,177,8,12,1,13,1,13,1,13,1,13,5,13,183,
  	8,13,10,13,12,13,186,9,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,3,15,
  	196,8,15,1,15,1,15,1,15,1,15,5,15,202,8,15,10,15,12,15,205,9,15,1,15,
  	1,15,1,16,1,16,1,16,1,16,5,16,213,8,16,10,16,12,16,216,9,16,1,16,1,16,
  	1,17,1,17,5,17,222,8,17,10,17,12,17,225,9,17,1,17,1,17,1,18,1,18,1,18,
  	1,18,1,18,1,18,1,18,3,18,236,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	3,19,245,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,22,1,22,3,22,265,8,22,1,22,1,22,1,23,1,23,
  	3,23,271,8,23,1,23,1,23,1,24,1,24,1,24,3,24,278,8,24,1,25,1,25,1,25,1,
  	26,1,26,1,27,1,27,1,27,3,27,288,8,27,1,28,1,28,1,28,5,28,293,8,28,10,
  	28,12,28,296,9,28,1,29,1,29,1,29,5,29,301,8,29,10,29,12,29,304,9,29,1,
  	30,1,30,1,30,5,30,309,8,30,10,30,12,30,312,9,30,1,31,1,31,1,31,5,31,317,
  	8,31,10,31,12,31,320,9,31,1,32,1,32,1,32,5,32,325,8,32,10,32,12,32,328,
  	9,32,1,33,1,33,1,33,5,33,333,8,33,10,33,12,33,336,9,33,1,34,1,34,1,34,
  	3,34,341,8,34,1,35,1,35,1,35,5,35,346,8,35,10,35,12,35,349,9,35,1,35,
  	1,35,3,35,353,8,35,1,35,5,35,356,8,35,10,35,12,35,359,9,35,1,36,1,36,
  	1,36,5,36,364,8,36,10,36,12,36,367,9,36,1,37,1,37,1,37,1,37,1,37,1,37,
  	1,37,1,37,1,37,3,37,378,8,37,1,38,1,38,1,38,1,38,0,0,39,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,
  	58,60,62,64,66,68,70,72,74,76,0,7,2,0,46,46,48,49,2,0,29,29,49,49,1,0,
  	34,35,1,0,41,44,1,0,36,37,1,0,38,40,2,0,37,37,45,45,392,0,81,1,0,0,0,
  	2,90,1,0,0,0,4,103,1,0,0,0,6,106,1,0,0,0,8,118,1,0,0,0,10,123,1,0,0,0,
  	12,131,1,0,0,0,14,139,1,0,0,0,16,147,1,0,0,0,18,149,1,0,0,0,20,152,1,
  	0,0,0,22,160,1,0,0,0,24,167,1,0,0,0,26,178,1,0,0,0,28,189,1,0,0,0,30,
  	195,1,0,0,0,32,208,1,0,0,0,34,219,1,0,0,0,36,228,1,0,0,0,38,237,1,0,0,
  	0,40,246,1,0,0,0,42,252,1,0,0,0,44,262,1,0,0,0,46,268,1,0,0,0,48,274,
  	1,0,0,0,50,279,1,0,0,0,52,282,1,0,0,0,54,284,1,0,0,0,56,289,1,0,0,0,58,
  	297,1,0,0,0,60,305,1,0,0,0,62,313,1,0,0,0,64,321,1,0,0,0,66,329,1,0,0,
  	0,68,340,1,0,0,0,70,342,1,0,0,0,72,360,1,0,0,0,74,377,1,0,0,0,76,379,
  	1,0,0,0,78,80,3,2,1,0,79,78,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,
  	1,0,0,0,82,84,1,0,0,0,83,81,1,0,0,0,84,85,5,0,0,1,85,1,1,0,0,0,86,91,
  	3,6,3,0,87,91,3,26,13,0,88,91,3,30,15,0,89,91,3,32,16,0,90,86,1,0,0,0,
  	90,87,1,0,0,0,90,88,1,0,0,0,90,89,1,0,0,0,91,3,1,0,0,0,92,93,3,36,18,
  	0,93,94,5,1,0,0,94,104,1,0,0,0,95,104,3,50,25,0,96,104,3,34,17,0,97,104,
  	3,38,19,0,98,104,3,40,20,0,99,104,3,42,21,0,100,104,3,44,22,0,101,104,
  	3,46,23,0,102,104,3,48,24,0,103,92,1,0,0,0,103,95,1,0,0,0,103,96,1,0,
  	0,0,103,97,1,0,0,0,103,98,1,0,0,0,103,99,1,0,0,0,103,100,1,0,0,0,103,
  	101,1,0,0,0,103,102,1,0,0,0,104,5,1,0,0,0,105,107,3,8,4,0,106,105,1,0,
  	0,0,106,107,1,0,0,0,107,108,1,0,0,0,108,109,5,22,0,0,109,110,5,49,0,0,
  	110,112,5,2,0,0,111,113,3,20,10,0,112,111,1,0,0,0,112,113,1,0,0,0,113,
  	114,1,0,0,0,114,115,5,3,0,0,115,116,3,18,9,0,116,117,3,34,17,0,117,7,
  	1,0,0,0,118,119,5,4,0,0,119,120,5,5,0,0,120,121,3,10,5,0,121,122,5,6,
  	0,0,122,9,1,0,0,0,123,128,3,12,6,0,124,125,5,7,0,0,125,127,3,12,6,0,126,
  	124,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,11,1,
  	0,0,0,130,128,1,0,0,0,131,137,5,49,0,0,132,134,5,2,0,0,133,135,3,14,7,
  	0,134,133,1,0,0,0,134,135,1,0,0,0,135,136,1,0,0,0,136,138,5,3,0,0,137,
  	132,1,0,0,0,137,138,1,0,0,0,138,13,1,0,0,0,139,144,3,16,8,0,140,141,5,
  	7,0,0,141,143,3,16,8,0,142,140,1,0,0,0,143,146,1,0,0,0,144,142,1,0,0,
  	0,144,145,1,0,0,0,145,15,1,0,0,0,146,144,1,0,0,0,147,148,7,0,0,0,148,
  	17,1,0,0,0,149,150,5,30,0,0,150,151,3,24,12,0,151,19,1,0,0,0,152,157,
  	3,22,11,0,153,154,5,7,0,0,154,156,3,22,11,0,155,153,1,0,0,0,156,159,1,
  	0,0,0,157,155,1,0,0,0,157,158,1,0,0,0,158,21,1,0,0,0,159,157,1,0,0,0,
  	160,161,5,49,0,0,161,163,5,8,0,0,162,164,5,28,0,0,163,162,1,0,0,0,163,
  	164,1,0,0,0,164,165,1,0,0,0,165,166,3,24,12,0,166,23,1,0,0,0,167,172,
  	7,1,0,0,168,169,5,41,0,0,169,170,3,24,12,0,170,171,5,43,0,0,171,173,1,
  	0,0,0,172,168,1,0,0,0,172,173,1,0,0,0,173,176,1,0,0,0,174,175,5,5,0,0,
  	175,177,5,6,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,25,1,0,0,0,178,179,
  	5,23,0,0,179,180,5,49,0,0,180,184,5,9,0,0,181,183,3,28,14,0,182,181,1,
  	0,0,0,183,186,1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,0,185,187,1,0,0,0,
  	186,184,1,0,0,0,187,188,5,10,0,0,188,27,1,0,0,0,189,190,5,49,0,0,190,
  	191,5,8,0,0,191,192,3,24,12,0,192,193,5,1,0,0,193,29,1,0,0,0,194,196,
  	5,25,0,0,195,194,1,0,0,0,195,196,1,0,0,0,196,197,1,0,0,0,197,198,5,24,
  	0,0,198,199,5,49,0,0,199,203,5,9,0,0,200,202,3,28,14,0,201,200,1,0,0,
  	0,202,205,1,0,0,0,203,201,1,0,0,0,203,204,1,0,0,0,204,206,1,0,0,0,205,
  	203,1,0,0,0,206,207,5,10,0,0,207,31,1,0,0,0,208,209,5,26,0,0,209,210,
  	5,49,0,0,210,214,5,9,0,0,211,213,3,4,2,0,212,211,1,0,0,0,213,216,1,0,
  	0,0,214,212,1,0,0,0,214,215,1,0,0,0,215,217,1,0,0,0,216,214,1,0,0,0,217,
  	218,5,10,0,0,218,33,1,0,0,0,219,223,5,9,0,0,220,222,3,4,2,0,221,220,1,
  	0,0,0,222,225,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,224,226,1,0,0,0,
  	225,223,1,0,0,0,226,227,5,10,0,0,227,35,1,0,0,0,228,229,5,21,0,0,229,
  	230,5,49,0,0,230,231,5,8,0,0,231,232,3,24,12,0,232,235,5,11,0,0,233,236,
  	3,52,26,0,234,236,3,76,38,0,235,233,1,0,0,0,235,234,1,0,0,0,236,37,1,
  	0,0,0,237,238,5,14,0,0,238,239,5,2,0,0,239,240,3,52,26,0,240,241,5,3,
  	0,0,241,244,3,34,17,0,242,243,5,15,0,0,243,245,3,34,17,0,244,242,1,0,
  	0,0,244,245,1,0,0,0,245,39,1,0,0,0,246,247,5,16,0,0,247,248,5,2,0,0,248,
  	249,3,52,26,0,249,250,5,3,0,0,250,251,3,34,17,0,251,41,1,0,0,0,252,253,
  	5,17,0,0,253,254,5,2,0,0,254,255,3,36,18,0,255,256,5,1,0,0,256,257,3,
  	52,26,0,257,258,5,1,0,0,258,259,3,52,26,0,259,260,5,3,0,0,260,261,3,34,
  	17,0,261,43,1,0,0,0,262,264,5,18,0,0,263,265,3,52,26,0,264,263,1,0,0,
  	0,264,265,1,0,0,0,265,266,1,0,0,0,266,267,5,1,0,0,267,45,1,0,0,0,268,
  	270,5,19,0,0,269,271,3,52,26,0,270,269,1,0,0,0,270,271,1,0,0,0,271,272,
  	1,0,0,0,272,273,5,1,0,0,273,47,1,0,0,0,274,277,5,20,0,0,275,278,3,34,
  	17,0,276,278,3,50,25,0,277,275,1,0,0,0,277,276,1,0,0,0,278,49,1,0,0,0,
  	279,280,3,52,26,0,280,281,5,1,0,0,281,51,1,0,0,0,282,283,3,54,27,0,283,
  	53,1,0,0,0,284,287,3,56,28,0,285,286,5,11,0,0,286,288,3,52,26,0,287,285,
  	1,0,0,0,287,288,1,0,0,0,288,55,1,0,0,0,289,294,3,58,29,0,290,291,5,32,
  	0,0,291,293,3,58,29,0,292,290,1,0,0,0,293,296,1,0,0,0,294,292,1,0,0,0,
  	294,295,1,0,0,0,295,57,1,0,0,0,296,294,1,0,0,0,297,302,3,60,30,0,298,
  	299,5,33,0,0,299,301,3,60,30,0,300,298,1,0,0,0,301,304,1,0,0,0,302,300,
  	1,0,0,0,302,303,1,0,0,0,303,59,1,0,0,0,304,302,1,0,0,0,305,310,3,62,31,
  	0,306,307,7,2,0,0,307,309,3,62,31,0,308,306,1,0,0,0,309,312,1,0,0,0,310,
  	308,1,0,0,0,310,311,1,0,0,0,311,61,1,0,0,0,312,310,1,0,0,0,313,318,3,
  	64,32,0,314,315,7,3,0,0,315,317,3,64,32,0,316,314,1,0,0,0,317,320,1,0,
  	0,0,318,316,1,0,0,0,318,319,1,0,0,0,319,63,1,0,0,0,320,318,1,0,0,0,321,
  	326,3,66,33,0,322,323,7,4,0,0,323,325,3,66,33,0,324,322,1,0,0,0,325,328,
  	1,0,0,0,326,324,1,0,0,0,326,327,1,0,0,0,327,65,1,0,0,0,328,326,1,0,0,
  	0,329,334,3,68,34,0,330,331,7,5,0,0,331,333,3,68,34,0,332,330,1,0,0,0,
  	333,336,1,0,0,0,334,332,1,0,0,0,334,335,1,0,0,0,335,67,1,0,0,0,336,334,
  	1,0,0,0,337,338,7,6,0,0,338,341,3,68,34,0,339,341,3,70,35,0,340,337,1,
  	0,0,0,340,339,1,0,0,0,341,69,1,0,0,0,342,347,3,74,37,0,343,344,5,12,0,
  	0,344,346,5,49,0,0,345,343,1,0,0,0,346,349,1,0,0,0,347,345,1,0,0,0,347,
  	348,1,0,0,0,348,357,1,0,0,0,349,347,1,0,0,0,350,352,5,2,0,0,351,353,3,
  	72,36,0,352,351,1,0,0,0,352,353,1,0,0,0,353,354,1,0,0,0,354,356,5,3,0,
  	0,355,350,1,0,0,0,356,359,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,
  	71,1,0,0,0,359,357,1,0,0,0,360,365,3,52,26,0,361,362,5,7,0,0,362,364,
  	3,52,26,0,363,361,1,0,0,0,364,367,1,0,0,0,365,363,1,0,0,0,365,366,1,0,
  	0,0,366,73,1,0,0,0,367,365,1,0,0,0,368,378,5,46,0,0,369,378,5,47,0,0,
  	370,378,5,13,0,0,371,378,5,48,0,0,372,378,5,49,0,0,373,374,5,2,0,0,374,
  	375,3,52,26,0,375,376,5,3,0,0,376,378,1,0,0,0,377,368,1,0,0,0,377,369,
  	1,0,0,0,377,370,1,0,0,0,377,371,1,0,0,0,377,372,1,0,0,0,377,373,1,0,0,
  	0,378,75,1,0,0,0,379,380,5,27,0,0,380,381,3,34,17,0,381,77,1,0,0,0,36,
  	81,90,103,106,112,128,134,137,144,157,163,172,176,184,195,203,214,223,
  	235,244,264,270,277,287,294,302,310,318,326,334,340,347,352,357,365,377
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  zapParserStaticData = std::move(staticData);
}

}

zapParser::zapParser(TokenStream *input) : zapParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

zapParser::zapParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  zapParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *zapParserStaticData->atn, zapParserStaticData->decisionToDFA, zapParserStaticData->sharedContextCache, options);
}

zapParser::~zapParser() {
  delete _interpreter;
}

const atn::ATN& zapParser::getATN() const {
  return *zapParserStaticData->atn;
}

std::string zapParser::getGrammarFileName() const {
  return "zap.g4";
}

const std::vector<std::string>& zapParser::getRuleNames() const {
  return zapParserStaticData->ruleNames;
}

const dfa::Vocabulary& zapParser::getVocabulary() const {
  return zapParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView zapParser::getSerializedATN() const {
  return zapParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

zapParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ProgramContext::EOF() {
  return getToken(zapParser::EOF, 0);
}

std::vector<zapParser::DeclarationContext *> zapParser::ProgramContext::declaration() {
  return getRuleContexts<zapParser::DeclarationContext>();
}

zapParser::DeclarationContext* zapParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<zapParser::DeclarationContext>(i);
}


size_t zapParser::ProgramContext::getRuleIndex() const {
  return zapParser::RuleProgram;
}


std::any zapParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ProgramContext* zapParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, zapParser::RuleProgram);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 130023440) != 0)) {
      setState(78);
      declaration();
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(84);
    match(zapParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

zapParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::FunctionDeclContext* zapParser::DeclarationContext::functionDecl() {
  return getRuleContext<zapParser::FunctionDeclContext>(0);
}

zapParser::StructDeclContext* zapParser::DeclarationContext::structDecl() {
  return getRuleContext<zapParser::StructDeclContext>(0);
}

zapParser::ComponentDeclContext* zapParser::DeclarationContext::componentDecl() {
  return getRuleContext<zapParser::ComponentDeclContext>(0);
}

zapParser::ModuleDeclContext* zapParser::DeclarationContext::moduleDecl() {
  return getRuleContext<zapParser::ModuleDeclContext>(0);
}


size_t zapParser::DeclarationContext::getRuleIndex() const {
  return zapParser::RuleDeclaration;
}


std::any zapParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

zapParser::DeclarationContext* zapParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, zapParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__3:
      case zapParser::FUNC: {
        enterOuterAlt(_localctx, 1);
        setState(86);
        functionDecl();
        break;
      }

      case zapParser::STRUCT: {
        enterOuterAlt(_localctx, 2);
        setState(87);
        structDecl();
        break;
      }

      case zapParser::COMPONENT:
      case zapParser::READONLY: {
        enterOuterAlt(_localctx, 3);
        setState(88);
        componentDecl();
        break;
      }

      case zapParser::MODULE: {
        enterOuterAlt(_localctx, 4);
        setState(89);
        moduleDecl();
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

//----------------- StatementContext ------------------------------------------------------------------

zapParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::VariableDeclContext* zapParser::StatementContext::variableDecl() {
  return getRuleContext<zapParser::VariableDeclContext>(0);
}

zapParser::ExpressionStmtContext* zapParser::StatementContext::expressionStmt() {
  return getRuleContext<zapParser::ExpressionStmtContext>(0);
}

zapParser::BlockContext* zapParser::StatementContext::block() {
  return getRuleContext<zapParser::BlockContext>(0);
}

zapParser::IfStmtContext* zapParser::StatementContext::ifStmt() {
  return getRuleContext<zapParser::IfStmtContext>(0);
}

zapParser::WhileStmtContext* zapParser::StatementContext::whileStmt() {
  return getRuleContext<zapParser::WhileStmtContext>(0);
}

zapParser::ForStmtContext* zapParser::StatementContext::forStmt() {
  return getRuleContext<zapParser::ForStmtContext>(0);
}

zapParser::ReturnStmtContext* zapParser::StatementContext::returnStmt() {
  return getRuleContext<zapParser::ReturnStmtContext>(0);
}

zapParser::YieldStmtContext* zapParser::StatementContext::yieldStmt() {
  return getRuleContext<zapParser::YieldStmtContext>(0);
}

zapParser::DeferStmtContext* zapParser::StatementContext::deferStmt() {
  return getRuleContext<zapParser::DeferStmtContext>(0);
}


size_t zapParser::StatementContext::getRuleIndex() const {
  return zapParser::RuleStatement;
}


std::any zapParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

zapParser::StatementContext* zapParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, zapParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::LET: {
        enterOuterAlt(_localctx, 1);
        setState(92);
        variableDecl();
        setState(93);
        match(zapParser::T__0);
        break;
      }

      case zapParser::T__1:
      case zapParser::BOOL:
      case zapParser::SUB:
      case zapParser::NOT:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(95);
        expressionStmt();
        break;
      }

      case zapParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(96);
        block();
        break;
      }

      case zapParser::IF: {
        enterOuterAlt(_localctx, 4);
        setState(97);
        ifStmt();
        break;
      }

      case zapParser::WHILE: {
        enterOuterAlt(_localctx, 5);
        setState(98);
        whileStmt();
        break;
      }

      case zapParser::FOR: {
        enterOuterAlt(_localctx, 6);
        setState(99);
        forStmt();
        break;
      }

      case zapParser::RETURN: {
        enterOuterAlt(_localctx, 7);
        setState(100);
        returnStmt();
        break;
      }

      case zapParser::YIELD: {
        enterOuterAlt(_localctx, 8);
        setState(101);
        yieldStmt();
        break;
      }

      case zapParser::DEFER: {
        enterOuterAlt(_localctx, 9);
        setState(102);
        deferStmt();
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

//----------------- FunctionDeclContext ------------------------------------------------------------------

zapParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::FunctionDeclContext::FUNC() {
  return getToken(zapParser::FUNC, 0);
}

tree::TerminalNode* zapParser::FunctionDeclContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::ReturnTypeContext* zapParser::FunctionDeclContext::returnType() {
  return getRuleContext<zapParser::ReturnTypeContext>(0);
}

zapParser::BlockContext* zapParser::FunctionDeclContext::block() {
  return getRuleContext<zapParser::BlockContext>(0);
}

zapParser::AttributeBlockContext* zapParser::FunctionDeclContext::attributeBlock() {
  return getRuleContext<zapParser::AttributeBlockContext>(0);
}

zapParser::ParameterListContext* zapParser::FunctionDeclContext::parameterList() {
  return getRuleContext<zapParser::ParameterListContext>(0);
}


size_t zapParser::FunctionDeclContext::getRuleIndex() const {
  return zapParser::RuleFunctionDecl;
}


std::any zapParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

zapParser::FunctionDeclContext* zapParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, zapParser::RuleFunctionDecl);
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
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__3) {
      setState(105);
      attributeBlock();
    }
    setState(108);
    match(zapParser::FUNC);
    setState(109);
    match(zapParser::IDENTIFIER);
    setState(110);
    match(zapParser::T__1);
    setState(112);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::IDENTIFIER) {
      setState(111);
      parameterList();
    }
    setState(114);
    match(zapParser::T__2);
    setState(115);
    returnType();
    setState(116);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeBlockContext ------------------------------------------------------------------

zapParser::AttributeBlockContext::AttributeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::AttributeListContext* zapParser::AttributeBlockContext::attributeList() {
  return getRuleContext<zapParser::AttributeListContext>(0);
}


size_t zapParser::AttributeBlockContext::getRuleIndex() const {
  return zapParser::RuleAttributeBlock;
}


std::any zapParser::AttributeBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAttributeBlock(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AttributeBlockContext* zapParser::attributeBlock() {
  AttributeBlockContext *_localctx = _tracker.createInstance<AttributeBlockContext>(_ctx, getState());
  enterRule(_localctx, 8, zapParser::RuleAttributeBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(zapParser::T__3);
    setState(119);
    match(zapParser::T__4);
    setState(120);
    attributeList();
    setState(121);
    match(zapParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeListContext ------------------------------------------------------------------

zapParser::AttributeListContext::AttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::AttributeContext *> zapParser::AttributeListContext::attribute() {
  return getRuleContexts<zapParser::AttributeContext>();
}

zapParser::AttributeContext* zapParser::AttributeListContext::attribute(size_t i) {
  return getRuleContext<zapParser::AttributeContext>(i);
}


size_t zapParser::AttributeListContext::getRuleIndex() const {
  return zapParser::RuleAttributeList;
}


std::any zapParser::AttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAttributeList(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AttributeListContext* zapParser::attributeList() {
  AttributeListContext *_localctx = _tracker.createInstance<AttributeListContext>(_ctx, getState());
  enterRule(_localctx, 10, zapParser::RuleAttributeList);
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
    setState(123);
    attribute();
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(124);
      match(zapParser::T__6);
      setState(125);
      attribute();
      setState(130);
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

//----------------- AttributeContext ------------------------------------------------------------------

zapParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::AttributeContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::AttributeArgsContext* zapParser::AttributeContext::attributeArgs() {
  return getRuleContext<zapParser::AttributeArgsContext>(0);
}


size_t zapParser::AttributeContext::getRuleIndex() const {
  return zapParser::RuleAttribute;
}


std::any zapParser::AttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAttribute(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AttributeContext* zapParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 12, zapParser::RuleAttribute);
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
    setState(131);
    match(zapParser::IDENTIFIER);
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__1) {
      setState(132);
      match(zapParser::T__1);
      setState(134);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 914793674309632) != 0)) {
        setState(133);
        attributeArgs();
      }
      setState(136);
      match(zapParser::T__2);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeArgsContext ------------------------------------------------------------------

zapParser::AttributeArgsContext::AttributeArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::AttributeArgContext *> zapParser::AttributeArgsContext::attributeArg() {
  return getRuleContexts<zapParser::AttributeArgContext>();
}

zapParser::AttributeArgContext* zapParser::AttributeArgsContext::attributeArg(size_t i) {
  return getRuleContext<zapParser::AttributeArgContext>(i);
}


size_t zapParser::AttributeArgsContext::getRuleIndex() const {
  return zapParser::RuleAttributeArgs;
}


std::any zapParser::AttributeArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAttributeArgs(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AttributeArgsContext* zapParser::attributeArgs() {
  AttributeArgsContext *_localctx = _tracker.createInstance<AttributeArgsContext>(_ctx, getState());
  enterRule(_localctx, 14, zapParser::RuleAttributeArgs);
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
    setState(139);
    attributeArg();
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(140);
      match(zapParser::T__6);
      setState(141);
      attributeArg();
      setState(146);
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

//----------------- AttributeArgContext ------------------------------------------------------------------

zapParser::AttributeArgContext::AttributeArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::AttributeArgContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

tree::TerminalNode* zapParser::AttributeArgContext::STRING() {
  return getToken(zapParser::STRING, 0);
}

tree::TerminalNode* zapParser::AttributeArgContext::INT() {
  return getToken(zapParser::INT, 0);
}


size_t zapParser::AttributeArgContext::getRuleIndex() const {
  return zapParser::RuleAttributeArg;
}


std::any zapParser::AttributeArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAttributeArg(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AttributeArgContext* zapParser::attributeArg() {
  AttributeArgContext *_localctx = _tracker.createInstance<AttributeArgContext>(_ctx, getState());
  enterRule(_localctx, 16, zapParser::RuleAttributeArg);
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
    setState(147);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 914793674309632) != 0))) {
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

//----------------- ReturnTypeContext ------------------------------------------------------------------

zapParser::ReturnTypeContext::ReturnTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ReturnTypeContext::ARROW() {
  return getToken(zapParser::ARROW, 0);
}

zapParser::TypeContext* zapParser::ReturnTypeContext::type() {
  return getRuleContext<zapParser::TypeContext>(0);
}


size_t zapParser::ReturnTypeContext::getRuleIndex() const {
  return zapParser::RuleReturnType;
}


std::any zapParser::ReturnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitReturnType(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ReturnTypeContext* zapParser::returnType() {
  ReturnTypeContext *_localctx = _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, zapParser::RuleReturnType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(zapParser::ARROW);
    setState(150);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

zapParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::ParameterContext *> zapParser::ParameterListContext::parameter() {
  return getRuleContexts<zapParser::ParameterContext>();
}

zapParser::ParameterContext* zapParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<zapParser::ParameterContext>(i);
}


size_t zapParser::ParameterListContext::getRuleIndex() const {
  return zapParser::RuleParameterList;
}


std::any zapParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ParameterListContext* zapParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 20, zapParser::RuleParameterList);
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
    setState(152);
    parameter();
    setState(157);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(153);
      match(zapParser::T__6);
      setState(154);
      parameter();
      setState(159);
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

//----------------- ParameterContext ------------------------------------------------------------------

zapParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ParameterContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::TypeContext* zapParser::ParameterContext::type() {
  return getRuleContext<zapParser::TypeContext>(0);
}

tree::TerminalNode* zapParser::ParameterContext::REF() {
  return getToken(zapParser::REF, 0);
}


size_t zapParser::ParameterContext::getRuleIndex() const {
  return zapParser::RuleParameter;
}


std::any zapParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ParameterContext* zapParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 22, zapParser::RuleParameter);
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
    setState(160);
    match(zapParser::IDENTIFIER);
    setState(161);
    match(zapParser::T__7);
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::REF) {
      setState(162);
      match(zapParser::REF);
    }
    setState(165);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

zapParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::TypeContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

tree::TerminalNode* zapParser::TypeContext::VOID() {
  return getToken(zapParser::VOID, 0);
}

tree::TerminalNode* zapParser::TypeContext::LT() {
  return getToken(zapParser::LT, 0);
}

zapParser::TypeContext* zapParser::TypeContext::type() {
  return getRuleContext<zapParser::TypeContext>(0);
}

tree::TerminalNode* zapParser::TypeContext::GT() {
  return getToken(zapParser::GT, 0);
}


size_t zapParser::TypeContext::getRuleIndex() const {
  return zapParser::RuleType;
}


std::any zapParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

zapParser::TypeContext* zapParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 24, zapParser::RuleType);
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
    setState(167);
    _la = _input->LA(1);
    if (!(_la == zapParser::VOID

    || _la == zapParser::IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::LT) {
      setState(168);
      match(zapParser::LT);
      setState(169);
      type();
      setState(170);
      match(zapParser::GT);
    }
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__4) {
      setState(174);
      match(zapParser::T__4);
      setState(175);
      match(zapParser::T__5);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclContext ------------------------------------------------------------------

zapParser::StructDeclContext::StructDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::StructDeclContext::STRUCT() {
  return getToken(zapParser::STRUCT, 0);
}

tree::TerminalNode* zapParser::StructDeclContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

std::vector<zapParser::StructFieldContext *> zapParser::StructDeclContext::structField() {
  return getRuleContexts<zapParser::StructFieldContext>();
}

zapParser::StructFieldContext* zapParser::StructDeclContext::structField(size_t i) {
  return getRuleContext<zapParser::StructFieldContext>(i);
}


size_t zapParser::StructDeclContext::getRuleIndex() const {
  return zapParser::RuleStructDecl;
}


std::any zapParser::StructDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitStructDecl(this);
  else
    return visitor->visitChildren(this);
}

zapParser::StructDeclContext* zapParser::structDecl() {
  StructDeclContext *_localctx = _tracker.createInstance<StructDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, zapParser::RuleStructDecl);
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
    setState(178);
    match(zapParser::STRUCT);
    setState(179);
    match(zapParser::IDENTIFIER);
    setState(180);
    match(zapParser::T__8);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::IDENTIFIER) {
      setState(181);
      structField();
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(187);
    match(zapParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructFieldContext ------------------------------------------------------------------

zapParser::StructFieldContext::StructFieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::StructFieldContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::TypeContext* zapParser::StructFieldContext::type() {
  return getRuleContext<zapParser::TypeContext>(0);
}


size_t zapParser::StructFieldContext::getRuleIndex() const {
  return zapParser::RuleStructField;
}


std::any zapParser::StructFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitStructField(this);
  else
    return visitor->visitChildren(this);
}

zapParser::StructFieldContext* zapParser::structField() {
  StructFieldContext *_localctx = _tracker.createInstance<StructFieldContext>(_ctx, getState());
  enterRule(_localctx, 28, zapParser::RuleStructField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(zapParser::IDENTIFIER);
    setState(190);
    match(zapParser::T__7);
    setState(191);
    type();
    setState(192);
    match(zapParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentDeclContext ------------------------------------------------------------------

zapParser::ComponentDeclContext::ComponentDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ComponentDeclContext::COMPONENT() {
  return getToken(zapParser::COMPONENT, 0);
}

tree::TerminalNode* zapParser::ComponentDeclContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

tree::TerminalNode* zapParser::ComponentDeclContext::READONLY() {
  return getToken(zapParser::READONLY, 0);
}

std::vector<zapParser::StructFieldContext *> zapParser::ComponentDeclContext::structField() {
  return getRuleContexts<zapParser::StructFieldContext>();
}

zapParser::StructFieldContext* zapParser::ComponentDeclContext::structField(size_t i) {
  return getRuleContext<zapParser::StructFieldContext>(i);
}


size_t zapParser::ComponentDeclContext::getRuleIndex() const {
  return zapParser::RuleComponentDecl;
}


std::any zapParser::ComponentDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitComponentDecl(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ComponentDeclContext* zapParser::componentDecl() {
  ComponentDeclContext *_localctx = _tracker.createInstance<ComponentDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, zapParser::RuleComponentDecl);
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
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::READONLY) {
      setState(194);
      match(zapParser::READONLY);
    }
    setState(197);
    match(zapParser::COMPONENT);
    setState(198);
    match(zapParser::IDENTIFIER);
    setState(199);
    match(zapParser::T__8);
    setState(203);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::IDENTIFIER) {
      setState(200);
      structField();
      setState(205);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(206);
    match(zapParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleDeclContext ------------------------------------------------------------------

zapParser::ModuleDeclContext::ModuleDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ModuleDeclContext::MODULE() {
  return getToken(zapParser::MODULE, 0);
}

tree::TerminalNode* zapParser::ModuleDeclContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

std::vector<zapParser::StatementContext *> zapParser::ModuleDeclContext::statement() {
  return getRuleContexts<zapParser::StatementContext>();
}

zapParser::StatementContext* zapParser::ModuleDeclContext::statement(size_t i) {
  return getRuleContext<zapParser::StatementContext>(i);
}


size_t zapParser::ModuleDeclContext::getRuleIndex() const {
  return zapParser::RuleModuleDecl;
}


std::any zapParser::ModuleDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitModuleDecl(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ModuleDeclContext* zapParser::moduleDecl() {
  ModuleDeclContext *_localctx = _tracker.createInstance<ModuleDeclContext>(_ctx, getState());
  enterRule(_localctx, 32, zapParser::RuleModuleDecl);
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
    setState(208);
    match(zapParser::MODULE);
    setState(209);
    match(zapParser::IDENTIFIER);
    setState(210);
    match(zapParser::T__8);
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1090852977861124) != 0)) {
      setState(211);
      statement();
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(217);
    match(zapParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

zapParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::StatementContext *> zapParser::BlockContext::statement() {
  return getRuleContexts<zapParser::StatementContext>();
}

zapParser::StatementContext* zapParser::BlockContext::statement(size_t i) {
  return getRuleContext<zapParser::StatementContext>(i);
}


size_t zapParser::BlockContext::getRuleIndex() const {
  return zapParser::RuleBlock;
}


std::any zapParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

zapParser::BlockContext* zapParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 34, zapParser::RuleBlock);
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
    setState(219);
    match(zapParser::T__8);
    setState(223);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1090852977861124) != 0)) {
      setState(220);
      statement();
      setState(225);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(226);
    match(zapParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclContext ------------------------------------------------------------------

zapParser::VariableDeclContext::VariableDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::VariableDeclContext::LET() {
  return getToken(zapParser::LET, 0);
}

tree::TerminalNode* zapParser::VariableDeclContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::TypeContext* zapParser::VariableDeclContext::type() {
  return getRuleContext<zapParser::TypeContext>(0);
}

zapParser::ExpressionContext* zapParser::VariableDeclContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}

zapParser::AotBlockContext* zapParser::VariableDeclContext::aotBlock() {
  return getRuleContext<zapParser::AotBlockContext>(0);
}


size_t zapParser::VariableDeclContext::getRuleIndex() const {
  return zapParser::RuleVariableDecl;
}


std::any zapParser::VariableDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitVariableDecl(this);
  else
    return visitor->visitChildren(this);
}

zapParser::VariableDeclContext* zapParser::variableDecl() {
  VariableDeclContext *_localctx = _tracker.createInstance<VariableDeclContext>(_ctx, getState());
  enterRule(_localctx, 36, zapParser::RuleVariableDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(zapParser::LET);
    setState(229);
    match(zapParser::IDENTIFIER);
    setState(230);
    match(zapParser::T__7);
    setState(231);
    type();
    setState(232);
    match(zapParser::T__10);
    setState(235);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__1:
      case zapParser::BOOL:
      case zapParser::SUB:
      case zapParser::NOT:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        setState(233);
        expression();
        break;
      }

      case zapParser::AOT: {
        setState(234);
        aotBlock();
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

//----------------- IfStmtContext ------------------------------------------------------------------

zapParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::IfStmtContext::IF() {
  return getToken(zapParser::IF, 0);
}

zapParser::ExpressionContext* zapParser::IfStmtContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}

std::vector<zapParser::BlockContext *> zapParser::IfStmtContext::block() {
  return getRuleContexts<zapParser::BlockContext>();
}

zapParser::BlockContext* zapParser::IfStmtContext::block(size_t i) {
  return getRuleContext<zapParser::BlockContext>(i);
}

tree::TerminalNode* zapParser::IfStmtContext::ELSE() {
  return getToken(zapParser::ELSE, 0);
}


size_t zapParser::IfStmtContext::getRuleIndex() const {
  return zapParser::RuleIfStmt;
}


std::any zapParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::IfStmtContext* zapParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 38, zapParser::RuleIfStmt);
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
    setState(237);
    match(zapParser::IF);
    setState(238);
    match(zapParser::T__1);
    setState(239);
    expression();
    setState(240);
    match(zapParser::T__2);
    setState(241);
    block();
    setState(244);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::ELSE) {
      setState(242);
      match(zapParser::ELSE);
      setState(243);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

zapParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::WhileStmtContext::WHILE() {
  return getToken(zapParser::WHILE, 0);
}

zapParser::ExpressionContext* zapParser::WhileStmtContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}

zapParser::BlockContext* zapParser::WhileStmtContext::block() {
  return getRuleContext<zapParser::BlockContext>(0);
}


size_t zapParser::WhileStmtContext::getRuleIndex() const {
  return zapParser::RuleWhileStmt;
}


std::any zapParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::WhileStmtContext* zapParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, zapParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(zapParser::WHILE);
    setState(247);
    match(zapParser::T__1);
    setState(248);
    expression();
    setState(249);
    match(zapParser::T__2);
    setState(250);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

zapParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ForStmtContext::FOR() {
  return getToken(zapParser::FOR, 0);
}

zapParser::VariableDeclContext* zapParser::ForStmtContext::variableDecl() {
  return getRuleContext<zapParser::VariableDeclContext>(0);
}

std::vector<zapParser::ExpressionContext *> zapParser::ForStmtContext::expression() {
  return getRuleContexts<zapParser::ExpressionContext>();
}

zapParser::ExpressionContext* zapParser::ForStmtContext::expression(size_t i) {
  return getRuleContext<zapParser::ExpressionContext>(i);
}

zapParser::BlockContext* zapParser::ForStmtContext::block() {
  return getRuleContext<zapParser::BlockContext>(0);
}


size_t zapParser::ForStmtContext::getRuleIndex() const {
  return zapParser::RuleForStmt;
}


std::any zapParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ForStmtContext* zapParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 42, zapParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(zapParser::FOR);
    setState(253);
    match(zapParser::T__1);
    setState(254);
    variableDecl();
    setState(255);
    match(zapParser::T__0);
    setState(256);
    expression();
    setState(257);
    match(zapParser::T__0);
    setState(258);
    expression();
    setState(259);
    match(zapParser::T__2);
    setState(260);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

zapParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::ReturnStmtContext::RETURN() {
  return getToken(zapParser::RETURN, 0);
}

zapParser::ExpressionContext* zapParser::ReturnStmtContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}


size_t zapParser::ReturnStmtContext::getRuleIndex() const {
  return zapParser::RuleReturnStmt;
}


std::any zapParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ReturnStmtContext* zapParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 44, zapParser::RuleReturnStmt);
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
    match(zapParser::RETURN);
    setState(264);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1090852973715460) != 0)) {
      setState(263);
      expression();
    }
    setState(266);
    match(zapParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YieldStmtContext ------------------------------------------------------------------

zapParser::YieldStmtContext::YieldStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::YieldStmtContext::YIELD() {
  return getToken(zapParser::YIELD, 0);
}

zapParser::ExpressionContext* zapParser::YieldStmtContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}


size_t zapParser::YieldStmtContext::getRuleIndex() const {
  return zapParser::RuleYieldStmt;
}


std::any zapParser::YieldStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitYieldStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::YieldStmtContext* zapParser::yieldStmt() {
  YieldStmtContext *_localctx = _tracker.createInstance<YieldStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, zapParser::RuleYieldStmt);
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
    setState(268);
    match(zapParser::YIELD);
    setState(270);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1090852973715460) != 0)) {
      setState(269);
      expression();
    }
    setState(272);
    match(zapParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeferStmtContext ------------------------------------------------------------------

zapParser::DeferStmtContext::DeferStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::DeferStmtContext::DEFER() {
  return getToken(zapParser::DEFER, 0);
}

zapParser::BlockContext* zapParser::DeferStmtContext::block() {
  return getRuleContext<zapParser::BlockContext>(0);
}

zapParser::ExpressionStmtContext* zapParser::DeferStmtContext::expressionStmt() {
  return getRuleContext<zapParser::ExpressionStmtContext>(0);
}


size_t zapParser::DeferStmtContext::getRuleIndex() const {
  return zapParser::RuleDeferStmt;
}


std::any zapParser::DeferStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitDeferStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::DeferStmtContext* zapParser::deferStmt() {
  DeferStmtContext *_localctx = _tracker.createInstance<DeferStmtContext>(_ctx, getState());
  enterRule(_localctx, 48, zapParser::RuleDeferStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(zapParser::DEFER);
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__8: {
        setState(275);
        block();
        break;
      }

      case zapParser::T__1:
      case zapParser::BOOL:
      case zapParser::SUB:
      case zapParser::NOT:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        setState(276);
        expressionStmt();
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

//----------------- ExpressionStmtContext ------------------------------------------------------------------

zapParser::ExpressionStmtContext::ExpressionStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::ExpressionContext* zapParser::ExpressionStmtContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}


size_t zapParser::ExpressionStmtContext::getRuleIndex() const {
  return zapParser::RuleExpressionStmt;
}


std::any zapParser::ExpressionStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitExpressionStmt(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ExpressionStmtContext* zapParser::expressionStmt() {
  ExpressionStmtContext *_localctx = _tracker.createInstance<ExpressionStmtContext>(_ctx, getState());
  enterRule(_localctx, 50, zapParser::RuleExpressionStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    expression();
    setState(280);
    match(zapParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

zapParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::AssignmentContext* zapParser::ExpressionContext::assignment() {
  return getRuleContext<zapParser::AssignmentContext>(0);
}


size_t zapParser::ExpressionContext::getRuleIndex() const {
  return zapParser::RuleExpression;
}


std::any zapParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ExpressionContext* zapParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 52, zapParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    assignment();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

zapParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::LogicOrContext* zapParser::AssignmentContext::logicOr() {
  return getRuleContext<zapParser::LogicOrContext>(0);
}

zapParser::ExpressionContext* zapParser::AssignmentContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}


size_t zapParser::AssignmentContext::getRuleIndex() const {
  return zapParser::RuleAssignment;
}


std::any zapParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AssignmentContext* zapParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 54, zapParser::RuleAssignment);
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
    setState(284);
    logicOr();
    setState(287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__10) {
      setState(285);
      match(zapParser::T__10);
      setState(286);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicOrContext ------------------------------------------------------------------

zapParser::LogicOrContext::LogicOrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::LogicAndContext *> zapParser::LogicOrContext::logicAnd() {
  return getRuleContexts<zapParser::LogicAndContext>();
}

zapParser::LogicAndContext* zapParser::LogicOrContext::logicAnd(size_t i) {
  return getRuleContext<zapParser::LogicAndContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::LogicOrContext::OR() {
  return getTokens(zapParser::OR);
}

tree::TerminalNode* zapParser::LogicOrContext::OR(size_t i) {
  return getToken(zapParser::OR, i);
}


size_t zapParser::LogicOrContext::getRuleIndex() const {
  return zapParser::RuleLogicOr;
}


std::any zapParser::LogicOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitLogicOr(this);
  else
    return visitor->visitChildren(this);
}

zapParser::LogicOrContext* zapParser::logicOr() {
  LogicOrContext *_localctx = _tracker.createInstance<LogicOrContext>(_ctx, getState());
  enterRule(_localctx, 56, zapParser::RuleLogicOr);
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
    setState(289);
    logicAnd();
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::OR) {
      setState(290);
      match(zapParser::OR);
      setState(291);
      logicAnd();
      setState(296);
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

//----------------- LogicAndContext ------------------------------------------------------------------

zapParser::LogicAndContext::LogicAndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::EqualityContext *> zapParser::LogicAndContext::equality() {
  return getRuleContexts<zapParser::EqualityContext>();
}

zapParser::EqualityContext* zapParser::LogicAndContext::equality(size_t i) {
  return getRuleContext<zapParser::EqualityContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::LogicAndContext::AND() {
  return getTokens(zapParser::AND);
}

tree::TerminalNode* zapParser::LogicAndContext::AND(size_t i) {
  return getToken(zapParser::AND, i);
}


size_t zapParser::LogicAndContext::getRuleIndex() const {
  return zapParser::RuleLogicAnd;
}


std::any zapParser::LogicAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitLogicAnd(this);
  else
    return visitor->visitChildren(this);
}

zapParser::LogicAndContext* zapParser::logicAnd() {
  LogicAndContext *_localctx = _tracker.createInstance<LogicAndContext>(_ctx, getState());
  enterRule(_localctx, 58, zapParser::RuleLogicAnd);
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
    setState(297);
    equality();
    setState(302);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::AND) {
      setState(298);
      match(zapParser::AND);
      setState(299);
      equality();
      setState(304);
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

//----------------- EqualityContext ------------------------------------------------------------------

zapParser::EqualityContext::EqualityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::ComparisonContext *> zapParser::EqualityContext::comparison() {
  return getRuleContexts<zapParser::ComparisonContext>();
}

zapParser::ComparisonContext* zapParser::EqualityContext::comparison(size_t i) {
  return getRuleContext<zapParser::ComparisonContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::EqualityContext::EQ() {
  return getTokens(zapParser::EQ);
}

tree::TerminalNode* zapParser::EqualityContext::EQ(size_t i) {
  return getToken(zapParser::EQ, i);
}

std::vector<tree::TerminalNode *> zapParser::EqualityContext::NEQ() {
  return getTokens(zapParser::NEQ);
}

tree::TerminalNode* zapParser::EqualityContext::NEQ(size_t i) {
  return getToken(zapParser::NEQ, i);
}


size_t zapParser::EqualityContext::getRuleIndex() const {
  return zapParser::RuleEquality;
}


std::any zapParser::EqualityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitEquality(this);
  else
    return visitor->visitChildren(this);
}

zapParser::EqualityContext* zapParser::equality() {
  EqualityContext *_localctx = _tracker.createInstance<EqualityContext>(_ctx, getState());
  enterRule(_localctx, 60, zapParser::RuleEquality);
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
    setState(305);
    comparison();
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::EQ

    || _la == zapParser::NEQ) {
      setState(306);
      antlrcpp::downCast<EqualityContext *>(_localctx)->_tset794 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == zapParser::EQ

      || _la == zapParser::NEQ)) {
        antlrcpp::downCast<EqualityContext *>(_localctx)->_tset794 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<EqualityContext *>(_localctx)->op.push_back(antlrcpp::downCast<EqualityContext *>(_localctx)->_tset794);
      setState(307);
      comparison();
      setState(312);
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

//----------------- ComparisonContext ------------------------------------------------------------------

zapParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::TermContext *> zapParser::ComparisonContext::term() {
  return getRuleContexts<zapParser::TermContext>();
}

zapParser::TermContext* zapParser::ComparisonContext::term(size_t i) {
  return getRuleContext<zapParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::LT() {
  return getTokens(zapParser::LT);
}

tree::TerminalNode* zapParser::ComparisonContext::LT(size_t i) {
  return getToken(zapParser::LT, i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::LTE() {
  return getTokens(zapParser::LTE);
}

tree::TerminalNode* zapParser::ComparisonContext::LTE(size_t i) {
  return getToken(zapParser::LTE, i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::GT() {
  return getTokens(zapParser::GT);
}

tree::TerminalNode* zapParser::ComparisonContext::GT(size_t i) {
  return getToken(zapParser::GT, i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::GTE() {
  return getTokens(zapParser::GTE);
}

tree::TerminalNode* zapParser::ComparisonContext::GTE(size_t i) {
  return getToken(zapParser::GTE, i);
}


size_t zapParser::ComparisonContext::getRuleIndex() const {
  return zapParser::RuleComparison;
}


std::any zapParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ComparisonContext* zapParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 62, zapParser::RuleComparison);
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
    setState(313);
    term();
    setState(318);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32985348833280) != 0)) {
      setState(314);
      antlrcpp::downCast<ComparisonContext *>(_localctx)->_tset819 = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32985348833280) != 0))) {
        antlrcpp::downCast<ComparisonContext *>(_localctx)->_tset819 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<ComparisonContext *>(_localctx)->op.push_back(antlrcpp::downCast<ComparisonContext *>(_localctx)->_tset819);
      setState(315);
      term();
      setState(320);
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

//----------------- TermContext ------------------------------------------------------------------

zapParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::FactorContext *> zapParser::TermContext::factor() {
  return getRuleContexts<zapParser::FactorContext>();
}

zapParser::FactorContext* zapParser::TermContext::factor(size_t i) {
  return getRuleContext<zapParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::TermContext::ADD() {
  return getTokens(zapParser::ADD);
}

tree::TerminalNode* zapParser::TermContext::ADD(size_t i) {
  return getToken(zapParser::ADD, i);
}

std::vector<tree::TerminalNode *> zapParser::TermContext::SUB() {
  return getTokens(zapParser::SUB);
}

tree::TerminalNode* zapParser::TermContext::SUB(size_t i) {
  return getToken(zapParser::SUB, i);
}


size_t zapParser::TermContext::getRuleIndex() const {
  return zapParser::RuleTerm;
}


std::any zapParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

zapParser::TermContext* zapParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 64, zapParser::RuleTerm);
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
    factor();
    setState(326);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::ADD

    || _la == zapParser::SUB) {
      setState(322);
      antlrcpp::downCast<TermContext *>(_localctx)->_tset852 = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == zapParser::ADD

      || _la == zapParser::SUB)) {
        antlrcpp::downCast<TermContext *>(_localctx)->_tset852 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<TermContext *>(_localctx)->op.push_back(antlrcpp::downCast<TermContext *>(_localctx)->_tset852);
      setState(323);
      factor();
      setState(328);
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

//----------------- FactorContext ------------------------------------------------------------------

zapParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::UnaryContext *> zapParser::FactorContext::unary() {
  return getRuleContexts<zapParser::UnaryContext>();
}

zapParser::UnaryContext* zapParser::FactorContext::unary(size_t i) {
  return getRuleContext<zapParser::UnaryContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::FactorContext::MUL() {
  return getTokens(zapParser::MUL);
}

tree::TerminalNode* zapParser::FactorContext::MUL(size_t i) {
  return getToken(zapParser::MUL, i);
}

std::vector<tree::TerminalNode *> zapParser::FactorContext::DIV() {
  return getTokens(zapParser::DIV);
}

tree::TerminalNode* zapParser::FactorContext::DIV(size_t i) {
  return getToken(zapParser::DIV, i);
}

std::vector<tree::TerminalNode *> zapParser::FactorContext::MOD() {
  return getTokens(zapParser::MOD);
}

tree::TerminalNode* zapParser::FactorContext::MOD(size_t i) {
  return getToken(zapParser::MOD, i);
}


size_t zapParser::FactorContext::getRuleIndex() const {
  return zapParser::RuleFactor;
}


std::any zapParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

zapParser::FactorContext* zapParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 66, zapParser::RuleFactor);
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
    setState(329);
    unary();
    setState(334);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1924145348608) != 0)) {
      setState(330);
      antlrcpp::downCast<FactorContext *>(_localctx)->_tset877 = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1924145348608) != 0))) {
        antlrcpp::downCast<FactorContext *>(_localctx)->_tset877 = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      antlrcpp::downCast<FactorContext *>(_localctx)->op.push_back(antlrcpp::downCast<FactorContext *>(_localctx)->_tset877);
      setState(331);
      unary();
      setState(336);
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

//----------------- UnaryContext ------------------------------------------------------------------

zapParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::UnaryContext* zapParser::UnaryContext::unary() {
  return getRuleContext<zapParser::UnaryContext>(0);
}

tree::TerminalNode* zapParser::UnaryContext::NOT() {
  return getToken(zapParser::NOT, 0);
}

tree::TerminalNode* zapParser::UnaryContext::SUB() {
  return getToken(zapParser::SUB, 0);
}

zapParser::CallContext* zapParser::UnaryContext::call() {
  return getRuleContext<zapParser::CallContext>(0);
}


size_t zapParser::UnaryContext::getRuleIndex() const {
  return zapParser::RuleUnary;
}


std::any zapParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

zapParser::UnaryContext* zapParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 68, zapParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(340);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::SUB:
      case zapParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(337);
        antlrcpp::downCast<UnaryContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == zapParser::SUB

        || _la == zapParser::NOT)) {
          antlrcpp::downCast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(338);
        unary();
        break;
      }

      case zapParser::T__1:
      case zapParser::BOOL:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(339);
        call();
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

//----------------- CallContext ------------------------------------------------------------------

zapParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

zapParser::PrimaryContext* zapParser::CallContext::primary() {
  return getRuleContext<zapParser::PrimaryContext>(0);
}

std::vector<tree::TerminalNode *> zapParser::CallContext::IDENTIFIER() {
  return getTokens(zapParser::IDENTIFIER);
}

tree::TerminalNode* zapParser::CallContext::IDENTIFIER(size_t i) {
  return getToken(zapParser::IDENTIFIER, i);
}

std::vector<zapParser::ArgumentListContext *> zapParser::CallContext::argumentList() {
  return getRuleContexts<zapParser::ArgumentListContext>();
}

zapParser::ArgumentListContext* zapParser::CallContext::argumentList(size_t i) {
  return getRuleContext<zapParser::ArgumentListContext>(i);
}


size_t zapParser::CallContext::getRuleIndex() const {
  return zapParser::RuleCall;
}


std::any zapParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

zapParser::CallContext* zapParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 70, zapParser::RuleCall);
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
    setState(342);
    primary();
    setState(347);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__11) {
      setState(343);
      match(zapParser::T__11);
      setState(344);
      match(zapParser::IDENTIFIER);
      setState(349);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(357);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__1) {
      setState(350);
      match(zapParser::T__1);
      setState(352);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1090852973715460) != 0)) {
        setState(351);
        argumentList();
      }
      setState(354);
      match(zapParser::T__2);
      setState(359);
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

//----------------- ArgumentListContext ------------------------------------------------------------------

zapParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<zapParser::ExpressionContext *> zapParser::ArgumentListContext::expression() {
  return getRuleContexts<zapParser::ExpressionContext>();
}

zapParser::ExpressionContext* zapParser::ArgumentListContext::expression(size_t i) {
  return getRuleContext<zapParser::ExpressionContext>(i);
}


size_t zapParser::ArgumentListContext::getRuleIndex() const {
  return zapParser::RuleArgumentList;
}


std::any zapParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

zapParser::ArgumentListContext* zapParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 72, zapParser::RuleArgumentList);
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
    setState(360);
    expression();
    setState(365);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(361);
      match(zapParser::T__6);
      setState(362);
      expression();
      setState(367);
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

//----------------- PrimaryContext ------------------------------------------------------------------

zapParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::PrimaryContext::INT() {
  return getToken(zapParser::INT, 0);
}

tree::TerminalNode* zapParser::PrimaryContext::FLOAT() {
  return getToken(zapParser::FLOAT, 0);
}

tree::TerminalNode* zapParser::PrimaryContext::BOOL() {
  return getToken(zapParser::BOOL, 0);
}

tree::TerminalNode* zapParser::PrimaryContext::STRING() {
  return getToken(zapParser::STRING, 0);
}

tree::TerminalNode* zapParser::PrimaryContext::IDENTIFIER() {
  return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::ExpressionContext* zapParser::PrimaryContext::expression() {
  return getRuleContext<zapParser::ExpressionContext>(0);
}


size_t zapParser::PrimaryContext::getRuleIndex() const {
  return zapParser::RulePrimary;
}


std::any zapParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

zapParser::PrimaryContext* zapParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 74, zapParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(377);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(368);
        match(zapParser::INT);
        break;
      }

      case zapParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(369);
        match(zapParser::FLOAT);
        break;
      }

      case zapParser::BOOL: {
        enterOuterAlt(_localctx, 3);
        setState(370);
        match(zapParser::BOOL);
        break;
      }

      case zapParser::STRING: {
        enterOuterAlt(_localctx, 4);
        setState(371);
        match(zapParser::STRING);
        break;
      }

      case zapParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 5);
        setState(372);
        match(zapParser::IDENTIFIER);
        break;
      }

      case zapParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(373);
        match(zapParser::T__1);
        setState(374);
        expression();
        setState(375);
        match(zapParser::T__2);
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

//----------------- AotBlockContext ------------------------------------------------------------------

zapParser::AotBlockContext::AotBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* zapParser::AotBlockContext::AOT() {
  return getToken(zapParser::AOT, 0);
}

zapParser::BlockContext* zapParser::AotBlockContext::block() {
  return getRuleContext<zapParser::BlockContext>(0);
}


size_t zapParser::AotBlockContext::getRuleIndex() const {
  return zapParser::RuleAotBlock;
}


std::any zapParser::AotBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<zapVisitor*>(visitor))
    return parserVisitor->visitAotBlock(this);
  else
    return visitor->visitChildren(this);
}

zapParser::AotBlockContext* zapParser::aotBlock() {
  AotBlockContext *_localctx = _tracker.createInstance<AotBlockContext>(_ctx, getState());
  enterRule(_localctx, 76, zapParser::RuleAotBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    match(zapParser::AOT);
    setState(380);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void zapParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  zapParserInitialize();
#else
  ::antlr4::internal::call_once(zapParserOnceFlag, zapParserInitialize);
#endif
}
