#include "Token.hpp"

Token::Token() {}

Token::Token( Token const & t ) {
    this->type = t.type;
    this->content = t.content;
    this->value = t.value;
}

Token & Token::operator=( Token const & t ) {
    if (this != &t) {
        this->type = t.type;
        this->content = t.content;
        this->value = t.value;
    }
    return *this;
}

Token::~Token() {}