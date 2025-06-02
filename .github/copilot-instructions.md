# GitHub Copilot Instructions for ZapLang

This is a Rust-based programming language parser for ZapLang, a games programming language intended to be a friendlier alternative to Jai. The project uses LALRPOP for parser generation and follows Rust best practices. Please follow these guidelines when contributing:

## Code Standards

### Required Before Each Commit
- Run `cargo fmt` before committing any changes to ensure proper code formatting
- Run `cargo test` to ensure all tests pass
- This maintains consistent style and prevents regressions

### Development Flow
- Build: `cargo build`
- Test: `cargo test`
- Format: `cargo fmt`
- Format check: `cargo fmt --check`
- Full check: `cargo build && cargo test && cargo fmt --check`

## Repository Structure
- `src/`: Source code directory
  - `lib.rs`: Main library entry point with comprehensive test suite
  - `main.rs`: Binary entry point for the REPL interface
  - `ast.rs`: Abstract syntax tree definitions for ZapLang
  - `zap.lalrpop`: LALRPOP grammar file for ZapLang parser
- `build.rs`: Build script for LALRPOP parser generation
- `Cargo.toml`: Rust package configuration
- `LICENSE`: GPL v3 license file
- `README.md`: Project documentation

## Key Guidelines
1. **Testing Requirements**: Every piece of functionality needs an associated test suite. Not every function necessarily needs a unit test, but major pieces of functionality absolutely need unit tests. The project already has comprehensive test coverage in `src/lib.rs` - follow this pattern.
2. **Naming Conventions**: 
   - Variables and functions: `snake_case`
   - Structs and traits: `CamelCase` 
   - Follow existing patterns in `ast.rs` for consistency
3. **Code Formatting**:
   - Use 4 spaces per indent, no tabs
   - Run `cargo fmt` to ensure consistent formatting
   - Follow Rust standard formatting conventions
4. **Parser Development**: When modifying the LALRPOP grammar in `zap.lalrpop`, ensure corresponding AST types are updated in `ast.rs` and test coverage is added
5. **Test-Driven Development**: Write tests for new functionality following the existing pattern in `src/lib.rs`. Use descriptive test names like `test_function_with_parameters()` and `test_complex_zap_file()`
6. **Error Handling**: Use Rust's `Result` types appropriately and provide meaningful error messages
7. **Documentation**: Document public APIs and complex parsing logic when adding new language features

## ZapLang Language Features
When extending the language, maintain consistency with existing features:
- Functions: `func name(params) -> return_type { body }`
- Structs: `struct Name { field: type; }`
- Components: `readonly component Name { fields }`
- Variables: `let name: type = value;`
- Modules: `module Name { statements }`
- Control flow: `if`, `while`, `for`, `return`, `yield`, `defer`