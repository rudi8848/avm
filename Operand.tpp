
template <typename T>
Operand<T>::Operand( eOperandType type, std::string const & value )
{
		this->_type = type;
		this->_val = stoi(value);
		this->_str = value;
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
	//if (type == double || type == float) return 2; else return 0; 
	return 1;
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