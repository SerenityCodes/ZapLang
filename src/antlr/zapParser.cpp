
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
      "program", "statement", "functionDecl", "attributeBlock", "attributeList", 
      "attribute", "attributeArgs", "attributeArg", "returnType", "parameterList", 
      "parameter", "type", "structDecl", "structField", "componentDecl", 
      "moduleDecl", "block", "variableDecl", "ifStmt", "whileStmt", "forStmt", 
      "returnStmt", "yieldStmt", "deferStmt", "expressionStmt", "expression", 
      "assignment", "logicOr", "logicAnd", "equality", "comparison", "term", 
      "factor", "unary", "call", "argumentList", "primary", "aotBlock"
    },
    std::vector<std::string>{
      "", "';'", "'('", "')'", "'@'", "'['", "']'", "','", "':'", "'<'", 
      "'>'", "'{'", "'}'", "'='", "'||'", "'&&'", "'=='", "'!='", "'<='", 
      "'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "", "'if'", "'else'", 
      "'while'", "'for'", "'return'", "'yield'", "'defer'", "'let'", "'func'", 
      "'struct'", "'component'", "'readonly'", "'module'", "'system'", "'aot'", 
      "'ref'", "'void'", "'->'", "'use'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "BOOL", "IF", "ELSE", "WHILE", 
      "FOR", "RETURN", "YIELD", "DEFER", "LET", "FUNC", "STRUCT", "COMPONENT", 
      "READONLY", "MODULE", "SYSTEM", "AOT", "REF", "VOID", "ARROW", "USE", 
      "INT", "FLOAT", "STRING", "IDENTIFIER", "WS", "LINE_COMMENT", "BLOCK_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,52,369,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,5,0,78,8,0,10,0,12,0,81,9,0,1,0,1,0,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,100,8,1,1,2,
  	3,2,103,8,2,1,2,1,2,1,2,1,2,3,2,109,8,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,
  	3,1,3,1,4,1,4,1,4,5,4,123,8,4,10,4,12,4,126,9,4,1,5,1,5,1,5,3,5,131,8,
  	5,1,5,3,5,134,8,5,1,6,1,6,1,6,5,6,139,8,6,10,6,12,6,142,9,6,1,7,1,7,1,
  	8,1,8,1,8,1,9,1,9,1,9,5,9,152,8,9,10,9,12,9,155,9,9,1,10,1,10,1,10,1,
  	10,1,11,1,11,1,11,1,11,1,11,3,11,166,8,11,1,11,1,11,3,11,170,8,11,1,12,
  	1,12,1,12,1,12,5,12,176,8,12,10,12,12,12,179,9,12,1,12,1,12,1,13,1,13,
  	1,13,1,13,1,13,1,14,3,14,189,8,14,1,14,1,14,1,14,1,14,5,14,195,8,14,10,
  	14,12,14,198,9,14,1,14,1,14,1,15,1,15,1,15,1,15,5,15,206,8,15,10,15,12,
  	15,209,9,15,1,15,1,15,1,16,1,16,5,16,215,8,16,10,16,12,16,218,9,16,1,
  	16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,229,8,17,1,18,1,18,1,
  	18,1,18,1,18,1,18,1,18,3,18,238,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,3,21,258,8,
  	21,1,21,1,21,1,22,1,22,3,22,264,8,22,1,22,1,22,1,23,1,23,1,23,3,23,271,
  	8,23,1,24,1,24,1,24,1,25,1,25,1,26,1,26,1,26,3,26,281,8,26,1,27,1,27,
  	1,27,5,27,286,8,27,10,27,12,27,289,9,27,1,28,1,28,1,28,5,28,294,8,28,
  	10,28,12,28,297,9,28,1,29,1,29,1,29,5,29,302,8,29,10,29,12,29,305,9,29,
  	1,30,1,30,1,30,5,30,310,8,30,10,30,12,30,313,9,30,1,31,1,31,1,31,5,31,
  	318,8,31,10,31,12,31,321,9,31,1,32,1,32,1,32,5,32,326,8,32,10,32,12,32,
  	329,9,32,1,33,1,33,1,33,3,33,334,8,33,1,34,1,34,1,34,3,34,339,8,34,1,
  	34,5,34,342,8,34,10,34,12,34,345,9,34,1,35,1,35,1,35,5,35,350,8,35,10,
  	35,12,35,353,9,35,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,3,36,364,
  	8,36,1,37,1,37,1,37,1,37,0,0,38,0,2,4,6,8,10,12,14,16,18,20,22,24,26,
  	28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,
  	74,0,7,2,0,46,46,48,49,2,0,43,43,49,49,1,0,16,17,2,0,9,10,18,19,1,0,20,
  	21,1,0,22,24,2,0,21,21,25,25,378,0,79,1,0,0,0,2,99,1,0,0,0,4,102,1,0,
  	0,0,6,114,1,0,0,0,8,119,1,0,0,0,10,127,1,0,0,0,12,135,1,0,0,0,14,143,
  	1,0,0,0,16,145,1,0,0,0,18,148,1,0,0,0,20,156,1,0,0,0,22,160,1,0,0,0,24,
  	171,1,0,0,0,26,182,1,0,0,0,28,188,1,0,0,0,30,201,1,0,0,0,32,212,1,0,0,
  	0,34,221,1,0,0,0,36,230,1,0,0,0,38,239,1,0,0,0,40,245,1,0,0,0,42,255,
  	1,0,0,0,44,261,1,0,0,0,46,267,1,0,0,0,48,272,1,0,0,0,50,275,1,0,0,0,52,
  	277,1,0,0,0,54,282,1,0,0,0,56,290,1,0,0,0,58,298,1,0,0,0,60,306,1,0,0,
  	0,62,314,1,0,0,0,64,322,1,0,0,0,66,333,1,0,0,0,68,335,1,0,0,0,70,346,
  	1,0,0,0,72,363,1,0,0,0,74,365,1,0,0,0,76,78,3,2,1,0,77,76,1,0,0,0,78,
  	81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,82,1,0,0,0,81,79,1,0,0,0,82,
  	83,5,0,0,1,83,1,1,0,0,0,84,100,3,4,2,0,85,100,3,24,12,0,86,100,3,28,14,
  	0,87,100,3,30,15,0,88,89,3,34,17,0,89,90,5,1,0,0,90,100,1,0,0,0,91,100,
  	3,48,24,0,92,100,3,32,16,0,93,100,3,36,18,0,94,100,3,38,19,0,95,100,3,
  	40,20,0,96,100,3,42,21,0,97,100,3,44,22,0,98,100,3,46,23,0,99,84,1,0,
  	0,0,99,85,1,0,0,0,99,86,1,0,0,0,99,87,1,0,0,0,99,88,1,0,0,0,99,91,1,0,
  	0,0,99,92,1,0,0,0,99,93,1,0,0,0,99,94,1,0,0,0,99,95,1,0,0,0,99,96,1,0,
  	0,0,99,97,1,0,0,0,99,98,1,0,0,0,100,3,1,0,0,0,101,103,3,6,3,0,102,101,
  	1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,105,5,35,0,0,105,106,5,49,
  	0,0,106,108,5,2,0,0,107,109,3,18,9,0,108,107,1,0,0,0,108,109,1,0,0,0,
  	109,110,1,0,0,0,110,111,5,3,0,0,111,112,3,16,8,0,112,113,3,32,16,0,113,
  	5,1,0,0,0,114,115,5,4,0,0,115,116,5,5,0,0,116,117,3,8,4,0,117,118,5,6,
  	0,0,118,7,1,0,0,0,119,124,3,10,5,0,120,121,5,7,0,0,121,123,3,10,5,0,122,
  	120,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,9,1,0,
  	0,0,126,124,1,0,0,0,127,133,5,49,0,0,128,130,5,2,0,0,129,131,3,12,6,0,
  	130,129,1,0,0,0,130,131,1,0,0,0,131,132,1,0,0,0,132,134,5,3,0,0,133,128,
  	1,0,0,0,133,134,1,0,0,0,134,11,1,0,0,0,135,140,3,14,7,0,136,137,5,7,0,
  	0,137,139,3,14,7,0,138,136,1,0,0,0,139,142,1,0,0,0,140,138,1,0,0,0,140,
  	141,1,0,0,0,141,13,1,0,0,0,142,140,1,0,0,0,143,144,7,0,0,0,144,15,1,0,
  	0,0,145,146,5,44,0,0,146,147,3,22,11,0,147,17,1,0,0,0,148,153,3,20,10,
  	0,149,150,5,7,0,0,150,152,3,20,10,0,151,149,1,0,0,0,152,155,1,0,0,0,153,
  	151,1,0,0,0,153,154,1,0,0,0,154,19,1,0,0,0,155,153,1,0,0,0,156,157,5,
  	49,0,0,157,158,5,8,0,0,158,159,3,22,11,0,159,21,1,0,0,0,160,165,7,1,0,
  	0,161,162,5,9,0,0,162,163,3,22,11,0,163,164,5,10,0,0,164,166,1,0,0,0,
  	165,161,1,0,0,0,165,166,1,0,0,0,166,169,1,0,0,0,167,168,5,5,0,0,168,170,
  	5,6,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,23,1,0,0,0,171,172,5,36,0,
  	0,172,173,5,49,0,0,173,177,5,11,0,0,174,176,3,26,13,0,175,174,1,0,0,0,
  	176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,
  	1,0,0,0,180,181,5,12,0,0,181,25,1,0,0,0,182,183,5,49,0,0,183,184,5,8,
  	0,0,184,185,3,22,11,0,185,186,5,1,0,0,186,27,1,0,0,0,187,189,5,38,0,0,
  	188,187,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,0,190,191,5,37,0,0,191,
  	192,5,49,0,0,192,196,5,11,0,0,193,195,3,26,13,0,194,193,1,0,0,0,195,198,
  	1,0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,199,1,0,0,0,198,196,1,0,0,
  	0,199,200,5,12,0,0,200,29,1,0,0,0,201,202,5,39,0,0,202,203,5,49,0,0,203,
  	207,5,11,0,0,204,206,3,2,1,0,205,204,1,0,0,0,206,209,1,0,0,0,207,205,
  	1,0,0,0,207,208,1,0,0,0,208,210,1,0,0,0,209,207,1,0,0,0,210,211,5,12,
  	0,0,211,31,1,0,0,0,212,216,5,11,0,0,213,215,3,2,1,0,214,213,1,0,0,0,215,
  	218,1,0,0,0,216,214,1,0,0,0,216,217,1,0,0,0,217,219,1,0,0,0,218,216,1,
  	0,0,0,219,220,5,12,0,0,220,33,1,0,0,0,221,222,5,34,0,0,222,223,5,49,0,
  	0,223,224,5,8,0,0,224,225,3,22,11,0,225,228,5,13,0,0,226,229,3,50,25,
  	0,227,229,3,74,37,0,228,226,1,0,0,0,228,227,1,0,0,0,229,35,1,0,0,0,230,
  	231,5,27,0,0,231,232,5,2,0,0,232,233,3,50,25,0,233,234,5,3,0,0,234,237,
  	3,32,16,0,235,236,5,28,0,0,236,238,3,32,16,0,237,235,1,0,0,0,237,238,
  	1,0,0,0,238,37,1,0,0,0,239,240,5,29,0,0,240,241,5,2,0,0,241,242,3,50,
  	25,0,242,243,5,3,0,0,243,244,3,32,16,0,244,39,1,0,0,0,245,246,5,30,0,
  	0,246,247,5,2,0,0,247,248,3,34,17,0,248,249,5,1,0,0,249,250,3,50,25,0,
  	250,251,5,1,0,0,251,252,3,50,25,0,252,253,5,3,0,0,253,254,3,32,16,0,254,
  	41,1,0,0,0,255,257,5,31,0,0,256,258,3,50,25,0,257,256,1,0,0,0,257,258,
  	1,0,0,0,258,259,1,0,0,0,259,260,5,1,0,0,260,43,1,0,0,0,261,263,5,32,0,
  	0,262,264,3,50,25,0,263,262,1,0,0,0,263,264,1,0,0,0,264,265,1,0,0,0,265,
  	266,5,1,0,0,266,45,1,0,0,0,267,270,5,33,0,0,268,271,3,32,16,0,269,271,
  	3,48,24,0,270,268,1,0,0,0,270,269,1,0,0,0,271,47,1,0,0,0,272,273,3,50,
  	25,0,273,274,5,1,0,0,274,49,1,0,0,0,275,276,3,52,26,0,276,51,1,0,0,0,
  	277,280,3,54,27,0,278,279,5,13,0,0,279,281,3,50,25,0,280,278,1,0,0,0,
  	280,281,1,0,0,0,281,53,1,0,0,0,282,287,3,56,28,0,283,284,5,14,0,0,284,
  	286,3,56,28,0,285,283,1,0,0,0,286,289,1,0,0,0,287,285,1,0,0,0,287,288,
  	1,0,0,0,288,55,1,0,0,0,289,287,1,0,0,0,290,295,3,58,29,0,291,292,5,15,
  	0,0,292,294,3,58,29,0,293,291,1,0,0,0,294,297,1,0,0,0,295,293,1,0,0,0,
  	295,296,1,0,0,0,296,57,1,0,0,0,297,295,1,0,0,0,298,303,3,60,30,0,299,
  	300,7,2,0,0,300,302,3,60,30,0,301,299,1,0,0,0,302,305,1,0,0,0,303,301,
  	1,0,0,0,303,304,1,0,0,0,304,59,1,0,0,0,305,303,1,0,0,0,306,311,3,62,31,
  	0,307,308,7,3,0,0,308,310,3,62,31,0,309,307,1,0,0,0,310,313,1,0,0,0,311,
  	309,1,0,0,0,311,312,1,0,0,0,312,61,1,0,0,0,313,311,1,0,0,0,314,319,3,
  	64,32,0,315,316,7,4,0,0,316,318,3,64,32,0,317,315,1,0,0,0,318,321,1,0,
  	0,0,319,317,1,0,0,0,319,320,1,0,0,0,320,63,1,0,0,0,321,319,1,0,0,0,322,
  	327,3,66,33,0,323,324,7,5,0,0,324,326,3,66,33,0,325,323,1,0,0,0,326,329,
  	1,0,0,0,327,325,1,0,0,0,327,328,1,0,0,0,328,65,1,0,0,0,329,327,1,0,0,
  	0,330,331,7,6,0,0,331,334,3,66,33,0,332,334,3,68,34,0,333,330,1,0,0,0,
  	333,332,1,0,0,0,334,67,1,0,0,0,335,343,3,72,36,0,336,338,5,2,0,0,337,
  	339,3,70,35,0,338,337,1,0,0,0,338,339,1,0,0,0,339,340,1,0,0,0,340,342,
  	5,3,0,0,341,336,1,0,0,0,342,345,1,0,0,0,343,341,1,0,0,0,343,344,1,0,0,
  	0,344,69,1,0,0,0,345,343,1,0,0,0,346,351,3,50,25,0,347,348,5,7,0,0,348,
  	350,3,50,25,0,349,347,1,0,0,0,350,353,1,0,0,0,351,349,1,0,0,0,351,352,
  	1,0,0,0,352,71,1,0,0,0,353,351,1,0,0,0,354,364,5,46,0,0,355,364,5,47,
  	0,0,356,364,5,26,0,0,357,364,5,48,0,0,358,364,5,49,0,0,359,360,5,2,0,
  	0,360,361,3,50,25,0,361,362,5,3,0,0,362,364,1,0,0,0,363,354,1,0,0,0,363,
  	355,1,0,0,0,363,356,1,0,0,0,363,357,1,0,0,0,363,358,1,0,0,0,363,359,1,
  	0,0,0,364,73,1,0,0,0,365,366,5,41,0,0,366,367,3,32,16,0,367,75,1,0,0,
  	0,33,79,99,102,108,124,130,133,140,153,165,169,177,188,196,207,216,228,
  	237,257,263,270,280,287,295,303,311,319,327,333,338,343,351,363
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

std::vector<zapParser::StatementContext *> zapParser::ProgramContext::statement() {
  return getRuleContexts<zapParser::StatementContext>();
}

zapParser::StatementContext* zapParser::ProgramContext::statement(size_t i) {
  return getRuleContext<zapParser::StatementContext>(i);
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
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056630374402068) != 0)) {
      setState(76);
      statement();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
    match(zapParser::EOF);
   
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

zapParser::FunctionDeclContext* zapParser::StatementContext::functionDecl() {
  return getRuleContext<zapParser::FunctionDeclContext>(0);
}

zapParser::StructDeclContext* zapParser::StatementContext::structDecl() {
  return getRuleContext<zapParser::StructDeclContext>(0);
}

zapParser::ComponentDeclContext* zapParser::StatementContext::componentDecl() {
  return getRuleContext<zapParser::ComponentDeclContext>(0);
}

zapParser::ModuleDeclContext* zapParser::StatementContext::moduleDecl() {
  return getRuleContext<zapParser::ModuleDeclContext>(0);
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
  enterRule(_localctx, 2, zapParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__3:
      case zapParser::FUNC: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        functionDecl();
        break;
      }

      case zapParser::STRUCT: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        structDecl();
        break;
      }

      case zapParser::COMPONENT:
      case zapParser::READONLY: {
        enterOuterAlt(_localctx, 3);
        setState(86);
        componentDecl();
        break;
      }

      case zapParser::MODULE: {
        enterOuterAlt(_localctx, 4);
        setState(87);
        moduleDecl();
        break;
      }

      case zapParser::LET: {
        enterOuterAlt(_localctx, 5);
        setState(88);
        variableDecl();
        setState(89);
        match(zapParser::T__0);
        break;
      }

      case zapParser::T__1:
      case zapParser::T__20:
      case zapParser::T__24:
      case zapParser::BOOL:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 6);
        setState(91);
        expressionStmt();
        break;
      }

      case zapParser::T__10: {
        enterOuterAlt(_localctx, 7);
        setState(92);
        block();
        break;
      }

      case zapParser::IF: {
        enterOuterAlt(_localctx, 8);
        setState(93);
        ifStmt();
        break;
      }

      case zapParser::WHILE: {
        enterOuterAlt(_localctx, 9);
        setState(94);
        whileStmt();
        break;
      }

      case zapParser::FOR: {
        enterOuterAlt(_localctx, 10);
        setState(95);
        forStmt();
        break;
      }

      case zapParser::RETURN: {
        enterOuterAlt(_localctx, 11);
        setState(96);
        returnStmt();
        break;
      }

      case zapParser::YIELD: {
        enterOuterAlt(_localctx, 12);
        setState(97);
        yieldStmt();
        break;
      }

      case zapParser::DEFER: {
        enterOuterAlt(_localctx, 13);
        setState(98);
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
  enterRule(_localctx, 4, zapParser::RuleFunctionDecl);
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
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__3) {
      setState(101);
      attributeBlock();
    }
    setState(104);
    match(zapParser::FUNC);
    setState(105);
    match(zapParser::IDENTIFIER);
    setState(106);
    match(zapParser::T__1);
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::IDENTIFIER) {
      setState(107);
      parameterList();
    }
    setState(110);
    match(zapParser::T__2);
    setState(111);
    returnType();
    setState(112);
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
  enterRule(_localctx, 6, zapParser::RuleAttributeBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(zapParser::T__3);
    setState(115);
    match(zapParser::T__4);
    setState(116);
    attributeList();
    setState(117);
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
  enterRule(_localctx, 8, zapParser::RuleAttributeList);
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
    setState(119);
    attribute();
    setState(124);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(120);
      match(zapParser::T__6);
      setState(121);
      attribute();
      setState(126);
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
  enterRule(_localctx, 10, zapParser::RuleAttribute);
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
    setState(127);
    match(zapParser::IDENTIFIER);
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__1) {
      setState(128);
      match(zapParser::T__1);
      setState(130);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 914793674309632) != 0)) {
        setState(129);
        attributeArgs();
      }
      setState(132);
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
  enterRule(_localctx, 12, zapParser::RuleAttributeArgs);
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
    setState(135);
    attributeArg();
    setState(140);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(136);
      match(zapParser::T__6);
      setState(137);
      attributeArg();
      setState(142);
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
  enterRule(_localctx, 14, zapParser::RuleAttributeArg);
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
    setState(143);
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
  enterRule(_localctx, 16, zapParser::RuleReturnType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(zapParser::ARROW);
    setState(146);
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
  enterRule(_localctx, 18, zapParser::RuleParameterList);
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
    setState(148);
    parameter();
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(149);
      match(zapParser::T__6);
      setState(150);
      parameter();
      setState(155);
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
  enterRule(_localctx, 20, zapParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(zapParser::IDENTIFIER);
    setState(157);
    match(zapParser::T__7);
    setState(158);
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

zapParser::TypeContext* zapParser::TypeContext::type() {
  return getRuleContext<zapParser::TypeContext>(0);
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
  enterRule(_localctx, 22, zapParser::RuleType);
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
    _la = _input->LA(1);
    if (!(_la == zapParser::VOID

    || _la == zapParser::IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__8) {
      setState(161);
      match(zapParser::T__8);
      setState(162);
      type();
      setState(163);
      match(zapParser::T__9);
    }
    setState(169);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__4) {
      setState(167);
      match(zapParser::T__4);
      setState(168);
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
  enterRule(_localctx, 24, zapParser::RuleStructDecl);
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
    setState(171);
    match(zapParser::STRUCT);
    setState(172);
    match(zapParser::IDENTIFIER);
    setState(173);
    match(zapParser::T__10);
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::IDENTIFIER) {
      setState(174);
      structField();
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(180);
    match(zapParser::T__11);
   
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
  enterRule(_localctx, 26, zapParser::RuleStructField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(zapParser::IDENTIFIER);
    setState(183);
    match(zapParser::T__7);
    setState(184);
    type();
    setState(185);
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
  enterRule(_localctx, 28, zapParser::RuleComponentDecl);
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
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::READONLY) {
      setState(187);
      match(zapParser::READONLY);
    }
    setState(190);
    match(zapParser::COMPONENT);
    setState(191);
    match(zapParser::IDENTIFIER);
    setState(192);
    match(zapParser::T__10);
    setState(196);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::IDENTIFIER) {
      setState(193);
      structField();
      setState(198);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(199);
    match(zapParser::T__11);
   
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
  enterRule(_localctx, 30, zapParser::RuleModuleDecl);
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
    setState(201);
    match(zapParser::MODULE);
    setState(202);
    match(zapParser::IDENTIFIER);
    setState(203);
    match(zapParser::T__10);
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056630374402068) != 0)) {
      setState(204);
      statement();
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(210);
    match(zapParser::T__11);
   
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
  enterRule(_localctx, 32, zapParser::RuleBlock);
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
    setState(212);
    match(zapParser::T__10);
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056630374402068) != 0)) {
      setState(213);
      statement();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(219);
    match(zapParser::T__11);
   
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
  enterRule(_localctx, 34, zapParser::RuleVariableDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(zapParser::LET);
    setState(222);
    match(zapParser::IDENTIFIER);
    setState(223);
    match(zapParser::T__7);
    setState(224);
    type();
    setState(225);
    match(zapParser::T__12);
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__1:
      case zapParser::T__20:
      case zapParser::T__24:
      case zapParser::BOOL:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        setState(226);
        expression();
        break;
      }

      case zapParser::AOT: {
        setState(227);
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
  enterRule(_localctx, 36, zapParser::RuleIfStmt);
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
    setState(230);
    match(zapParser::IF);
    setState(231);
    match(zapParser::T__1);
    setState(232);
    expression();
    setState(233);
    match(zapParser::T__2);
    setState(234);
    block();
    setState(237);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::ELSE) {
      setState(235);
      match(zapParser::ELSE);
      setState(236);
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
  enterRule(_localctx, 38, zapParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(zapParser::WHILE);
    setState(240);
    match(zapParser::T__1);
    setState(241);
    expression();
    setState(242);
    match(zapParser::T__2);
    setState(243);
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
  enterRule(_localctx, 40, zapParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(zapParser::FOR);
    setState(246);
    match(zapParser::T__1);
    setState(247);
    variableDecl();
    setState(248);
    match(zapParser::T__0);
    setState(249);
    expression();
    setState(250);
    match(zapParser::T__0);
    setState(251);
    expression();
    setState(252);
    match(zapParser::T__2);
    setState(253);
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
  enterRule(_localctx, 42, zapParser::RuleReturnStmt);
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
    setState(255);
    match(zapParser::RETURN);
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1055531265425412) != 0)) {
      setState(256);
      expression();
    }
    setState(259);
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
  enterRule(_localctx, 44, zapParser::RuleYieldStmt);
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
    setState(261);
    match(zapParser::YIELD);
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1055531265425412) != 0)) {
      setState(262);
      expression();
    }
    setState(265);
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
  enterRule(_localctx, 46, zapParser::RuleDeferStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(zapParser::DEFER);
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__10: {
        setState(268);
        block();
        break;
      }

      case zapParser::T__1:
      case zapParser::T__20:
      case zapParser::T__24:
      case zapParser::BOOL:
      case zapParser::INT:
      case zapParser::FLOAT:
      case zapParser::STRING:
      case zapParser::IDENTIFIER: {
        setState(269);
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
  enterRule(_localctx, 48, zapParser::RuleExpressionStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    expression();
    setState(273);
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
  enterRule(_localctx, 50, zapParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
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
  enterRule(_localctx, 52, zapParser::RuleAssignment);
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
    setState(277);
    logicOr();
    setState(280);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__12) {
      setState(278);
      match(zapParser::T__12);
      setState(279);
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
  enterRule(_localctx, 54, zapParser::RuleLogicOr);
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
    setState(282);
    logicAnd();
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__13) {
      setState(283);
      match(zapParser::T__13);
      setState(284);
      logicAnd();
      setState(289);
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
  enterRule(_localctx, 56, zapParser::RuleLogicAnd);
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
    setState(290);
    equality();
    setState(295);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__14) {
      setState(291);
      match(zapParser::T__14);
      setState(292);
      equality();
      setState(297);
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
  enterRule(_localctx, 58, zapParser::RuleEquality);
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
    setState(298);
    comparison();
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__15

    || _la == zapParser::T__16) {
      setState(299);
      _la = _input->LA(1);
      if (!(_la == zapParser::T__15

      || _la == zapParser::T__16)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(300);
      comparison();
      setState(305);
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
  enterRule(_localctx, 60, zapParser::RuleComparison);
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
    setState(306);
    term();
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 787968) != 0)) {
      setState(307);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 787968) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(308);
      term();
      setState(313);
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
  enterRule(_localctx, 62, zapParser::RuleTerm);
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
    setState(314);
    factor();
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__19

    || _la == zapParser::T__20) {
      setState(315);
      _la = _input->LA(1);
      if (!(_la == zapParser::T__19

      || _la == zapParser::T__20)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(316);
      factor();
      setState(321);
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
  enterRule(_localctx, 64, zapParser::RuleFactor);
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
    setState(322);
    unary();
    setState(327);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29360128) != 0)) {
      setState(323);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 29360128) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(324);
      unary();
      setState(329);
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
  enterRule(_localctx, 66, zapParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(333);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__20:
      case zapParser::T__24: {
        enterOuterAlt(_localctx, 1);
        setState(330);
        _la = _input->LA(1);
        if (!(_la == zapParser::T__20

        || _la == zapParser::T__24)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(331);
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
        setState(332);
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
  enterRule(_localctx, 68, zapParser::RuleCall);
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
    setState(335);
    primary();
    setState(343);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__1) {
      setState(336);
      match(zapParser::T__1);
      setState(338);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1055531265425412) != 0)) {
        setState(337);
        argumentList();
      }
      setState(340);
      match(zapParser::T__2);
      setState(345);
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
  enterRule(_localctx, 70, zapParser::RuleArgumentList);
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
    setState(346);
    expression();
    setState(351);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__6) {
      setState(347);
      match(zapParser::T__6);
      setState(348);
      expression();
      setState(353);
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
  enterRule(_localctx, 72, zapParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(354);
        match(zapParser::INT);
        break;
      }

      case zapParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(355);
        match(zapParser::FLOAT);
        break;
      }

      case zapParser::BOOL: {
        enterOuterAlt(_localctx, 3);
        setState(356);
        match(zapParser::BOOL);
        break;
      }

      case zapParser::STRING: {
        enterOuterAlt(_localctx, 4);
        setState(357);
        match(zapParser::STRING);
        break;
      }

      case zapParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 5);
        setState(358);
        match(zapParser::IDENTIFIER);
        break;
      }

      case zapParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(359);
        match(zapParser::T__1);
        setState(360);
        expression();
        setState(361);
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
  enterRule(_localctx, 74, zapParser::RuleAotBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(zapParser::AOT);
    setState(366);
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
