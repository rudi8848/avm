#ifndef FACTORY_H
# define FACTORY_H

#include "IOperand.hpp"

class Factory;

typedef	IOperand const*( Factory::*createFunc )( std::string const & ) const;

class Factory
{
public:
	Factory();
	~Factory();
	typedef enum 
	{
		Int8,
		Int16,
		Int32,
		Float,
		Double,
		Types
	} eOperandType;
	
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
private:

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
	createFunc funcArr [Types] = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble,
	};
};

#endif