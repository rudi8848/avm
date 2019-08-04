#include "Parser.hpp"

/*
 *  check if there is one instruction per line (via states)
 * */
void    Parser::getParsedInput()
{
    Token *tok;

    std::string line;
    while (true)
    {
        std::getline(std::cin, line);
        if (!line.size())
        {
            continue;
        }
        size_t commentPos = -1;
        if ((commentPos = line.find(';') ) != std::string::npos && line.find(";;") == std::string::npos)
        {
            line = line.substr(0, commentPos);
            std::cout << "COMMENT : " << line << std::endl;
        }
        std::istringstream ist(line);
        std::string word;

            /*  reading 1 line by single words
             * first MUST be an instruction (or comment, in this case no need to read next words)
             * second OPTIONAL operand or comment
             * */
            if (ist >> word)
            {
                if ((tok = Lexer::getToken(word)) && tok->type == INSTRUCTION)
                {
                    this->tokens.push_back(tok);
                    if (tok->content == PUSH || tok->content == ASSERT)
                    {
                        if (ist >> word)
                        {
                            if ((tok = Lexer::getToken(word)) && tok->type == OPERAND)
                            {
                                this->tokens.push_back(tok);
                            }
                            else {
                                std::cout << __PRETTY_FUNCTION__ << " : unexpected argument" << std::endl;
                                exit(0);
                            }
                        }
                        else {
                            std::cout << __PRETTY_FUNCTION__ << " : argument expected" << std::endl;
                            exit(0);
                        }
                    }
                    else if (tok->content == EXIT)
                        break;
                    if (ist >> word && (tok = Lexer::getToken(word)) ) // if there is next word and it is not comment - return error
                    {
                        if (tok->type == INSTRUCTION && tok->content == EXIT)
                            break;
                        else {
                            std::cout << __PRETTY_FUNCTION__ << " : too much arguments" << std::endl;
                            exit(0);
                        }
                    }
                }
                else
                {
                    std::cout << __PRETTY_FUNCTION__ << " : parse error" << std::endl;
                    exit(0);
                }
            }
    }
    std::cout << "END OF LOOP" << std::endl;
    // check all the sequence of tokens in this->tokens
    for (auto i : this->tokens)
        std::cout << i->type << " : " << i->content << " : " << i->value << std::endl;
}