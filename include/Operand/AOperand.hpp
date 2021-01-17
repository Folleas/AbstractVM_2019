/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** AOperand
*/

#ifndef AOPERAND_HPP_
#define AOPERAND_HPP_

#include "Operand/IOperand.hpp"
#include "Core/Factory.hpp"
#include <math.h>

class AOperand : public IOperand {
    public:
        AOperand() = default;
        ~AOperand() = default;

        eOperandType getType() const;
        void setType(const eOperandType &newValue);

        void setString(const std::string &newValue);
        std::string getString() const;
    private:
        eOperandType _type;
        std::string _str;
};

#endif /* !AOPERAND_HPP_ */