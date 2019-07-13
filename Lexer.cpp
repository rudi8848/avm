#include "Lexer.hpp"

e_keyword getToken( ) {
    std::string line;
    std::getline(std::cin, line);

    std::cmatch result;
    std::regex operand("(int)"
                       "([8|16|32])"
                       "(\\()"
                       "[0-9]+"
                       "(\\))");

    if (std::regex_match(line.c_str(), result, operand)) {
        for (auto i : result)
            std::cout << i << std::endl;
    }
    else
        std::cout << "no matches" << std::endl;
    return PRINT;
}

