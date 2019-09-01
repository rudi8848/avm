#ifndef TOKEN_H
# define TOKEN_H

#include "defines.h"
#include <iostream>

struct Token
{
    Token();
    Token( Token const & t );
    Token &operator=( Token const & t );
    ~Token();

    eTokenType  type;
    int         content;
    std::string value;
};

#endif