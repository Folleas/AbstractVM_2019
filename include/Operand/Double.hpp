/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "Operand/AOperand.hpp"

namespace VM {
    class Double : public AOperand {
        public:
            Double() = default;
            Double(const double value);

            std::string toString() const;

            IOperand *operator+(const IOperand &rhs) const;
            IOperand *operator-(const IOperand &rhs) const;
            IOperand *operator*(const IOperand &rhs) const;
            IOperand *operator/(const IOperand &rhs) const;
            IOperand *operator%(const IOperand &rhs) const;
        private:
            double _value;
    };
};

#endif /* !DOUBLE_HPP_ */
