# GitHub Copilot Instructions for ZapLang

This is a C++-based programming language parser for ZapLang, a games programming language intended to be a friendlier alternative to Jai. The project uses ANTLR for parser generation and follows C++ best practices. Please follow these guidelines when contributing:

## Code Standards

### Required Before Each Commit
- Run `clang-format -i src/*.cpp src/*.h src/**/*.cpp src/**/*.h` before committing any changes to ensure proper code formatting
- Build and test the project to ensure all functionality works correctly
- This maintains consistent style and prevents regressions

### Development Flow
- Build: `mkdir build && cd build && cmake .. && make`
- Format: `clang-format -i src/*.cpp src/*.h src/**/*.cpp src/**/*.h`
- Format check: `clang-format --dry-run src/*.cpp src/*.h src/**/*.cpp src/**/*.h`
- Full check: Clean build from scratch and format verification

## Repository Structure
- `src/`: Source code directory
  - `main.cpp`: Main entry point for the ZapLang compiler
  - `antlr/`: ANTLR-generated parser and lexer files
  - `ast/`: Abstract syntax tree definitions for ZapLang (if present)
  - `LLVMListener.cpp/.h`: LLVM code generation components
- `vendor/`: Third-party dependencies including ANTLR runtime
- `examples/`: Example ZapLang programs
- `CMakeLists.txt`: CMake build configuration
- `.clang-format`: Code formatting configuration
- `LICENSE`: GPL v3 license file
- `README.md`: Project documentation

## Key Guidelines
1. **Testing Requirements**: Every piece of functionality needs associated tests. Major pieces of functionality should have unit tests. Follow the existing testing patterns in the codebase.
2. **Naming Conventions**: 
   - Variables and functions: `snake_case`
   - Classes and structs: `PascalCase` 
   - Follow existing patterns in the codebase for consistency
3. **Code Formatting**:
   - Use the provided `.clang-format` configuration (based on Google style)
   - Run `clang-format` to ensure consistent formatting
   - Follow C++ standard formatting conventions
4. **Parser Development**: When modifying the ANTLR grammar files, ensure corresponding C++ code is updated and test coverage is added
5. **Test-Driven Development**: Write tests for new functionality following existing patterns. Use descriptive test names and organize tests logically
6. **Error Handling**: Use appropriate C++ error handling mechanisms and provide meaningful error messages
7. **Documentation**: Document public APIs and complex parsing logic when adding new language features

## ZapLang Language Features
When extending the language, maintain consistency with existing features:
- Functions: `func name(params) -> return_type { body }`
- Structs: `struct Name { field: type; }`
- Components: `readonly component Name { fields }`
- Variables: `let name: type = value;`
- Modules: `module Name { statements }`
- Control flow: `if`, `while`, `for`, `return`, `yield`, `defer`