/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** BigDecimal
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include "Operand/AOperand.hpp"

namespace VM {
    class BigDecimal : public AOperand {
        public:
            BigDecimal() = default;
            BigDecimal(const std::string &value);

            std::string toString() const;

            IOperand *operator+(const IOperand &rhs) const;
            IOperand *operator-(const IOperand &rhs) const;
            IOperand *operator*(const IOperand &rhs) const;
            IOperand *operator/(const IOperand &rhs) const;
            IOperand *operator%(const IOperand &rhs) const;

            void alignDots(std::string &s1, std::string &s2) const;
            uint8_t countDigitsAfterDot(const std::string &s1) const;
            bool firstIsGreater(const std::string &s1, const std::string &s2) const; // Attention, les points doivent être alignés
            bool isNegGreater(const std::string &s1, const std::string &s2) const;
            bool hasDot(const std::string &s1) const;
            void addDot(std::string &s1) const;
            std::string &getGreater(std::string &s1, std::string &s2) const { return firstIsGreater(s1, s2) ? s1 : s2; };
            const std::string &getGreater(const std::string &s1, const std::string &s2) const { return firstIsGreater(s1, s2) ? s1 : s2; };
            std::string &getSmaller(std::string &s1, std::string &s2) const { return firstIsGreater(s1, s2) ? s2 : s1; };
            const std::string &getSmaller(const std::string &s1, const std::string &s2) const { return firstIsGreater(s1, s2) ? s2 : s1; };

            // Addition
            std::string addStrings(const std::string &s1, const std::string &s2) const;
            bool isNeg(const std::string &s1) const;
            std::string addToSub(const std::string &s1, const std::string &s2) const;

            // Subtraction
            std::string &doSameLen(std::string &s1, const std::string &s2) const;
            std::string subStrings(const std::string &s1, const std::string &s2) const;
            std::string handleSub(const std::string &s1, const std::string &s2) const;

            // Multiplication
            std::string placeDot(std::string &s, int dotPlacement) const;
            std::string multStrings(const std::string &s1, const std::string &s2) const;

            // Division

            // Modulo
            void removeIntPart(std::string &s) const;
        private:
            std::string _value;
    };
};

#endif /* !BIGDECIMAL_HPP_ */