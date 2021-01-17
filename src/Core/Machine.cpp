/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** Machine
*/

#include <fstream>
#include "Core/Machine.hpp"

void Machine::getCommands(std::istream &fileStream)
{
    std::string line;
    int line_nb = 1;

    while (std::getline(fileStream, line) && line != ";;") {
        try {
            ParsedLine command(line);

            _commands.push_back(command.getCommandData());
        } catch (std::exception &e) {
            throw MyException("Line " + std::to_string(line_nb) + ": " + "Bad command");
        }
        ++line_nb;
    }
}

void Machine::runCommands()
{
    unsigned int command_nb = 1;
    bool isExit = false;

    for (command_data_t elem : _commands) {
        if (elem.instruction == "")
            continue;
        if (elem.instruction == "exit") {
            isExit = true;
            break;
        }
        IOperand *operand = nullptr;
        if (elem.value != "")
            operand = Factory::createOperand(getOperandType(elem.valueType), elem.value);
        _cpu.executeInstruction(elem.instruction, operand);
        ++command_nb;
    }
    printLog();
    if (!isExit)
        throw MyException("Missing Exit at the end of the file");
}

eOperandType Machine::getOperandType(const std::string &operand)
{
    return _operandMap[operand];
}

void Machine::printLog()
{
    std::vector<std::string> toBePrinted = _cpu.getPrinted();
    for (std::string elem : toBePrinted) {
        if (Utils::containChar(elem, '.')) {
            for (std::size_t i = elem.size() - 1; i != 0; i--)
                if (elem.at(i) == '0')
                    elem.erase(elem.begin() + i);
                else
                    break;
        }
        if (elem.at(elem.size() - 1) == '.')
            elem.erase(elem.begin() + elem.size() - 1);
        std::cout << elem << std::endl;
    }
}

void Machine::run(std::istream &stream)
{
    getCommands(stream);
    runCommands();
}

Machine::Machine()
{
    _operandMap["int8"] = eOperandType::Int8;
    _operandMap["int16"] = eOperandType::Int16;
    _operandMap["int32"] = eOperandType::Int32;
    _operandMap["float"] = eOperandType::Float;
    _operandMap["double"] = eOperandType::Double;
    _operandMap["bigdecimal"] = eOperandType::BigDecimal;

    run();
}

Machine::Machine(const std::string &filename)
{
    std::ifstream file(filename);

    _operandMap["int8"] = eOperandType::Int8;
    _operandMap["int16"] = eOperandType::Int16;
    _operandMap["int32"] = eOperandType::Int32;
    _operandMap["float"] = eOperandType::Float;
    _operandMap["double"] = eOperandType::Double;
    _operandMap["bigdecimal"] = eOperandType::BigDecimal;
    if (!file.is_open())
        throw MyException("Error: open failed");
    else
        run(file);
}