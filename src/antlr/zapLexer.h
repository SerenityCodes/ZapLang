
// Generated from zap.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

class zapLexer : public antlr4::Lexer {
   public:
    enum {
        T__0          = 1,
        T__1          = 2,
        T__2          = 3,
        T__3          = 4,
        T__4          = 5,
        T__5          = 6,
        T__6          = 7,
        T__7          = 8,
        T__8          = 9,
        T__9          = 10,
        T__10         = 11,
        T__11         = 12,
        BOOL          = 13,
        IF            = 14,
        ELSE          = 15,
        WHILE         = 16,
        FOR           = 17,
        RETURN        = 18,
        YIELD         = 19,
        DEFER         = 20,
        LET           = 21,
        FUNC          = 22,
        STRUCT        = 23,
        COMPONENT     = 24,
        READONLY      = 25,
        MODULE        = 26,
        AOT           = 27,
        REF           = 28,
        VOID          = 29,
        ARROW         = 30,
        USE           = 31,
        OR            = 32,
        AND           = 33,
        EQ            = 34,
        NEQ           = 35,
        ADD           = 36,
        SUB           = 37,
        MUL           = 38,
        DIV           = 39,
        MOD           = 40,
        LT            = 41,
        LTE           = 42,
        GT            = 43,
        GTE           = 44,
        NOT           = 45,
        INT           = 46,
        FLOAT         = 47,
        STRING        = 48,
        IDENTIFIER    = 49,
        WS            = 50,
        LINE_COMMENT  = 51,
        BLOCK_COMMENT = 52
    };

    explicit zapLexer(antlr4::CharStream* input);

    ~zapLexer() override;

    std::string getGrammarFileName() const override;

    const std::vector<std::string>& getRuleNames() const override;

    const std::vector<std::string>& getChannelNames() const override;

    const std::vector<std::string>& getModeNames() const override;

    const antlr4::dfa::Vocabulary& getVocabulary() const override;

    antlr4::atn::SerializedATNView getSerializedATN() const override;

    const antlr4::atn::ATN& getATN() const override;

    // By default the static state used to implement the lexer is lazily initialized during the first
    // call to the constructor. You can call this function if you wish to initialize the static state
    // ahead of time.
    static void initialize();

   private:
    // Individual action functions triggered by action() above.

    // Individual semantic predicate functions triggered by sempred() above.
};
