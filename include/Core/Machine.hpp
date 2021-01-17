/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Machine
*/

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include "Miscellaneous/Parser.hpp"
#include "CPU.hpp"
#include "Factory.hpp"

class Machine {
    public:
        Machine();
        Machine(const std::string &fileName);
        ~Machine() = default;

        void getCommands(std::istream &fileStream);
        void runCommands();
        void printLog();
        void run(std::istream &stream = std::cin);

        eOperandType getOperandType(const std::string &str);
    private:
        std::map<std::string, eOperandType> _operandMap;
        std::vector<command_data_t> _commands;
        CPU _cpu;
};

#endif /* !MACHINE_HPP_ */
