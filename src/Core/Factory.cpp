/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Factory
*/

#include <regex>
#include "Core/Factory.hpp"
#include "Operand/Int8.hpp"
#include "Operand/Int16.hpp"
#include "Operand/Int32.hpp"
#include "Operand/Float.hpp"
#include "Operand/Double.hpp"
#include "Operand/BigDecimal.hpp"

Factory::Factory()
{
    _methodMap = { std::make_pair(eOperandType::Int8, &Factory::createInt8),
    std::make_pair(eOperandType::Int16, &Factory::createInt16),
    std::make_pair(eOperandType::Int32, &Factory::createInt32),
    std::make_pair(eOperandType::Float, &Factory::createFloat),
    std::make_pair(eOperandType::Double, &Factory::createDouble),
    std::make_pair(eOperandType::BigDecimal, &Factory::createBigDecimal)};
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
    static Factory factory;

    return factory._methodMap[type].second(factory, value);
}

IOperand *Factory::createInt8(const std::string &value)
{
    if (Utils::containChar(value, '.') || Utils::checkSize(value, "Int8") == true)
        throw MyException("Factory can't create Int8");
    IOperand *tmp = new VM::Int8(std::stoi(value));
    tmp->setType(eOperandType::Int8);
    tmp->setString(value);
    return (tmp);
}

IOperand *Factory::createInt16(const std::string &value)
{
    if (Utils::containChar(value, '.') || Utils::checkSize(value, "Int16") == true)
        throw MyException("Factory can't create Int16");
    IOperand *tmp = new VM::Int16(std::stoi(value));
    tmp->setType(eOperandType::Int16);
    tmp->setString(value);
    return (tmp);
}

IOperand *Factory::createInt32(const std::string &value)
{
    if (Utils::containChar(value, '.') || Utils::checkSize(value, "Int32") == true)
        throw MyException("Factory can't create Int32");
    IOperand *tmp = new VM::Int32(std::stoi(value));
    tmp->setType(eOperandType::Int32);
    tmp->setString(value);
    return (tmp);
}

IOperand *Factory::createFloat(const std::string &value)
{
    if (!std::regex_match(value, std::regex("-?[0-9]+(\\.[0-9]{1,7})?")))
        throw MyException("Error: float only has 7 floating point digits");
    if (Utils::checkSize(value, "Float") == true)
        throw MyException("Factory can't create Float");
    IOperand *tmp = new VM::Float(Utils::stof(value));
    tmp->setType(eOperandType::Float);
    tmp->setString(value);
    return (tmp);
}

IOperand *Factory::createDouble(const std::string &value)
{
    if (!std::regex_match(value, std::regex("-?[0-9]+(\\.[0-9]{1,15})?")))
        throw MyException("Error: double only has 15 floating point digits");
    if (Utils::checkSize(value, "Double") == true)
        throw MyException("Factory can't create Double");
    IOperand *tmp = new VM::Double(std::stod(value));
    tmp->setType(eOperandType::Double);
    tmp->setString(value);
    return (tmp);
}

IOperand *Factory::createBigDecimal(const std::string &value)
{
    if (!std::regex_match(value, std::regex("-?[0-9]+(\\.[0-9]{1,200})?")))
        throw MyException("Error: bigdecimal only has 200 floating point digits");
    IOperand *tmp = new VM::BigDecimal(value);
    tmp->setType(eOperandType::BigDecimal);
    tmp->setString(value);
    return (tmp);
}