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
AOT: 'aot';
REF: 'ref';
VOID: 'void';
ARROW: '->';
USE: 'use';

OR: '||';
AND: '&&';
EQ: '==';
NEQ: '!=';
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';
LT: '<';
LTE: '<=';
GT: '>';
GTE: '>=';
NOT: '!';

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

program: declaration* EOF;

declaration
    : functionDecl
    | structDecl
    | componentDecl
    | moduleDecl
    ;

statement
    : variableDecl ';'
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
parameter: IDENTIFIER ':' REF? type;

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
    : logicAnd ( OR logicAnd )*
    ;

logicAnd
    : equality ( AND equality )*
    ;

equality
    : comparison ( op+=(EQ | NEQ) comparison )*
    ;

comparison
    : term ( op+=(LT | LTE | GT | GTE) term )*
    ;

term
    : factor ( op+=(ADD | SUB) factor )*
    ;

factor
    : unary ( op+=(MUL | DIV | MOD) unary )*
    ;

unary
    : op=(NOT | SUB) unary
    | call
    ;

call
    : primary ('.' IDENTIFIER)* ( '(' argumentList? ')' )*
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

