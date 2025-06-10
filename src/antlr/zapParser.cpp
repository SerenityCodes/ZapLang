
// Generated from zap.g4 by ANTLR 4.13.2


#include "zapListener.h"

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
      "program", "statement", "functionDecl", "attributeBlock", "attribute", 
      "returnType", "parameterList", "parameter", "type", "structDecl", 
      "structField", "componentDecl", "moduleDecl", "block", "variableDecl", 
      "ifStmt", "whileStmt", "forStmt", "returnStmt", "yieldStmt", "deferStmt", 
      "expressionStmt", "expression", "assignment", "logicOr", "logicAnd", 
      "equality", "comparison", "term", "factor", "unary", "call", "argumentList", 
      "primary", "aotBlock"
    },
    std::vector<std::string>{
      "", "';'", "'('", "')'", "'@'", "'['", "','", "']'", "':'", "'<'", 
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
  	4,1,52,346,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,5,
  	0,72,8,0,10,0,12,0,75,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,3,1,94,8,1,1,2,3,2,97,8,2,1,2,1,2,1,2,1,2,3,2,
  	103,8,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,5,3,114,8,3,10,3,12,3,117,
  	9,3,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,5,6,129,8,6,10,6,12,6,132,
  	9,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,3,8,143,8,8,1,8,1,8,3,8,147,8,
  	8,1,9,1,9,1,9,1,9,5,9,153,8,9,10,9,12,9,156,9,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,11,3,11,166,8,11,1,11,1,11,1,11,1,11,5,11,172,8,11,10,11,
  	12,11,175,9,11,1,11,1,11,1,12,1,12,1,12,1,12,5,12,183,8,12,10,12,12,12,
  	186,9,12,1,12,1,12,1,13,1,13,5,13,192,8,13,10,13,12,13,195,9,13,1,13,
  	1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,206,8,14,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,3,15,215,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,3,18,235,8,18,
  	1,18,1,18,1,19,1,19,3,19,241,8,19,1,19,1,19,1,20,1,20,1,20,3,20,248,8,
  	20,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,23,3,23,258,8,23,1,24,1,24,1,
  	24,5,24,263,8,24,10,24,12,24,266,9,24,1,25,1,25,1,25,5,25,271,8,25,10,
  	25,12,25,274,9,25,1,26,1,26,1,26,5,26,279,8,26,10,26,12,26,282,9,26,1,
  	27,1,27,1,27,5,27,287,8,27,10,27,12,27,290,9,27,1,28,1,28,1,28,5,28,295,
  	8,28,10,28,12,28,298,9,28,1,29,1,29,1,29,5,29,303,8,29,10,29,12,29,306,
  	9,29,1,30,1,30,1,30,3,30,311,8,30,1,31,1,31,1,31,3,31,316,8,31,1,31,5,
  	31,319,8,31,10,31,12,31,322,9,31,1,32,1,32,1,32,5,32,327,8,32,10,32,12,
  	32,330,9,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,3,33,341,8,33,
  	1,34,1,34,1,34,1,34,0,0,35,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,0,6,2,0,43,43,
  	49,49,1,0,16,17,2,0,9,10,18,19,1,0,20,21,1,0,22,24,2,0,21,21,25,25,355,
  	0,73,1,0,0,0,2,93,1,0,0,0,4,96,1,0,0,0,6,108,1,0,0,0,8,120,1,0,0,0,10,
  	122,1,0,0,0,12,125,1,0,0,0,14,133,1,0,0,0,16,137,1,0,0,0,18,148,1,0,0,
  	0,20,159,1,0,0,0,22,165,1,0,0,0,24,178,1,0,0,0,26,189,1,0,0,0,28,198,
  	1,0,0,0,30,207,1,0,0,0,32,216,1,0,0,0,34,222,1,0,0,0,36,232,1,0,0,0,38,
  	238,1,0,0,0,40,244,1,0,0,0,42,249,1,0,0,0,44,252,1,0,0,0,46,254,1,0,0,
  	0,48,259,1,0,0,0,50,267,1,0,0,0,52,275,1,0,0,0,54,283,1,0,0,0,56,291,
  	1,0,0,0,58,299,1,0,0,0,60,310,1,0,0,0,62,312,1,0,0,0,64,323,1,0,0,0,66,
  	340,1,0,0,0,68,342,1,0,0,0,70,72,3,2,1,0,71,70,1,0,0,0,72,75,1,0,0,0,
  	73,71,1,0,0,0,73,74,1,0,0,0,74,76,1,0,0,0,75,73,1,0,0,0,76,77,5,0,0,1,
  	77,1,1,0,0,0,78,94,3,4,2,0,79,94,3,18,9,0,80,94,3,22,11,0,81,94,3,24,
  	12,0,82,83,3,28,14,0,83,84,5,1,0,0,84,94,1,0,0,0,85,94,3,42,21,0,86,94,
  	3,26,13,0,87,94,3,30,15,0,88,94,3,32,16,0,89,94,3,34,17,0,90,94,3,36,
  	18,0,91,94,3,38,19,0,92,94,3,40,20,0,93,78,1,0,0,0,93,79,1,0,0,0,93,80,
  	1,0,0,0,93,81,1,0,0,0,93,82,1,0,0,0,93,85,1,0,0,0,93,86,1,0,0,0,93,87,
  	1,0,0,0,93,88,1,0,0,0,93,89,1,0,0,0,93,90,1,0,0,0,93,91,1,0,0,0,93,92,
  	1,0,0,0,94,3,1,0,0,0,95,97,3,6,3,0,96,95,1,0,0,0,96,97,1,0,0,0,97,98,
  	1,0,0,0,98,99,5,35,0,0,99,100,5,49,0,0,100,102,5,2,0,0,101,103,3,12,6,
  	0,102,101,1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,105,5,3,0,0,105,
  	106,3,10,5,0,106,107,3,26,13,0,107,5,1,0,0,0,108,109,5,4,0,0,109,110,
  	5,5,0,0,110,115,3,8,4,0,111,112,5,6,0,0,112,114,3,8,4,0,113,111,1,0,0,
  	0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,118,1,0,0,0,117,
  	115,1,0,0,0,118,119,5,7,0,0,119,7,1,0,0,0,120,121,5,49,0,0,121,9,1,0,
  	0,0,122,123,5,44,0,0,123,124,3,16,8,0,124,11,1,0,0,0,125,130,3,14,7,0,
  	126,127,5,6,0,0,127,129,3,14,7,0,128,126,1,0,0,0,129,132,1,0,0,0,130,
  	128,1,0,0,0,130,131,1,0,0,0,131,13,1,0,0,0,132,130,1,0,0,0,133,134,5,
  	49,0,0,134,135,5,8,0,0,135,136,3,16,8,0,136,15,1,0,0,0,137,142,7,0,0,
  	0,138,139,5,9,0,0,139,140,3,16,8,0,140,141,5,10,0,0,141,143,1,0,0,0,142,
  	138,1,0,0,0,142,143,1,0,0,0,143,146,1,0,0,0,144,145,5,5,0,0,145,147,5,
  	7,0,0,146,144,1,0,0,0,146,147,1,0,0,0,147,17,1,0,0,0,148,149,5,36,0,0,
  	149,150,5,49,0,0,150,154,5,11,0,0,151,153,3,20,10,0,152,151,1,0,0,0,153,
  	156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,157,1,0,0,0,156,154,1,
  	0,0,0,157,158,5,12,0,0,158,19,1,0,0,0,159,160,5,49,0,0,160,161,5,8,0,
  	0,161,162,3,16,8,0,162,163,5,1,0,0,163,21,1,0,0,0,164,166,5,38,0,0,165,
  	164,1,0,0,0,165,166,1,0,0,0,166,167,1,0,0,0,167,168,5,37,0,0,168,169,
  	5,49,0,0,169,173,5,11,0,0,170,172,3,20,10,0,171,170,1,0,0,0,172,175,1,
  	0,0,0,173,171,1,0,0,0,173,174,1,0,0,0,174,176,1,0,0,0,175,173,1,0,0,0,
  	176,177,5,12,0,0,177,23,1,0,0,0,178,179,5,39,0,0,179,180,5,49,0,0,180,
  	184,5,11,0,0,181,183,3,2,1,0,182,181,1,0,0,0,183,186,1,0,0,0,184,182,
  	1,0,0,0,184,185,1,0,0,0,185,187,1,0,0,0,186,184,1,0,0,0,187,188,5,12,
  	0,0,188,25,1,0,0,0,189,193,5,11,0,0,190,192,3,2,1,0,191,190,1,0,0,0,192,
  	195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,196,1,0,0,0,195,193,1,
  	0,0,0,196,197,5,12,0,0,197,27,1,0,0,0,198,199,5,34,0,0,199,200,5,49,0,
  	0,200,201,5,8,0,0,201,202,3,16,8,0,202,205,5,13,0,0,203,206,3,44,22,0,
  	204,206,3,68,34,0,205,203,1,0,0,0,205,204,1,0,0,0,206,29,1,0,0,0,207,
  	208,5,27,0,0,208,209,5,2,0,0,209,210,3,44,22,0,210,211,5,3,0,0,211,214,
  	3,26,13,0,212,213,5,28,0,0,213,215,3,26,13,0,214,212,1,0,0,0,214,215,
  	1,0,0,0,215,31,1,0,0,0,216,217,5,29,0,0,217,218,5,2,0,0,218,219,3,44,
  	22,0,219,220,5,3,0,0,220,221,3,26,13,0,221,33,1,0,0,0,222,223,5,30,0,
  	0,223,224,5,2,0,0,224,225,3,28,14,0,225,226,5,1,0,0,226,227,3,44,22,0,
  	227,228,5,1,0,0,228,229,3,44,22,0,229,230,5,3,0,0,230,231,3,26,13,0,231,
  	35,1,0,0,0,232,234,5,31,0,0,233,235,3,44,22,0,234,233,1,0,0,0,234,235,
  	1,0,0,0,235,236,1,0,0,0,236,237,5,1,0,0,237,37,1,0,0,0,238,240,5,32,0,
  	0,239,241,3,44,22,0,240,239,1,0,0,0,240,241,1,0,0,0,241,242,1,0,0,0,242,
  	243,5,1,0,0,243,39,1,0,0,0,244,247,5,33,0,0,245,248,3,26,13,0,246,248,
  	3,42,21,0,247,245,1,0,0,0,247,246,1,0,0,0,248,41,1,0,0,0,249,250,3,44,
  	22,0,250,251,5,1,0,0,251,43,1,0,0,0,252,253,3,46,23,0,253,45,1,0,0,0,
  	254,257,3,48,24,0,255,256,5,13,0,0,256,258,3,44,22,0,257,255,1,0,0,0,
  	257,258,1,0,0,0,258,47,1,0,0,0,259,264,3,50,25,0,260,261,5,14,0,0,261,
  	263,3,50,25,0,262,260,1,0,0,0,263,266,1,0,0,0,264,262,1,0,0,0,264,265,
  	1,0,0,0,265,49,1,0,0,0,266,264,1,0,0,0,267,272,3,52,26,0,268,269,5,15,
  	0,0,269,271,3,52,26,0,270,268,1,0,0,0,271,274,1,0,0,0,272,270,1,0,0,0,
  	272,273,1,0,0,0,273,51,1,0,0,0,274,272,1,0,0,0,275,280,3,54,27,0,276,
  	277,7,1,0,0,277,279,3,54,27,0,278,276,1,0,0,0,279,282,1,0,0,0,280,278,
  	1,0,0,0,280,281,1,0,0,0,281,53,1,0,0,0,282,280,1,0,0,0,283,288,3,56,28,
  	0,284,285,7,2,0,0,285,287,3,56,28,0,286,284,1,0,0,0,287,290,1,0,0,0,288,
  	286,1,0,0,0,288,289,1,0,0,0,289,55,1,0,0,0,290,288,1,0,0,0,291,296,3,
  	58,29,0,292,293,7,3,0,0,293,295,3,58,29,0,294,292,1,0,0,0,295,298,1,0,
  	0,0,296,294,1,0,0,0,296,297,1,0,0,0,297,57,1,0,0,0,298,296,1,0,0,0,299,
  	304,3,60,30,0,300,301,7,4,0,0,301,303,3,60,30,0,302,300,1,0,0,0,303,306,
  	1,0,0,0,304,302,1,0,0,0,304,305,1,0,0,0,305,59,1,0,0,0,306,304,1,0,0,
  	0,307,308,7,5,0,0,308,311,3,60,30,0,309,311,3,62,31,0,310,307,1,0,0,0,
  	310,309,1,0,0,0,311,61,1,0,0,0,312,320,3,66,33,0,313,315,5,2,0,0,314,
  	316,3,64,32,0,315,314,1,0,0,0,315,316,1,0,0,0,316,317,1,0,0,0,317,319,
  	5,3,0,0,318,313,1,0,0,0,319,322,1,0,0,0,320,318,1,0,0,0,320,321,1,0,0,
  	0,321,63,1,0,0,0,322,320,1,0,0,0,323,328,3,44,22,0,324,325,5,6,0,0,325,
  	327,3,44,22,0,326,324,1,0,0,0,327,330,1,0,0,0,328,326,1,0,0,0,328,329,
  	1,0,0,0,329,65,1,0,0,0,330,328,1,0,0,0,331,341,5,46,0,0,332,341,5,47,
  	0,0,333,341,5,26,0,0,334,341,5,48,0,0,335,341,5,49,0,0,336,337,5,2,0,
  	0,337,338,3,44,22,0,338,339,5,3,0,0,339,341,1,0,0,0,340,331,1,0,0,0,340,
  	332,1,0,0,0,340,333,1,0,0,0,340,334,1,0,0,0,340,335,1,0,0,0,340,336,1,
  	0,0,0,341,67,1,0,0,0,342,343,5,41,0,0,343,344,3,26,13,0,344,69,1,0,0,
  	0,30,73,93,96,102,115,130,142,146,154,165,173,184,193,205,214,234,240,
  	247,257,264,272,280,288,296,304,310,315,320,328,340
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

void zapParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void zapParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
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
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056630374402068) != 0)) {
      setState(70);
      statement();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
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

void zapParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void zapParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
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
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__3:
      case zapParser::FUNC: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        functionDecl();
        break;
      }

      case zapParser::STRUCT: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        structDecl();
        break;
      }

      case zapParser::COMPONENT:
      case zapParser::READONLY: {
        enterOuterAlt(_localctx, 3);
        setState(80);
        componentDecl();
        break;
      }

      case zapParser::MODULE: {
        enterOuterAlt(_localctx, 4);
        setState(81);
        moduleDecl();
        break;
      }

      case zapParser::LET: {
        enterOuterAlt(_localctx, 5);
        setState(82);
        variableDecl();
        setState(83);
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
        setState(85);
        expressionStmt();
        break;
      }

      case zapParser::T__10: {
        enterOuterAlt(_localctx, 7);
        setState(86);
        block();
        break;
      }

      case zapParser::IF: {
        enterOuterAlt(_localctx, 8);
        setState(87);
        ifStmt();
        break;
      }

      case zapParser::WHILE: {
        enterOuterAlt(_localctx, 9);
        setState(88);
        whileStmt();
        break;
      }

      case zapParser::FOR: {
        enterOuterAlt(_localctx, 10);
        setState(89);
        forStmt();
        break;
      }

      case zapParser::RETURN: {
        enterOuterAlt(_localctx, 11);
        setState(90);
        returnStmt();
        break;
      }

      case zapParser::YIELD: {
        enterOuterAlt(_localctx, 12);
        setState(91);
        yieldStmt();
        break;
      }

      case zapParser::DEFER: {
        enterOuterAlt(_localctx, 13);
        setState(92);
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

void zapParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void zapParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
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
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__3) {
      setState(95);
      attributeBlock();
    }
    setState(98);
    match(zapParser::FUNC);
    setState(99);
    match(zapParser::IDENTIFIER);
    setState(100);
    match(zapParser::T__1);
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::IDENTIFIER) {
      setState(101);
      parameterList();
    }
    setState(104);
    match(zapParser::T__2);
    setState(105);
    returnType();
    setState(106);
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

std::vector<zapParser::AttributeContext *> zapParser::AttributeBlockContext::attribute() {
  return getRuleContexts<zapParser::AttributeContext>();
}

zapParser::AttributeContext* zapParser::AttributeBlockContext::attribute(size_t i) {
  return getRuleContext<zapParser::AttributeContext>(i);
}


size_t zapParser::AttributeBlockContext::getRuleIndex() const {
  return zapParser::RuleAttributeBlock;
}

void zapParser::AttributeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeBlock(this);
}

void zapParser::AttributeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeBlock(this);
}

zapParser::AttributeBlockContext* zapParser::attributeBlock() {
  AttributeBlockContext *_localctx = _tracker.createInstance<AttributeBlockContext>(_ctx, getState());
  enterRule(_localctx, 6, zapParser::RuleAttributeBlock);
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
    setState(108);
    match(zapParser::T__3);
    setState(109);
    match(zapParser::T__4);
    setState(110);
    attribute();
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__5) {
      setState(111);
      match(zapParser::T__5);
      setState(112);
      attribute();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
    match(zapParser::T__6);
   
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


size_t zapParser::AttributeContext::getRuleIndex() const {
  return zapParser::RuleAttribute;
}

void zapParser::AttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttribute(this);
}

void zapParser::AttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttribute(this);
}

zapParser::AttributeContext* zapParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 8, zapParser::RuleAttribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(zapParser::IDENTIFIER);
   
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

void zapParser::ReturnTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnType(this);
}

void zapParser::ReturnTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnType(this);
}

zapParser::ReturnTypeContext* zapParser::returnType() {
  ReturnTypeContext *_localctx = _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 10, zapParser::RuleReturnType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(zapParser::ARROW);
    setState(123);
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

void zapParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void zapParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

zapParser::ParameterListContext* zapParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 12, zapParser::RuleParameterList);
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
    setState(125);
    parameter();
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__5) {
      setState(126);
      match(zapParser::T__5);
      setState(127);
      parameter();
      setState(132);
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

void zapParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void zapParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

zapParser::ParameterContext* zapParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 14, zapParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(zapParser::IDENTIFIER);
    setState(134);
    match(zapParser::T__7);
    setState(135);
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

void zapParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void zapParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

zapParser::TypeContext* zapParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 16, zapParser::RuleType);
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
    setState(137);
    _la = _input->LA(1);
    if (!(_la == zapParser::VOID

    || _la == zapParser::IDENTIFIER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__8) {
      setState(138);
      match(zapParser::T__8);
      setState(139);
      type();
      setState(140);
      match(zapParser::T__9);
    }
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__4) {
      setState(144);
      match(zapParser::T__4);
      setState(145);
      match(zapParser::T__6);
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

void zapParser::StructDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDecl(this);
}

void zapParser::StructDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDecl(this);
}

zapParser::StructDeclContext* zapParser::structDecl() {
  StructDeclContext *_localctx = _tracker.createInstance<StructDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, zapParser::RuleStructDecl);
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
    match(zapParser::STRUCT);
    setState(149);
    match(zapParser::IDENTIFIER);
    setState(150);
    match(zapParser::T__10);
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::IDENTIFIER) {
      setState(151);
      structField();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(157);
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

void zapParser::StructFieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructField(this);
}

void zapParser::StructFieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructField(this);
}

zapParser::StructFieldContext* zapParser::structField() {
  StructFieldContext *_localctx = _tracker.createInstance<StructFieldContext>(_ctx, getState());
  enterRule(_localctx, 20, zapParser::RuleStructField);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(zapParser::IDENTIFIER);
    setState(160);
    match(zapParser::T__7);
    setState(161);
    type();
    setState(162);
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

void zapParser::ComponentDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponentDecl(this);
}

void zapParser::ComponentDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponentDecl(this);
}

zapParser::ComponentDeclContext* zapParser::componentDecl() {
  ComponentDeclContext *_localctx = _tracker.createInstance<ComponentDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, zapParser::RuleComponentDecl);
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
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::READONLY) {
      setState(164);
      match(zapParser::READONLY);
    }
    setState(167);
    match(zapParser::COMPONENT);
    setState(168);
    match(zapParser::IDENTIFIER);
    setState(169);
    match(zapParser::T__10);
    setState(173);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::IDENTIFIER) {
      setState(170);
      structField();
      setState(175);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(176);
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

void zapParser::ModuleDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleDecl(this);
}

void zapParser::ModuleDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleDecl(this);
}

zapParser::ModuleDeclContext* zapParser::moduleDecl() {
  ModuleDeclContext *_localctx = _tracker.createInstance<ModuleDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, zapParser::RuleModuleDecl);
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
    match(zapParser::MODULE);
    setState(179);
    match(zapParser::IDENTIFIER);
    setState(180);
    match(zapParser::T__10);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056630374402068) != 0)) {
      setState(181);
      statement();
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(187);
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

void zapParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void zapParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

zapParser::BlockContext* zapParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, zapParser::RuleBlock);
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
    setState(189);
    match(zapParser::T__10);
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1056630374402068) != 0)) {
      setState(190);
      statement();
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(196);
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

void zapParser::VariableDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDecl(this);
}

void zapParser::VariableDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDecl(this);
}

zapParser::VariableDeclContext* zapParser::variableDecl() {
  VariableDeclContext *_localctx = _tracker.createInstance<VariableDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, zapParser::RuleVariableDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(zapParser::LET);
    setState(199);
    match(zapParser::IDENTIFIER);
    setState(200);
    match(zapParser::T__7);
    setState(201);
    type();
    setState(202);
    match(zapParser::T__12);
    setState(205);
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
        setState(203);
        expression();
        break;
      }

      case zapParser::AOT: {
        setState(204);
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

void zapParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void zapParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}

zapParser::IfStmtContext* zapParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, zapParser::RuleIfStmt);
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
    setState(207);
    match(zapParser::IF);
    setState(208);
    match(zapParser::T__1);
    setState(209);
    expression();
    setState(210);
    match(zapParser::T__2);
    setState(211);
    block();
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::ELSE) {
      setState(212);
      match(zapParser::ELSE);
      setState(213);
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

void zapParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}

void zapParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}

zapParser::WhileStmtContext* zapParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, zapParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(zapParser::WHILE);
    setState(217);
    match(zapParser::T__1);
    setState(218);
    expression();
    setState(219);
    match(zapParser::T__2);
    setState(220);
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

void zapParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void zapParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}

zapParser::ForStmtContext* zapParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, zapParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(zapParser::FOR);
    setState(223);
    match(zapParser::T__1);
    setState(224);
    variableDecl();
    setState(225);
    match(zapParser::T__0);
    setState(226);
    expression();
    setState(227);
    match(zapParser::T__0);
    setState(228);
    expression();
    setState(229);
    match(zapParser::T__2);
    setState(230);
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

void zapParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void zapParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

zapParser::ReturnStmtContext* zapParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, zapParser::RuleReturnStmt);
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
    setState(232);
    match(zapParser::RETURN);
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1055531265425412) != 0)) {
      setState(233);
      expression();
    }
    setState(236);
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

void zapParser::YieldStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldStmt(this);
}

void zapParser::YieldStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldStmt(this);
}

zapParser::YieldStmtContext* zapParser::yieldStmt() {
  YieldStmtContext *_localctx = _tracker.createInstance<YieldStmtContext>(_ctx, getState());
  enterRule(_localctx, 38, zapParser::RuleYieldStmt);
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
    setState(238);
    match(zapParser::YIELD);
    setState(240);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1055531265425412) != 0)) {
      setState(239);
      expression();
    }
    setState(242);
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

void zapParser::DeferStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeferStmt(this);
}

void zapParser::DeferStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeferStmt(this);
}

zapParser::DeferStmtContext* zapParser::deferStmt() {
  DeferStmtContext *_localctx = _tracker.createInstance<DeferStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, zapParser::RuleDeferStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(zapParser::DEFER);
    setState(247);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__10: {
        setState(245);
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
        setState(246);
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

void zapParser::ExpressionStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStmt(this);
}

void zapParser::ExpressionStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStmt(this);
}

zapParser::ExpressionStmtContext* zapParser::expressionStmt() {
  ExpressionStmtContext *_localctx = _tracker.createInstance<ExpressionStmtContext>(_ctx, getState());
  enterRule(_localctx, 42, zapParser::RuleExpressionStmt);

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
    expression();
    setState(250);
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

void zapParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void zapParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

zapParser::ExpressionContext* zapParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 44, zapParser::RuleExpression);

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

void zapParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void zapParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

zapParser::AssignmentContext* zapParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 46, zapParser::RuleAssignment);
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
    setState(254);
    logicOr();
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == zapParser::T__12) {
      setState(255);
      match(zapParser::T__12);
      setState(256);
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

void zapParser::LogicOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicOr(this);
}

void zapParser::LogicOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicOr(this);
}

zapParser::LogicOrContext* zapParser::logicOr() {
  LogicOrContext *_localctx = _tracker.createInstance<LogicOrContext>(_ctx, getState());
  enterRule(_localctx, 48, zapParser::RuleLogicOr);
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
    setState(259);
    logicAnd();
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__13) {
      setState(260);
      match(zapParser::T__13);
      setState(261);
      logicAnd();
      setState(266);
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

void zapParser::LogicAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAnd(this);
}

void zapParser::LogicAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAnd(this);
}

zapParser::LogicAndContext* zapParser::logicAnd() {
  LogicAndContext *_localctx = _tracker.createInstance<LogicAndContext>(_ctx, getState());
  enterRule(_localctx, 50, zapParser::RuleLogicAnd);
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
    setState(267);
    equality();
    setState(272);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__14) {
      setState(268);
      match(zapParser::T__14);
      setState(269);
      equality();
      setState(274);
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

void zapParser::EqualityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquality(this);
}

void zapParser::EqualityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquality(this);
}

zapParser::EqualityContext* zapParser::equality() {
  EqualityContext *_localctx = _tracker.createInstance<EqualityContext>(_ctx, getState());
  enterRule(_localctx, 52, zapParser::RuleEquality);
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
    setState(275);
    comparison();
    setState(280);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__15

    || _la == zapParser::T__16) {
      setState(276);
      _la = _input->LA(1);
      if (!(_la == zapParser::T__15

      || _la == zapParser::T__16)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(277);
      comparison();
      setState(282);
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

void zapParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void zapParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

zapParser::ComparisonContext* zapParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 54, zapParser::RuleComparison);
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
    setState(283);
    term();
    setState(288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 787968) != 0)) {
      setState(284);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 787968) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(285);
      term();
      setState(290);
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

void zapParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void zapParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

zapParser::TermContext* zapParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 56, zapParser::RuleTerm);
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
    setState(291);
    factor();
    setState(296);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__19

    || _la == zapParser::T__20) {
      setState(292);
      _la = _input->LA(1);
      if (!(_la == zapParser::T__19

      || _la == zapParser::T__20)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(293);
      factor();
      setState(298);
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

void zapParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void zapParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

zapParser::FactorContext* zapParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 58, zapParser::RuleFactor);
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
    setState(299);
    unary();
    setState(304);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29360128) != 0)) {
      setState(300);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 29360128) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(301);
      unary();
      setState(306);
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

void zapParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}

void zapParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}

zapParser::UnaryContext* zapParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 60, zapParser::RuleUnary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case zapParser::T__20:
      case zapParser::T__24: {
        enterOuterAlt(_localctx, 1);
        setState(307);
        _la = _input->LA(1);
        if (!(_la == zapParser::T__20

        || _la == zapParser::T__24)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(308);
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
        setState(309);
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

void zapParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void zapParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

zapParser::CallContext* zapParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 62, zapParser::RuleCall);
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
    setState(312);
    primary();
    setState(320);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__1) {
      setState(313);
      match(zapParser::T__1);
      setState(315);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1055531265425412) != 0)) {
        setState(314);
        argumentList();
      }
      setState(317);
      match(zapParser::T__2);
      setState(322);
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

void zapParser::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void zapParser::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}

zapParser::ArgumentListContext* zapParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 64, zapParser::RuleArgumentList);
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
    setState(323);
    expression();
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == zapParser::T__5) {
      setState(324);
      match(zapParser::T__5);
      setState(325);
      expression();
      setState(330);
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

void zapParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void zapParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}

zapParser::PrimaryContext* zapParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 66, zapParser::RulePrimary);

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
      case zapParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(331);
        match(zapParser::INT);
        break;
      }

      case zapParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(332);
        match(zapParser::FLOAT);
        break;
      }

      case zapParser::BOOL: {
        enterOuterAlt(_localctx, 3);
        setState(333);
        match(zapParser::BOOL);
        break;
      }

      case zapParser::STRING: {
        enterOuterAlt(_localctx, 4);
        setState(334);
        match(zapParser::STRING);
        break;
      }

      case zapParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 5);
        setState(335);
        match(zapParser::IDENTIFIER);
        break;
      }

      case zapParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(336);
        match(zapParser::T__1);
        setState(337);
        expression();
        setState(338);
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

void zapParser::AotBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAotBlock(this);
}

void zapParser::AotBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<zapListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAotBlock(this);
}

zapParser::AotBlockContext* zapParser::aotBlock() {
  AotBlockContext *_localctx = _tracker.createInstance<AotBlockContext>(_ctx, getState());
  enterRule(_localctx, 68, zapParser::RuleAotBlock);

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
    match(zapParser::AOT);
    setState(343);
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
