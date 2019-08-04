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
    void    getParsedInput();
private:
    std::list<Token*> tokens;
};

#endif

/*
 *  while ((tok = getToken()) != ERROR || tok != END)
 *  {
 *
 *  }
 *  std::string line;
    std::getline(std::cin, line);

    std::istringstream ist(line);
    std::string word;

    while ( ist >> word )
        getToken(word);
 *
 * */