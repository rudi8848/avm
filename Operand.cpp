
template <typename T>
Operand<T>::Operand( eOperandType type, std::string const & value )
{
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