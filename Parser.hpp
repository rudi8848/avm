#ifndef PARSER_H
# define PARSER_H

#include "Token.hpp"
#include <list>

class Parser {


private:
    std::list<Token*>;
};

#endif

/*
 *  while ((tok = getToken()) != ERROR || tok != END)
 *  {
 *
 *  }
 *
 * */