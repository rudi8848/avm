/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:28:45 by gvynogra          #+#    #+#             */
/*   Updated: 2019/06/19 11:28:50 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_H
# define IOPERAND_H

#include <string>
#include <cstdint>

class IOperand;

typedef	IOperand const*( IOperand::*createFunc )( std::string const & ) const;

class IOperand
{
public:

	typedef enum 
	{
		Int8,
		Int16,
		Int32,
		Float,
		Double,
		Types
	} eOperandType;
	
	virtual int 			getPrecision( void ) const = 0;
	virtual eOperandType	getType ( void ) const = 0;

	virtual	IOperand const * operator+( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
	
	virtual std::string const & toString( void ) const = 0;

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	
	virtual ~IOperand( void ) {}

private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	createFunc funcArr [Types] = {
		&IOperand::createInt8,
		&IOperand::createInt16,
		&IOperand::createInt32,
		&IOperand::createFloat,
		&IOperand::createDouble,
	};
	
};

#endif