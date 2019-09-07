/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperStack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:16:00 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:16:01 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
T 		SuperStack<T>::top(void) const
{
	return this->_stack.front();
}

template <typename T>
void	SuperStack<T>::push(T val)
{
	this->_stack.push_front(val);
}

template <typename T>
size_t 	SuperStack<T>::size(void) const
{
	return this-> _stack.size();
}

template <typename T>
void	SuperStack<T>::pop(void)
{
	this->_stack.pop_front();
}

template <typename T>
typename SuperStack<T>::iterator	SuperStack<T>::begin()
{
	return this->_stack.begin();
}

template <typename T>
typename SuperStack<T>::iterator	SuperStack<T>::end()
{
	return this->_stack.end();
}
