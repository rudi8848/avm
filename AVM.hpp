#ifndef AVM_H
# define AVM_H

#include <exception>
#include <stack>
#include "IOperand.hpp"

class AVM
{
public:
	AVM();
	AVM( AVM const & avm );
	AVM & operator= ( AVM const & avm );
	~AVM();

	void	push( IOperand *opetand );
	void	pop( void );
	void	dump( void );
	void	assert( std::string const & val );
	void	add( void );
	void	sub( void );
	void	mul( void );
	void	div( void );
	void	mod( void );
	void	print( void );
	void	exit( void );


	class SyntaxError : public std::exception
	{
	public:
		SyntaxError();
		~SyntaxError() throw () {};
		virtual const char *what() const throw();
	};

	class UnknownInstruction : public std::exception
	{
	public:
		UnknownInstruction();
		~UnknownInstruction() throw () {};
		virtual const char *what() const throw();
	};

	class Overflow : public std::exception
	{
	public:
		Overflow();
		~Overflow() throw () {};
		virtual const char *what() const throw();
	};

	class Underflow : public std::exception
	{
	public:
		Underflow();
		~Underflow() throw () {};
		virtual const char *what() const throw();
	};

	class PopEmptyStack : public std::exception
	{
	public:
		PopEmptyStack();
		~PopEmptyStack() throw () {};
		virtual const char *what() const throw();
	};

	class DivisionByZero : public std::exception
	{
	public:
		DivisionByZero();
		~DivisionByZero() throw () {};
		virtual const char *what() const throw();
	};

	class ModuloByZero : public std::exception
	{
	public:
		ModuloByZero();
		~ModuloByZero() throw () {};
		virtual const char *what() const throw();
	};

	class NoExitInstruction : public std::exception
	{
	public:
		NoExitInstruction();
		~NoExitInstruction() throw () {};
		virtual const char *what() const throw();
	};

	class FalseAssert : public std::exception
	{
	public:
		FalseAssert();
		~FalseAssert() throw () {};
		virtual const char *what() const throw();
	};

	class TooLessOperands : public std::exception
	{
	public:
		TooLessOperands();
		~TooLessOperands() throw () {};
		virtual const char *what() const throw();
	};

private:
	std::stack<IOperand*> _stack;
	
};

#endif