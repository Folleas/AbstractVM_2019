/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Utils
*/

#include "Miscellaneous/Utils.hpp"
#include <limits>

Utils::Utils()
{
}

Utils::~Utils()
{
}

bool Utils::containChar(const std::string &str, const char &c)
{
    if (str.find(c) != std::string::npos)
        return (true);
    else
        return (false);
}

bool Utils::checkSize(const std::string &value, const std::string &type)
{
    if (type == "Int8")
        if (stoi(value) < -128 || stoi(value) > 127)
            return (true);
    if (type == "Int16")
        if (stoi(value) < -32768 || stoi(value) > 32767)
            return (true);
    if (type == "Int32")
        if (stoi(value) < -2147483648 || stoi(value) > 2147483647)
            return (true);
    if (type == "Float")
        if (stod(value) < std::numeric_limits<float>::max() * -1 || stod(value) > std::numeric_limits<float>::max())
            return (true);
    if (type == "Double")
        if (stold(value) < std::numeric_limits<double>::max() * -1|| stold(value) > std::numeric_limits<double>::max())
            return (true);
    return false;
}

float Utils::stof(const std::string &string)
{
    std::stringstream s(string);
    float ret = 0;
    s >> ret;
    return ret;
}

void Utils::trimZero(std::string &str)
{
    for (std::size_t i = str.size() - 1; i != 0; i--) {
        if (str.at(i) == '0') {
            str.erase(str.begin() + i);
        }
        else
            break;
    }
}

std::size_t Utils::decimalSize(float &nb)
{
    std::size_t n = 0;

    while (nb) {
        nb = std::fmod(nb, 1);
        n += 1;
        nb *= 10;
    }
    return (n);
}