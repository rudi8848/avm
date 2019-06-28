#ifndef FLOAT_H
# define FLOAT_H

#include "IOperand.hpp"

class Float : public IOperand
{
public:
	Float( std::string const & value );
	Float( Float const & float );
	Float & operator= ( Float const & float );
	~Float();
	
	int 			getPrecision( void ) const ;
	IOperand::eOperandType	getType ( void ) const ;

	IOperand const * operator+( IOperand const & rhs ) ;
	IOperand const * operator-( IOperand const & rhs ) ;
	IOperand const * operator*( IOperand const & rhs ) ;
	IOperand const * operator/( IOperand const & rhs ) ;
	IOperand const * operator%( IOperand const & rhs ) ;

private:
	int 	_precision;
	float	_val;
};

#endif