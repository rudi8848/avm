#include "AVM.hpp"
AVM::AVM(){}
AVM::~AVM(){}

void AVM::execute(std::list<Token*> & tokens) {
    std::cout << __PRETTY_FUNCTION__<< std::endl;
    auto i = tokens.begin();
    try {
        while (i != tokens.end())
        {

                if ((*i)->type == INSTRUCTION) {

                } else {
                   // throw SyntaxError();
                   return;
                }
                ++i;
        }

    }
    catch (std::exception &e)
    {
         throw;
    }
}


AVM::Overflow::Overflow() : exception() {}
const char* AVM::Overflow::what() const throw() {
	return "Overflow on a value";
}

AVM::Underflow::Underflow() : exception() {}
const char* AVM::Underflow::what() const throw() {
	return "Underflow on a value";
}

AVM::PopEmptyStack::PopEmptyStack() : exception() {}
const char* AVM::PopEmptyStack::what() const throw() {
	return "Instruction pop on an empty stack";
}

AVM::DivisionByZero::DivisionByZero() : exception() {}
const char* AVM::DivisionByZero::what() const throw() {
	return "Division by 0";
}

AVM::ModuloByZero::ModuloByZero() : exception() {}
const char* AVM::ModuloByZero::what() const throw() {
	return "Modulo by 0";
}

AVM::NoExitInstruction::NoExitInstruction() : exception() {}
const char* AVM::NoExitInstruction::what() const throw() {
	return "The program doesn’t have an exit instruction";
}

const char* AVM::FalseAssert::what() const throw() {
	return "An assert instruction is not true";
}

const char* AVM::TooLessOperands::what() const throw() {
	return "The stack is composed of strictly less that two values when an arithmetic instruction is executed";
}