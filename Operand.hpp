#ifndef OPERAND_H
# define OPERAND_H

#include "IOperand.hpp"
#include "Factory.hpp"
#include <iostream>
#include <cmath>

template <typename T>
class Operand : public IOperand
{
public:
	Operand( eOperandType type, std::string const & value );
	// Operand( Operand const & operand );
	// Operand & operator= ( Operand const & operand );
	~Operand();

	IOperand const * operator+( IOperand const & rhs ) const ;
	IOperand const * operator-( IOperand const & rhs ) const ;
	IOperand const * operator*( IOperand const & rhs ) const ;
	IOperand const * operator/( IOperand const & rhs ) const ;
	IOperand const * operator%( IOperand const & rhs ) const ;

	int 			getPrecision( void ) const;
	eOperandType	getType ( void ) const;
	std::string const & toString( void ) const;
private:
	eOperandType _type;
	T 			_val;
	std::string _str;
	unsigned	_precision;
};

#include "Operand.cpp"

#endif