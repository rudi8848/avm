#include "Lexer.hpp"

bool    isInstruction(std::string const & word, eKeyword &content)
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
        else if (word == ";;" || word == "exit")
        {
            content = EXIT;
            return true;
        }
        else if (word == ";")
        {
            content = COMMENT;
            return true;
        }
        else
            std::cout << "not an instruction" << std::endl;
            return false;

}

bool    isOperand(std::string const & word, eOperandType & type, std::string &value)
{
    std::cmatch result;

    std::regex integer ("(int(8|16|32))"
                       "(\\()"
                       "([+-]?[0-9]+)"  //  [.,] for double
                       "(\\))");
    std::regex point("(float|double)"
                     "(\\()"
                     "([+-]?[0-9]*[.,]?[0-9]+)"
                     "(\\))");



    if (std::regex_match(word.c_str(), result, integer))
    {
        for (auto i : result)
            std::cout << i << std::endl;
        return  true;
    }
    else if (std::regex_match(word.c_str(), result, point))
    {
        for (auto i : result)
            std::cout << i << std::endl;
        return true;
    }
    return false;
}

Token *getToken( std::string const & word) {

    //  relocate to parser

    //

    //  start of lexer
    Token *tok = new Token;


        eKeyword cont;
        std::string value;
        eOperandType type;

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
    std::cout << "NO MATCHES" << std::endl;
    delete(tok);
    tok = nullptr;
    return tok;
}

