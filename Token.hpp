/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:17:42 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:17:44 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#include "defines.h"
#include <iostream>

struct Token
{
	
    Token();
    Token( Token const & t );
    Token &operator=( Token const & t );
    ~Token();

    eTokenType  type;
    int         content;
    std::string value;
};

#endif
