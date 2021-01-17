/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** parser
*/

#include <iostream>
#include "Miscellaneous/Parser.hpp"

int main(int ac, char **av)
{
    if (ac == 2) {
        ParsedLine line(av[1]);

        if (line.isArgCommand()) {
            std::cout << line.getInstruction() << std::endl;
            std::cout << line.getValue() << std::endl;
            std::cout << line.getValueType() << std::endl;
        } else {
            std::cout << line.getInstruction() << std::endl;
        }

    }
    return 0;
}