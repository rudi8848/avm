#ifndef OPERAND_H
# define OPERAND_H

#include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
public:
	Operand( std::string const & value );
	// Operand( Operand const & operand );
	// Operand & operator= ( Operand const & operand );
	~Operand();

	// IOperand const * operator+( IOperand const & rhs ) ;
	// IOperand const * operator-( IOperand const & rhs ) ;
	// IOperand const * operator*( IOperand const & rhs ) ;
	// IOperand const * operator/( IOperand const & rhs ) ;
	// IOperand const * operator%( IOperand const & rhs ) ;

	int 			getPrecision( void ) const;
	T 	getVal() const;

private:
	T 		_val;
	
};

#include "Operand.tpp"

#endif