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
#include "AVM.hpp"


int     main(void)
{
    Parser parser;
    AVM avm;

    try
    {
        std::list<Token*> input = parser.getParsedInput();
        while (input.empty()) {

            std::cerr << "Repeat input" << std::endl;
            input = parser.getParsedInput();
        
        }
        avm.execute(input);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    system("leaks avm");
    return 0;
}
