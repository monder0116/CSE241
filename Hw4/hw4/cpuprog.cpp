#include "cpuprog.h"

CPUProgram::CPUProgram(int opt) {
    setoption(opt);
}

CPUProgram::CPUProgram() {
   setoption(0);
}
CPUProgram::CPUProgram(char *filename)
{
    setoption(0);
    ReadFile(filename);
}

/*---------------------------getters-----------------------*/
int CPUProgram::getoption() const {
    return option;
}

string CPUProgram::getLine(int index) const {
    if (!controlOption())
        cerr << "CPUprogram option value is false!!" << endl;

    else if (index < size() && index >= 0)
        return insArray[index]; 
    else
        cerr << "The index value is false!!" << endl;

    return "";
}

int CPUProgram::size() const {
    return insArray.size();
}

bool CPUProgram::controlOption()const {
    if (option < 0 || option > 2) {
        return false;
    }
    else
        return true;

}

/*-------------------setters --------------------*/
void CPUProgram::setoption(int value) {
    if (value < 0 || value > 2) {
        cerr << "The option value is false!!" << endl;
        cerr << "Please set again this!!" << endl;
        option = -1;
    }
    else
        option = value;
}

void CPUProgram::ReadFile(char *filename) {
    std::fstream file(filename);
    if (!file.is_open()) {
        cerr << "The file was not opened" << endl;

    }
    else if (controlOption()) {
     
        string line = "";
        while (std::getline(file, line)) {
            insArray.push_back(line);
        }
    }
    else
        cerr << "CPUprogram option value is false!!" << endl;
}

