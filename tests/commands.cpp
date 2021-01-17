#include "Operand/IOperand.hpp"
#include "Operand/Int8.hpp"
#include "Core/CPU.hpp"

int main()
{
    try {
        //Stack
        IOperand *ope = new VM::Int8(14);
        IOperand *ope1 = new VM::Int8(15);
        IOperand *ope2 = new VM::Int8(16);
        IOperand *ope3 = new VM::Int8(17);
        IOperand *ope4 = new VM::Int8(18);
        IOperand *ope5 = new VM::Int8(19);
        CPU cpu;
        cpu.executeInstruction("push", ope);
        cpu.executeInstruction("push", ope1);
        cpu.executeInstruction("push", ope2);
        cpu.executeInstruction("push", ope3);
        cpu.executeInstruction("push", ope4);
        cpu.executeInstruction("push", ope5);
        cpu.executeInstruction("add", nullptr);
        cpu.executeInstruction("dump", nullptr);

        //Register
        IOperand *pos = new VM::Int8(2);
        cpu.executeInstruction("store", pos);
        cpu.executeInstruction("load", pos);
        cpu.executeInstruction("load", pos);
        cpu.executeInstruction("load", pos);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
        std::cout << "\n";
        cpu.executeInstruction("dump", nullptr);
    }
    catch (Myexception &e)
    {
        std::cout << e.what() << std::endl;
        return 84;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}