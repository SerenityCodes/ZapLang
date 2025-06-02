use lalrpop_util::lalrpop_mod;
use std::fs;

pub mod ast;
lalrpop_mod!(pub zap);
use ast::*;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_simple_function() {
        let parser = zap::ProgramParser::new();
        let result = parser.parse("func main() {}");
        assert!(result.is_ok());

        let program = result.unwrap();
        assert_eq!(program.statements.len(), 1);

        if let Statement::FunctionDecl(func) = &program.statements[0] {
            assert_eq!(func.name, "main");
            assert!(func.parameters.is_empty());
            assert!(func.return_type.is_none());
        } else {
            panic!("Expected function declaration");
        }
    }

    #[test]
    fn test_function_with_parameters() {
        let parser = zap::ProgramParser::new();
        let result = parser.parse("func add(x: int, y: int) -> int {}");
        assert!(result.is_ok());

        let program = result.unwrap();
        if let Statement::FunctionDecl(func) = &program.statements[0] {
            assert_eq!(func.name, "add");
            assert_eq!(func.parameters.len(), 2);
            assert_eq!(func.parameters[0].name, "x");
            assert_eq!(func.parameters[0].param_type.name, "int");
            assert_eq!(func.parameters[1].name, "y");
            assert_eq!(func.parameters[1].param_type.name, "int");

            assert!(func.return_type.is_some());
            assert_eq!(func.return_type.as_ref().unwrap().name, "int");
        } else {
            panic!("Expected function declaration");
        }
    }

    #[test]
    fn test_variable_declaration() {
        let parser = zap::ProgramParser::new();
        let result = parser.parse("let x: int = 42;");
        assert!(result.is_ok());

        let program = result.unwrap();
        if let Statement::VariableDecl(var) = &program.statements[0] {
            assert_eq!(var.name, "x");
            assert_eq!(var.var_type.name, "int");
        } else {
            panic!("Expected variable declaration");
        }
    }

    #[test]
    fn test_struct_declaration() {
        let parser = zap::ProgramParser::new();
        let result = parser.parse("struct Point { x: float; y: float; }");
        assert!(result.is_ok());

        let program = result.unwrap();
        if let Statement::StructDecl(struct_decl) = &program.statements[0] {
            assert_eq!(struct_decl.name, "Point");
            assert_eq!(struct_decl.fields.len(), 2);
            assert_eq!(struct_decl.fields[0].name, "x");
            assert_eq!(struct_decl.fields[0].field_type.name, "float");
            assert_eq!(struct_decl.fields[1].name, "y");
            assert_eq!(struct_decl.fields[1].field_type.name, "float");
        } else {
            panic!("Expected struct declaration");
        }
    }

    #[test]
    fn test_if_statement() {
        let parser = zap::ProgramParser::new();
        let result = parser.parse("if (true) { return 1; }");
        assert!(result.is_ok());

        let program = result.unwrap();
        if let Statement::IfStmt(if_stmt) = &program.statements[0] {
            assert!(if_stmt.else_block.is_none());
        } else {
            panic!("Expected if statement");
        }
    }

    #[test]
    fn test_simple_expression() {
        let parser = zap::ProgramParser::new();
        let result = parser.parse("1 + 2;");
        assert!(result.is_ok());
    }

    #[test]
    fn test_complex_zap_file() {
        let test_code = r#"
// Simple ZapLang test file
func fibonacci(n: int) -> int {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

struct Point {
    x: float;
    y: float;
}

readonly component Transform {
    position: Point;
    rotation: float;
}

let pi: float = 3.14159;

module Math {
    func add(a: int, b: int) -> int {
        return a + b;
    }
}
"#;
        let parser = zap::ProgramParser::new();
        let result = parser.parse(test_code);
        assert!(result.is_ok());

        let program = result.unwrap();
        assert_eq!(program.statements.len(), 5); // func, struct, component, let, module

        // Check that we got all the expected top-level statements
        let mut found_function = false;
        let mut found_struct = false;
        let mut found_component = false;
        let mut found_variable = false;
        let mut found_module = false;

        for statement in &program.statements {
            match statement {
                Statement::FunctionDecl(f) if f.name == "fibonacci" => found_function = true,
                Statement::StructDecl(s) if s.name == "Point" => found_struct = true,
                Statement::ComponentDecl(c) if c.name == "Transform" => found_component = true,
                Statement::VariableDecl(v) if v.name == "pi" => found_variable = true,
                Statement::ModuleDecl(m) if m.name == "Math" => found_module = true,
                _ => {}
            }
        }

        assert!(found_function, "Should find fibonacci function");
        assert!(found_struct, "Should find Point struct");
        assert!(found_component, "Should find Transform component");
        assert!(found_variable, "Should find pi variable");
        assert!(found_module, "Should find Math module");
    }
}

pub fn parse_file(path: &str) -> Result<Program, Box<dyn std::error::Error>> {
    let content = fs::read_to_string(path)?;
    let parser = zap::ProgramParser::new();
    match parser.parse(&content) {
        Ok(program) => Ok(program),
        Err(e) => Err(Box::new(std::io::Error::new(
            std::io::ErrorKind::InvalidData,
            format!("Parse error: {:?}", e),
        ))),
    }
}
