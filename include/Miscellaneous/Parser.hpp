/*
** EPITECH PROJECT, 2020
** SYN_abstractVM_2019
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>

const std::string arg_commands("(push|assert|load|store)");
const std::string no_arg_commands("(pop|dump|clear|dup|swap|add|sub|mul|div|mod|print|exit)");
const std::string comment("(;.*)");
const std::string types("(int8|int16|int32|float|double|bigdecimal)");
const std::string value_pattern("(-?([0-9]+)(\\.[0-9]+)?)");
const std::string space("([ \t]+)");
const std::string spaces("([ \t]*)");
const std::string value(types + spaces + "?\\(" + value_pattern + "\\)");
const std::string arg_command("(" + arg_commands + space + value + ")");
const std::string com(spaces + "(" + arg_command + "|" + no_arg_commands + ")" + spaces + comment + "?");

typedef struct command_data {
    std::string instruction;
    std::string value;
    std::string valueType;
} command_data_t;

class ParsedLine {
    public:
        ParsedLine(const std::string &line);

        void checkValidInstruction(const std::string &line);
        bool lineIsCom(const std::string &line);
        bool isArgInstruction(const std::string &line);
        bool lineIsEmpty(const std::string &line);
        void extractNoArgInstruction(const std::string &line);
        void getArgInstruction(const std::string &line);
        void getNb(const std::string &line);
        void getType(const std::string &line);
        void getValue(const std::string &line);
        void extractArgInstruction(const std::string &line);

        // Getters
        bool isCom() { return _isCom; };
        bool isArgCommand() { return _isArgCommand; };
        std::string getInstruction() const { return _instructionName; };
        std::string getValueType() const { return _valueType; };
        std::string getValue() const { return _value; };
        command_data_t getCommandData() const { return {_instructionName, _value, _valueType }; };
    private:
        bool _isCom = false;
        bool _isEmpty = false;
        bool _isArgCommand = false;
        std::string _instructionName = "";
        std::string _valueType = "";
        std::string _value = "";
};

#endif /* !PARSER_HPP_ */
