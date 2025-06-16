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
        case ZapStatementKind::If: {
            ZapIfStatement if_statement = std::get<ZapIfStatement>(stmt.value);
            out << "if (";
            print(*if_statement.condition);
            out << ") {\n";
            indent();
            for (const auto& then_stmt : if_statement.then_block) {
                print(then_stmt);
            }
            indent_level--;
            printIndent();
            out << "}";
            if (!if_statement.else_block.empty()) {
                out << " else {\n";
                indent();
                for (const auto& else_stmt : if_statement.else_block) {
                    print(else_stmt);
                }
                indent_level--;
                printIndent();
                out << "}";
            }
            out << "\n";
            break;
        }
        case ZapStatementKind::For: {
            const auto& for_stmt = std::get<ZapForStatement>(stmt.value);
            out << "for (";
            out << "let " << for_stmt.start.name << ": ";
            print(for_stmt.start.type);
            out << " = ";
            print(*for_stmt.start.value);
            out << "; ";
            print(*for_stmt.condition);
            out << "; ";
            print(*for_stmt.step);
            out << ") {\n";
            indent();
            for (const auto& body_stmt : for_stmt.body) {
                print(body_stmt);
            }
            indent_level--;
            printIndent();
            out << "}\n";
            break;
        }
        case ZapStatementKind::While: {
            const auto& while_stmt = std::get<ZapWhileStatement>(stmt.value);
            out << "while (";
            print(*while_stmt.condition);
            out << ") {\n";
            indent();
            for (const auto& body_stmt : while_stmt.body) {
                print(body_stmt);
            }
            indent_level--;
            printIndent();
            out << "}\n";
            break;
        }
        case ZapStatementKind::Defer: {
            const auto& defer_stmt = std::get<ZapDeferStatement>(stmt.value);
            out << "defer ";
            if (defer_stmt.is_body) {
                out << "{\n";
                indent();
                for (const auto& body_stmt : defer_stmt.body) {
                    print(body_stmt);
                }
                indent_level--;
                printIndent();
                out << "}\n";
            } else {
                print(*defer_stmt.expr);
                out << ";\n";
            }
            break;
        }
        case ZapStatementKind::Block: {
            const auto& block_stmt = std::get<ZapBlockStatement>(stmt.value);
            out << "{\n";
            indent();
            for (const auto& body_stmt : block_stmt.statements) {
                print(body_stmt);
            }
            indent_level--;
            printIndent();
            out << "}\n";
            break;
        }
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

void ZapPrettyPrinter::print(const ZapIfStatement& ifstmt) {
    out << "if (";
    print(*ifstmt.condition);
    out << ") {\n";
    indent();
    for (const auto& stmt : ifstmt.then_block) {
        print(stmt);
    }
    indent_level--;
    printIndent();
    out << "}";
    if (!ifstmt.else_block.empty()) {
        out << " else {\n";
        indent();
        for (const auto& stmt : ifstmt.else_block) {
            print(stmt);
        }
        indent_level--;
        printIndent();
        out << "}";
    }
    out << "\n";
}

void ZapPrettyPrinter::print(const ZapForStatement& forstmt) {
    out << "for (";
    out << "let " << forstmt.start.name << ": ";
    print(forstmt.start.type);
    out << " = ";
    print(*forstmt.start.value);
    out << "; ";
    print(*forstmt.condition);
    out << "; ";
    print(*forstmt.step);
    out << ") {\n";
    indent();
    for (const auto& stmt : forstmt.body) {
        print(stmt);
    }
    indent_level--;
    printIndent();
    out << "}\n";
}

void ZapPrettyPrinter::print(const ZapWhileStatement& whilestmt) {
    out << "while (";
    print(*whilestmt.condition);
    out << ") {\n";
    indent();
    for (const auto& stmt : whilestmt.body) {
        print(stmt);
    }
    indent_level--;
    printIndent();
    out << "}\n";
}

void ZapPrettyPrinter::print(const ZapReturnStatement& retstmt) {
    out << "return";
    if (retstmt.value) {
        out << " ";
        print(*retstmt.value);
    }
    out << ";\n";
}

void ZapPrettyPrinter::print(const ZapDeferStatement& deferstmt) {
    out << "defer ";
    if (deferstmt.is_body) {
        out << "{\n";
        indent();
        for (const auto& stmt : deferstmt.body) {
            print(stmt);
        }
        indent_level--;
        printIndent();
        out << "}\n";
    } else {
        print(*deferstmt.expr);
        out << ";\n";
    }
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
            for (size_t i = 0; i < call.args.size(); ++i) {
                if (call.args[i] != nullptr) {
                    print(*call.args[i]);
                    if (i + 1 < call.args.size()) {
                        out << ", ";
                    }
                }
            }
            out << ")";
            break;
        }
        case ZapExpressionKind::AOTBlock: {
            const auto& aot = std::get<ZapAOTBlock>(expr.value);
            out << "@AOT {\n";
            indent();
            for (const auto& stmt : aot.statements) {
                print(stmt);
            }
            indent_level--;
            printIndent();
            out << "}";
            break;
        }
        case ZapExpressionKind::StructInit: {
            const auto& init = std::get<ZapStructInitExpression>(expr.value);
            out << init.type_name << " { ";
            for (size_t i = 0; i < init.fields.size(); ++i) {
                const auto& field = init.fields[i];
                out << field.field << ": ";
                print(*field.value);
                if (i + 1 < init.fields.size()) {
                    out << ", ";
                }
            }
            out << " }";
            break;
        }
        case ZapExpressionKind::StructAccess: {
            const auto& access =
                std::get<ZapStructAccessExpression>(expr.value);
            out << access.type << "." << access.field;
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
