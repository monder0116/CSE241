#include "cpuprogramdyn.h"
namespace cpu {

    CPUProgramDyn::CPUProgramDyn(int opt) {
        setoption(opt);
    }

    CPUProgramDyn::CPUProgramDyn() {
        setoption(0);
    }

    CPUProgramDyn::CPUProgramDyn(const char *filename) {
        setoption(0);
        ReadFile(filename);
    }

    CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn& other) {
        insArray = other.insArray;
        option = other.option;
    }

    /*---------------------------Getters-----------------------*/
    int CPUProgramDyn::getoption() const {
        return option;
    }

    string CPUProgramDyn::getLine(int index) const {
        if (!controlOption()) {
            cerr << "CPUprogram option value is false!!" << endl;
        }
        else if (index < size() && index >= 0)
            return insArray[index];
        else {
            cerr << "The index value is false!!" << endl;
        }

        return "";
    }

    int CPUProgramDyn::size() const {
        return insArray.getsize();
    }

    bool CPUProgramDyn::controlOption()const {
        if (option < 0 || option > 2) {
            return false;
        }
        else
            return true;

    }

    /*-------------------Setters --------------------*/
    void CPUProgramDyn::setoption(int value) {
        if (value < 0 || value > 2) {
            cerr << "CPUProg option value is false!!" << endl;
            return;
        }
        else
            option = value;
    }

    void CPUProgramDyn::ReadFile(const char *filename) {
        std::fstream file(filename);
        if (!file.is_open()) {
            cerr << "The file was not opened" << endl;
            return;
        }
        else if (controlOption()) {
            string line = "";
            while (std::getline(file, line)) {
                insArray.addline(line);
            }
        }
        else {
            cerr << "CPUprogram option value is false!!" << endl;
            return;
        }

    }

    /*------------operator overloading ------------*/

    /*index operator[]*/
    string CPUProgramDyn::operator[] (int index) const {
        string str = getLine(index);
        return str;

    }

    /*plus operator+*/
    const CPUProgramDyn CPUProgramDyn::operator+(string line) const {
        CPUProgramDyn yeni(*this);
        if (line != "")
            yeni.insArray.addline(line);
        else {
            cerr << "Line must be filed!!" << endl;
            CPUProgramDyn temp;
            return temp;
        }

        return yeni;
    }

    const CPUProgramDyn operator +(string line, const CPUProgramDyn& prg) {
        CPUProgramDyn yeni(prg);
        if (line != "")
            yeni.insArray.addline(line);
        else {
            cerr << "Line must be filled!!" << endl;
            CPUProgramDyn temp;
            return temp;
        }

        return yeni;
    }

    const CPUProgramDyn CPUProgramDyn::operator+(const CPUProgramDyn& second)const {
        CPUProgramDyn yeni(*this);
        for(int i = 0; i < second.size(); i++) {
            yeni.insArray.addline(second[i]);
        }
        return yeni;
    }

    CPUProgramDyn& CPUProgramDyn::operator+=(string line) {
        if (line != "")
            insArray.addline(line);
        else 
            cerr << "Line must be filled!!" << endl;

        return *this;
    }

    /*Compare operartors*/
    bool CPUProgramDyn::operator==(const CPUProgramDyn& second)const {
        if (size() == second.size())
            return true;
        return false;
    }

    bool CPUProgramDyn::operator!=(const CPUProgramDyn& second)const {
        return !(*this == second);
    }

    bool CPUProgramDyn::operator<(const CPUProgramDyn& second)const {
        if (second.size() > size())
            return true;
        return false;

    }

    bool CPUProgramDyn::operator>(const CPUProgramDyn& second)const {
        if (second.size() < size())
            return true;
        return false;

    }

    bool CPUProgramDyn::operator<=(const CPUProgramDyn& second)const {
        if (second.size() >= size())
            return true;
        return false;

    }

    bool CPUProgramDyn::operator>=(const CPUProgramDyn& second)const {
        if (second.size() <= size())
            return true;
        return false;

    }

    ostream& operator<<(ostream& output, const CPUProgramDyn& program) {

        for(int i = 0; i < program.size(); i++) {
            output << program[i] << endl;
        }

        return output;

    }

    CPUProgramDyn& CPUProgramDyn::operator --() {
        if (size() > 0)
            insArray.removelast();
        else 
            cerr << "The array is not filled!!" << endl;
        return *this;
    }

    const CPUProgramDyn CPUProgramDyn::operator --(int ignore) {
        CPUProgramDyn temp(*this);
        if (size() > 0)
            insArray.removelast();
        else
            cerr << "The array is not filled!!" << endl;
        return temp;
    }

    const CPUProgramDyn CPUProgramDyn::operator()(int begin, int end) const {
        if (begin >= 0 && end < size()) {
            CPUProgramDyn temp(option);
            for(int i = begin; i <= end; i++) {
                temp.insArray.addline(getLine(i));
            }
            return temp;
        }
        else {
            cerr << "The func.call index parameters are false!!" << endl;
            CPUProgramDyn temp;
            return temp;
        }
    }
}