/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** CPU
*/

#include "Core/CPU.hpp"
#include "Operand/Int8.hpp"
#include "Operand/Int16.hpp"
#include "Operand/Int32.hpp"
#include "Operand/Float.hpp"
#include "Operand/Double.hpp"
#include "Operand/BigDecimal.hpp"

CPU::CPU()
{
    this->_commands["exit"] = &CPU::exit;
    this->_commands["add"] = &CPU::add;
    this->_commands["push"] = &CPU::push;
    this->_commands["pop"] = &CPU::pop;
    this->_commands["mul"] = &CPU::mul;
    this->_commands["dump"] = &CPU::dump;
    this->_commands["assert"] = &CPU::assert;
    this->_commands["print"] = &CPU::print;
    this->_commands["sub"] = &CPU::sub;
    this->_commands["mod"] = &CPU::mod;
    this->_commands["div"] = &CPU::div;
    this->_commands["clear"] = &CPU::clear;
    this->_commands["store"] = &CPU::store;
    this->_commands["load"] = &CPU::load;
    this->_commands["dup"] = &CPU::dup;
    this->_commands["swap"] = &CPU::swap;
}

void CPU::executeInstruction(std::string &instruction, IOperand *operand)
{
    ((this)->*(_commands[instruction]))(operand);
}

CPU::~CPU()
{
}

IOperand *CPU::at(const std::size_t &n) const
{
    return (this->_stack.at(n));
}

void CPU::push(IOperand *value)
{
    this->_stack.insert(this->_stack.begin(), value);
}

void CPU::pop(IOperand *value)
{
    if (_stack.empty())
        throw MyException("Stack is empty.");
    delete _stack.front();
    _stack.erase(_stack.begin());
}

void CPU::clear(IOperand *value)
{
    if (_stack.empty())
        return;
    this->_stack.clear();
}

void CPU::dup(IOperand *value)
{
    IOperand *tmp = Factory::createOperand(this->at(0)->getType(), this->at(0)->toString());

    this->push(tmp);
}

void CPU::swap(IOperand *value)
{

    if (_stack.size() <= 1)
        return;
    IOperand *tmp = Factory::createOperand(this->at(0)->getType(), this->at(0)->toString());
    this->pop(nullptr);
    this->_stack.insert(this->_stack.begin() + 1, tmp);
}

void CPU::dump(IOperand *value)
{
    for (IOperand *elem : this->_stack) {
        if (elem)
            this->_log.push_back(elem->toString());
    }
}

void CPU::assert(IOperand *value)
{
    if (this->at(0)->toString() != value->toString() || this->at(0)->getType() != value->getType()) {
        throw MyException("Assert error");
    }
}

void CPU::add(IOperand *value)
{
    if (_stack.size() <= 1)
        throw MyException("Not enough members in the stack.");
    std::shared_ptr<IOperand> first(Factory::createOperand(this->at(0)->getType(), this->at(0)->toString()));
    std::shared_ptr<IOperand> second(Factory::createOperand(this->at(1)->getType(), this->at(1)->toString()));
    this->pop(nullptr);
    this->pop(nullptr);
    this->push(*first + *second);
}

void CPU::sub(IOperand *value)
{
    if (_stack.size() <= 1)
        throw MyException("Not enough members in the stack.");
    std::shared_ptr<IOperand> first(Factory::createOperand(this->at(0)->getType(), this->at(0)->toString()));
    std::shared_ptr<IOperand> second(Factory::createOperand(this->at(1)->getType(), this->at(1)->toString()));
    this->pop(nullptr);
    this->pop(nullptr);
    this->push(*second - *first);
}

void CPU::mul(IOperand *value)
{
    if (_stack.size() <= 1)
        throw MyException("Not enough members in the stack.");
    std::shared_ptr<IOperand> first(Factory::createOperand(this->at(0)->getType(), this->at(0)->toString()));
    std::shared_ptr<IOperand> second(Factory::createOperand(this->at(1)->getType(), this->at(1)->toString()));
    this->pop(nullptr);
    this->pop(nullptr);
    this->push(*first * *second);
}

void CPU::div(IOperand *value)
{
    if (_stack.size() <= 1)
        throw MyException("Not enough members in the stack.");
    std::shared_ptr<IOperand> first(Factory::createOperand(this->at(0)->getType(), this->at(0)->toString()));
    std::shared_ptr<IOperand> second(Factory::createOperand(this->at(1)->getType(), this->at(1)->toString()));
    this->pop(nullptr);
    this->pop(nullptr);
    if (first->toString() == "0") {
        throw MyException("Division by zero.");
    }
    this->push(*second / *first);
}

void CPU::mod(IOperand *value)
{
    if (_stack.size() <= 1)
        throw MyException("Not enough members in the stack.");
    std::shared_ptr<IOperand> first(Factory::createOperand(this->at(0)->getType(), this->at(0)->toString()));
    std::shared_ptr<IOperand> second(Factory::createOperand(this->at(1)->getType(), this->at(1)->toString()));
    this->pop(nullptr);
    this->pop(nullptr);
    if (first->toString() == "0")
        throw MyException("Modulo by zero.");
    this->push(*second % *first);
}

void CPU::print(IOperand *value)
{
    if (this->at(0)->getType() == eOperandType::Int8) {
        std::string tmp;
        tmp.push_back(static_cast<char>(std::stoi(this->at(0)->toString())));
        this->_log.push_back(tmp);
    }
    else {
        throw MyException("Print error");
    }
}

void CPU::exit(IOperand *value)
{
    this->_exit = true;
}


IOperand *CPU::getRegister(const std::size_t &n) const
{
    return (this->_registers.at(n).first);
}

void CPU::setRegister(const std::size_t &n, IOperand *value)
{
    this->_registers.at(n).first = value;
    this->_registers.at(n).second = true;
}

bool CPU::isRegister(const std::size_t &n) const
{
    if (this->_registers.at(n).second == false) {
        return (false);
    }
    return (true);
}

void CPU::load(IOperand *value)
{
    std::size_t pos = std::stoi(value->toString());

    if (isRegister(pos)) {
        this->push(Factory::createOperand(this->_registers.at(pos).first->getType(), this->_registers.at(pos).first->toString()));
    }
    else {
        throw MyException("Load error");
    }
}

void CPU::store(IOperand *value)
{
    std::size_t pos = std::stoi(value->toString());

    this->_registers.at(pos).first = Factory::createOperand(this->at(0)->getType(), this->at(0)->toString());
    this->_registers.at(pos).second = true;
    this->pop(nullptr);
}

std::vector<std::string> CPU::getPrinted()
{
    return (this->_log);
}

bool CPU::isExit()
{
    return (this->_exit);
}