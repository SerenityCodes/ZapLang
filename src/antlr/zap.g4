grammar zap;

// ------------------------
// Lexer Rules
// ------------------------

BOOL: 'true' | 'false';
IF: 'if';
ELSE: 'else';
WHILE: 'while';
FOR: 'for';
RETURN: 'return';
YIELD: 'yield';
DEFER: 'defer';
LET: 'let';
FUNC: 'func'; STRUCT: 'struct';
COMPONENT: 'component';
READONLY: 'readonly';
MODULE: 'module';
SYSTEM: 'system';
AOT: 'aot';
REF: 'ref';
VOID: 'void';
ARROW: '->';
USE: 'use';

INT: [0-9]+;
FLOAT: [0-9]+ '.' [0-9]+;
STRING: '"' (~["\r\n] | '\\' .)* '"';
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;

WS: [ \t\r\n]+ -> skip;
LINE_COMMENT: '//' ~[\r\n]* -> skip;
BLOCK_COMMENT: '/*' .*? '*/' -> skip;

// ------------------------
// Parser Rules
// ------------------------

program: statement* EOF;

statement
    : functionDecl
    | structDecl
    | componentDecl
    | moduleDecl
    | variableDecl ';'
    | expressionStmt
    | block
    | ifStmt
    | whileStmt
    | forStmt
    | returnStmt
    | yieldStmt
    | deferStmt
    ;

functionDecl: attributeBlock? FUNC IDENTIFIER '(' parameterList? ')' returnType block;

attributeBlock: '@' '[' attributeList ']';
attributeList: attribute (',' attribute)*;
attribute: IDENTIFIER ('(' attributeArgs? ')')?;
attributeArgs: attributeArg (',' attributeArg)*;
attributeArg: IDENTIFIER | STRING | INT;

returnType: ARROW type;

parameterList: parameter (',' parameter)*;
parameter: IDENTIFIER ':' type;

type: (IDENTIFIER | VOID) ('<' type '>' )? ('[' ']')?;

structDecl: STRUCT IDENTIFIER '{' structField* '}';
structField: IDENTIFIER ':' type ';';

componentDecl: (READONLY)? COMPONENT IDENTIFIER '{' structField* '}';

moduleDecl: MODULE IDENTIFIER '{' statement* '}';

block: '{' statement* '}';

variableDecl: LET IDENTIFIER ':' type '=' (expression | aotBlock);

ifStmt: IF '(' expression ')' block (ELSE block)?;
whileStmt: WHILE '(' expression ')' block;
forStmt: FOR '(' variableDecl ';' expression ';' expression ')' block;

returnStmt: RETURN expression? ';';
yieldStmt: YIELD expression? ';';
deferStmt: DEFER (block | expressionStmt);

expressionStmt: expression ';';

expression
    : assignment
    ;

assignment
    : logicOr ('=' expression)?
    ;

logicOr
    : logicAnd ( '||' logicAnd )*
    ;

logicAnd
    : equality ( '&&' equality )*
    ;

equality
    : comparison ( ('==' | '!=') comparison )*
    ;

comparison
    : term ( ('<' | '<=' | '>' | '>=') term )*
    ;

term
    : factor ( ('+' | '-') factor )*
    ;

factor
    : unary ( ('*' | '/' | '%') unary )*
    ;

unary
    : ('!' | '-') unary
    | call
    ;

call
    : primary ( '(' argumentList? ')' )*
    ;

argumentList: expression (',' expression)*;

primary
    : INT
    | FLOAT
    | BOOL
    | STRING
    | IDENTIFIER
    | '(' expression ')'
    ;

aotBlock: AOT block;

