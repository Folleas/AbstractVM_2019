/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Float
*/

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

#include "Operand/AOperand.hpp"
#include <sstream>
#include <iomanip>

namespace VM {
    class Float : public AOperand {
        public:
            Float() = default;
            Float(const float value);

            std::string toString() const;

            IOperand *operator+(const IOperand &rhs) const;
            IOperand *operator-(const IOperand &rhs) const;
            IOperand *operator*(const IOperand &rhs) const;
            IOperand *operator/(const IOperand &rhs) const;
            IOperand *operator%(const IOperand &rhs) const;
        private:
            float _value;
    };
};

#endif /* !FLOAT_HPP_ */