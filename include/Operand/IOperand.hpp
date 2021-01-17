/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <string>

typedef enum eOperandType {
    Int8 = 0,
    Int16 = 1,
    Int32 = 2,
    Float = 3,
    Double = 4,
    BigDecimal = 5
} eOperandType;

class IOperand {
    public:
        virtual ~IOperand() {};

        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;

        virtual void setType(const eOperandType &newValue) = 0;
        virtual void setString(const std::string &newValue) = 0;

        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;
    private:
};

#endif /* !IOPERAND_HPP_ */