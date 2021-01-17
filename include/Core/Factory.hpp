/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Operand/IOperand.hpp"
#include "Miscellaneous/Exception.hpp"

#include "Miscellaneous/Utils.hpp"

#include <string>
#include <array>
#include <map>
#include <utility>
#include <functional>

class Factory {
    public:
        ~Factory() = default;

        static IOperand *createOperand(eOperandType type, const std::string &value);

    private:
        Factory();

        std::array<std::pair<eOperandType, std::function<IOperand *(Factory, const std::string &value)>>, 6> _methodMap;

        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);
        IOperand *createBigDecimal(const std::string &value);

};

#endif /* !FACTORY_HPP_ */