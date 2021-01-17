/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Float
*/

#include "Operand/Int8.hpp"
#include "Operand/Int16.hpp"
#include "Operand/Int32.hpp"
#include "Operand/Float.hpp"
#include "Operand/Double.hpp"
#include "Operand/BigDecimal.hpp"

VM::Float::Float(const float value)
{
    this->_value = value;
}

std::string VM::Float::toString() const
{
    std::ostringstream strStream;

    strStream << std::setprecision(7) << this->_value;
    std::string str(strStream.str());
    return (str);
}

IOperand *VM::Float::operator+(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) + std::stof(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) + std::stof(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) + std::stof(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) + std::stof(rhs.toString())));
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

IOperand *VM::Float::operator-(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) - std::stof(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) - std::stof(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) - std::stof(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) - std::stof(rhs.toString())));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::stod(this->toString()) - std::stod(rhs.toString())));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first - *second;
            break;
    }
    return (tmp);
}

IOperand *VM::Float::operator*(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) * std::stof(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) * std::stof(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) * std::stof(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) * std::stof(rhs.toString())));
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

IOperand *VM::Float::operator/(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) / std::stof(rhs.toString())));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) / std::stof(rhs.toString())));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) / std::stof(rhs.toString())));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::stof(this->toString()) / std::stof(rhs.toString())));
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

IOperand *VM::Float::operator%(const IOperand &rhs) const
{
    IOperand *tmp;

    switch (rhs.getType()) {
        case eOperandType::Int8 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::fmod(std::stof(this->toString()), std::stof(rhs.toString()))));
            break;
        case eOperandType::Int16 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::fmod(std::stof(this->toString()), std::stof(rhs.toString()))));
            break;
        case eOperandType::Int32 :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::fmod(std::stof(this->toString()), std::stof(rhs.toString()))));
            break;
        case eOperandType::Float :
            tmp = Factory::createOperand(eOperandType::Float, std::to_string(std::fmod(std::stof(this->toString()), std::stof(rhs.toString()))));
            break;
        case eOperandType::Double :
            tmp = Factory::createOperand(eOperandType::Double, std::to_string(std::fmod(std::stof(this->toString()), std::stof(rhs.toString()))));
            break;
        case eOperandType::BigDecimal :
            IOperand *first = Factory::createOperand(eOperandType::BigDecimal, this->toString());
            IOperand *second = Factory::createOperand(eOperandType::BigDecimal, rhs.toString());
            tmp = *first % *second;
            break;
    }
    return (tmp);
}