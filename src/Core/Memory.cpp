/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Memory
*/

#include "Core/Memory.hpp"

Memory::Memory()
{
    this->_exit = false;
    for (std::pair<IOperand *, bool> elem : this->_registers) {
        elem.second = false;
    }
}

Memory::~Memory()
{
    while (!_stack.empty()) {
        delete _stack.front();
        _stack.erase(_stack.begin());
    }
}