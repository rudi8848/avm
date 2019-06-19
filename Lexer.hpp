#ifndef LEXER_HPP
# define LEXER_HPP


#include <string>

typedef enum
{
	PUSH,
	POP,
	DUMP,
	ASSERT,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	WORDS
} e_keywords;

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
}

typedef enum 
{
	NEUTRAL,
	INWORD,
	INBRACKETS,
	COMMENT,	// 	';'
	END 		//	';;'
} e_states;

#endif