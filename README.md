# regexEngine (V1) ⚙️ 🔤

a regex engine built from scratch in C++, following the lexer → parser → matcher pipeline used in compilers & interpreters.

**Status: WIP** — Lexer is DONE. Parser and matcher are next.

## Why?

Built 2 understand how regex works under the hood instead of treating `std::regex` as a black box, and to get hands-on with recursive descent parsing, AST construction, and the visitor pattern.

## ArchiTecture

```
Raw regex string → Lexer → Tokens → Parser → AST → Matcher → Match result
```

### 1. Lexer (`lexer.hpp`) — ✅ Done
Converts a raw regex string into a `std::vector<Token>`.

Supported tokens:
| Symbol | Token |
|---|---|
| `.` | `Dot` |
| `(` `)` | `LParen` / `RParen` |
| `[` `]` | `LBracket` / `RBracket` |
| `+` `*` `?` | `Plus` / `Star` / `Question` |
| `\d` `\s` `\w` | `AnyDigit` / `AnyWhitespace` / `AnyWordChar` |
| any other char | `Literal` |

Ends every token stream with an `End` sentinel token.

### 2. Parser — 🔲 IN PROGRESS ...

### 3. Matcher — 🔲 IN PROGRESS ...

## Example

```cpp
RegexEngine::Lexer lexer{ "(ab)+\\d" };
auto tokens = lexer.tokenize();
```

## Build

```bash
g++ -std=c++17 main.cpp -o regex_engine
./regex_engine
```

## Author

Moises Guillen

## Date: September 26, 2026
