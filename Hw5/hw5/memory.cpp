#include "memory.h"


Memory::Memory(int opt) {
    setOption(opt);
    if (controlOption()) {
        for(int i = 0; i < memorySize; i++) {
            setMem(i, 0);
        }
    }
}

Memory::Memory():Memory(0) {
}

int Memory::getMem(int index) const {
    if ((index < memorySize && index >= 0) || controlOption()) {
        return memArray[index];
    }
    else
        cerr << "Wrong Memory index!!" << endl;
}

void Memory::printAll() const{
    if (controlOption()) {
        cout << "Memory Values;" << endl;
        for(int i = 1; i < memorySize + 1; ++i) {
            cout << "Mem" << i - 1 << "=" << memArray[i - 1] << ",";
            if (i % 5 == 0 && i != 0)
                cout << endl;
        }
    }
}

bool Memory::controlOption()const {
    if (option < 0 || option > 2) {
        cerr << "Memory option value is false!!" << endl;
        return false;
    }
    else
        return true;
}

int Memory::getOption() const {
    return option;
}

void Memory::setOption(int value) {
    if (value < 0 || value > 2) {
        cerr << "Setting option value is false!!" << endl;
        option = -1;
    }
    else {
        option = value;
        for(int i = 0; i < memorySize; i++) {
            setMem(i, 0);
        }
    }
}

void Memory::setMem(int index, unsigned int value) {
    if (!controlOption()) {
        cout << "Firstly,Please edit the option !!" << endl;
    }
    else if (value >= 0)
        memArray[index] = value;
    else
        cerr << "The memory value is not be negatif!!" << endl;
}