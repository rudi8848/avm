#include "AVM.hpp"
AVM::AVM(){}
AVM::~AVM(){}

void AVM::execute(std::list<Token*> & tokens) {
    std::cout << __PRETTY_FUNCTION__<< std::endl;
    auto i = tokens.begin();
    Factory factory;

    if (tokens.empty() || tokens.back()->type != INSTRUCTION || tokens.back()->content != EXIT) {
        throw NoExitInstruction();
    }
    try {
        while (i != tokens.end())
        {
            //std::cout << (*i)->type << " : " << (*i)->content << std::endl;

            if ((*i)->type == INSTRUCTION) {
                switch ((*i)->content)
                {
                    case PUSH:
                    {
                        ++i;
                        if ((*i)->type != OPERAND)
                            throw TooLessOperands();
                        const IOperand * op = factory.createOperand((eOperandType)(*i)->content, (*i)->value);
                        this->_stack.push(op);
                        break;
                    }
                    case POP:
                    {
                        if (this->_stack.empty())
                            throw PopEmptyStack();
                        this->_stack.pop();
                        break;
                    }
                    case DUMP:
                    {
                        for (auto i : this->_stack) {
                            std::cout << i->toString() << std::endl;
                        }
                        break;
                    }
                    case ASSERT:
                    {
                        ++i;
                        if ((*i)->type == OPERAND) {

                            const IOperand *op = this->_stack.top();

                            if ((*i)->content != op->getType() || (*i)->value != op->toString())
                                throw FalseAssert();
                        }
                        break;
                    }
                    case ADD:
                    {
                        if (_stack.size() < 2) {
                            throw TooLessOperands();
                        }
                        const IOperand  *right = _stack.top();
                        _stack.pop();
                        const IOperand  *left = _stack.top();
                        _stack.pop();
                        _stack.push(*left + *right);
                        break;
                    }
                    case SUB:
                    {
                        if (_stack.size() < 2) {
                            throw TooLessOperands();
                        }
                        const IOperand  *right = _stack.top();
                        _stack.pop();
                        const IOperand  *left = _stack.top();
                        _stack.pop();
                        _stack.push(*left - *right);
                        break;
                    }
                    case MUL:
                    {
                        if (_stack.size() < 2) {
                            throw TooLessOperands();
                        }
                        const IOperand  *right = _stack.top();
                        _stack.pop();
                        const IOperand  *left = _stack.top();
                        _stack.pop();
                        _stack.push(*left * *right);
                        break;
                    }
                    case DIV:
                    {
                        if (_stack.size() < 2) {
                            throw TooLessOperands();
                        }
                        const IOperand  *right = _stack.top();
                        if (std::stod(right->toString()) ==  0) {
                            throw DivisionByZero();
                        }
                        _stack.pop();
                        const IOperand  *left = _stack.top();
                        _stack.pop();
                        _stack.push(*left / *right);
                        break;
                    }
                    case MOD:
                    {
                        if (_stack.size() < 2) {
                            throw TooLessOperands();
                        }
                        const IOperand  *right = _stack.top();
                        if (std::stod(right->toString()) ==  0) {
                            throw DivisionByZero();
                        }
                        _stack.pop();
                        const IOperand  *left = _stack.top();
                        _stack.pop();
                        _stack.push(*left % *right);
                        break;
                    }
                    case PRINT:
                    {
                        if (_stack.top()->getType() != Int8) {
                            throw FalseAssert();
                        }
                        std::cout << (char)std::stoi(_stack.top()->toString()) << std::endl;
                        break;
                    }
                    default:
                        break;
                }
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
	return "The program doesnt have an exit instruction";
}

AVM::FalseAssert::FalseAssert() : exception() {}
const char* AVM::FalseAssert::what() const throw() {
	return "An assert instruction is not true";
}

AVM::TooLessOperands::TooLessOperands() : exception() {}
const char* AVM::TooLessOperands::what() const throw() {
	return "The stack is composed of strictly less that two values when an arithmetic instruction is executed";
}