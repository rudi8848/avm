#ifndef SUPER_STACK_H
# define SUPER_STACK_H

# include <iostream>
# include <list>
# include <vector>
# include <stack>
# include <iterator>

template <typename T>
class SuperStack : public std::stack<T>
{

public:
	SuperStack() : std::stack<T>() {}
	SuperStack( SuperStack const & stack ) {}
	SuperStack & operator= ( SuperStack const & st ) {}
	~SuperStack() {}

	T 		top( void ) const;
	void	push( T val );
	size_t 	size( void ) const;
	void	pop( void );

	typedef typename std::list<T>::iterator iterator;

	iterator	begin();
	iterator	end();

	
private:
	std::list<T> _stack;
};
#include "SuperStack.cpp"
#endif