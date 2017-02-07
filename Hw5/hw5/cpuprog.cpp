#include "cpuprog.h"

CPUProgram::CPUProgram(int opt) {
    setoption(opt);
}

CPUProgram::CPUProgram() {
    setoption(0);
}

CPUProgram::CPUProgram(const char *filename) {
    setoption(0);
    ReadFile(filename);
}

CPUProgram::CPUProgram(const CPUProgram& other) {
    insArray = other.insArray;
    option = other.option;
}

/*---------------------------Getters-----------------------*/
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

/*-------------------Setters --------------------*/
void CPUProgram::setoption(int value) {
    if (value < 0 || value > 2) {
        cerr << "The option value is false!!" << endl;
        cerr << "Please set again this!!" << endl;
        option = -1;
    }
    else
        option = value;
}

void CPUProgram::ReadFile(const char *filename) {
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

/*------------operator overloading ------------*/

/*index operator[]*/
string CPUProgram::operator[] (int index) const {
    string str = getLine(index);
    return str;

}

/*plus operator+*/
const CPUProgram CPUProgram::operator+(string line) const {
    CPUProgram yeni(*this);
    if (line != "")
        yeni.insArray.push_back(line);
    else
        cerr << "Line must be filed!!" << endl;
    return yeni;
}

const CPUProgram operator +(string line, const CPUProgram& prg) {
    CPUProgram yeni(prg);
    if (line != "")
        yeni.insArray.push_back(line);
    else
        cerr << "Line must be filled!!" << endl;
    return yeni;
}

const CPUProgram CPUProgram::operator+(const CPUProgram& second)const {
    CPUProgram yeni(*this);
    for(int i = 0; i < second.size(); i++) {
        yeni.insArray.push_back(second[i]);
    }
    return yeni;
}

CPUProgram& CPUProgram::operator+=(string line) {
    if (line != "")
        insArray.push_back(line);
    else
        cerr << "Line must be filled!!" << endl;
    return *this;
}

/*Compare operartors*/
bool CPUProgram::operator==(const CPUProgram& second)const {
    if (size() == second.size())
        return true;
    return false;
}

bool CPUProgram::operator!=(const CPUProgram& second)const {
    return !(*this == second);
}

bool CPUProgram::operator<(const CPUProgram& second)const {
    if (second.size() > size())
        return true;
    return false;

}

bool CPUProgram::operator>(const CPUProgram& second)const {
    if (second.size() < size())
        return true;
    return false;

}

bool CPUProgram::operator<=(const CPUProgram& second)const {
    if (second.size() >= size())
        return true;
    return false;

}

bool CPUProgram::operator>=(const CPUProgram& second)const {
    if (second.size() <= size())
        return true;
    return false;

}

ostream& operator<<(ostream& output, const CPUProgram& program) {

    for(int i = 0; i < program.size(); i++) {
        output << program[i] << endl;
    }

    return output;

}

CPUProgram& CPUProgram::operator --() {
    if (size() > 0)
        insArray.pop_back();
    else
        cerr << "The array is not filled!!" << endl;
    return *this;
}

const CPUProgram CPUProgram::operator --(int ignore) {
    CPUProgram temp(*this);
    if (size() > 0)
        insArray.pop_back();
    else
        cerr << "The array is not filled!!" << endl;
    return temp;
}

const CPUProgram CPUProgram::operator()(int begin, int end) const {
    if (begin >= 0 && end < size()) {
        CPUProgram temp(option);
        for(int i = begin; i <= end; i++) {
            temp.insArray.push_back(getLine(i));
        }
        return temp;
    }
    else {
        cerr << "The func.call index parameters are false!!" << endl;
        CPUProgram temp;
        return temp;
    }
}