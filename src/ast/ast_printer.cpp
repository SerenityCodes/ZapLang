#include "ast_printer.h"

namespace ast {

void ASTPrinter::indent(std::ostream& out, int level) {
    for (int i = 0; i < level; ++i)
        out << "  ";
}

void ASTPrinter::print(const ZapProgram& program, std::ostream& out) {
    for (const auto& decl : program.declarations)
        print_decl(decl, out, 0);
}

void ASTPrinter::print_type(const ZapType& type, std::ostream& out, int level) {
    switch (type.kind) {
        case ZapTypeKind::CUSTOM:
            out << *type.custom_name;
            break;
        case ZapTypeKind::ARRAY:
            out << "Array<";
            print_type(*type.inner, out, level);
            out << ">";
            break;
        case ZapTypeKind::REF:
            out << "Ref<";
            print_type(*type.inner, out, level);
            out << ">";
            break;
        default:
            out << static_cast<int>(type.kind);  // Simplified
    }
}

void ASTPrinter::print_expr(const ZapExpression& expr, std::ostream& out, int level) {
    indent(out, level);
    out << "Expr(" << static_cast<int>(expr.kind) << "): ";

    std::visit([&](auto&& val) {
        using T = std::decay_t<decltype(val)>;
        if constexpr (std::is_same_v<T, ZapLiteral>) {
            std::visit([&](auto&& lit_val) {
                out << "Literal: " << lit_val << "\n";
            }, val.value);
        } else if constexpr (std::is_same_v<T, ZapIdentifier>) {
            out << "Identifier: " << val << "\n";
        } else if constexpr (std::is_same_v<T, ZapBinaryExpression>) {
            out << "Binary(\n";
            print_expr(*val.left, out, level + 1);
            indent(out, level + 1);
            out << "Op: " << val.op << "\n";
            print_expr(*val.right, out, level + 1);
            indent(out, level);
            out << ")\n";
        } else if constexpr (std::is_same_v<T, ZapCallExpression>) {
            out << "Call to " << val.function << "(\n";
            for (const auto& arg : val.args)
                print_expr(*arg, out, level + 1);
            indent(out, level);
            out << ")\n";
        } else if constexpr (std::is_same_v<T, ZapAOTBlock>) {
            out << "AOTBlock(\n";
            for (const auto& stmt : val.statements)
                print_stmt(stmt, out, level + 1);
            indent(out, level + 1);
            out << "Yield:\n";
            print_expr(*val.yield_expr, out, level + 2);
            indent(out, level);
            out << ")\n";
        } else if constexpr (std::is_same_v<T, ZapStructInitExpression>) {
            out << "StructInit(" << val.type_name << ") {\n";
            for (const auto& field : val.fields) {
                indent(out, level + 1);
                out << field.field << ": ";
                print_expr(*field.value, out, 0);
            }
            indent(out, level);
            out << "}\n";
        }
    }, expr.value);
}

void ASTPrinter::print_stmt(const ZapStatement& stmt, std::ostream& out, int level) {
    indent(out, level);
    out << "Stmt(" << static_cast<int>(stmt.kind) << "):\n";

    std::visit([&](auto&& val) {
        using T = std::decay_t<decltype(val)>;
        if constexpr (std::is_same_v<T, ZapLetStatement>) {
            indent(out, level + 1);
            out << "Let " << val.name << " : ";
            print_type(val.type, out, level + 1);
            out << " =\n";
            print_expr(*val.value, out, level + 2);
        } else if constexpr (std::is_same_v<T, ZapAssignStatement>) {
            indent(out, level + 1);
            out << "Assign:\n";
            print_expr(*val.target, out, level + 2);
            print_expr(*val.value, out, level + 2);
        } else if constexpr (std::is_same_v<T, std::unique_ptr<ZapExpression>>) {
            print_expr(*val, out, level + 1);
        } else if constexpr (std::is_same_v<T, ZapIfStatement>) {
            indent(out, level + 1);
            out << "If:\n";
            print_expr(*val.condition, out, level + 2);
            indent(out, level + 1);
            out << "Then:\n";
            for (const auto& s : val.then_block)
                print_stmt(s, out, level + 2);
            if (!val.else_block.empty()) {
                indent(out, level + 1);
                out << "Else:\n";
                for (const auto& s : val.else_block)
                    print_stmt(s, out, level + 2);
            }
        } else if constexpr (std::is_same_v<T, ZapForStatement>) {
            indent(out, level + 1);
            out << "For " << val.var << ":\n";
            print_expr(*val.start, out, level + 2);
            print_expr(*val.condition, out, level + 2);
            print_expr(*val.step, out, level + 2);
            for (const auto& s : val.body)
                print_stmt(s, out, level + 2);
        } else if constexpr (std::is_same_v<T, ZapReturnStatement>) {
            indent(out, level + 1);
            out << "Return:\n";
            print_expr(*val.value, out, level + 2);
        } else if constexpr (std::is_same_v<T, ZapDeferStatement>) {
            indent(out, level + 1);
            out << "Defer:\n";
            print_expr(*val.expr, out, level + 2);
        }
    }, stmt.value);
}

void ASTPrinter::print_function(const ZapFunction& func, std::ostream& out, int level) {
    indent(out, level);
    out << "Function " << func.name << "(\n";
    for (const auto& param : func.params) {
        indent(out, level + 1);
        out << param.name << ": ";
        print_type(param.type, out, level + 1);
        out << "\n";
    }
    indent(out, level);
    out << ") -> ";
    print_type(func.return_type, out, level);
    out << "\n";

    for (const auto& stmt : func.body)
        print_stmt(stmt, out, level + 1);
}

void ASTPrinter::print_struct(const ZapStruct& strct, std::ostream& out, int level) {
    indent(out, level);
    out << "Struct " << strct.name << " {\n";
    for (const auto& field : strct.fields) {
        indent(out, level + 1);
        out << field.name << ": ";
        print_type(field.type, out, level + 1);
        out << "\n";
    }
    indent(out, level);
    out << "}\n";
}

void ASTPrinter::print_component(const ZapComponent& comp, std::ostream& out, int level) {
    indent(out, level);
    out << (comp.is_readonly ? "Readonly " : "") << "Component " << comp.name << " {\n";
    for (const auto& field : comp.fields) {
        indent(out, level + 1);
        out << field.name << ": ";
        print_type(field.type, out, level + 1);
        out << "\n";
    }
    indent(out, level);
    out << "}\n";
}

void ASTPrinter::print_decl(const ZapDecl& decl, std::ostream& out, int level) {
    std::visit([&](auto&& val) {
        using T = std::decay_t<decltype(val)>;
        if constexpr (std::is_same_v<T, ZapFunction>) {
            print_function(val, out, level);
        } else if constexpr (std::is_same_v<T, ZapComponent>) {
            print_component(val, out, level);
        } else if constexpr (std::is_same_v<T, ZapStruct>) {
            print_struct(val, out, level);
        }
    }, decl.value);
}

}  // namespace ast

