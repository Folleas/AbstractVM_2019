/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "Operand/AOperand.hpp"

namespace VM {
    class Int32 : public AOperand {
        public:
            Int32() = default;
            Int32(const int32_t value);

            std::string toString() const;

            IOperand *operator+(const IOperand &rhs) const;
            IOperand *operator-(const IOperand &rhs) const;
            IOperand *operator*(const IOperand &rhs) const;
            IOperand *operator/(const IOperand &rhs) const;
            IOperand *operator%(const IOperand &rhs) const;
        private:
            int32_t _value;
    };
};


#endif /* !INT32_HPP_ */
