/* 
 * File:   computer.h
 * Author: onder
 *
 * Created on October 30, 2016, 1:51 PM
 */

#ifndef COMPUTER_H
#define	COMPUTER_H
#include "cpu.h"
#include "memory.h"
#include "cpuprog.h"

class Computer {
private:
    CPU *defaultCpu;
    Memory *defaultMemory;
    CPUProgram *defaultCpuprog;
    int option;
public:
    /* --------------constructors-----------*/
    /*this initialize the option with zero,and
     *this is not initialize the CPU,CPUprog and Memory member!!*/
    Computer();
    /*this initialize the option with opt value,and
     *this is not initialize the CPU,CPUprog and Memory member!!*/
    Computer(int opt);
    /*this initialize the option with opt value,and
     *this is initialize the CPU,CPUprog and Memory member
     with parameters references!*/
    Computer(CPU& cpuref, CPUProgram& progref, Memory& memoryref, int opt);

    /*---------------setters----------------*/
    /*This set the CPU member with reference of parameter*/
    void setCPU(CPU& cpuobj);
    /*This set the CPUprogram member with reference of parameter*/
    void setCPUProgram(CPUProgram& obj);
    /*This set the Memory member with reference of parameter*/
    void setMemory(Memory& obj);
    /*This set the option member with parameter*/
    void setOption(int value);
    /*This firstly,control the references of members(CPU,CPUprog,Memory)
     *if these are not initialize ,this function does not run!!!
     *then, if option value is false,this function does not run!! 
     *else, this function initialize all member option with own option then
     *  run all of instruction which in CPUprog*/
    void execute();

    /*getters*/
    /*this return the reference of member cpu*/
    CPU& getCPU();
    /*this return the reference of member cpuprog*/
    CPUProgram& getCPUProgram();
    /*this return the  reference of member memory*/
    Memory& getMemory();
    /* this control the option , if the option false 
    return false else true*/
    bool controlOption()const;
    /*this return the option value*/
    int getOption()const;
};

#endif	/* COMPUTER_H */

