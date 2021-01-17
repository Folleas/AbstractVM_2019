/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** parser
*/

#include <iostream>
#include <regex>
#include "Miscellaneous/Exception.hpp"
#include "Miscellaneous/Parser.hpp"

void ParsedLine::checkValidInstruction(const std::string &line)
{
    if (!std::regex_match(line, std::regex(com)))
        throw MyException("Invalid command");
}

bool ParsedLine::lineIsCom(const std::string &line)
{
    if (std::regex_match(line, std::regex(spaces + comment)))
        _isCom = true;
    return _isCom;
}

bool ParsedLine::lineIsEmpty(const std::string &line)
{
    if (std::regex_match(line, std::regex(spaces)))
        _isEmpty = true;
    return _isEmpty;
}

bool ParsedLine::isArgInstruction(const std::string &line)
{
    if (std::regex_search(line, std::regex(arg_commands)))
        _isArgCommand = true;
    return _isArgCommand;
}

void ParsedLine::extractNoArgInstruction(const std::string &line)
{
    std::smatch match;

    if (std::regex_search(line.begin(), line.end(), match, std::regex(no_arg_commands)))
        _instructionName = match[0];
}

void ParsedLine::getArgInstruction(const std::string &line)
{
    std::smatch match;

    std::regex_search(line.begin(), line.end(), match, std::regex(arg_commands));
    _instructionName = match[0];
}

void ParsedLine::getNb(const std::string &line)
{
    std::smatch match;

    std::regex_search(line.begin(), line.end(), match, std::regex("\\(" + value_pattern + "\\)"));
    const std::string &submatch = match[0];
    std::regex_search(submatch.begin(), submatch.end(), match, std::regex(value_pattern));
    _value = match[0];

}

void ParsedLine::getType(const std::string &line)
{
    std::smatch match;

    std::regex_search(line.begin(), line.end(), match, std::regex(types));
    _valueType = match[0];
}

void ParsedLine::getValue(const std::string &line)
{
    getType(line);
    getNb(line);
}

void ParsedLine::extractArgInstruction(const std::string &line)
{
    getArgInstruction(line);
    getValue(line);
}

ParsedLine::ParsedLine(const std::string &line)
{
    if (lineIsCom(line))
        return;
    if (lineIsEmpty(line))
        return; 
    checkValidInstruction(line);
    if (isArgInstruction(line))
        extractArgInstruction(line);
    else
        extractNoArgInstruction(line);
}