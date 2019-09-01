#ifndef PARSER_H
# define PARSER_H

#include "Token.hpp"
#include "Lexer.hpp"
#include <list>
#include <sstream>
#include <iostream>
#include "defines.h"

class Parser {

public:
    Parser();
    Parser( Parser const & p );
    Parser &operator= (Parser const & p );
    ~Parser();
    std::list<Token*> &    getParsedInput( void );
private:
    std::list<Token*> tokens;

    class SyntaxError : public std::exception
    {
    public:
        SyntaxError();
        ~SyntaxError() throw () {};
        virtual const char *what() const throw();
    };

    class UnknownInstruction : public std::exception
    {
    public:
        UnknownInstruction();
        ~UnknownInstruction() throw () {};
        virtual const char *what() const throw();
    };
};

#endif
