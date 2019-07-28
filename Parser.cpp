#include "Parser.hpp"


/*
 *  check if there is one instruction per line (via states)
 * */
void    Parser::getParsedInput()
{
    Token *tok;

    while (true)
    {

        std::string line;
        std::getline(std::cin, line);
        if (!line.size())
        {
            exit(0);
        }

        std::istringstream ist(line);
        std::string word;

        while ( ist >> word )
        {
            tok = getToken(word);

            if (!tok || tok->type == EXIT || tok->type == ERROR)
                exit(0);

        }

    }
}