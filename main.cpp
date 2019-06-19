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
#include <iostream>

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		//	read from files argv
		std::cout << argv[1] << std::endl;
	}
	else
		//	read from standart input	";;" means EOF
	return (0);
}