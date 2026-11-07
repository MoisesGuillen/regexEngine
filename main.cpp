// REGEX Engine
// Moises Guillen
// 3:17 AM - 11/07/26
#include <iostream>
#include "lexer.hpp"

int main(int argc, char *argv[]) {
    RegexEngine::Lexer lexer { "(ab)+\\d" };
    lexer.tokenize();
    std::cout << "lexer.tokenize() ... SUCCESS!\n";

    return {};
}

