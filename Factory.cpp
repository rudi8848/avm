#include "Factory.hpp"
#include "IOperand.hpp"
#include "Operand.hpp"

Factory::Factory() {}
Factory::~Factory() {}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const
{
	createFunc func = funcArr[type];
	return (this->*func)(type, value);
}

IOperand const * Factory::createInt8( eOperandType type, std::string const & value ) const
{
	Operand<int8_t> *op = new Operand<int8_t>(type, value);
	return op;
}

IOperand const * Factory::createInt16( eOperandType type, std::string const & value ) const
{
	Operand<int16_t> *op = new Operand<int16_t>(type, value);
	return op;
}

IOperand const * Factory::createInt32( eOperandType type, std::string const & value ) const
{
	Operand<int32_t> *op = new Operand<int32_t>(type, value);
	return op;
}

IOperand const * Factory::createFloat( eOperandType type, std::string const & value ) const
{
	Operand<float> *op = new Operand<float>(type, value);
	return op;
}

IOperand const * Factory::createDouble( eOperandType type, std::string const & value ) const
{
	Operand<double> *op = new Operand<double>(type, value);
	return op;
}