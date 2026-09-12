#pragma once

#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include "token.hpp"
#include "tokenType.hpp"

namespace RegexEngine {
    class Lexer {
    public:

    Lexer(std::string_view regex)
        : m_regex(regex) {}

        std::vector<Token> tokenize() {
            while (!is_at_end()) {
                auto c{ advance() };
                switch (c) {
                    case '.' :
                        m_tokens.push_back(Token {c, TokenType::Dot});
                        break;
                    case '(' :
                        m_tokens.push_back(Token {c, TokenType::LParen});
                        break;
                    case ')' :
                        m_tokens.push_back(Token {c, TokenType::RParen});
                        break;
                    case '[' :
                        m_tokens.push_back(Token {c, TokenType::LBracket});
                        break;
                    case ']' :
                        m_tokens.push_back(Token {c, TokenType::RBracket});
                        break;
                    case '+' :
                        m_tokens.push_back(Token {c, TokenType::Plus});
                        break;
                    case '*' :
                        m_tokens.push_back(Token {c, TokenType::Star});
                        break;
                    case '?' :
                        m_tokens.push_back(Token {c, TokenType::Question});
                        break;
                    case '\\' : {
                        if (is_at_end())
                            throw std::runtime_error("Expected character after \\.");
                        auto escaped{ advance() };
                        switch (escaped) {
                            case 'd':
                                m_tokens.push_back(Token{escaped,TokenType::AnyDigit});
                                break;
                            case 's':
                                m_tokens.push_back(Token{escaped,TokenType::AnyWhitespace});
                                break;
                            case 'w':
                                m_tokens.push_back(Token{escaped,TokenType::AnyWordChar});
                                break;
                            default:
                                m_tokens.push_back(Token { escaped, TokenType::Literal});
                                break;
                        }

                        break;
                    }
                    default:
                        m_tokens.push_back(Token {c, TokenType::Literal});
                        break;
                }
            }

        m_tokens.push_back(Token { 0 , TokenType::End});

        return m_tokens;
    }

    private:
        bool is_at_end() const {
            return m_current >= m_regex.size();
        }

        char advance() {
            if (is_at_end()) {return 0;}

            return m_regex[m_current++];
        }

    private:
        std::string m_regex{};
        std::size_t m_current{};
        std::vector<Token> m_tokens{};
    };

}
