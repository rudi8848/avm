/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:14:08 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:14:10 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_H
# define FACTORY_H

#include "IOperand.hpp"

class Factory;

typedef	IOperand const*( Factory::*createFunc )(eOperandType type, std::string const & ) const;

class Factory
{
public:
	Factory();
	~Factory();
	
	
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
private:

	IOperand const * createInt8( eOperandType type, std::string const & value ) const;
	IOperand const * createInt16( eOperandType type, std::string const & value ) const;
	IOperand const * createInt32( eOperandType type, std::string const & value ) const;
	IOperand const * createFloat( eOperandType type, std::string const & value ) const;
	IOperand const * createDouble( eOperandType type, std::string const & value ) const;
	createFunc funcArr [Types] = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
};

#endif
