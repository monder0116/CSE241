/* 
 * File:   main.cpp
 * Author: onder
 *
 * Created on October 18, 2016, 8:54 PM
 */

#include <cstdlib>
#include "CPU.h"
#include "CPUPROG.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    CPUProgram file(argv[1]);
    CPU process(argv[2]);/*this parameter is mean option*/
    while(!process.gethalted())
    {
          string line=file.getline(process.getPC());
          process.execute(line);
    }
     return 0;
}

