/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "Operand/AOperand.hpp"

namespace VM {
    class Int16 : public AOperand {
        public:
            Int16() = default;
            Int16(const int16_t value);

            std::string toString() const;

            IOperand *operator+(const IOperand &rhs) const;
            IOperand *operator-(const IOperand &rhs) const;
            IOperand *operator*(const IOperand &rhs) const;
            IOperand *operator/(const IOperand &rhs) const;
            IOperand *operator%(const IOperand &rhs) const;
        private:
            int16_t _value;
    };
}

#endif /* !INT16_HPP_ */