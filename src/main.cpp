/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** main
*/

#include "Core/Machine.hpp"

int main(int ac, char **av)
{
    try {
        if (ac == 2)
            Machine(std::string(av[1]));
        else if (ac == 1)
            Machine();
        else
            throw MyException("Error: invalid arguments");
    }
    catch (const MyException &e)
    {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}