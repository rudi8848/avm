/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvynogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:15:08 by gvynogra          #+#    #+#             */
/*   Updated: 2019/09/07 13:15:12 by gvynogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IOperand.hpp"
#include "Parser.hpp"

template <typename T>
Operand<T>::Operand( eOperandType type, std::string const & value )
{

		if ( value.empty())
		{
			throw AVM::SomeError();
		}
		this->_type = type;
		this->_str = value;
        this->_precision = 0;
        try
        {
			if (type == Int8 || type == Int16 || type == Int32) {

	            int tmpval = std::stoi(value);

	            switch (type)
	            {
	            	case Int8:
	            	{
	            		
	            		if (tmpval > std::numeric_limits<signed char>::max()) {
	            			
	            			throw AVM::Overflow();
	            		}
	            		else if (tmpval < std::numeric_limits<signed char>::lowest()) {
	            			
	            			throw AVM::Underflow();
	            		}
	            		this->_val = tmpval;
	            		break;
	            	}
	            	case Int16:
	            	{
	            		
	            		if (tmpval > std::numeric_limits<short>::max()) {
	            			
	            			throw AVM::Overflow();
	            		}
	            		else if (tmpval < std::numeric_limits<short>::lowest()) {
	            			
	            			throw AVM::Underflow();
	            		}
	            		this->_val = tmpval;
	            		break;
	            	}
	            	case Int32:
	            	{
	            		
	            		if (tmpval > std::numeric_limits<int>::max()) {
	            			
	            			throw AVM::Overflow();
	            		}
	            		else if (tmpval < std::numeric_limits<int>::lowest()) {
	            			
	            			throw AVM::Underflow();
	            		}
	            		this->_val = tmpval;
	            		break;
	            	}
	            	default:
	            		break;
	            }
	            
			}
			else if (type == Float || type == Double)
			{
			    std::string tmp = "";
				bool point = false;
				for (auto i = value.begin(); i != value.end(); ++i)
				{
					if (point)
						++this->_precision;
					if ((*i == '.' || *i == ',') && !point) {
	                    point = true;
	                    tmp += ".";
	                }
					else if ((*i == '.' || *i == ',') && point)
					{
	                    std::cerr << "Error: Extra point. " ;
	                    throw AVM::SomeError();
	                }
					else
					    tmp += *i;
				}

				long double tmpval = std::stold(tmp);
				
				switch (type)
				{
					case Float:
					{

						if (tmpval > std::numeric_limits<float>::max()) {
							throw AVM::Overflow();
						}
						else if (tmpval < std::numeric_limits<float>::lowest()) {
							throw AVM::Underflow();
						}
						this->_val = stof(tmp);
						break;
					
					}
					case Double:
					{

						if (tmpval > std::numeric_limits<double>::max()) {
							throw AVM::Overflow();
						}
						else if (tmpval < std::numeric_limits<double>::lowest()) {
							throw AVM::Underflow();
						}
						this->_val = stod(tmp);
						break;

					}
					default:
						break;
				}

				this->_str = tmp;
			}
		} catch (std::exception &e) {
			throw ;
		}

}

template <typename T>
Operand<T>::Operand( Operand const & operand )
{
    this->_type = operand._type;
    this->_val = operand._val;
    this->str = operand._str;
    this->_precision = operand._precision;
}

template <typename T>
Operand<T> & Operand<T>::operator= ( Operand const & operand )
{
    if (this != &operand) {
        this->_type = operand._type;
        this->_val = operand._val;
        this->str = operand._str;
        this->_precision = operand._precision;
    }
	return *this;
}

template <typename T>
Operand<T>::~Operand() {}

template <typename T>
int 			Operand<T>::getPrecision( void ) const
{
	return this->_precision;
}

template <typename T>
eOperandType	Operand<T>::getType ( void ) const
{
	return this->_type;
}

template <typename T>
std::string const & Operand<T>::toString( void ) const
{
	return this->_str;
}

template <typename T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const
{
	Factory f;
	switch (rhs.getType())
	{
		case (Int8):
		case (Int16):
		case (Int32):
		{
			auto rval = std::stoi(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val + rval));
		}
		case (Float):
		{
			auto rval = std::stof(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val + rval));
		}
		case (Double):
		{
			auto rval = std::stod(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val + rval));
		}
		default:
			break ;
	}
	return f.createOperand(std::max(this->getType(), rhs.getType()), this->toString());
}


template <typename T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const
{
	Factory f;
	switch (rhs.getType())
	{
		case (Int8):
		case (Int16):
		case (Int32):
		{
			auto rval = std::stoi(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val - rval));
		}
		case (Float):
		{
			auto rval = std::stof(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val - rval));
		}
		case (Double):
		{
			auto rval = std::stod(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val - rval));
		}
		default:
			break ;
	}
	return f.createOperand(std::max(this->getType(), rhs.getType()), this->toString());
}

template <typename T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const
{
	Factory f;
	switch (rhs.getType())
	{
		case (Int8):
		case (Int16):
		case (Int32):
		{
			auto rval = std::stoi(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val * rval));
		}
		case (Float):
		{
			auto rval = std::stof(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val * rval));
		}
		case (Double):
		{
			auto rval = std::stod(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val * rval));
		}
		default:
			break ;
	}
	return f.createOperand(std::max(this->getType(), rhs.getType()), this->toString());
}

template <typename T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const
{
	Factory f;
	switch (rhs.getType())
	{
		case (Int8):
		case (Int16):
		case (Int32):
		{
			auto rval = std::stoi(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val / rval));
		}
		case (Float):
		{
			auto rval = std::stof(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val / rval));
		}
		case (Double):
		{
			auto rval = std::stod(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val / rval));
		}
		default:
			break ;
	}
	return f.createOperand(std::max(this->getType(), rhs.getType()), this->toString());
}

template <typename T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const
{
	Factory f;
	
	switch (rhs.getType())
	{	
		case (Int8):
		case (Int16):
		case (Int32):
		{
			auto rval = std::stoi(rhs.toString());
			switch (this->getType())
			{
				case (Int8):
				case (Int16):
				case (Int32):
				{
					return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(int (this->_val) % int(rval)));
				}
				default:
					return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(fmod(this->_val, rval)));

            }
		}
		case (Float):
		{
			auto rval = std::stof(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(fmod(this->_val, rval)));
		}
		case (Double):
		{
			auto rval = std::stod(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(fmod(this->_val, rval)));
		}
		default:
			break ;
	}
	return f.createOperand(std::max(this->getType(), rhs.getType()), this->toString());
}
