#ifndef INT32_H
# define INT32_H

#include "IOperand.hpp"

class Int32 : public IOperand
{
public:
	Int32( std::string const & value );
	Int32( Int32 const & int32 );
	Int32 & operator= ( Int32 const & int32 );
	~Int32();
	
	int 			getPrecision( void ) const ;
	IOperand::eOperandType	getType ( void ) const ;

	IOperand const * operator+( IOperand const & rhs ) ;
	IOperand const * operator-( IOperand const & rhs ) ;
	IOperand const * operator*( IOperand const & rhs ) ;
	IOperand const * operator/( IOperand const & rhs ) ;
	IOperand const * operator%( IOperand const & rhs ) ;
};

#endif