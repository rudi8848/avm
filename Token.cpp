/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:16:39 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:16:41 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Token::~Token() {

}
