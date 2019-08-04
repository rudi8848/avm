#ifndef LEXER_HPP
# define LEXER_HPP

#include "defines.h"
#include <iostream>
#include <regex>
#include "Token.hpp"

class Lexer
{
    static bool    isInstruction(std::string const & word, eKeyword &content);
    static bool    isOperand(std::string const & word, eOperandType & type, std::string &value);
public:
    static Token* getToken( std::string const & word );
};

#endif