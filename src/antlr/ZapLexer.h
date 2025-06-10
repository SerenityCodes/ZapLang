
// Generated from zap.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ZapLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, BOOL = 26, 
    IF = 27, ELSE = 28, WHILE = 29, FOR = 30, RETURN = 31, YIELD = 32, DEFER = 33, 
    LET = 34, FUNC = 35, STRUCT = 36, COMPONENT = 37, READONLY = 38, MODULE = 39, 
    SYSTEM = 40, AOT = 41, REF = 42, READONLY_REF = 43, VOID = 44, ARROW = 45, 
    USE = 46, INT = 47, FLOAT = 48, STRING = 49, IDENTIFIER = 50, WS = 51, 
    LINE_COMMENT = 52, BLOCK_COMMENT = 53
  };

  explicit ZapLexer(antlr4::CharStream *input);

  ~ZapLexer() override;


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

