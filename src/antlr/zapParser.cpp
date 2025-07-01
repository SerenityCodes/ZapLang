
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
        : ruleNames(std::move(ruleNames)),
          literalNames(std::move(literalNames)),
          symbolicNames(std::move(symbolicNames)),
          vocabulary(this->literalNames, this->symbolicNames) {}

    ZapParserStaticData(const ZapParserStaticData &)            = delete;
    ZapParserStaticData(ZapParserStaticData &&)                 = delete;
    ZapParserStaticData &operator=(const ZapParserStaticData &) = delete;
    ZapParserStaticData &operator=(ZapParserStaticData &&)      = delete;

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
    std::unique_ptr<ZapParserStaticData>
        zapParserStaticData = nullptr;

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
            "program",       "declaration",    "statement",
            "functionDecl",  "attributeBlock", "attributeList",
            "attribute",     "attributeArgs",  "attributeArg",
            "returnType",    "parameterList",  "parameter",
            "type",          "structDecl",     "structField",
            "componentDecl", "moduleDecl",     "block",
            "variableDecl",  "ifStmt",         "whileStmt",
            "forStmt",       "returnStmt",     "yieldStmt",
            "deferStmt",     "expressionStmt", "expression",
            "lvalue",        "assignment",     "logicOr",
            "logicAnd",      "equality",       "comparison",
            "term",          "factor",         "unary",
            "call",          "argumentList",   "primary",
            "aotBlock"},
        std::vector<std::string>{
            "",           "';'",      "'('",    "')'",      "'@'",
            "'['",        "']'",      "','",    "':'",      "'{'",
            "'}'",        "'='",      "'.'",    "",         "'if'",
            "'else'",     "'while'",  "'for'",  "'return'", "'yield'",
            "'defer'",    "'let'",    "'func'", "'struct'", "'component'",
            "'readonly'", "'module'", "'aot'",  "'ref'",    "'void'",
            "'->'",       "'use'",    "'||'",   "'&&'",     "'=='",
            "'!='",       "'+'",      "'-'",    "'*'",      "'/'",
            "'%'",        "'<'",      "'<='",   "'>'",      "'>='",
            "'!'"},
        std::vector<std::string>{"",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "BOOL",
                                 "IF",
                                 "ELSE",
                                 "WHILE",
                                 "FOR",
                                 "RETURN",
                                 "YIELD",
                                 "DEFER",
                                 "LET",
                                 "FUNC",
                                 "STRUCT",
                                 "COMPONENT",
                                 "READONLY",
                                 "MODULE",
                                 "AOT",
                                 "REF",
                                 "VOID",
                                 "ARROW",
                                 "USE",
                                 "OR",
                                 "AND",
                                 "EQ",
                                 "NEQ",
                                 "ADD",
                                 "SUB",
                                 "MUL",
                                 "DIV",
                                 "MOD",
                                 "LT",
                                 "LTE",
                                 "GT",
                                 "GTE",
                                 "NOT",
                                 "INT",
                                 "FLOAT",
                                 "STRING",
                                 "IDENTIFIER",
                                 "WS",
                                 "LINE_COMMENT",
                                 "BLOCK_COMMENT"});
    static const int32_t serializedATNSegment[] = {
        4,   1,   52,  404, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,
        7,   2,   2,   3,   7,   3,   2,   4,   7,   4,   2,   5,   7,   5,
        2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,
        7,   9,   2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,
        2,   13,  7,   13,  2,   14,  7,   14,  2,   15,  7,   15,  2,   16,
        7,   16,  2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,
        2,   20,  7,   20,  2,   21,  7,   21,  2,   22,  7,   22,  2,   23,
        7,   23,  2,   24,  7,   24,  2,   25,  7,   25,  2,   26,  7,   26,
        2,   27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29,  2,   30,
        7,   30,  2,   31,  7,   31,  2,   32,  7,   32,  2,   33,  7,   33,
        2,   34,  7,   34,  2,   35,  7,   35,  2,   36,  7,   36,  2,   37,
        7,   37,  2,   38,  7,   38,  2,   39,  7,   39,  1,   0,   5,   0,
        82,  8,   0,   10,  0,   12,  0,   85,  9,   0,   1,   0,   1,   0,
        1,   1,   1,   1,   1,   1,   1,   1,   3,   1,   93,  8,   1,   1,
        2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   1,
        2,   1,   2,   1,   2,   1,   2,   3,   2,   106, 8,   2,   1,   3,
        3,   3,   109, 8,   3,   1,   3,   1,   3,   1,   3,   1,   3,   3,
        3,   115, 8,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   4,
        1,   4,   1,   4,   1,   4,   1,   4,   1,   5,   1,   5,   1,   5,
        5,   5,   129, 8,   5,   10,  5,   12,  5,   132, 9,   5,   1,   6,
        1,   6,   1,   6,   3,   6,   137, 8,   6,   1,   6,   3,   6,   140,
        8,   6,   1,   7,   1,   7,   1,   7,   5,   7,   145, 8,   7,   10,
        7,   12,  7,   148, 9,   7,   1,   8,   1,   8,   1,   9,   1,   9,
        1,   9,   1,   10,  1,   10,  1,   10,  5,   10,  158, 8,   10,  10,
        10,  12,  10,  161, 9,   10,  1,   11,  1,   11,  1,   11,  3,   11,
        166, 8,   11,  1,   11,  1,   11,  1,   12,  1,   12,  1,   12,  1,
        12,  1,   12,  3,   12,  175, 8,   12,  1,   12,  1,   12,  3,   12,
        179, 8,   12,  1,   13,  1,   13,  1,   13,  1,   13,  5,   13,  185,
        8,   13,  10,  13,  12,  13,  188, 9,   13,  1,   13,  1,   13,  1,
        14,  1,   14,  1,   14,  1,   14,  1,   14,  1,   15,  3,   15,  198,
        8,   15,  1,   15,  1,   15,  1,   15,  1,   15,  5,   15,  204, 8,
        15,  10,  15,  12,  15,  207, 9,   15,  1,   15,  1,   15,  1,   16,
        1,   16,  1,   16,  1,   16,  5,   16,  215, 8,   16,  10,  16,  12,
        16,  218, 9,   16,  1,   16,  1,   16,  1,   17,  1,   17,  5,   17,
        224, 8,   17,  10,  17,  12,  17,  227, 9,   17,  1,   17,  1,   17,
        1,   18,  1,   18,  1,   18,  1,   18,  1,   18,  1,   18,  1,   18,
        3,   18,  238, 8,   18,  1,   19,  1,   19,  1,   19,  1,   19,  1,
        19,  1,   19,  1,   19,  3,   19,  247, 8,   19,  1,   20,  1,   20,
        1,   20,  1,   20,  1,   20,  1,   20,  1,   21,  1,   21,  1,   21,
        1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,
        1,   22,  1,   22,  3,   22,  267, 8,   22,  1,   22,  1,   22,  1,
        23,  1,   23,  3,   23,  273, 8,   23,  1,   23,  1,   23,  1,   24,
        1,   24,  1,   24,  3,   24,  280, 8,   24,  1,   25,  1,   25,  1,
        25,  1,   26,  1,   26,  1,   27,  1,   27,  1,   27,  1,   27,  1,
        27,  1,   27,  1,   27,  1,   27,  1,   27,  1,   27,  1,   27,  5,
        27,  298, 8,   27,  10,  27,  12,  27,  301, 9,   27,  1,   28,  1,
        28,  1,   28,  1,   28,  1,   28,  3,   28,  308, 8,   28,  1,   29,
        1,   29,  1,   29,  5,   29,  313, 8,   29,  10,  29,  12,  29,  316,
        9,   29,  1,   30,  1,   30,  1,   30,  5,   30,  321, 8,   30,  10,
        30,  12,  30,  324, 9,   30,  1,   31,  1,   31,  1,   31,  5,   31,
        329, 8,   31,  10,  31,  12,  31,  332, 9,   31,  1,   32,  1,   32,
        1,   32,  5,   32,  337, 8,   32,  10,  32,  12,  32,  340, 9,   32,
        1,   33,  1,   33,  1,   33,  5,   33,  345, 8,   33,  10,  33,  12,
        33,  348, 9,   33,  1,   34,  1,   34,  1,   34,  5,   34,  353, 8,
        34,  10,  34,  12,  34,  356, 9,   34,  1,   35,  1,   35,  1,   35,
        3,   35,  361, 8,   35,  1,   36,  1,   36,  1,   36,  5,   36,  366,
        8,   36,  10,  36,  12,  36,  369, 9,   36,  1,   36,  1,   36,  3,
        36,  373, 8,   36,  1,   36,  5,   36,  376, 8,   36,  10,  36,  12,
        36,  379, 9,   36,  1,   37,  1,   37,  1,   37,  5,   37,  384, 8,
        37,  10,  37,  12,  37,  387, 9,   37,  1,   38,  1,   38,  1,   38,
        1,   38,  1,   38,  1,   38,  1,   38,  1,   38,  1,   38,  1,   38,
        3,   38,  399, 8,   38,  1,   39,  1,   39,  1,   39,  1,   39,  0,
        1,   54,  40,  0,   2,   4,   6,   8,   10,  12,  14,  16,  18,  20,
        22,  24,  26,  28,  30,  32,  34,  36,  38,  40,  42,  44,  46,  48,
        50,  52,  54,  56,  58,  60,  62,  64,  66,  68,  70,  72,  74,  76,
        78,  0,   7,   2,   0,   46,  46,  48,  49,  2,   0,   29,  29,  49,
        49,  1,   0,   34,  35,  1,   0,   41,  44,  1,   0,   36,  37,  1,
        0,   38,  40,  2,   0,   37,  37,  45,  45,  415, 0,   83,  1,   0,
        0,   0,   2,   92,  1,   0,   0,   0,   4,   105, 1,   0,   0,   0,
        6,   108, 1,   0,   0,   0,   8,   120, 1,   0,   0,   0,   10,  125,
        1,   0,   0,   0,   12,  133, 1,   0,   0,   0,   14,  141, 1,   0,
        0,   0,   16,  149, 1,   0,   0,   0,   18,  151, 1,   0,   0,   0,
        20,  154, 1,   0,   0,   0,   22,  162, 1,   0,   0,   0,   24,  169,
        1,   0,   0,   0,   26,  180, 1,   0,   0,   0,   28,  191, 1,   0,
        0,   0,   30,  197, 1,   0,   0,   0,   32,  210, 1,   0,   0,   0,
        34,  221, 1,   0,   0,   0,   36,  230, 1,   0,   0,   0,   38,  239,
        1,   0,   0,   0,   40,  248, 1,   0,   0,   0,   42,  254, 1,   0,
        0,   0,   44,  264, 1,   0,   0,   0,   46,  270, 1,   0,   0,   0,
        48,  276, 1,   0,   0,   0,   50,  281, 1,   0,   0,   0,   52,  284,
        1,   0,   0,   0,   54,  286, 1,   0,   0,   0,   56,  307, 1,   0,
        0,   0,   58,  309, 1,   0,   0,   0,   60,  317, 1,   0,   0,   0,
        62,  325, 1,   0,   0,   0,   64,  333, 1,   0,   0,   0,   66,  341,
        1,   0,   0,   0,   68,  349, 1,   0,   0,   0,   70,  360, 1,   0,
        0,   0,   72,  362, 1,   0,   0,   0,   74,  380, 1,   0,   0,   0,
        76,  398, 1,   0,   0,   0,   78,  400, 1,   0,   0,   0,   80,  82,
        3,   2,   1,   0,   81,  80,  1,   0,   0,   0,   82,  85,  1,   0,
        0,   0,   83,  81,  1,   0,   0,   0,   83,  84,  1,   0,   0,   0,
        84,  86,  1,   0,   0,   0,   85,  83,  1,   0,   0,   0,   86,  87,
        5,   0,   0,   1,   87,  1,   1,   0,   0,   0,   88,  93,  3,   6,
        3,   0,   89,  93,  3,   26,  13,  0,   90,  93,  3,   30,  15,  0,
        91,  93,  3,   32,  16,  0,   92,  88,  1,   0,   0,   0,   92,  89,
        1,   0,   0,   0,   92,  90,  1,   0,   0,   0,   92,  91,  1,   0,
        0,   0,   93,  3,   1,   0,   0,   0,   94,  95,  3,   36,  18,  0,
        95,  96,  5,   1,   0,   0,   96,  106, 1,   0,   0,   0,   97,  106,
        3,   50,  25,  0,   98,  106, 3,   34,  17,  0,   99,  106, 3,   38,
        19,  0,   100, 106, 3,   40,  20,  0,   101, 106, 3,   42,  21,  0,
        102, 106, 3,   44,  22,  0,   103, 106, 3,   46,  23,  0,   104, 106,
        3,   48,  24,  0,   105, 94,  1,   0,   0,   0,   105, 97,  1,   0,
        0,   0,   105, 98,  1,   0,   0,   0,   105, 99,  1,   0,   0,   0,
        105, 100, 1,   0,   0,   0,   105, 101, 1,   0,   0,   0,   105, 102,
        1,   0,   0,   0,   105, 103, 1,   0,   0,   0,   105, 104, 1,   0,
        0,   0,   106, 5,   1,   0,   0,   0,   107, 109, 3,   8,   4,   0,
        108, 107, 1,   0,   0,   0,   108, 109, 1,   0,   0,   0,   109, 110,
        1,   0,   0,   0,   110, 111, 5,   22,  0,   0,   111, 112, 5,   49,
        0,   0,   112, 114, 5,   2,   0,   0,   113, 115, 3,   20,  10,  0,
        114, 113, 1,   0,   0,   0,   114, 115, 1,   0,   0,   0,   115, 116,
        1,   0,   0,   0,   116, 117, 5,   3,   0,   0,   117, 118, 3,   18,
        9,   0,   118, 119, 3,   34,  17,  0,   119, 7,   1,   0,   0,   0,
        120, 121, 5,   4,   0,   0,   121, 122, 5,   5,   0,   0,   122, 123,
        3,   10,  5,   0,   123, 124, 5,   6,   0,   0,   124, 9,   1,   0,
        0,   0,   125, 130, 3,   12,  6,   0,   126, 127, 5,   7,   0,   0,
        127, 129, 3,   12,  6,   0,   128, 126, 1,   0,   0,   0,   129, 132,
        1,   0,   0,   0,   130, 128, 1,   0,   0,   0,   130, 131, 1,   0,
        0,   0,   131, 11,  1,   0,   0,   0,   132, 130, 1,   0,   0,   0,
        133, 139, 5,   49,  0,   0,   134, 136, 5,   2,   0,   0,   135, 137,
        3,   14,  7,   0,   136, 135, 1,   0,   0,   0,   136, 137, 1,   0,
        0,   0,   137, 138, 1,   0,   0,   0,   138, 140, 5,   3,   0,   0,
        139, 134, 1,   0,   0,   0,   139, 140, 1,   0,   0,   0,   140, 13,
        1,   0,   0,   0,   141, 146, 3,   16,  8,   0,   142, 143, 5,   7,
        0,   0,   143, 145, 3,   16,  8,   0,   144, 142, 1,   0,   0,   0,
        145, 148, 1,   0,   0,   0,   146, 144, 1,   0,   0,   0,   146, 147,
        1,   0,   0,   0,   147, 15,  1,   0,   0,   0,   148, 146, 1,   0,
        0,   0,   149, 150, 7,   0,   0,   0,   150, 17,  1,   0,   0,   0,
        151, 152, 5,   30,  0,   0,   152, 153, 3,   24,  12,  0,   153, 19,
        1,   0,   0,   0,   154, 159, 3,   22,  11,  0,   155, 156, 5,   7,
        0,   0,   156, 158, 3,   22,  11,  0,   157, 155, 1,   0,   0,   0,
        158, 161, 1,   0,   0,   0,   159, 157, 1,   0,   0,   0,   159, 160,
        1,   0,   0,   0,   160, 21,  1,   0,   0,   0,   161, 159, 1,   0,
        0,   0,   162, 163, 5,   49,  0,   0,   163, 165, 5,   8,   0,   0,
        164, 166, 5,   28,  0,   0,   165, 164, 1,   0,   0,   0,   165, 166,
        1,   0,   0,   0,   166, 167, 1,   0,   0,   0,   167, 168, 3,   24,
        12,  0,   168, 23,  1,   0,   0,   0,   169, 174, 7,   1,   0,   0,
        170, 171, 5,   41,  0,   0,   171, 172, 3,   24,  12,  0,   172, 173,
        5,   43,  0,   0,   173, 175, 1,   0,   0,   0,   174, 170, 1,   0,
        0,   0,   174, 175, 1,   0,   0,   0,   175, 178, 1,   0,   0,   0,
        176, 177, 5,   5,   0,   0,   177, 179, 5,   6,   0,   0,   178, 176,
        1,   0,   0,   0,   178, 179, 1,   0,   0,   0,   179, 25,  1,   0,
        0,   0,   180, 181, 5,   23,  0,   0,   181, 182, 5,   49,  0,   0,
        182, 186, 5,   9,   0,   0,   183, 185, 3,   28,  14,  0,   184, 183,
        1,   0,   0,   0,   185, 188, 1,   0,   0,   0,   186, 184, 1,   0,
        0,   0,   186, 187, 1,   0,   0,   0,   187, 189, 1,   0,   0,   0,
        188, 186, 1,   0,   0,   0,   189, 190, 5,   10,  0,   0,   190, 27,
        1,   0,   0,   0,   191, 192, 5,   49,  0,   0,   192, 193, 5,   8,
        0,   0,   193, 194, 3,   24,  12,  0,   194, 195, 5,   1,   0,   0,
        195, 29,  1,   0,   0,   0,   196, 198, 5,   25,  0,   0,   197, 196,
        1,   0,   0,   0,   197, 198, 1,   0,   0,   0,   198, 199, 1,   0,
        0,   0,   199, 200, 5,   24,  0,   0,   200, 201, 5,   49,  0,   0,
        201, 205, 5,   9,   0,   0,   202, 204, 3,   28,  14,  0,   203, 202,
        1,   0,   0,   0,   204, 207, 1,   0,   0,   0,   205, 203, 1,   0,
        0,   0,   205, 206, 1,   0,   0,   0,   206, 208, 1,   0,   0,   0,
        207, 205, 1,   0,   0,   0,   208, 209, 5,   10,  0,   0,   209, 31,
        1,   0,   0,   0,   210, 211, 5,   26,  0,   0,   211, 212, 5,   49,
        0,   0,   212, 216, 5,   9,   0,   0,   213, 215, 3,   4,   2,   0,
        214, 213, 1,   0,   0,   0,   215, 218, 1,   0,   0,   0,   216, 214,
        1,   0,   0,   0,   216, 217, 1,   0,   0,   0,   217, 219, 1,   0,
        0,   0,   218, 216, 1,   0,   0,   0,   219, 220, 5,   10,  0,   0,
        220, 33,  1,   0,   0,   0,   221, 225, 5,   9,   0,   0,   222, 224,
        3,   4,   2,   0,   223, 222, 1,   0,   0,   0,   224, 227, 1,   0,
        0,   0,   225, 223, 1,   0,   0,   0,   225, 226, 1,   0,   0,   0,
        226, 228, 1,   0,   0,   0,   227, 225, 1,   0,   0,   0,   228, 229,
        5,   10,  0,   0,   229, 35,  1,   0,   0,   0,   230, 231, 5,   21,
        0,   0,   231, 232, 5,   49,  0,   0,   232, 233, 5,   8,   0,   0,
        233, 234, 3,   24,  12,  0,   234, 237, 5,   11,  0,   0,   235, 238,
        3,   52,  26,  0,   236, 238, 3,   78,  39,  0,   237, 235, 1,   0,
        0,   0,   237, 236, 1,   0,   0,   0,   238, 37,  1,   0,   0,   0,
        239, 240, 5,   14,  0,   0,   240, 241, 5,   2,   0,   0,   241, 242,
        3,   52,  26,  0,   242, 243, 5,   3,   0,   0,   243, 246, 3,   34,
        17,  0,   244, 245, 5,   15,  0,   0,   245, 247, 3,   34,  17,  0,
        246, 244, 1,   0,   0,   0,   246, 247, 1,   0,   0,   0,   247, 39,
        1,   0,   0,   0,   248, 249, 5,   16,  0,   0,   249, 250, 5,   2,
        0,   0,   250, 251, 3,   52,  26,  0,   251, 252, 5,   3,   0,   0,
        252, 253, 3,   34,  17,  0,   253, 41,  1,   0,   0,   0,   254, 255,
        5,   17,  0,   0,   255, 256, 5,   2,   0,   0,   256, 257, 3,   36,
        18,  0,   257, 258, 5,   1,   0,   0,   258, 259, 3,   52,  26,  0,
        259, 260, 5,   1,   0,   0,   260, 261, 3,   52,  26,  0,   261, 262,
        5,   3,   0,   0,   262, 263, 3,   34,  17,  0,   263, 43,  1,   0,
        0,   0,   264, 266, 5,   18,  0,   0,   265, 267, 3,   52,  26,  0,
        266, 265, 1,   0,   0,   0,   266, 267, 1,   0,   0,   0,   267, 268,
        1,   0,   0,   0,   268, 269, 5,   1,   0,   0,   269, 45,  1,   0,
        0,   0,   270, 272, 5,   19,  0,   0,   271, 273, 3,   52,  26,  0,
        272, 271, 1,   0,   0,   0,   272, 273, 1,   0,   0,   0,   273, 274,
        1,   0,   0,   0,   274, 275, 5,   1,   0,   0,   275, 47,  1,   0,
        0,   0,   276, 279, 5,   20,  0,   0,   277, 280, 3,   34,  17,  0,
        278, 280, 3,   50,  25,  0,   279, 277, 1,   0,   0,   0,   279, 278,
        1,   0,   0,   0,   280, 49,  1,   0,   0,   0,   281, 282, 3,   52,
        26,  0,   282, 283, 5,   1,   0,   0,   283, 51,  1,   0,   0,   0,
        284, 285, 3,   56,  28,  0,   285, 53,  1,   0,   0,   0,   286, 287,
        6,   27,  -1,  0,   287, 288, 5,   49,  0,   0,   288, 299, 1,   0,
        0,   0,   289, 290, 10,  2,   0,   0,   290, 291, 5,   12,  0,   0,
        291, 298, 5,   49,  0,   0,   292, 293, 10,  1,   0,   0,   293, 294,
        5,   5,   0,   0,   294, 295, 3,   52,  26,  0,   295, 296, 5,   6,
        0,   0,   296, 298, 1,   0,   0,   0,   297, 289, 1,   0,   0,   0,
        297, 292, 1,   0,   0,   0,   298, 301, 1,   0,   0,   0,   299, 297,
        1,   0,   0,   0,   299, 300, 1,   0,   0,   0,   300, 55,  1,   0,
        0,   0,   301, 299, 1,   0,   0,   0,   302, 303, 3,   54,  27,  0,
        303, 304, 5,   11,  0,   0,   304, 305, 3,   52,  26,  0,   305, 308,
        1,   0,   0,   0,   306, 308, 3,   58,  29,  0,   307, 302, 1,   0,
        0,   0,   307, 306, 1,   0,   0,   0,   308, 57,  1,   0,   0,   0,
        309, 314, 3,   60,  30,  0,   310, 311, 5,   32,  0,   0,   311, 313,
        3,   60,  30,  0,   312, 310, 1,   0,   0,   0,   313, 316, 1,   0,
        0,   0,   314, 312, 1,   0,   0,   0,   314, 315, 1,   0,   0,   0,
        315, 59,  1,   0,   0,   0,   316, 314, 1,   0,   0,   0,   317, 322,
        3,   62,  31,  0,   318, 319, 5,   33,  0,   0,   319, 321, 3,   62,
        31,  0,   320, 318, 1,   0,   0,   0,   321, 324, 1,   0,   0,   0,
        322, 320, 1,   0,   0,   0,   322, 323, 1,   0,   0,   0,   323, 61,
        1,   0,   0,   0,   324, 322, 1,   0,   0,   0,   325, 330, 3,   64,
        32,  0,   326, 327, 7,   2,   0,   0,   327, 329, 3,   64,  32,  0,
        328, 326, 1,   0,   0,   0,   329, 332, 1,   0,   0,   0,   330, 328,
        1,   0,   0,   0,   330, 331, 1,   0,   0,   0,   331, 63,  1,   0,
        0,   0,   332, 330, 1,   0,   0,   0,   333, 338, 3,   66,  33,  0,
        334, 335, 7,   3,   0,   0,   335, 337, 3,   66,  33,  0,   336, 334,
        1,   0,   0,   0,   337, 340, 1,   0,   0,   0,   338, 336, 1,   0,
        0,   0,   338, 339, 1,   0,   0,   0,   339, 65,  1,   0,   0,   0,
        340, 338, 1,   0,   0,   0,   341, 346, 3,   68,  34,  0,   342, 343,
        7,   4,   0,   0,   343, 345, 3,   68,  34,  0,   344, 342, 1,   0,
        0,   0,   345, 348, 1,   0,   0,   0,   346, 344, 1,   0,   0,   0,
        346, 347, 1,   0,   0,   0,   347, 67,  1,   0,   0,   0,   348, 346,
        1,   0,   0,   0,   349, 354, 3,   70,  35,  0,   350, 351, 7,   5,
        0,   0,   351, 353, 3,   70,  35,  0,   352, 350, 1,   0,   0,   0,
        353, 356, 1,   0,   0,   0,   354, 352, 1,   0,   0,   0,   354, 355,
        1,   0,   0,   0,   355, 69,  1,   0,   0,   0,   356, 354, 1,   0,
        0,   0,   357, 358, 7,   6,   0,   0,   358, 361, 3,   70,  35,  0,
        359, 361, 3,   72,  36,  0,   360, 357, 1,   0,   0,   0,   360, 359,
        1,   0,   0,   0,   361, 71,  1,   0,   0,   0,   362, 367, 3,   76,
        38,  0,   363, 364, 5,   12,  0,   0,   364, 366, 5,   49,  0,   0,
        365, 363, 1,   0,   0,   0,   366, 369, 1,   0,   0,   0,   367, 365,
        1,   0,   0,   0,   367, 368, 1,   0,   0,   0,   368, 377, 1,   0,
        0,   0,   369, 367, 1,   0,   0,   0,   370, 372, 5,   2,   0,   0,
        371, 373, 3,   74,  37,  0,   372, 371, 1,   0,   0,   0,   372, 373,
        1,   0,   0,   0,   373, 374, 1,   0,   0,   0,   374, 376, 5,   3,
        0,   0,   375, 370, 1,   0,   0,   0,   376, 379, 1,   0,   0,   0,
        377, 375, 1,   0,   0,   0,   377, 378, 1,   0,   0,   0,   378, 73,
        1,   0,   0,   0,   379, 377, 1,   0,   0,   0,   380, 385, 3,   52,
        26,  0,   381, 382, 5,   7,   0,   0,   382, 384, 3,   52,  26,  0,
        383, 381, 1,   0,   0,   0,   384, 387, 1,   0,   0,   0,   385, 383,
        1,   0,   0,   0,   385, 386, 1,   0,   0,   0,   386, 75,  1,   0,
        0,   0,   387, 385, 1,   0,   0,   0,   388, 399, 5,   46,  0,   0,
        389, 399, 5,   47,  0,   0,   390, 399, 5,   13,  0,   0,   391, 399,
        5,   48,  0,   0,   392, 399, 5,   49,  0,   0,   393, 399, 3,   54,
        27,  0,   394, 395, 5,   2,   0,   0,   395, 396, 3,   52,  26,  0,
        396, 397, 5,   3,   0,   0,   397, 399, 1,   0,   0,   0,   398, 388,
        1,   0,   0,   0,   398, 389, 1,   0,   0,   0,   398, 390, 1,   0,
        0,   0,   398, 391, 1,   0,   0,   0,   398, 392, 1,   0,   0,   0,
        398, 393, 1,   0,   0,   0,   398, 394, 1,   0,   0,   0,   399, 77,
        1,   0,   0,   0,   400, 401, 5,   27,  0,   0,   401, 402, 3,   34,
        17,  0,   402, 79,  1,   0,   0,   0,   38,  83,  92,  105, 108, 114,
        130, 136, 139, 146, 159, 165, 174, 178, 186, 197, 205, 216, 225, 237,
        246, 266, 272, 279, 297, 299, 307, 314, 322, 330, 338, 346, 354, 360,
        367, 372, 377, 385, 398};
    staticData->serializedATN = antlr4::atn::SerializedATNView(
        serializedATNSegment,
        sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

    antlr4::atn::ATNDeserializer deserializer;
    staticData->atn    = deserializer.deserialize(staticData->serializedATN);

    const size_t count = staticData->atn->getNumberOfDecisions();
    staticData->decisionToDFA.reserve(count);
    for (size_t i = 0; i < count; i++) {
        staticData->decisionToDFA.emplace_back(
            staticData->atn->getDecisionState(i), i);
    }
    zapParserStaticData = std::move(staticData);
}

}  // namespace

zapParser::zapParser(TokenStream *input)
    : zapParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

zapParser::zapParser(TokenStream *input,
                     const antlr4::atn::ParserATNSimulatorOptions &options)
    : Parser(input) {
    zapParser::initialize();
    _interpreter = new atn::ParserATNSimulator(
        this, *zapParserStaticData->atn, zapParserStaticData->decisionToDFA,
        zapParserStaticData->sharedContextCache, options);
}

zapParser::~zapParser() {
    delete _interpreter;
}

const atn::ATN &zapParser::getATN() const {
    return *zapParserStaticData->atn;
}

std::string zapParser::getGrammarFileName() const {
    return "zap.g4";
}

const std::vector<std::string> &zapParser::getRuleNames() const {
    return zapParserStaticData->ruleNames;
}

const dfa::Vocabulary &zapParser::getVocabulary() const {
    return zapParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView zapParser::getSerializedATN() const {
    return zapParserStaticData->serializedATN;
}

//----------------- ProgramContext ------------------------------------------------------------------

zapParser::ProgramContext::ProgramContext(ParserRuleContext *parent,
                                          size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ProgramContext::EOF() {
    return getToken(zapParser::EOF, 0);
}

std::vector<zapParser::DeclarationContext *>
zapParser::ProgramContext::declaration() {
    return getRuleContexts<zapParser::DeclarationContext>();
}

zapParser::DeclarationContext *zapParser::ProgramContext::declaration(
    size_t i) {
    return getRuleContext<zapParser::DeclarationContext>(i);
}

size_t zapParser::ProgramContext::getRuleIndex() const {
    return zapParser::RuleProgram;
}

std::any zapParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitProgram(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ProgramContext *zapParser::program() {
    ProgramContext *_localctx =
        _tracker.createInstance<ProgramContext>(_ctx, getState());
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
        setState(83);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 130023440) != 0)) {
            setState(80);
            declaration();
            setState(85);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(86);
        match(zapParser::EOF);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

zapParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent,
                                                  size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::FunctionDeclContext *zapParser::DeclarationContext::functionDecl() {
    return getRuleContext<zapParser::FunctionDeclContext>(0);
}

zapParser::StructDeclContext *zapParser::DeclarationContext::structDecl() {
    return getRuleContext<zapParser::StructDeclContext>(0);
}

zapParser::ComponentDeclContext *
zapParser::DeclarationContext::componentDecl() {
    return getRuleContext<zapParser::ComponentDeclContext>(0);
}

zapParser::ModuleDeclContext *zapParser::DeclarationContext::moduleDecl() {
    return getRuleContext<zapParser::ModuleDeclContext>(0);
}

size_t zapParser::DeclarationContext::getRuleIndex() const {
    return zapParser::RuleDeclaration;
}

std::any zapParser::DeclarationContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitDeclaration(this);
    else
        return visitor->visitChildren(this);
}

zapParser::DeclarationContext *zapParser::declaration() {
    DeclarationContext *_localctx =
        _tracker.createInstance<DeclarationContext>(_ctx, getState());
    enterRule(_localctx, 2, zapParser::RuleDeclaration);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(92);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
            case zapParser::T__3:
            case zapParser::FUNC: {
                enterOuterAlt(_localctx, 1);
                setState(88);
                functionDecl();
                break;
            }

            case zapParser::STRUCT: {
                enterOuterAlt(_localctx, 2);
                setState(89);
                structDecl();
                break;
            }

            case zapParser::COMPONENT:
            case zapParser::READONLY: {
                enterOuterAlt(_localctx, 3);
                setState(90);
                componentDecl();
                break;
            }

            case zapParser::MODULE: {
                enterOuterAlt(_localctx, 4);
                setState(91);
                moduleDecl();
                break;
            }

            default:
                throw NoViableAltException(this);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

zapParser::StatementContext::StatementContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::VariableDeclContext *zapParser::StatementContext::variableDecl() {
    return getRuleContext<zapParser::VariableDeclContext>(0);
}

zapParser::ExpressionStmtContext *
zapParser::StatementContext::expressionStmt() {
    return getRuleContext<zapParser::ExpressionStmtContext>(0);
}

zapParser::BlockContext *zapParser::StatementContext::block() {
    return getRuleContext<zapParser::BlockContext>(0);
}

zapParser::IfStmtContext *zapParser::StatementContext::ifStmt() {
    return getRuleContext<zapParser::IfStmtContext>(0);
}

zapParser::WhileStmtContext *zapParser::StatementContext::whileStmt() {
    return getRuleContext<zapParser::WhileStmtContext>(0);
}

zapParser::ForStmtContext *zapParser::StatementContext::forStmt() {
    return getRuleContext<zapParser::ForStmtContext>(0);
}

zapParser::ReturnStmtContext *zapParser::StatementContext::returnStmt() {
    return getRuleContext<zapParser::ReturnStmtContext>(0);
}

zapParser::YieldStmtContext *zapParser::StatementContext::yieldStmt() {
    return getRuleContext<zapParser::YieldStmtContext>(0);
}

zapParser::DeferStmtContext *zapParser::StatementContext::deferStmt() {
    return getRuleContext<zapParser::DeferStmtContext>(0);
}

size_t zapParser::StatementContext::getRuleIndex() const {
    return zapParser::RuleStatement;
}

std::any zapParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitStatement(this);
    else
        return visitor->visitChildren(this);
}

zapParser::StatementContext *zapParser::statement() {
    StatementContext *_localctx =
        _tracker.createInstance<StatementContext>(_ctx, getState());
    enterRule(_localctx, 4, zapParser::RuleStatement);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(105);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
            case zapParser::LET: {
                enterOuterAlt(_localctx, 1);
                setState(94);
                variableDecl();
                setState(95);
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
                setState(97);
                expressionStmt();
                break;
            }

            case zapParser::T__8: {
                enterOuterAlt(_localctx, 3);
                setState(98);
                block();
                break;
            }

            case zapParser::IF: {
                enterOuterAlt(_localctx, 4);
                setState(99);
                ifStmt();
                break;
            }

            case zapParser::WHILE: {
                enterOuterAlt(_localctx, 5);
                setState(100);
                whileStmt();
                break;
            }

            case zapParser::FOR: {
                enterOuterAlt(_localctx, 6);
                setState(101);
                forStmt();
                break;
            }

            case zapParser::RETURN: {
                enterOuterAlt(_localctx, 7);
                setState(102);
                returnStmt();
                break;
            }

            case zapParser::YIELD: {
                enterOuterAlt(_localctx, 8);
                setState(103);
                yieldStmt();
                break;
            }

            case zapParser::DEFER: {
                enterOuterAlt(_localctx, 9);
                setState(104);
                deferStmt();
                break;
            }

            default:
                throw NoViableAltException(this);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

zapParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent,
                                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::FunctionDeclContext::FUNC() {
    return getToken(zapParser::FUNC, 0);
}

tree::TerminalNode *zapParser::FunctionDeclContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::ReturnTypeContext *zapParser::FunctionDeclContext::returnType() {
    return getRuleContext<zapParser::ReturnTypeContext>(0);
}

zapParser::BlockContext *zapParser::FunctionDeclContext::block() {
    return getRuleContext<zapParser::BlockContext>(0);
}

zapParser::AttributeBlockContext *
zapParser::FunctionDeclContext::attributeBlock() {
    return getRuleContext<zapParser::AttributeBlockContext>(0);
}

zapParser::ParameterListContext *
zapParser::FunctionDeclContext::parameterList() {
    return getRuleContext<zapParser::ParameterListContext>(0);
}

size_t zapParser::FunctionDeclContext::getRuleIndex() const {
    return zapParser::RuleFunctionDecl;
}

std::any zapParser::FunctionDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitFunctionDecl(this);
    else
        return visitor->visitChildren(this);
}

zapParser::FunctionDeclContext *zapParser::functionDecl() {
    FunctionDeclContext *_localctx =
        _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
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
        setState(108);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::T__3) {
            setState(107);
            attributeBlock();
        }
        setState(110);
        match(zapParser::FUNC);
        setState(111);
        match(zapParser::IDENTIFIER);
        setState(112);
        match(zapParser::T__1);
        setState(114);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::IDENTIFIER) {
            setState(113);
            parameterList();
        }
        setState(116);
        match(zapParser::T__2);
        setState(117);
        returnType();
        setState(118);
        block();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AttributeBlockContext ------------------------------------------------------------------

zapParser::AttributeBlockContext::AttributeBlockContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::AttributeListContext *
zapParser::AttributeBlockContext::attributeList() {
    return getRuleContext<zapParser::AttributeListContext>(0);
}

size_t zapParser::AttributeBlockContext::getRuleIndex() const {
    return zapParser::RuleAttributeBlock;
}

std::any zapParser::AttributeBlockContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAttributeBlock(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AttributeBlockContext *zapParser::attributeBlock() {
    AttributeBlockContext *_localctx =
        _tracker.createInstance<AttributeBlockContext>(_ctx, getState());
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
        setState(120);
        match(zapParser::T__3);
        setState(121);
        match(zapParser::T__4);
        setState(122);
        attributeList();
        setState(123);
        match(zapParser::T__5);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AttributeListContext ------------------------------------------------------------------

zapParser::AttributeListContext::AttributeListContext(ParserRuleContext *parent,
                                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::AttributeContext *>
zapParser::AttributeListContext::attribute() {
    return getRuleContexts<zapParser::AttributeContext>();
}

zapParser::AttributeContext *zapParser::AttributeListContext::attribute(
    size_t i) {
    return getRuleContext<zapParser::AttributeContext>(i);
}

size_t zapParser::AttributeListContext::getRuleIndex() const {
    return zapParser::RuleAttributeList;
}

std::any zapParser::AttributeListContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAttributeList(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AttributeListContext *zapParser::attributeList() {
    AttributeListContext *_localctx =
        _tracker.createInstance<AttributeListContext>(_ctx, getState());
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
        setState(125);
        attribute();
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::T__6) {
            setState(126);
            match(zapParser::T__6);
            setState(127);
            attribute();
            setState(132);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AttributeContext ------------------------------------------------------------------

zapParser::AttributeContext::AttributeContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::AttributeContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::AttributeArgsContext *zapParser::AttributeContext::attributeArgs() {
    return getRuleContext<zapParser::AttributeArgsContext>(0);
}

size_t zapParser::AttributeContext::getRuleIndex() const {
    return zapParser::RuleAttribute;
}

std::any zapParser::AttributeContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAttribute(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AttributeContext *zapParser::attribute() {
    AttributeContext *_localctx =
        _tracker.createInstance<AttributeContext>(_ctx, getState());
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
        setState(133);
        match(zapParser::IDENTIFIER);
        setState(139);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::T__1) {
            setState(134);
            match(zapParser::T__1);
            setState(136);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~0x3fULL) == 0) &&
                 ((1ULL << _la) & 914793674309632) != 0)) {
                setState(135);
                attributeArgs();
            }
            setState(138);
            match(zapParser::T__2);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AttributeArgsContext ------------------------------------------------------------------

zapParser::AttributeArgsContext::AttributeArgsContext(ParserRuleContext *parent,
                                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::AttributeArgContext *>
zapParser::AttributeArgsContext::attributeArg() {
    return getRuleContexts<zapParser::AttributeArgContext>();
}

zapParser::AttributeArgContext *zapParser::AttributeArgsContext::attributeArg(
    size_t i) {
    return getRuleContext<zapParser::AttributeArgContext>(i);
}

size_t zapParser::AttributeArgsContext::getRuleIndex() const {
    return zapParser::RuleAttributeArgs;
}

std::any zapParser::AttributeArgsContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAttributeArgs(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AttributeArgsContext *zapParser::attributeArgs() {
    AttributeArgsContext *_localctx =
        _tracker.createInstance<AttributeArgsContext>(_ctx, getState());
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
        setState(141);
        attributeArg();
        setState(146);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::T__6) {
            setState(142);
            match(zapParser::T__6);
            setState(143);
            attributeArg();
            setState(148);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AttributeArgContext ------------------------------------------------------------------

zapParser::AttributeArgContext::AttributeArgContext(ParserRuleContext *parent,
                                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::AttributeArgContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

tree::TerminalNode *zapParser::AttributeArgContext::STRING() {
    return getToken(zapParser::STRING, 0);
}

tree::TerminalNode *zapParser::AttributeArgContext::INT() {
    return getToken(zapParser::INT, 0);
}

size_t zapParser::AttributeArgContext::getRuleIndex() const {
    return zapParser::RuleAttributeArg;
}

std::any zapParser::AttributeArgContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAttributeArg(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AttributeArgContext *zapParser::attributeArg() {
    AttributeArgContext *_localctx =
        _tracker.createInstance<AttributeArgContext>(_ctx, getState());
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
        setState(149);
        _la = _input->LA(1);
        if (!((((_la & ~0x3fULL) == 0) &&
               ((1ULL << _la) & 914793674309632) != 0))) {
            _errHandler->recoverInline(this);
        } else {
            _errHandler->reportMatch(this);
            consume();
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ReturnTypeContext ------------------------------------------------------------------

zapParser::ReturnTypeContext::ReturnTypeContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ReturnTypeContext::ARROW() {
    return getToken(zapParser::ARROW, 0);
}

zapParser::TypeContext *zapParser::ReturnTypeContext::type() {
    return getRuleContext<zapParser::TypeContext>(0);
}

size_t zapParser::ReturnTypeContext::getRuleIndex() const {
    return zapParser::RuleReturnType;
}

std::any zapParser::ReturnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitReturnType(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ReturnTypeContext *zapParser::returnType() {
    ReturnTypeContext *_localctx =
        _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
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
        setState(151);
        match(zapParser::ARROW);
        setState(152);
        type();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

zapParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent,
                                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::ParameterContext *>
zapParser::ParameterListContext::parameter() {
    return getRuleContexts<zapParser::ParameterContext>();
}

zapParser::ParameterContext *zapParser::ParameterListContext::parameter(
    size_t i) {
    return getRuleContext<zapParser::ParameterContext>(i);
}

size_t zapParser::ParameterListContext::getRuleIndex() const {
    return zapParser::RuleParameterList;
}

std::any zapParser::ParameterListContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitParameterList(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ParameterListContext *zapParser::parameterList() {
    ParameterListContext *_localctx =
        _tracker.createInstance<ParameterListContext>(_ctx, getState());
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
        setState(154);
        parameter();
        setState(159);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::T__6) {
            setState(155);
            match(zapParser::T__6);
            setState(156);
            parameter();
            setState(161);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

zapParser::ParameterContext::ParameterContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ParameterContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::TypeContext *zapParser::ParameterContext::type() {
    return getRuleContext<zapParser::TypeContext>(0);
}

tree::TerminalNode *zapParser::ParameterContext::REF() {
    return getToken(zapParser::REF, 0);
}

size_t zapParser::ParameterContext::getRuleIndex() const {
    return zapParser::RuleParameter;
}

std::any zapParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitParameter(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ParameterContext *zapParser::parameter() {
    ParameterContext *_localctx =
        _tracker.createInstance<ParameterContext>(_ctx, getState());
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
        setState(162);
        match(zapParser::IDENTIFIER);
        setState(163);
        match(zapParser::T__7);
        setState(165);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::REF) {
            setState(164);
            match(zapParser::REF);
        }
        setState(167);
        type();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

zapParser::TypeContext::TypeContext(ParserRuleContext *parent,
                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::TypeContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

tree::TerminalNode *zapParser::TypeContext::VOID() {
    return getToken(zapParser::VOID, 0);
}

tree::TerminalNode *zapParser::TypeContext::LT() {
    return getToken(zapParser::LT, 0);
}

zapParser::TypeContext *zapParser::TypeContext::type() {
    return getRuleContext<zapParser::TypeContext>(0);
}

tree::TerminalNode *zapParser::TypeContext::GT() {
    return getToken(zapParser::GT, 0);
}

size_t zapParser::TypeContext::getRuleIndex() const {
    return zapParser::RuleType;
}

std::any zapParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitType(this);
    else
        return visitor->visitChildren(this);
}

zapParser::TypeContext *zapParser::type() {
    TypeContext *_localctx =
        _tracker.createInstance<TypeContext>(_ctx, getState());
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
        setState(169);
        _la = _input->LA(1);
        if (!(_la == zapParser::VOID

              || _la == zapParser::IDENTIFIER)) {
            _errHandler->recoverInline(this);
        } else {
            _errHandler->reportMatch(this);
            consume();
        }
        setState(174);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::LT) {
            setState(170);
            match(zapParser::LT);
            setState(171);
            type();
            setState(172);
            match(zapParser::GT);
        }
        setState(178);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::T__4) {
            setState(176);
            match(zapParser::T__4);
            setState(177);
            match(zapParser::T__5);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StructDeclContext ------------------------------------------------------------------

zapParser::StructDeclContext::StructDeclContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::StructDeclContext::STRUCT() {
    return getToken(zapParser::STRUCT, 0);
}

tree::TerminalNode *zapParser::StructDeclContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

std::vector<zapParser::StructFieldContext *>
zapParser::StructDeclContext::structField() {
    return getRuleContexts<zapParser::StructFieldContext>();
}

zapParser::StructFieldContext *zapParser::StructDeclContext::structField(
    size_t i) {
    return getRuleContext<zapParser::StructFieldContext>(i);
}

size_t zapParser::StructDeclContext::getRuleIndex() const {
    return zapParser::RuleStructDecl;
}

std::any zapParser::StructDeclContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitStructDecl(this);
    else
        return visitor->visitChildren(this);
}

zapParser::StructDeclContext *zapParser::structDecl() {
    StructDeclContext *_localctx =
        _tracker.createInstance<StructDeclContext>(_ctx, getState());
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
        setState(180);
        match(zapParser::STRUCT);
        setState(181);
        match(zapParser::IDENTIFIER);
        setState(182);
        match(zapParser::T__8);
        setState(186);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::IDENTIFIER) {
            setState(183);
            structField();
            setState(188);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(189);
        match(zapParser::T__9);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StructFieldContext ------------------------------------------------------------------

zapParser::StructFieldContext::StructFieldContext(ParserRuleContext *parent,
                                                  size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::StructFieldContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::TypeContext *zapParser::StructFieldContext::type() {
    return getRuleContext<zapParser::TypeContext>(0);
}

size_t zapParser::StructFieldContext::getRuleIndex() const {
    return zapParser::RuleStructField;
}

std::any zapParser::StructFieldContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitStructField(this);
    else
        return visitor->visitChildren(this);
}

zapParser::StructFieldContext *zapParser::structField() {
    StructFieldContext *_localctx =
        _tracker.createInstance<StructFieldContext>(_ctx, getState());
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
        setState(191);
        match(zapParser::IDENTIFIER);
        setState(192);
        match(zapParser::T__7);
        setState(193);
        type();
        setState(194);
        match(zapParser::T__0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ComponentDeclContext ------------------------------------------------------------------

zapParser::ComponentDeclContext::ComponentDeclContext(ParserRuleContext *parent,
                                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ComponentDeclContext::COMPONENT() {
    return getToken(zapParser::COMPONENT, 0);
}

tree::TerminalNode *zapParser::ComponentDeclContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

tree::TerminalNode *zapParser::ComponentDeclContext::READONLY() {
    return getToken(zapParser::READONLY, 0);
}

std::vector<zapParser::StructFieldContext *>
zapParser::ComponentDeclContext::structField() {
    return getRuleContexts<zapParser::StructFieldContext>();
}

zapParser::StructFieldContext *zapParser::ComponentDeclContext::structField(
    size_t i) {
    return getRuleContext<zapParser::StructFieldContext>(i);
}

size_t zapParser::ComponentDeclContext::getRuleIndex() const {
    return zapParser::RuleComponentDecl;
}

std::any zapParser::ComponentDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitComponentDecl(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ComponentDeclContext *zapParser::componentDecl() {
    ComponentDeclContext *_localctx =
        _tracker.createInstance<ComponentDeclContext>(_ctx, getState());
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
        setState(197);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::READONLY) {
            setState(196);
            match(zapParser::READONLY);
        }
        setState(199);
        match(zapParser::COMPONENT);
        setState(200);
        match(zapParser::IDENTIFIER);
        setState(201);
        match(zapParser::T__8);
        setState(205);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::IDENTIFIER) {
            setState(202);
            structField();
            setState(207);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(208);
        match(zapParser::T__9);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ModuleDeclContext ------------------------------------------------------------------

zapParser::ModuleDeclContext::ModuleDeclContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ModuleDeclContext::MODULE() {
    return getToken(zapParser::MODULE, 0);
}

tree::TerminalNode *zapParser::ModuleDeclContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

std::vector<zapParser::StatementContext *>
zapParser::ModuleDeclContext::statement() {
    return getRuleContexts<zapParser::StatementContext>();
}

zapParser::StatementContext *zapParser::ModuleDeclContext::statement(size_t i) {
    return getRuleContext<zapParser::StatementContext>(i);
}

size_t zapParser::ModuleDeclContext::getRuleIndex() const {
    return zapParser::RuleModuleDecl;
}

std::any zapParser::ModuleDeclContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitModuleDecl(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ModuleDeclContext *zapParser::moduleDecl() {
    ModuleDeclContext *_localctx =
        _tracker.createInstance<ModuleDeclContext>(_ctx, getState());
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
        setState(210);
        match(zapParser::MODULE);
        setState(211);
        match(zapParser::IDENTIFIER);
        setState(212);
        match(zapParser::T__8);
        setState(216);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~0x3fULL) == 0) &&
                ((1ULL << _la) & 1090852977861124) != 0)) {
            setState(213);
            statement();
            setState(218);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(219);
        match(zapParser::T__9);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

zapParser::BlockContext::BlockContext(ParserRuleContext *parent,
                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::StatementContext *>
zapParser::BlockContext::statement() {
    return getRuleContexts<zapParser::StatementContext>();
}

zapParser::StatementContext *zapParser::BlockContext::statement(size_t i) {
    return getRuleContext<zapParser::StatementContext>(i);
}

size_t zapParser::BlockContext::getRuleIndex() const {
    return zapParser::RuleBlock;
}

std::any zapParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitBlock(this);
    else
        return visitor->visitChildren(this);
}

zapParser::BlockContext *zapParser::block() {
    BlockContext *_localctx =
        _tracker.createInstance<BlockContext>(_ctx, getState());
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
        setState(221);
        match(zapParser::T__8);
        setState(225);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~0x3fULL) == 0) &&
                ((1ULL << _la) & 1090852977861124) != 0)) {
            setState(222);
            statement();
            setState(227);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(228);
        match(zapParser::T__9);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- VariableDeclContext ------------------------------------------------------------------

zapParser::VariableDeclContext::VariableDeclContext(ParserRuleContext *parent,
                                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::VariableDeclContext::LET() {
    return getToken(zapParser::LET, 0);
}

tree::TerminalNode *zapParser::VariableDeclContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::TypeContext *zapParser::VariableDeclContext::type() {
    return getRuleContext<zapParser::TypeContext>(0);
}

zapParser::ExpressionContext *zapParser::VariableDeclContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

zapParser::AotBlockContext *zapParser::VariableDeclContext::aotBlock() {
    return getRuleContext<zapParser::AotBlockContext>(0);
}

size_t zapParser::VariableDeclContext::getRuleIndex() const {
    return zapParser::RuleVariableDecl;
}

std::any zapParser::VariableDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitVariableDecl(this);
    else
        return visitor->visitChildren(this);
}

zapParser::VariableDeclContext *zapParser::variableDecl() {
    VariableDeclContext *_localctx =
        _tracker.createInstance<VariableDeclContext>(_ctx, getState());
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
        setState(230);
        match(zapParser::LET);
        setState(231);
        match(zapParser::IDENTIFIER);
        setState(232);
        match(zapParser::T__7);
        setState(233);
        type();
        setState(234);
        match(zapParser::T__10);
        setState(237);
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
                setState(235);
                expression();
                break;
            }

            case zapParser::AOT: {
                setState(236);
                aotBlock();
                break;
            }

            default:
                throw NoViableAltException(this);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

zapParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent,
                                        size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::IfStmtContext::IF() {
    return getToken(zapParser::IF, 0);
}

zapParser::ExpressionContext *zapParser::IfStmtContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

std::vector<zapParser::BlockContext *> zapParser::IfStmtContext::block() {
    return getRuleContexts<zapParser::BlockContext>();
}

zapParser::BlockContext *zapParser::IfStmtContext::block(size_t i) {
    return getRuleContext<zapParser::BlockContext>(i);
}

tree::TerminalNode *zapParser::IfStmtContext::ELSE() {
    return getToken(zapParser::ELSE, 0);
}

size_t zapParser::IfStmtContext::getRuleIndex() const {
    return zapParser::RuleIfStmt;
}

std::any zapParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitIfStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::IfStmtContext *zapParser::ifStmt() {
    IfStmtContext *_localctx =
        _tracker.createInstance<IfStmtContext>(_ctx, getState());
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
        setState(239);
        match(zapParser::IF);
        setState(240);
        match(zapParser::T__1);
        setState(241);
        expression();
        setState(242);
        match(zapParser::T__2);
        setState(243);
        block();
        setState(246);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == zapParser::ELSE) {
            setState(244);
            match(zapParser::ELSE);
            setState(245);
            block();
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

zapParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::WhileStmtContext::WHILE() {
    return getToken(zapParser::WHILE, 0);
}

zapParser::ExpressionContext *zapParser::WhileStmtContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

zapParser::BlockContext *zapParser::WhileStmtContext::block() {
    return getRuleContext<zapParser::BlockContext>(0);
}

size_t zapParser::WhileStmtContext::getRuleIndex() const {
    return zapParser::RuleWhileStmt;
}

std::any zapParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitWhileStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::WhileStmtContext *zapParser::whileStmt() {
    WhileStmtContext *_localctx =
        _tracker.createInstance<WhileStmtContext>(_ctx, getState());
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
        setState(248);
        match(zapParser::WHILE);
        setState(249);
        match(zapParser::T__1);
        setState(250);
        expression();
        setState(251);
        match(zapParser::T__2);
        setState(252);
        block();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

zapParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent,
                                          size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ForStmtContext::FOR() {
    return getToken(zapParser::FOR, 0);
}

zapParser::VariableDeclContext *zapParser::ForStmtContext::variableDecl() {
    return getRuleContext<zapParser::VariableDeclContext>(0);
}

std::vector<zapParser::ExpressionContext *>
zapParser::ForStmtContext::expression() {
    return getRuleContexts<zapParser::ExpressionContext>();
}

zapParser::ExpressionContext *zapParser::ForStmtContext::expression(size_t i) {
    return getRuleContext<zapParser::ExpressionContext>(i);
}

zapParser::BlockContext *zapParser::ForStmtContext::block() {
    return getRuleContext<zapParser::BlockContext>(0);
}

size_t zapParser::ForStmtContext::getRuleIndex() const {
    return zapParser::RuleForStmt;
}

std::any zapParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitForStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ForStmtContext *zapParser::forStmt() {
    ForStmtContext *_localctx =
        _tracker.createInstance<ForStmtContext>(_ctx, getState());
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
        setState(254);
        match(zapParser::FOR);
        setState(255);
        match(zapParser::T__1);
        setState(256);
        variableDecl();
        setState(257);
        match(zapParser::T__0);
        setState(258);
        expression();
        setState(259);
        match(zapParser::T__0);
        setState(260);
        expression();
        setState(261);
        match(zapParser::T__2);
        setState(262);
        block();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

zapParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::ReturnStmtContext::RETURN() {
    return getToken(zapParser::RETURN, 0);
}

zapParser::ExpressionContext *zapParser::ReturnStmtContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

size_t zapParser::ReturnStmtContext::getRuleIndex() const {
    return zapParser::RuleReturnStmt;
}

std::any zapParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitReturnStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ReturnStmtContext *zapParser::returnStmt() {
    ReturnStmtContext *_localctx =
        _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
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
        setState(264);
        match(zapParser::RETURN);
        setState(266);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) &&
             ((1ULL << _la) & 1090852973715460) != 0)) {
            setState(265);
            expression();
        }
        setState(268);
        match(zapParser::T__0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- YieldStmtContext ------------------------------------------------------------------

zapParser::YieldStmtContext::YieldStmtContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::YieldStmtContext::YIELD() {
    return getToken(zapParser::YIELD, 0);
}

zapParser::ExpressionContext *zapParser::YieldStmtContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

size_t zapParser::YieldStmtContext::getRuleIndex() const {
    return zapParser::RuleYieldStmt;
}

std::any zapParser::YieldStmtContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitYieldStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::YieldStmtContext *zapParser::yieldStmt() {
    YieldStmtContext *_localctx =
        _tracker.createInstance<YieldStmtContext>(_ctx, getState());
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
        setState(270);
        match(zapParser::YIELD);
        setState(272);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~0x3fULL) == 0) &&
             ((1ULL << _la) & 1090852973715460) != 0)) {
            setState(271);
            expression();
        }
        setState(274);
        match(zapParser::T__0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- DeferStmtContext ------------------------------------------------------------------

zapParser::DeferStmtContext::DeferStmtContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::DeferStmtContext::DEFER() {
    return getToken(zapParser::DEFER, 0);
}

zapParser::BlockContext *zapParser::DeferStmtContext::block() {
    return getRuleContext<zapParser::BlockContext>(0);
}

zapParser::ExpressionStmtContext *
zapParser::DeferStmtContext::expressionStmt() {
    return getRuleContext<zapParser::ExpressionStmtContext>(0);
}

size_t zapParser::DeferStmtContext::getRuleIndex() const {
    return zapParser::RuleDeferStmt;
}

std::any zapParser::DeferStmtContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitDeferStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::DeferStmtContext *zapParser::deferStmt() {
    DeferStmtContext *_localctx =
        _tracker.createInstance<DeferStmtContext>(_ctx, getState());
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
        setState(276);
        match(zapParser::DEFER);
        setState(279);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
            case zapParser::T__8: {
                setState(277);
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
                setState(278);
                expressionStmt();
                break;
            }

            default:
                throw NoViableAltException(this);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ExpressionStmtContext ------------------------------------------------------------------

zapParser::ExpressionStmtContext::ExpressionStmtContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::ExpressionContext *zapParser::ExpressionStmtContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

size_t zapParser::ExpressionStmtContext::getRuleIndex() const {
    return zapParser::RuleExpressionStmt;
}

std::any zapParser::ExpressionStmtContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitExpressionStmt(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ExpressionStmtContext *zapParser::expressionStmt() {
    ExpressionStmtContext *_localctx =
        _tracker.createInstance<ExpressionStmtContext>(_ctx, getState());
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
        setState(281);
        expression();
        setState(282);
        match(zapParser::T__0);

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

zapParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::AssignmentContext *zapParser::ExpressionContext::assignment() {
    return getRuleContext<zapParser::AssignmentContext>(0);
}

size_t zapParser::ExpressionContext::getRuleIndex() const {
    return zapParser::RuleExpression;
}

std::any zapParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitExpression(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ExpressionContext *zapParser::expression() {
    ExpressionContext *_localctx =
        _tracker.createInstance<ExpressionContext>(_ctx, getState());
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
        setState(284);
        assignment();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LvalueContext ------------------------------------------------------------------

zapParser::LvalueContext::LvalueContext(ParserRuleContext *parent,
                                        size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::LvalueContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::LvalueContext *zapParser::LvalueContext::lvalue() {
    return getRuleContext<zapParser::LvalueContext>(0);
}

zapParser::ExpressionContext *zapParser::LvalueContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

size_t zapParser::LvalueContext::getRuleIndex() const {
    return zapParser::RuleLvalue;
}

std::any zapParser::LvalueContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitLvalue(this);
    else
        return visitor->visitChildren(this);
}

zapParser::LvalueContext *zapParser::lvalue() {
    return lvalue(0);
}

zapParser::LvalueContext *zapParser::lvalue(int precedence) {
    ParserRuleContext *parentContext = _ctx;
    size_t parentState               = getState();
    zapParser::LvalueContext *_localctx =
        _tracker.createInstance<LvalueContext>(_ctx, parentState);
    zapParser::LvalueContext *previousContext = _localctx;
    (void)
        previousContext;  // Silence compiler, in case the context is not used by generated code.
    size_t startState = 54;
    enterRecursionRule(_localctx, 54, zapParser::RuleLvalue, precedence);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        unrollRecursionContexts(parentContext);
    });
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(287);
        match(zapParser::IDENTIFIER);
        _ctx->stop = _input->LT(-1);
        setState(299);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 24, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                if (!_parseListeners.empty())
                    triggerExitRuleEvent();
                previousContext = _localctx;
                setState(297);
                _errHandler->sync(this);
                switch (
                    getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
                        _input, 23, _ctx)) {
                    case 1: {
                        _localctx = _tracker.createInstance<LvalueContext>(
                            parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState,
                                                RuleLvalue);
                        setState(289);

                        if (!(precpred(_ctx, 2)))
                            throw FailedPredicateException(this,
                                                           "precpred(_ctx, 2)");
                        setState(290);
                        match(zapParser::T__11);
                        setState(291);
                        match(zapParser::IDENTIFIER);
                        break;
                    }

                    case 2: {
                        _localctx = _tracker.createInstance<LvalueContext>(
                            parentContext, parentState);
                        pushNewRecursionContext(_localctx, startState,
                                                RuleLvalue);
                        setState(292);

                        if (!(precpred(_ctx, 1)))
                            throw FailedPredicateException(this,
                                                           "precpred(_ctx, 1)");
                        setState(293);
                        match(zapParser::T__4);
                        setState(294);
                        expression();
                        setState(295);
                        match(zapParser::T__5);
                        break;
                    }

                    default:
                        break;
                }
            }
            setState(301);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
                _input, 24, _ctx);
        }
    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }
    return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

zapParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::LvalueContext *zapParser::AssignmentContext::lvalue() {
    return getRuleContext<zapParser::LvalueContext>(0);
}

zapParser::ExpressionContext *zapParser::AssignmentContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

zapParser::LogicOrContext *zapParser::AssignmentContext::logicOr() {
    return getRuleContext<zapParser::LogicOrContext>(0);
}

size_t zapParser::AssignmentContext::getRuleIndex() const {
    return zapParser::RuleAssignment;
}

std::any zapParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAssignment(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AssignmentContext *zapParser::assignment() {
    AssignmentContext *_localctx =
        _tracker.createInstance<AssignmentContext>(_ctx, getState());
    enterRule(_localctx, 56, zapParser::RuleAssignment);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(307);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 25, _ctx)) {
            case 1: {
                enterOuterAlt(_localctx, 1);
                setState(302);
                lvalue(0);
                setState(303);
                match(zapParser::T__10);
                setState(304);
                expression();
                break;
            }

            case 2: {
                enterOuterAlt(_localctx, 2);
                setState(306);
                logicOr();
                break;
            }

            default:
                break;
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LogicOrContext ------------------------------------------------------------------

zapParser::LogicOrContext::LogicOrContext(ParserRuleContext *parent,
                                          size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::LogicAndContext *>
zapParser::LogicOrContext::logicAnd() {
    return getRuleContexts<zapParser::LogicAndContext>();
}

zapParser::LogicAndContext *zapParser::LogicOrContext::logicAnd(size_t i) {
    return getRuleContext<zapParser::LogicAndContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::LogicOrContext::OR() {
    return getTokens(zapParser::OR);
}

tree::TerminalNode *zapParser::LogicOrContext::OR(size_t i) {
    return getToken(zapParser::OR, i);
}

size_t zapParser::LogicOrContext::getRuleIndex() const {
    return zapParser::RuleLogicOr;
}

std::any zapParser::LogicOrContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitLogicOr(this);
    else
        return visitor->visitChildren(this);
}

zapParser::LogicOrContext *zapParser::logicOr() {
    LogicOrContext *_localctx =
        _tracker.createInstance<LogicOrContext>(_ctx, getState());
    enterRule(_localctx, 58, zapParser::RuleLogicOr);
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
        setState(309);
        logicAnd();
        setState(314);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::OR) {
            setState(310);
            match(zapParser::OR);
            setState(311);
            logicAnd();
            setState(316);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LogicAndContext ------------------------------------------------------------------

zapParser::LogicAndContext::LogicAndContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::EqualityContext *>
zapParser::LogicAndContext::equality() {
    return getRuleContexts<zapParser::EqualityContext>();
}

zapParser::EqualityContext *zapParser::LogicAndContext::equality(size_t i) {
    return getRuleContext<zapParser::EqualityContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::LogicAndContext::AND() {
    return getTokens(zapParser::AND);
}

tree::TerminalNode *zapParser::LogicAndContext::AND(size_t i) {
    return getToken(zapParser::AND, i);
}

size_t zapParser::LogicAndContext::getRuleIndex() const {
    return zapParser::RuleLogicAnd;
}

std::any zapParser::LogicAndContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitLogicAnd(this);
    else
        return visitor->visitChildren(this);
}

zapParser::LogicAndContext *zapParser::logicAnd() {
    LogicAndContext *_localctx =
        _tracker.createInstance<LogicAndContext>(_ctx, getState());
    enterRule(_localctx, 60, zapParser::RuleLogicAnd);
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
        setState(317);
        equality();
        setState(322);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::AND) {
            setState(318);
            match(zapParser::AND);
            setState(319);
            equality();
            setState(324);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- EqualityContext ------------------------------------------------------------------

zapParser::EqualityContext::EqualityContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::ComparisonContext *>
zapParser::EqualityContext::comparison() {
    return getRuleContexts<zapParser::ComparisonContext>();
}

zapParser::ComparisonContext *zapParser::EqualityContext::comparison(size_t i) {
    return getRuleContext<zapParser::ComparisonContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::EqualityContext::EQ() {
    return getTokens(zapParser::EQ);
}

tree::TerminalNode *zapParser::EqualityContext::EQ(size_t i) {
    return getToken(zapParser::EQ, i);
}

std::vector<tree::TerminalNode *> zapParser::EqualityContext::NEQ() {
    return getTokens(zapParser::NEQ);
}

tree::TerminalNode *zapParser::EqualityContext::NEQ(size_t i) {
    return getToken(zapParser::NEQ, i);
}

size_t zapParser::EqualityContext::getRuleIndex() const {
    return zapParser::RuleEquality;
}

std::any zapParser::EqualityContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitEquality(this);
    else
        return visitor->visitChildren(this);
}

zapParser::EqualityContext *zapParser::equality() {
    EqualityContext *_localctx =
        _tracker.createInstance<EqualityContext>(_ctx, getState());
    enterRule(_localctx, 62, zapParser::RuleEquality);
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
        setState(325);
        comparison();
        setState(330);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::EQ

               || _la == zapParser::NEQ) {
            setState(326);
            antlrcpp::downCast<EqualityContext *>(_localctx)->_tset821 =
                _input->LT(1);
            _la = _input->LA(1);
            if (!(_la == zapParser::EQ

                  || _la == zapParser::NEQ)) {
                antlrcpp::downCast<EqualityContext *>(_localctx)->_tset821 =
                    _errHandler->recoverInline(this);
            } else {
                _errHandler->reportMatch(this);
                consume();
            }
            antlrcpp::downCast<EqualityContext *>(_localctx)->op.push_back(
                antlrcpp::downCast<EqualityContext *>(_localctx)->_tset821);
            setState(327);
            comparison();
            setState(332);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ComparisonContext ------------------------------------------------------------------

zapParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::TermContext *> zapParser::ComparisonContext::term() {
    return getRuleContexts<zapParser::TermContext>();
}

zapParser::TermContext *zapParser::ComparisonContext::term(size_t i) {
    return getRuleContext<zapParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::LT() {
    return getTokens(zapParser::LT);
}

tree::TerminalNode *zapParser::ComparisonContext::LT(size_t i) {
    return getToken(zapParser::LT, i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::LTE() {
    return getTokens(zapParser::LTE);
}

tree::TerminalNode *zapParser::ComparisonContext::LTE(size_t i) {
    return getToken(zapParser::LTE, i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::GT() {
    return getTokens(zapParser::GT);
}

tree::TerminalNode *zapParser::ComparisonContext::GT(size_t i) {
    return getToken(zapParser::GT, i);
}

std::vector<tree::TerminalNode *> zapParser::ComparisonContext::GTE() {
    return getTokens(zapParser::GTE);
}

tree::TerminalNode *zapParser::ComparisonContext::GTE(size_t i) {
    return getToken(zapParser::GTE, i);
}

size_t zapParser::ComparisonContext::getRuleIndex() const {
    return zapParser::RuleComparison;
}

std::any zapParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitComparison(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ComparisonContext *zapParser::comparison() {
    ComparisonContext *_localctx =
        _tracker.createInstance<ComparisonContext>(_ctx, getState());
    enterRule(_localctx, 64, zapParser::RuleComparison);
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
        setState(333);
        term();
        setState(338);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~0x3fULL) == 0) &&
                ((1ULL << _la) & 32985348833280) != 0)) {
            setState(334);
            antlrcpp::downCast<ComparisonContext *>(_localctx)->_tset846 =
                _input->LT(1);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) &&
                   ((1ULL << _la) & 32985348833280) != 0))) {
                antlrcpp::downCast<ComparisonContext *>(_localctx)->_tset846 =
                    _errHandler->recoverInline(this);
            } else {
                _errHandler->reportMatch(this);
                consume();
            }
            antlrcpp::downCast<ComparisonContext *>(_localctx)->op.push_back(
                antlrcpp::downCast<ComparisonContext *>(_localctx)->_tset846);
            setState(335);
            term();
            setState(340);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

zapParser::TermContext::TermContext(ParserRuleContext *parent,
                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::FactorContext *> zapParser::TermContext::factor() {
    return getRuleContexts<zapParser::FactorContext>();
}

zapParser::FactorContext *zapParser::TermContext::factor(size_t i) {
    return getRuleContext<zapParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::TermContext::ADD() {
    return getTokens(zapParser::ADD);
}

tree::TerminalNode *zapParser::TermContext::ADD(size_t i) {
    return getToken(zapParser::ADD, i);
}

std::vector<tree::TerminalNode *> zapParser::TermContext::SUB() {
    return getTokens(zapParser::SUB);
}

tree::TerminalNode *zapParser::TermContext::SUB(size_t i) {
    return getToken(zapParser::SUB, i);
}

size_t zapParser::TermContext::getRuleIndex() const {
    return zapParser::RuleTerm;
}

std::any zapParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitTerm(this);
    else
        return visitor->visitChildren(this);
}

zapParser::TermContext *zapParser::term() {
    TermContext *_localctx =
        _tracker.createInstance<TermContext>(_ctx, getState());
    enterRule(_localctx, 66, zapParser::RuleTerm);
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
        setState(341);
        factor();
        setState(346);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::ADD

               || _la == zapParser::SUB) {
            setState(342);
            antlrcpp::downCast<TermContext *>(_localctx)->_tset879 =
                _input->LT(1);
            _la = _input->LA(1);
            if (!(_la == zapParser::ADD

                  || _la == zapParser::SUB)) {
                antlrcpp::downCast<TermContext *>(_localctx)->_tset879 =
                    _errHandler->recoverInline(this);
            } else {
                _errHandler->reportMatch(this);
                consume();
            }
            antlrcpp::downCast<TermContext *>(_localctx)->op.push_back(
                antlrcpp::downCast<TermContext *>(_localctx)->_tset879);
            setState(343);
            factor();
            setState(348);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

zapParser::FactorContext::FactorContext(ParserRuleContext *parent,
                                        size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::UnaryContext *> zapParser::FactorContext::unary() {
    return getRuleContexts<zapParser::UnaryContext>();
}

zapParser::UnaryContext *zapParser::FactorContext::unary(size_t i) {
    return getRuleContext<zapParser::UnaryContext>(i);
}

std::vector<tree::TerminalNode *> zapParser::FactorContext::MUL() {
    return getTokens(zapParser::MUL);
}

tree::TerminalNode *zapParser::FactorContext::MUL(size_t i) {
    return getToken(zapParser::MUL, i);
}

std::vector<tree::TerminalNode *> zapParser::FactorContext::DIV() {
    return getTokens(zapParser::DIV);
}

tree::TerminalNode *zapParser::FactorContext::DIV(size_t i) {
    return getToken(zapParser::DIV, i);
}

std::vector<tree::TerminalNode *> zapParser::FactorContext::MOD() {
    return getTokens(zapParser::MOD);
}

tree::TerminalNode *zapParser::FactorContext::MOD(size_t i) {
    return getToken(zapParser::MOD, i);
}

size_t zapParser::FactorContext::getRuleIndex() const {
    return zapParser::RuleFactor;
}

std::any zapParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitFactor(this);
    else
        return visitor->visitChildren(this);
}

zapParser::FactorContext *zapParser::factor() {
    FactorContext *_localctx =
        _tracker.createInstance<FactorContext>(_ctx, getState());
    enterRule(_localctx, 68, zapParser::RuleFactor);
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
        setState(349);
        unary();
        setState(354);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (
            (((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 1924145348608) != 0)) {
            setState(350);
            antlrcpp::downCast<FactorContext *>(_localctx)->_tset904 =
                _input->LT(1);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) &&
                   ((1ULL << _la) & 1924145348608) != 0))) {
                antlrcpp::downCast<FactorContext *>(_localctx)->_tset904 =
                    _errHandler->recoverInline(this);
            } else {
                _errHandler->reportMatch(this);
                consume();
            }
            antlrcpp::downCast<FactorContext *>(_localctx)->op.push_back(
                antlrcpp::downCast<FactorContext *>(_localctx)->_tset904);
            setState(351);
            unary();
            setState(356);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

zapParser::UnaryContext::UnaryContext(ParserRuleContext *parent,
                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::UnaryContext *zapParser::UnaryContext::unary() {
    return getRuleContext<zapParser::UnaryContext>(0);
}

tree::TerminalNode *zapParser::UnaryContext::NOT() {
    return getToken(zapParser::NOT, 0);
}

tree::TerminalNode *zapParser::UnaryContext::SUB() {
    return getToken(zapParser::SUB, 0);
}

zapParser::CallContext *zapParser::UnaryContext::call() {
    return getRuleContext<zapParser::CallContext>(0);
}

size_t zapParser::UnaryContext::getRuleIndex() const {
    return zapParser::RuleUnary;
}

std::any zapParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitUnary(this);
    else
        return visitor->visitChildren(this);
}

zapParser::UnaryContext *zapParser::unary() {
    UnaryContext *_localctx =
        _tracker.createInstance<UnaryContext>(_ctx, getState());
    enterRule(_localctx, 70, zapParser::RuleUnary);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(360);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
            case zapParser::SUB:
            case zapParser::NOT: {
                enterOuterAlt(_localctx, 1);
                setState(357);
                antlrcpp::downCast<UnaryContext *>(_localctx)->op =
                    _input->LT(1);
                _la = _input->LA(1);
                if (!(_la == zapParser::SUB

                      || _la == zapParser::NOT)) {
                    antlrcpp::downCast<UnaryContext *>(_localctx)->op =
                        _errHandler->recoverInline(this);
                } else {
                    _errHandler->reportMatch(this);
                    consume();
                }
                setState(358);
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
                setState(359);
                call();
                break;
            }

            default:
                throw NoViableAltException(this);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

zapParser::CallContext::CallContext(ParserRuleContext *parent,
                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

zapParser::PrimaryContext *zapParser::CallContext::primary() {
    return getRuleContext<zapParser::PrimaryContext>(0);
}

std::vector<tree::TerminalNode *> zapParser::CallContext::IDENTIFIER() {
    return getTokens(zapParser::IDENTIFIER);
}

tree::TerminalNode *zapParser::CallContext::IDENTIFIER(size_t i) {
    return getToken(zapParser::IDENTIFIER, i);
}

std::vector<zapParser::ArgumentListContext *>
zapParser::CallContext::argumentList() {
    return getRuleContexts<zapParser::ArgumentListContext>();
}

zapParser::ArgumentListContext *zapParser::CallContext::argumentList(size_t i) {
    return getRuleContext<zapParser::ArgumentListContext>(i);
}

size_t zapParser::CallContext::getRuleIndex() const {
    return zapParser::RuleCall;
}

std::any zapParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitCall(this);
    else
        return visitor->visitChildren(this);
}

zapParser::CallContext *zapParser::call() {
    CallContext *_localctx =
        _tracker.createInstance<CallContext>(_ctx, getState());
    enterRule(_localctx, 72, zapParser::RuleCall);
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
        setState(362);
        primary();
        setState(367);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::T__11) {
            setState(363);
            match(zapParser::T__11);
            setState(364);
            match(zapParser::IDENTIFIER);
            setState(369);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(377);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::T__1) {
            setState(370);
            match(zapParser::T__1);
            setState(372);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~0x3fULL) == 0) &&
                 ((1ULL << _la) & 1090852973715460) != 0)) {
                setState(371);
                argumentList();
            }
            setState(374);
            match(zapParser::T__2);
            setState(379);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

zapParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent,
                                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<zapParser::ExpressionContext *>
zapParser::ArgumentListContext::expression() {
    return getRuleContexts<zapParser::ExpressionContext>();
}

zapParser::ExpressionContext *zapParser::ArgumentListContext::expression(
    size_t i) {
    return getRuleContext<zapParser::ExpressionContext>(i);
}

size_t zapParser::ArgumentListContext::getRuleIndex() const {
    return zapParser::RuleArgumentList;
}

std::any zapParser::ArgumentListContext::accept(
    tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitArgumentList(this);
    else
        return visitor->visitChildren(this);
}

zapParser::ArgumentListContext *zapParser::argumentList() {
    ArgumentListContext *_localctx =
        _tracker.createInstance<ArgumentListContext>(_ctx, getState());
    enterRule(_localctx, 74, zapParser::RuleArgumentList);
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
        setState(380);
        expression();
        setState(385);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == zapParser::T__6) {
            setState(381);
            match(zapParser::T__6);
            setState(382);
            expression();
            setState(387);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

zapParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent,
                                          size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::PrimaryContext::INT() {
    return getToken(zapParser::INT, 0);
}

tree::TerminalNode *zapParser::PrimaryContext::FLOAT() {
    return getToken(zapParser::FLOAT, 0);
}

tree::TerminalNode *zapParser::PrimaryContext::BOOL() {
    return getToken(zapParser::BOOL, 0);
}

tree::TerminalNode *zapParser::PrimaryContext::STRING() {
    return getToken(zapParser::STRING, 0);
}

tree::TerminalNode *zapParser::PrimaryContext::IDENTIFIER() {
    return getToken(zapParser::IDENTIFIER, 0);
}

zapParser::LvalueContext *zapParser::PrimaryContext::lvalue() {
    return getRuleContext<zapParser::LvalueContext>(0);
}

zapParser::ExpressionContext *zapParser::PrimaryContext::expression() {
    return getRuleContext<zapParser::ExpressionContext>(0);
}

size_t zapParser::PrimaryContext::getRuleIndex() const {
    return zapParser::RulePrimary;
}

std::any zapParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitPrimary(this);
    else
        return visitor->visitChildren(this);
}

zapParser::PrimaryContext *zapParser::primary() {
    PrimaryContext *_localctx =
        _tracker.createInstance<PrimaryContext>(_ctx, getState());
    enterRule(_localctx, 76, zapParser::RulePrimary);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(398);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 37, _ctx)) {
            case 1: {
                enterOuterAlt(_localctx, 1);
                setState(388);
                match(zapParser::INT);
                break;
            }

            case 2: {
                enterOuterAlt(_localctx, 2);
                setState(389);
                match(zapParser::FLOAT);
                break;
            }

            case 3: {
                enterOuterAlt(_localctx, 3);
                setState(390);
                match(zapParser::BOOL);
                break;
            }

            case 4: {
                enterOuterAlt(_localctx, 4);
                setState(391);
                match(zapParser::STRING);
                break;
            }

            case 5: {
                enterOuterAlt(_localctx, 5);
                setState(392);
                match(zapParser::IDENTIFIER);
                break;
            }

            case 6: {
                enterOuterAlt(_localctx, 6);
                setState(393);
                lvalue(0);
                break;
            }

            case 7: {
                enterOuterAlt(_localctx, 7);
                setState(394);
                match(zapParser::T__1);
                setState(395);
                expression();
                setState(396);
                match(zapParser::T__2);
                break;
            }

            default:
                break;
        }

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AotBlockContext ------------------------------------------------------------------

zapParser::AotBlockContext::AotBlockContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *zapParser::AotBlockContext::AOT() {
    return getToken(zapParser::AOT, 0);
}

zapParser::BlockContext *zapParser::AotBlockContext::block() {
    return getRuleContext<zapParser::BlockContext>(0);
}

size_t zapParser::AotBlockContext::getRuleIndex() const {
    return zapParser::RuleAotBlock;
}

std::any zapParser::AotBlockContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<zapVisitor *>(visitor))
        return parserVisitor->visitAotBlock(this);
    else
        return visitor->visitChildren(this);
}

zapParser::AotBlockContext *zapParser::aotBlock() {
    AotBlockContext *_localctx =
        _tracker.createInstance<AotBlockContext>(_ctx, getState());
    enterRule(_localctx, 78, zapParser::RuleAotBlock);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(400);
        match(zapParser::AOT);
        setState(401);
        block();

    } catch (RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

bool zapParser::sempred(RuleContext *context, size_t ruleIndex,
                        size_t predicateIndex) {
    switch (ruleIndex) {
        case 27:
            return lvalueSempred(antlrcpp::downCast<LvalueContext *>(context),
                                 predicateIndex);

        default:
            break;
    }
    return true;
}

bool zapParser::lvalueSempred(LvalueContext *_localctx, size_t predicateIndex) {
    switch (predicateIndex) {
        case 0:
            return precpred(_ctx, 2);
        case 1:
            return precpred(_ctx, 1);

        default:
            break;
    }
    return true;
}

void zapParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
    zapParserInitialize();
#else
    ::antlr4::internal::call_once(zapParserOnceFlag, zapParserInitialize);
#endif
}
