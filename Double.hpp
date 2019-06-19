#ifndef DOUBLE_H
# define DOUBLE_H

#include "IOperand.hpp"

class Double : public IOperand
{
public:
	Double( std::string const & value );
	Double( Double const & double );
	Double & operator= ( Double const & double );
	~Double();
	
	int 			getPrecision( void ) const ;
	IOperand::eOperandType	getType ( void ) const ;

	IOperand const * operator+( IOperand const & rhs ) ;
	IOperand const * operator-( IOperand const & rhs ) ;
	IOperand const * operator*( IOperand const & rhs ) ;
	IOperand const * operator/( IOperand const & rhs ) ;
	IOperand const * operator%( IOperand const & rhs ) ;

private:
	int 	_precision;
	double	_val;
};

#endif