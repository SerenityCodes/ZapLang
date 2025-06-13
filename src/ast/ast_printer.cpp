#include "ast_printer.h"
#include "ast.h"

namespace ast {

ZapPrettyPrinter::ZapPrettyPrinter(std::ostream& out) : out(out) {}

void ZapPrettyPrinter::indent() {
    indent_level++;
}
void ZapPrettyPrinter::printIndent() {
    for (int i = 0; i < indent_level; ++i)
        out << "    ";
}

void ZapPrettyPrinter::print(const ZapProgram& program) {
    std::cout << "Declarations size: " << program.declarations.size() << '\n';
    for (const auto& decl : program.declarations) {
        print(decl);
        out << "\n";
    }
}

void ZapPrettyPrinter::print(const ZapDecl& decl) {
    switch (decl.kind) {
        case ZapDeclKind::Function:
            print(std::get<ZapFunction>(decl.value));
            break;
        case ZapDeclKind::Component:
            print(std::get<ZapComponent>(decl.value));
            break;
        case ZapDeclKind::Struct:
            print(std::get<ZapStruct>(decl.value));
            break;
    }
}

void ZapPrettyPrinter::print(const ZapComponent& comp) {
    printIndent();
    if (comp.is_readonly)
        out << "readonly ";
    out << "component " << comp.name << " {\n";
    indent();
    for (const auto& field : comp.fields) {
        printIndent();
        out << field.name << ": ";
        print(field.type);
        out << ";\n";
    }
    indent_level--;
    printIndent();
    out << "}\n";
}

void ZapPrettyPrinter::print(const ZapStruct& strct) {
    printIndent();
    out << "struct " << strct.name << " {\n";
    indent();
    for (const auto& field : strct.fields) {
        printIndent();
        out << field.name << ": ";
        print(field.type);
        out << ";\n";
    }
    indent_level--;
    printIndent();
    out << "}\n";
}

void ZapPrettyPrinter::print(const ZapFunction& func) {
    for (const auto& attr : func.attributes) {
        printIndent();
        out << "@" << attr.name;
        if (!attr.args.empty()) {
            out << "(";
            for (size_t i = 0; i < attr.args.size(); ++i) {
                out << attr.args[i];
                if (i + 1 < attr.args.size())
                    out << ", ";
            }
            out << ")";
        }
        out << "\n";
    }

    printIndent();
    out << "func " << func.name << "(";
    for (size_t i = 0; i < func.params.size(); ++i) {
        const auto& p = func.params[i];
        out << p.name << ": ";
        print(p.type);
        if (i + 1 < func.params.size())
            out << ", ";
    }
    out << ") -> ";
    print(func.return_type);
    out << " {\n";
    indent();
    for (const auto& stmt : func.body) {
        print(stmt);
    }
    indent_level--;
    printIndent();
    out << "}\n";
}

void ZapPrettyPrinter::print(const ZapType& type) {
    switch (type.kind) {
        case CUSTOM:
            out << *type.custom_name;
            break;
        case ARRAY:
            print(*type.inner);
            out << "[]";
            break;
        case REF:
            out << "ref ";
            print(*type.inner);
            break;
        default:
            printTypeKind(type.kind);
            break;
    }
}

void ZapPrettyPrinter::printTypeKind(ZapTypeKind kind) {
    switch (kind) {
        case U8:
            out << "u8";
            break;
        case U16:
            out << "u16";
            break;
        case U32:
            out << "u32";
            break;
        case U64:
            out << "u64";
            break;
        case I16:
            out << "i16";
            break;
        case I32:
            out << "i32";
            break;
        case I64:
            out << "i64";
            break;
        case F32:
            out << "f32";
            break;
        case F64:
            out << "f64";
            break;
        case BOOL:
            out << "bool";
            break;
        case STRING:
            out << "str";
            break;
        case VOID:
            out << "void";
            break;
        // add others as needed
        default:
            out << "unknown";
            break;
    }
}

void ZapPrettyPrinter::print(const ZapStatement& stmt) {
    printIndent();
    switch (stmt.kind) {
        case ZapStatementKind::Let:
            print(std::get<ZapLetStatement>(stmt.value));
            break;
        case ZapStatementKind::Assign:
            print(std::get<ZapAssignStatement>(stmt.value));
            break;
        case ZapStatementKind::Expression:
            print(*std::get<std::shared_ptr<ZapExpression>>(stmt.value));
            out << ";\n";
            break;
        case ZapStatementKind::Return:
            out << "return ";
            print(std::get<ZapReturnStatement>(stmt.value).value
                      ? *std::get<ZapReturnStatement>(stmt.value).value
                      : ZapExpression{});
            out << ";\n";
            break;
        case ZapStatementKind::If:
            ZapIfStatement if_statement = std::get<ZapIfStatement>(stmt.value);
            out << "if (";
            print(*if_statement.condition);
            out << ") {\n";
            break;

        default:
            out << "// [unimplemented statement]\n";
    }
}

void ZapPrettyPrinter::print(const ZapLetStatement& let) {
    out << "let " << let.name << ": ";
    print(let.type);
    out << " = ";
    print(*let.value);
    out << ";\n";
}

void ZapPrettyPrinter::print(const ZapAssignStatement& assign) {
    print(*assign.target);
    out << " = ";
    print(*assign.value);
    out << ";\n";
}

void ZapPrettyPrinter::print(const ZapExpression& expr) {
    switch (expr.kind) {
        case ZapExpressionKind::Literal: {
            const auto& val = std::get<ZapLiteral>(expr.value).value;
            std::visit([&](auto&& v) { out << v; }, val);
            break;
        }
        case ZapExpressionKind::Identifier:
            out << std::get<ZapIdentifier>(expr.value);
            break;
        case ZapExpressionKind::Binary: {
            const auto& bin = std::get<ZapBinaryExpression>(expr.value);
            out << "(";
            print(*bin.left);
            out << " ";
            printBinaryOp(bin.op);
            out << " ";
            print(*bin.right);
            out << ")";
            break;
        }
        case ZapExpressionKind::Unary: {
            const auto& un = std::get<ZapUnaryExpression>(expr.value);
            printUnaryOp(un.op);
            print(*un.unary);
            break;
        }
        case ZapExpressionKind::Call: {
            const auto& call = std::get<ZapCallExpression>(expr.value);
            out << call.function << "(";
            if (call.args.size() == 1) {
                std::shared_ptr arg = call.args[0];
                if (arg != nullptr) {
                    print(*arg);
                }
            } else {
                for (size_t i = 0; i < call.args.size(); ++i) {
                    std::shared_ptr arg = call.args[i];
                    if (arg != nullptr) {
                        print(*arg);
                        out << ", ";
                    }
                }
            }
            out << ")";
            break;
        }
        default:
            out << "[unsupported expression]";
            break;
    }
}

void ZapPrettyPrinter::printBinaryOp(BinaryOp op) {
    switch (op) {
        case ASSIGNMENT:
            out << "=";
            break;
        case ADD:
            out << "+";
            break;
        case SUBTRACT:
            out << "-";
            break;
        case MULTIPLY:
            out << "*";
            break;
        case DIVIDE:
            out << "/";
            break;
        case MOD:
            out << "%";
            break;
        case EQUAL:
            out << "==";
            break;
        case NOT_EQUAL:
            out << "!=";
            break;
        case LESS_THAN:
            out << "<";
            break;
        case LESS_THAN_OR_EQUAL:
            out << "<=";
            break;
        case GREATER_THAN:
            out << ">";
            break;
        case GREATER_THAN_OR_EQUAL:
            out << ">=";
            break;
        case AND:
            out << "&&";
            break;
        case OR:
            out << "||";
            break;
        default:
            out << "?";
            break;
    }
}

void ZapPrettyPrinter::printUnaryOp(BinaryOp op) {
    switch (op) {
        case NOT:
            out << "!";
            break;
        case NEGATIVE:
            out << "-";
            break;
        default:
            out << "?";
            break;
    }
}

}  // namespace ast
