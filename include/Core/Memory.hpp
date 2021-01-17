/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include "Operand/IOperand.hpp"
#include "Core/Factory.hpp"

#include <iostream>

#include <vector>
#include <array>
#include <memory>

class Memory {
    public:
        Memory();
        ~Memory();

    protected:
        std::vector<IOperand *> _stack;
        std::array<std::pair<IOperand *, bool>, 16> _registers;

        std::vector<std::string> _log;
        bool _exit;
};

#endif /* !MEMORY_HPP_ */
