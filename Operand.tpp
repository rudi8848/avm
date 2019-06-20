
template <typename T>
Operand<T>::Operand( std::string const & value )
{
		this->_val = stoi(value);
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
	return 1;
}

template <typename T>
T 	Operand<T>::getVal() const
{
	return this->_val;
}