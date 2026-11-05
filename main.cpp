// REGEX Engine
// Moises Guillen
// 11:55 PM - 11/04/26
#include <iostream>
#include "lexer.hpp"

int main(int argc, char *argv[]) {
    RegexEngine::Lexer lexer { "(ab)+\\d" };
    lexer.tokenize();
    std::cout << "lexer.tokenize() ... SUCCESS!\n";

    return {};
}

