/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

class Utils {
    public:
        Utils();
        ~Utils();

        static bool containChar(const std::string &str, const char &c);
        static bool checkSize(const std::string &value, const std::string &type);
        static float stof(const std::string &string);
        static std::size_t decimalSize(float &nb);
        static void trimZero(std::string &str);
    private:
};

#endif /* !UTILS_HPP_ */