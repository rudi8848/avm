/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:14:32 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:14:35 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

bool    Lexer::isInstruction(std::string const & word, eKeyword &content)
{
        if (word == "push")
        {
            content = PUSH;
            return true;
        }
        else if (word == "pop")
        {
            content = POP;
            return true;
        }
        else if (word == "dump")
        {
            content = DUMP;
            return true;
        }
        else if (word == "assert")
        {
            content = ASSERT;
            return true;
        }
        else if (word == "add")
        {
            content = ADD;
            return true;
        }
        else if (word == "sub")
        {
            content = SUB;
            return true;
        }
        else if (word == "mul")
        {
            content = MUL;
            return true;
        }
        else if (word == "div")
        {
            content = DIV;
            return true;
        }
        else if (word == "mod")
        {
            content = MOD;
            return true;
        }
        else if (word == "print")
        {
            content = PRINT;
            return true;
        }
        else if (word == "exit")
        {
            content = EXIT;
            return true;
        }
        else if (word == ";;")
        {
            content = CLOSEINPUT;
            return true;
        }
        else if (word == ";")
        {
            content = COMMENT;
            return true;
        }
        return false;
}



bool    Lexer::isOperand(std::string const & word, eOperandType & type, std::string &value)
{
    std::cmatch result;

    std::regex integer ("(int(8|16|32))"
                       "(\\()"
                       "([+-]?[0-9]+)"
                       "(\\))");
    std::regex point("(float|double)"
                     "(\\()"
                     "([+-]?[0-9]*[.,]?[0-9]+)"
                     "(\\))");



    if (std::regex_match(word.c_str(), result, integer))
    {
        unsigned i = result.size() - 2;

        value = result.str(i);

        std::string operand = result.str(i - 2);
        size_t len = operand.length();
        if (operand[len - 1] == '2'){

            type = Int32;
        }
        else if (operand[len - 1] == '6'){

            type = Int16;
        }
        else if (operand[len - 1] == '8'){
            
            type = Int8;
        }

        return  true;
    }
    else if (std::regex_match(word.c_str(), result, point))
    {
        unsigned i = result.size() - 2;

        value = result.str(i);
        std::string operand = result.str(0);


        if (operand.find("double") != std::string::npos) {

            type =  Double;
        }
        else {

            type = Float;
        }

        return true;
    }
    return false;
}



Token *Lexer::getToken( std::string const & word) {

    Token *tok = new Token;

    eKeyword        cont;
    std::string     value;
    eOperandType    type;

    if (isInstruction(word, cont))
    {
        tok->type = INSTRUCTION;
        tok->content = cont;
        return tok;
    }
    else if (isOperand(word, type, value))
    {
        tok->type = OPERAND;
        tok->content = type;
        tok->value = value;
        return tok;
    }
    delete(tok);
    tok = nullptr;
    return tok;
}

