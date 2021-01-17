/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** AOperand
*/

#include "Operand/AOperand.hpp"

eOperandType AOperand::getType() const
{
    return (this->_type);
}

void AOperand::setType(const eOperandType &newValue)
{
    this->_type = newValue;
}

void AOperand::setString(const std::string &newValue)
{
    this->_str = newValue;
}

std::string AOperand::getString() const
{
    return (this->_str);
}
