/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Int32
*/

#include "Operand/Int8.hpp"
#include "Operand/Int16.hpp"
#include "Operand/Int32.hpp"
#include "Operand/Float.hpp"
#include "Operand/Double.hpp"
#include "Operand/BigDecimal.hpp"


VM::Int32::Int32(const int32_t value)
{
    this->_value = value;
}

std::string VM::Int32::toString() const
{
    return (std::to_string(this->_value));
}

IOperand *VM::Int32::operator+(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) + std::stoi(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(Utils::stof(this->toString()) + Utils::stof(rhs.toString())));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::stod(this->toString()) + std::stod(rhs.toString())));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first + *second;
            break;
    }
    return (tmp);
}

IOperand *VM::Int32::operator-(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) - std::stoi(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) - std::stoi(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) - std::stoi(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(Utils::stof(this->toString()) - Utils::stof(rhs.toString())));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::stol(this->toString()) - std::stol(rhs.toString())));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first - *second;
            break;
    }
    return (tmp);
}

IOperand *VM::Int32::operator*(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) * std::stoi(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(Utils::stof(this->toString()) * Utils::stof(rhs.toString())));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::stod(this->toString()) * std::stod(rhs.toString())));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first * *second;
            break;
    }
    return (tmp);
}

IOperand *VM::Int32::operator/(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) / std::stoi(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) / std::stoi(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) / std::stoi(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(Utils::stof(this->toString()) / Utils::stof(rhs.toString())));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::stod(this->toString()) / std::stod(rhs.toString())));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first / *second;
            break;
    }
    return (tmp);
}

IOperand *VM::Int32::operator%(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) % std::stoi(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) % std::stoi(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Int32, std::to_string(std::stoi(this->toString()) % std::stoi(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::fmod(std::stof(this->toString()), std::stof(rhs.toString()))));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::fmod(std::stod(this->toString()), std::stod(rhs.toString()))));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first % *second;
            break;
    }
    return (tmp);
}