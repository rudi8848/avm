#ifndef TOKEN_H
# define TOKEN_H

#include "defines.h"
#include <iostream>

struct Token
{
    eTokenType type;           //  keyword, operand, end of expression
    int content;        //  what exactly    (eKeyword, eOperandType)
    std::string value;  //  for operand
};

#endif