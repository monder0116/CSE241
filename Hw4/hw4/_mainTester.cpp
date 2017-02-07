#include "requiredIncs.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int option =atoi(argv[2]);
    //Testing class CPU
    Memory myMemory(option);


    CPU myCPU(option);


    //////////////////////////////////////////////
    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(argv[1]);
    Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
    Computer myComputer2(option);
    myComputer2.setCPU(myComputer1.getCPU());
    myComputer2.setCPUProgram(myComputer1.getCPUProgram());
    myComputer2.setMemory(myComputer1.getMemory());
    myComputer2.execute();
    //////////////////////////////////////////////////////////////////////////
    return 0;
}


