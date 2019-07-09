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

typedef enum 
	{
		Int8,
		Int16,
		Int32,
		Float,
		Double,
		Types
	} eOperandType;

class IOperand
{
public:
	
	virtual int 			getPrecision( void ) const = 0;
	virtual eOperandType	getType ( void ) const = 0;

	virtual	IOperand const * operator+( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
	//virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
	
	virtual std::string const & toString( void ) const = 0;
	
	virtual ~IOperand( void ) {}

	
};

#endif