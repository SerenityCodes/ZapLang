#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include "antlr/zapLexer.h"
#include "antlr/zapParser.h"
#include "antlr4-runtime.h"

std::string read_file(const char* file_name) {
    std::ifstream file_stream(file_name, std::ios::in | std::ios::binary);
    const auto file_size = std::filesystem::file_size(file_name);
    std::string result(file_size, '\0');
    file_stream.read(result.data(), file_size);
    return result;
}

int main (int argc, const char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: zapc <file>\n";
        return 1;
    }
    antlr4::ANTLRInputStream input(read_file(argv[1]));

    zapLexer lexer(&input); 

    antlr4::CommonTokenStream tokens(&lexer);

    zapParser parser(&tokens);

    std::cout << parser.program()->toStringTree() << '\n';
    return 0;
}
