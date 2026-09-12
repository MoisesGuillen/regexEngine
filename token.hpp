#pragma once
#include "tokenType.hpp"

namespace RegexEngine {

    struct Token {
        char character{};
        TokenType type{};

    };
}
