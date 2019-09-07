/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:13:45 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:13:47 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_H
# define AVM_H

#include <exception>
#include <stack>
#include "IOperand.hpp"
#include "Token.hpp"
#include "SuperStack.hpp"
#include "Factory.hpp"

class AVM
{

    SuperStack <const IOperand* > _stack;

	bool isExitCorrect(std::list<Token*> const & tokens);
	AVM( AVM const & avm );
	AVM & operator= ( AVM const & avm );

public:
	AVM();
	~AVM();

	void execute(std::list<Token*> & tokens);
	
/*
**				Exceptions:
*/


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

    class SomeError : public std::exception
    {
    public:
        SomeError();
        ~SomeError() throw () {};
        virtual const char *what() const throw();
    };
	
};

#endif
