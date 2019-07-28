#ifndef LEXER_HPP
# define LEXER_HPP

#include "defines.h"
#include <iostream>
#include <regex>
#include "Token.hpp"






/*

std::string keywords [WORDS] = {
	"push",
	"pop",
	"dump",
	"assert",
	"add",
	"sub",
	"mul",
	"div",
	"mod",
	"print",
	"exit"
};
*/


Token   *getToken( std::string const & word );

#endif