/* 
 * File:   main.cpp
 * Author: onder
 *
 * Created on October 31, 2016, 10:56 AM
 */
#include "requiredIncs.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //////////////////////////////////////////////////////////////////////////
    //command line parameters
    const char* filename ="file.txt";
    int option = atoi(argv[2]);
    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(filename);
    cout << myCPUProgram[0] << endl;
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;

    cout << ((myCPUProgram+"MOV R1, #45" )[myCPUProgram.size() ]) << endl;

    myCPUProgram += "MOV R2, #50";
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;

    CPUProgram myOtherCPUProgram(option);
    myOtherCPUProgram.ReadFile(filename);
  
    cout << (myCPUProgram + myOtherCPUProgram) << endl;

    cout << (myCPUProgram == myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram <= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram > myOtherCPUProgram ? "FAIL" : "DONE") << endl;
    --myOtherCPUProgram;
    cout << (myCPUProgram != myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram >= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram < myOtherCPUProgram ? "FAIL" : "DONE") << endl;

    //op ()
    cout << myCPUProgram(5, 7) << endl;
    //error check
    cout << myCPUProgram[myCPUProgram.size()] << endl;
    myCPUProgram += "";
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;
    ///////////////////////////////////////////////////////
    return 0;
}

