/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "Operand/AOperand.hpp"

namespace VM {
    class Int8 : public AOperand {
        public:
            Int8() = default;
            Int8(const int8_t value);

            std::string toString() const;

            IOperand *operator+(const IOperand &rhs) const;
            IOperand *operator-(const IOperand &rhs) const;
            IOperand *operator*(const IOperand &rhs) const;
            IOperand *operator/(const IOperand &rhs) const;
            IOperand *operator%(const IOperand &rhs) const;
        private:
            int8_t _value;
    };
};

#endif /* !INT8_HPP_ */