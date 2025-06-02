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
            assert!(!func.parameters[0].is_ref, "x should not be ref");
            assert_eq!(func.parameters[1].name, "y");
            assert_eq!(func.parameters[1].param_type.name, "int");
            assert!(!func.parameters[1].is_ref, "y should not be ref");

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

    #[test]
    fn test_example_program() {
        let parser = zap::ProgramParser::new();
        let example_code = include_str!("../examples/game_systems.zap");
        let result = parser.parse(example_code);
        assert!(result.is_ok(), "Example program should parse successfully");

        let program = result.unwrap();
        assert_eq!(
            program.statements.len(),
            8,
            "Example should have 8 top-level statements"
        );

        // Check for specific statements
        let mut found_health_component = false;
        let mut found_name_component = false;
        let mut found_game_settings_struct = false;
        let mut found_update_health_func = false;
        let mut found_init_system_func = false;
        let mut found_get_spawn_points_func = false;
        let mut found_load_assets_func = false;
        let mut found_main_func = false;

        for statement in &program.statements {
            match statement {
                Statement::ComponentDecl(c) => {
                    if c.name == "Health" {
                        found_health_component = true;
                        assert!(!c.readonly, "Health component should not be readonly");
                        assert_eq!(c.fields.len(), 1, "Health should have 1 field");
                        assert_eq!(c.fields[0].name, "value");
                        assert_eq!(c.fields[0].field_type.name, "u8");
                    } else if c.name == "Name" {
                        found_name_component = true;
                        assert!(c.readonly, "Name component should be readonly");
                        assert_eq!(c.fields.len(), 1, "Name should have 1 field");
                        assert_eq!(c.fields[0].name, "ascii_name");
                        assert_eq!(c.fields[0].field_type.name, "u8");
                        assert!(
                            c.fields[0].field_type.is_array,
                            "ascii_name should be an array"
                        );
                    }
                }
                Statement::StructDecl(s) => {
                    if s.name == "GameSettings" {
                        found_game_settings_struct = true;
                        assert_eq!(s.fields.len(), 2, "GameSettings should have 2 fields");
                        assert_eq!(s.fields[0].name, "max_players");
                        assert_eq!(s.fields[0].field_type.name, "u16");
                        assert_eq!(s.fields[1].name, "gravity");
                        assert_eq!(s.fields[1].field_type.name, "f32");
                    }
                }
                Statement::FunctionDecl(f) => match f.name.as_str() {
                    "update_health" => {
                        found_update_health_func = true;
                        assert!(
                            f.attributes.is_some(),
                            "update_health should have attributes"
                        );
                        let attrs = f.attributes.as_ref().unwrap();
                        assert_eq!(attrs.attributes.len(), 1);
                        assert_eq!(attrs.attributes[0], "system(Update)");
                        assert_eq!(
                            f.parameters.len(),
                            2,
                            "update_health should have 2 parameters"
                        );
                        assert_eq!(f.parameters[0].name, "entity");
                        assert_eq!(f.parameters[0].param_type.name, "u32");
                        assert!(!f.parameters[0].is_ref, "entity should not be ref");
                        assert_eq!(f.parameters[1].name, "health");
                        assert_eq!(f.parameters[1].param_type.name, "Health");
                        assert!(f.parameters[1].is_ref, "health should be ref");
                    }
                    "init_system" => {
                        found_init_system_func = true;
                        assert!(f.attributes.is_some(), "init_system should have attributes");
                        let attrs = f.attributes.as_ref().unwrap();
                        assert_eq!(attrs.attributes[0], "system(Init)");
                    }
                    "get_spawn_points" => {
                        found_get_spawn_points_func = true;
                        assert!(
                            f.return_type.is_some(),
                            "get_spawn_points should have return type"
                        );
                        assert_eq!(f.return_type.as_ref().unwrap().name, "u32");
                    }
                    "load_assets" => {
                        found_load_assets_func = true;
                        assert!(
                            f.return_type.is_some(),
                            "load_assets should have return type"
                        );
                        assert_eq!(f.return_type.as_ref().unwrap().name, "void");
                    }
                    "main" => {
                        found_main_func = true;
                        assert!(f.return_type.is_some(), "main should have return type");
                        assert_eq!(f.return_type.as_ref().unwrap().name, "void");
                    }
                    _ => {}
                },
                _ => {}
            }
        }

        assert!(found_health_component, "Should find Health component");
        assert!(found_name_component, "Should find Name component");
        assert!(
            found_game_settings_struct,
            "Should find GameSettings struct"
        );
        assert!(
            found_update_health_func,
            "Should find update_health function"
        );
        assert!(found_init_system_func, "Should find init_system function");
        assert!(
            found_get_spawn_points_func,
            "Should find get_spawn_points function"
        );
        assert!(found_load_assets_func, "Should find load_assets function");
        assert!(found_main_func, "Should find main function");
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
