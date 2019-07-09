
template <typename T>
Operand<T>::Operand( eOperandType type, std::string const & value )
{
	std::cout << "new [" << type << "] " << value << std::endl; 
		if ( value.empty())
		{
			std::cerr << "Error: No number" << std::endl;
			exit(EXIT_FAILURE);	//	throw exception
		}
		this->_type = type;
		this->_val = stoi(value);
		this->_str = value;
		this->_precision = 0;
		if (type == Float || type == Double)
		{
			bool point = false;
			for (auto i = value.begin(); i != value.end(); ++i)
			{
				if (point)
					++this->_precision;
				if ((*i == '.' || *i == ',') && !point)
					point = true;
				else if ((*i == '.' || *i == ',') && point)
				{
					std::cerr << "Error: Extra point" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
		}
}
/*
Operand::Operand( Operand const & operand )
{

}

Operand & Operand::operator= ( Operand const & operand )
{
	return this;
}
*/
template <typename T>
Operand<T>::~Operand()
{

}
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
/*
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
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val % rval));
		}
		case (Float):
		{
			auto rval = std::stof(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val % rval));
		}
		case (Double):
		{
			auto rval = std::stod(rhs.toString());
			return f.createOperand(std::max(this->getType(), rhs.getType()), std::to_string(this->_val % rval));
		}
		default:
			break ;
	}
	return f.createOperand(std::max(this->getType(), rhs.getType()), this->toString());
}
*/