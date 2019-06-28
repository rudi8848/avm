#ifndef INT16_H
# define INT16_H

#include "IOperand.hpp"

class Int16 : public IOperand
{
public:
	Int16( std::string const & value );
	Int16( Int16 const & int16 );
	Int16 & operator= ( Int16 const & int16 );
	~Int16();
	
	int 			getPrecision( void ) const ;
	IOperand::eOperandType	getType ( void ) const ;

	IOperand const * operator+( IOperand const & rhs ) ;
	IOperand const * operator-( IOperand const & rhs ) ;
	IOperand const * operator*( IOperand const & rhs ) ;
	IOperand const * operator/( IOperand const & rhs ) ;
	IOperand const * operator%( IOperand const & rhs ) ;

private:
	int 	_precision;
	int16_t	_val;
};

#endif