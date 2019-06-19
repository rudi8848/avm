#include "AVM.hpp"

const char* AVM::SyntaxError::what() const throw() {
	return "The assembly program includes one or several lexical errors or syntactic errors";
}

const char* AVM::UnknownInstruction::what() const throw() {
	return "An instruction is unknown";
}

const char* AVM::Overflow::what() const throw() {
	return "Overflow on a value";
}

const char* AVM::Underflow::what() const throw() {
	return "Underflow on a value";
}

const char* AVM::PopEmptyStack::what() const throw() {
	return "Instruction pop on an empty stack";
}

const char* AVM::DivisionByZero::what() const throw() {
	return "Division by 0";
}

const char* AVM::ModuloByZero::what() const throw() {
	return "Modulo by 0";
}

const char* AVM::NoExitInstruction::what() const throw() {
	return "The program doesn’t have an exit instruction";
}

const char* AVM::FalseAssert::what() const throw() {
	return "An assert instruction is not true";
}

const char* AVM::TooLessOperands::what() const throw() {
	return "The stack is composed of strictly less that two values when an arithmetic instruction is executed";
}