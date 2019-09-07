/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:16:27 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:16:29 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_STACK_H
# define SUPER_STACK_H

# include <iostream>
# include <list>
# include <vector>
# include <iterator>

template <typename T>
class SuperStack : public std::list<T>
{
	SuperStack( SuperStack const & );
	SuperStack & operator= ( SuperStack const& );

public:
	SuperStack() : std::list<T>() {}	
	~SuperStack() {}


	T 		top( void ) const;
	void	push( T val );
	size_t 	size( void ) const;
	void	pop( void );
	void	clear( void );
	bool 	empty( void ) const;

	typedef typename std::list<T>::iterator iterator;

	iterator	begin();
	iterator	end();

	
private:
	std::list<T> _stack;
};

#include "SuperStack.cpp"
#endif
