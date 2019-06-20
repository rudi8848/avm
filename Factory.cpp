#include "Factory.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"

Factory::Factory() {}
Factory::~Factory() {}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	createFunc func = funcArr[type];
	const IOperand *op = (this->*func)(value);
	return op;
}

IOperand const * Factory::createInt8( std::string const & value ) const
{
	Operand<int8_t> *op = new Operand<int8_t>(value);
	return op;
}

IOperand const * Factory::createInt16( std::string const & value ) const
{
	Operand<int16_t> *op = new Operand<int16_t>(value);
	return op;
}

IOperand const * Factory::createInt32( std::string const & value ) const
{
	Operand<int32_t> *op = new Operand<int32_t>(value);
	return op;
}

IOperand const * Factory::createFloat( std::string const & value ) const
{
	Operand<float> *op = new Operand<float>(value);
	return op;
}

IOperand const * Factory::createDouble( std::string const & value ) const
{
	Operand<double> *op = new Operand<double>(value);
	return op;
}