/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:15:36 by gvynogra          #+#    #+#             */
/*   Updated: 2019/06/19 14:15:38 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperand.hpp"
#include "Factory.hpp"
#include "SuperStack.hpp"
#include <iostream>
#include "Parser.hpp"


int     main(void)
{
    Parser parser;
    parser.getParsedInput();
    return 0;
}
