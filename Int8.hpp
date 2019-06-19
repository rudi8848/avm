#ifndef INT8_H
# define INT8_H

#include "IOperand.hpp"

class Int8 : public IOperand
{
public:
	Int8( std::string const & value );
	Int8( Int8 const & int8 );
	Int8 & operator= ( Int8 const & int8 );
	~Int8();

	int 			getPrecision( void ) const ;
	IOperand::eOperandType	getType ( void ) const ;

	IOperand const * operator+( IOperand const & rhs ) ;
	IOperand const * operator-( IOperand const & rhs ) ;
	IOperand const * operator*( IOperand const & rhs ) ;
	IOperand const * operator/( IOperand const & rhs ) ;
	IOperand const * operator%( IOperand const & rhs ) ;
	
};

#endif