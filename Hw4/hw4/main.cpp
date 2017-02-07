/* 
 * File:   main.cpp
 * Author: onder
 *
 * Created on October 31, 2016, 10:56 AM
 */
#include <iostream>
#include "memory.h"
#include "cpuprog.h"
#include "cpu.h"
#include "computer.h"
#include "helper.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
   int option = Helper::convertToint(argv[2]);
    //Testing class CPU
    Memory myMemory(option);
    CPU myCPU(option);

    //////////////////////////////////////////////
    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(argv[1]);
    //////////////////////////////////////////////
    //Testing class Computer
    Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
    Computer myComputer2(option);
    myComputer2.setCPU(myComputer1.getCPU());
    myComputer2.setCPUProgram(myComputer1.getCPUProgram());
    myComputer2.setMemory(myComputer1.getMemory());
    myComputer2.execute();
    //////////////////////////////////////////////////////////////////////////
    return 0;
}

