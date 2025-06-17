#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "ast/ast.h"

namespace typechecker {

/**
 * Type checker for ZapLang AST.
 * Validates type compatibility and correctness throughout the program.
 */
class TypeChecker {
   public:
    /**
     * Check types in the given program.
     * @param program The AST program to type check
     * @return true if type checking succeeds, false if errors are found
     */
    bool check(const ast::ZapProgram& program);

   private:
    // Symbol table for the current scope
    std::unordered_map<std::string, ast::ZapType> current_scope_;

    // Global symbol tables from the program
    const ast::ZapSymbolTable* global_symbols_;

    // Current function context for return type checking
    const ast::ZapFunction* current_function_;

    // Type checking methods for different AST nodes
    bool check_declaration(const ast::ZapDecl& decl);
    bool check_function(const ast::ZapFunction& func);
    bool check_struct(const ast::ZapStruct& struct_decl);
    bool check_component(const ast::ZapComponent& component);

    bool check_statement(const ast::ZapStatement& stmt);
    bool check_let_statement(const ast::ZapLetStatement& stmt);
    bool check_assign_statement(const ast::ZapAssignStatement& stmt);
    bool check_if_statement(const ast::ZapIfStatement& stmt);
    bool check_while_statement(const ast::ZapWhileStatement& stmt);
    bool check_for_statement(const ast::ZapForStatement& stmt);
    bool check_return_statement(const ast::ZapReturnStatement& stmt);
    bool check_block_statement(const ast::ZapBlockStatement& stmt);

    // Expression type checking and inference
    ast::ZapType infer_expression_type(const ast::ZapExpression& expr);
    ast::ZapType infer_binary_expression_type(
        const ast::ZapBinaryExpression& expr);
    ast::ZapType infer_unary_expression_type(
        const ast::ZapUnaryExpression& expr);
    ast::ZapType infer_call_expression_type(const ast::ZapCallExpression& expr);
    ast::ZapType infer_struct_access_type(
        const ast::ZapStructAccessExpression& expr);
    ast::ZapType infer_struct_init_type(
        const ast::ZapStructInitExpression& expr);
    ast::ZapType infer_literal_type(const ast::ZapLiteral& literal);

    // Type compatibility checking
    bool types_compatible(const ast::ZapType& expected,
                          const ast::ZapType& actual);
    bool is_numeric_type(const ast::ZapType& type);
    bool is_integer_type(const ast::ZapType& type);
    bool is_floating_type(const ast::ZapType& type);

    // Utility methods
    bool resolve_custom_type(const std::string& type_name,
                             ast::ZapType& resolved_type);
    std::string type_to_string(const ast::ZapType& type);

    // Error reporting
    void report_error(const std::string& message);
    void report_type_mismatch(const std::string& context,
                              const ast::ZapType& expected,
                              const ast::ZapType& actual);
};

}  // namespace typechecker