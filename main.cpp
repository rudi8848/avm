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

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		//	read from files argv
		std::cout << argv[1] << std::endl;
	}
	else
	{
		//	read from standart input	";;" means EOF
		Factory f;
		SuperStack<const IOperand*> stack;
		const IOperand *ptr = f.createOperand(eOperandType::Int8, "42");
		stack.push(ptr);
		std::cout << "push " << ptr->toString() << std::endl;
		
		const IOperand *ptr1 = f.createOperand(eOperandType::Double, "32.32");
		stack.push(ptr1);
		std::cout << "push " << ptr1->toString() << std::endl;
		
		const IOperand *ptr2 = f.createOperand(eOperandType::Double, "22,222");
		stack.push(ptr2);
		std::cout << "push " << ptr2->toString() << std::endl;

		const IOperand *ptr3 = *ptr+*ptr1;
		stack.push(ptr3);
		
		//const IOperand *ptr3 = f.createOperand(eOperandType::Double, "42.42.42");
		//stack.push(ptr3);
		std::cout << "Iterator: " << std::endl;
		for (auto i : stack)
		{
			std::cout << i->getPrecision() << " ";
			std::cout <<i->toString() << std::endl;
		}
		std::cout << "top, pop: " << std::endl;
		while (stack.size())
		{
			std::cout << "top: " << stack.top()->toString() << std::endl;
			std::cout << "pop() " << std::endl;
			stack.pop();
		}
	}
	return (0);
}