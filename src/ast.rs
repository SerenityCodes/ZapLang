#[derive(Debug, Clone)]
pub enum Statement {
    FunctionDecl(FunctionDecl),
    StructDecl(StructDecl),
    ComponentDecl(ComponentDecl),
    ModuleDecl(ModuleDecl),
    VariableDecl(VariableDecl),
    ExpressionStmt(Expression),
    Block(Block),
    IfStmt(IfStmt),
    WhileStmt(WhileStmt),
    ForStmt(ForStmt),
    ReturnStmt(ReturnStmt),
    YieldStmt(YieldStmt),
    DeferStmt(DeferStmt),
}

#[derive(Debug, Clone)]
pub struct Program {
    pub statements: Vec<Statement>,
}

#[derive(Debug, Clone)]
pub struct FunctionDecl {
    pub attributes: Option<AttributeBlock>,
    pub name: String,
    pub parameters: Vec<Parameter>,
    pub return_type: Option<Type>,
    pub body: Block,
}

#[derive(Debug, Clone)]
pub struct AttributeBlock {
    pub attributes: Vec<String>,
}

#[derive(Debug, Clone)]
pub struct Parameter {
    pub name: String,
    pub param_type: Type,
}

#[derive(Debug, Clone)]
pub struct Type {
    pub name: String,
    pub generic: Option<Box<Type>>,
    pub is_array: bool,
}

#[derive(Debug, Clone)]
pub struct StructDecl {
    pub name: String,
    pub fields: Vec<StructField>,
}

#[derive(Debug, Clone)]
pub struct StructField {
    pub name: String,
    pub field_type: Type,
}

#[derive(Debug, Clone)]
pub struct ComponentDecl {
    pub readonly: bool,
    pub name: String,
    pub fields: Vec<StructField>,
}

#[derive(Debug, Clone)]
pub struct ModuleDecl {
    pub name: String,
    pub statements: Vec<Statement>,
}

#[derive(Debug, Clone)]
pub struct Block {
    pub statements: Vec<Statement>,
}

#[derive(Debug, Clone)]
pub struct VariableDecl {
    pub name: String,
    pub var_type: Type,
    pub value: VariableValue,
}

#[derive(Debug, Clone)]
pub enum VariableValue {
    Expression(Expression),
    AotBlock(Block),
}

#[derive(Debug, Clone)]
pub struct IfStmt {
    pub condition: Expression,
    pub then_block: Block,
    pub else_block: Option<Block>,
}

#[derive(Debug, Clone)]
pub struct WhileStmt {
    pub condition: Expression,
    pub body: Block,
}

#[derive(Debug, Clone)]
pub struct ForStmt {
    pub init: VariableDecl,
    pub condition: Expression,
    pub update: Expression,
    pub body: Block,
}

#[derive(Debug, Clone)]
pub struct ReturnStmt {
    pub value: Option<Expression>,
}

#[derive(Debug, Clone)]
pub struct YieldStmt {
    pub value: Option<Expression>,
}

#[derive(Debug, Clone)]
pub enum DeferStmt {
    Block(Block),
    Expression(Expression),
}

#[derive(Debug, Clone)]
pub enum Expression {
    Assignment(Box<Expression>, Box<Expression>),
    LogicOr(Box<Expression>, Box<Expression>),
    LogicAnd(Box<Expression>, Box<Expression>),
    Equality(Box<Expression>, EqualityOp, Box<Expression>),
    Comparison(Box<Expression>, ComparisonOp, Box<Expression>),
    Term(Box<Expression>, TermOp, Box<Expression>),
    Factor(Box<Expression>, FactorOp, Box<Expression>),
    Unary(UnaryOp, Box<Expression>),
    Call(Box<Expression>, Vec<Expression>),
    Primary(Primary),
}

#[derive(Debug, Clone)]
pub enum EqualityOp {
    Equal,
    NotEqual,
}

#[derive(Debug, Clone)]
pub enum ComparisonOp {
    Less,
    LessEqual,
    Greater,
    GreaterEqual,
}

#[derive(Debug, Clone)]
pub enum TermOp {
    Add,
    Subtract,
}

#[derive(Debug, Clone)]
pub enum FactorOp {
    Multiply,
    Divide,
    Modulo,
}

#[derive(Debug, Clone)]
pub enum UnaryOp {
    Not,
    Negate,
}

#[derive(Debug, Clone)]
pub enum Primary {
    Integer(i64),
    Float(f64),
    Boolean(bool),
    String(String),
    Identifier(String),
    Parenthesized(Box<Expression>),
}
