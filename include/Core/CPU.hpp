/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** CPU
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include "Core/Memory.hpp"
#include <map>
#include <string>

class CPU : public Memory {
    public:
        CPU();
        ~CPU();

        void executeInstruction(std::string &instruction, IOperand *operand);

        IOperand * at(const std::size_t &n) const;
        void push(IOperand *value);
        void pop(IOperand *value);
        void clear(IOperand *value);
        void dup(IOperand *value);
        void swap(IOperand *value);
        void dump(IOperand *value);
        void assert(IOperand * value);
        void add(IOperand *value);
        void sub(IOperand *value);
        void mul(IOperand *value);
        void div(IOperand *value);
        void mod(IOperand *value);
        void print(IOperand *value);
        void exit(IOperand *value);

        IOperand *getRegister(const std::size_t &n) const;
        void setRegister(const std::size_t &n, IOperand *value);
        bool isRegister(const std::size_t &n) const;
        void load(IOperand *value);
        void store(IOperand *value);

        std::vector<std::string> getPrinted();
        bool isExit();
    private:
        std::map<std::string, void (CPU::*)(IOperand *)> _commands;
        std::string display;
};

#endif /* !CPU_HPP_ */
