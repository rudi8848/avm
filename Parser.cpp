#include "Parser.hpp"

/*
 *  check if there is one instruction per line (via states)
 * */
std::list<Token*> &    Parser::getParsedInput()
{
    Token *tok;

    std::string line;
    try {
        while (std::getline(std::cin, line)) {
            //std::getline(std::cin, line);
            if (!line.size()) {
                continue;
            }
            size_t commentPos = -1;
            if ((commentPos = line.find(';')) != std::string::npos && line.find(";;") == std::string::npos) {
                line = line.substr(0, commentPos);
            }
            std::istringstream ist(line);
            std::string word;

            /*  reading 1 line by single words
             * first MUST be an instruction (or comment, in this case no need to read next words)
             * second OPTIONAL operand or comment
             * */
            if (ist >> word) {
                if ((tok = Lexer::getToken(word)) && tok->type == INSTRUCTION) {
                    this->tokens.push_back(tok);
                    if (tok->content == PUSH || tok->content == ASSERT) {
                        if (ist >> word) {
                            if ((tok = Lexer::getToken(word)) && tok->type == OPERAND) {
                                this->tokens.push_back(tok);
                            } else {
                                std::cerr << "Unexpected argument" << std::endl;
                                throw SyntaxError();
                            }
                        } else {
                            std::cerr << "Argument expected." << std::endl;
                            throw SyntaxError();
                        }
                    } else if (tok->content == CLOSEINPUT)
                        break;
                    if (ist >> word &&
                        (tok = Lexer::getToken(word))) // if there is next word and it is not comment - return error
                    {
                        if (tok->type == INSTRUCTION && tok->content == CLOSEINPUT) {
                            this->tokens.push_back(tok);
                            break;
                        }
                        else {
                            std::cerr << "Too much arguments." << std::endl;
                            throw SyntaxError();
                        }
                    }
                } else {
                    if (word.empty())
                        return this->tokens;
                    throw UnknownInstruction();
                }
            }
        }
        return this->tokens;
    }
    catch (std::exception &e)
    {
        throw;
    }
}


Parser::SyntaxError::SyntaxError() : exception(){}

const char* Parser::SyntaxError::what() const throw() {
    return "The assembly program includes one or several lexical errors or syntactic errors";
}

Parser::UnknownInstruction::UnknownInstruction() : exception(){}

const char* Parser::UnknownInstruction::what() const throw() {
    return "An instruction is unknown";
}