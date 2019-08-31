//
// Created by Ganna VYNOGRADOVA on 2019-07-28.
//

#ifndef AVM_DEFINES_H
#define AVM_DEFINES_H

typedef enum {
    INSTRUCTION,
    OPERAND,
    ERROR,
    END         //  end of line. we must read until ;; or error
} eTokenType;

typedef enum
{
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    Types
} eOperandType;

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
    CLOSEINPUT,
    COMMENT,
    WORDS
} eKeyword;
/*
typedef enum
{
    NEUTRAL,
    OPERAND_WAITING,
    EOL_WAITING,
    //COMMENT,	// 	';'
    END 		//	';;'
} eStates;
*/
#endif //AVM_DEFINES_H
