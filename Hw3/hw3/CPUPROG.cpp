#include "CPUPROG.h"
#include <cstdlib>
CPUProgram::CPUProgram(char  *filename){
    readfile(filename);
}
void CPUProgram::readfile(char *filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        cerr << "The file was not opened" << endl;
        exit(1);     
    } 
    string line = "";
    while (std::getline(file, line)) {
        insArray.push_back(line);
    }
}
string CPUProgram::getline(int index) const {
    /*the -1 mean when the parameter is 3 but the vector index stared with zero*/
    return insArray[index-1];
}
int CPUProgram::getsize() const {
    return insArray.size();
}
