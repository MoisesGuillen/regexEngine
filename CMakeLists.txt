cmake_minimum_required(VERSION 4.2)
project(regexEngine)

set(CMAKE_CXX_STANDARD 26)

add_executable(regexEngine main.cpp
        lexer.hpp
        token.hpp
        tokenType.hpp)
