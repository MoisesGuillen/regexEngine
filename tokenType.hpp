#pragma once

namespace RegexEngine {

    enum class TokenType {
        Dot,
        Literal,

        LParen,
        RParen,

        LBracket,
        RBracket,

        Plus,
        Star,
        Question,
        
        AnyDigit,       // \d
        AnyWhitespace,  // \s
        AnyWordChar,    // \w

        End
    };
}
