#include "cpu.h"

CPU::CPU(int opt) : memories(opt) {
    setOption(opt);
    setPC(1);
    setHalt(false);
    if (controlOption()) {
        for(int i = 1; i <= register_Count; i++) {
            setReg(i, 0);
        }
    }
}

CPU::CPU() : memories(0) {
    setOption(0);
    for(int i = 1; i <= register_Count; i++) {
        setReg(i, 0);
    }
    setHalt(false);
    setPC(1);
}

bool CPU::controlOption()const {
    if (option < 0 || option > 2) {
        cerr << "CPU option value is false!!" << endl;
        return false;
    }
    else
        return true;
}

void CPU::execute(string line, Memory& memArray) {
    memories = memArray; /* initialize the default memory*/
    if (!firstLineControl(line)) {
        cerr << getPC() << ".th line is not readable!" << endl;
        setHalt(true);
        return;
    }
    else if (line == "") {
        return;
    }
    else if (!controlOption()) {
        return;
    }
    else if (!memories.controlOption()) {
        return;
    }
    string command = "", parm1 = "", parm2 = "";
    int lastPoint = 0;
    bool work = false;
    command = parseLine(line, &lastPoint);
    convertToUpper(command);
    if (command == "PRN") {
        parm1 = parseLine(line, &lastPoint);
        convertToUpper(parm1);
        if (ControlSemicolon(&line[lastPoint])) {
            work = doPRN(parm1);
        }
        else
            work = false;

    }/* This instructions are take two parametry*/
    else if (command == "MOV" || command == "ADD" || command == "SUB"
            || command=="JPN") {
        parm1 = parseLine(line, &lastPoint);
        convertToUpper(parm1);
        int tempppoint=lastPoint;
        if (findComma(&line[tempppoint]) && !ControlSemicolon(&line[lastPoint])) {
            parm2 = parseLine(line, &lastPoint);
            convertToUpper(parm2);
            if (ControlSemicolon(&line[lastPoint])) {
                if (command == "MOV")
                    work = doMOV(parm1, parm2);
                else if (command == "ADD")
                    work = doADD(parm1, parm2);
                else if (command == "SUB")
                    work = doSUB(parm1, parm2);
                else if(command=="JPN")
                    work=doJPN(parm1,parm2);
            }
            else
                work = false;
        }
        else
            work = false;


    }/* jmp instruction take one or two parametry*/
    else if (command == "JMP") {
        parm1 = parseLine(line, &lastPoint);
        convertToUpper(parm1);

        if (ControlSemicolon(&line[lastPoint])) {
            work = doJMP(parm1);

        }
        else {
            if(findComma(&line[lastPoint]))
            parm2 = parseLine(line, &lastPoint);
            convertToUpper(parm2);
            if (ControlSemicolon(&line[lastPoint])) {
                work = doJMP(parm1, parm2);

            }
            else
                work = false;
        }
    }
    
        /* HLT does not take any parametry*/
    else if (command == "HLT") {
        if (ControlSemicolon(&line[lastPoint])) {
            setHalt(true);
            work = true;
            if (getOption() >= 1)
                cout << "HLT " << endl;
        }
        else
            work = false;
    }
    if (!work) {
        cerr << getPC() << ".th line is not readable!" << endl;
        setHalt(true);
        return;
    }
    else {

        if (getOption() == 1)
            print();
        else if (getOption() == 2) {
            print();
            memories.printAll();
        }
        if (command == "HLT") {
            print();
            memories.printAll();
        }
    }
    memArray = memories;
    setPC(getPC() + 1);
}

/* ------------------- instruction Functions-----------------*/
bool CPU::doMOV(string parm1, string parm2) {
    bool CommandWork = false;
    if (parm1 == "" || parm2 == "")
        CommandWork = false;
    else if (isRegister(parm1) && isMemoryAddress(parm2)) {
        int parm1Num = convertToint(parm1);
        int parm2Num = convertToint(parm2);
        memories.setMem(parm2Num, getReg(parm1Num));

        CommandWork = true;

    }
    else if (isMemoryAddress(parm1) && isRegister(parm2)) {
        int parm1Num = convertToint(parm1);
        int parm2Num = convertToint(parm2);
        setReg(parm2Num, memories.getMem(parm1Num));

        CommandWork = true;
    }
    else if (isMemoryAddress(parm1) && isonlyinteger(parm2)) {
        int parm1Num = convertToint(parm1);
        int parm2Num = convertToint(parm2);
        if (parm2Num >= 0) {
            memories.setMem(parm1Num, parm2Num);
            CommandWork = true;
        }
        else
            CommandWork = false;

    }
    else if (isRegister(parm1) && isRegister(parm2)) {
        int parm1Num = convertToint(parm1[1]);
        int parm2Num = convertToint(parm2[1]);
        setReg(parm2Num, getReg(parm1Num));
        CommandWork = true;

    }
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int constant = convertToint(parm2);
        int reg1Num = convertToint(parm1[1]);
        setReg(reg1Num, constant);
        CommandWork = true;
    }
    if (getOption() >= 1)
        cout << "MOV " << parm1 << "," << parm2 << endl;

    return CommandWork;


}

bool CPU::doADD(string parm1, string parm2) {
    bool CommandWork = false;
    if (parm1 == "" || parm1 == "")
        CommandWork = false;
    else if (isRegister(parm1) && isRegister(parm2)) {
        int parm1Num = convertToint(parm1[1]);
        int parm2Num = convertToint(parm2[1]);
        setReg(parm1Num, getReg(parm1Num) + getReg(parm2Num));
        CommandWork = true;
    }
    else if (isRegister(parm1) && isMemoryAddress(parm2)) {
        int parm1Num = convertToint(parm1);
        int parm2Num = convertToint(parm2);
        setReg(parm1Num, getReg(parm1Num) + memories.getMem(parm2Num));
        CommandWork = true;
    }
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int constant = convertToint(parm2);
        int reg1Num = convertToint(parm1[1]);
        setReg(reg1Num, getReg(reg1Num) + constant);
        CommandWork = true;
    }
    if (getOption() >= 1)
        cout << "ADD " << parm1 << "," << parm2 << endl;
    return CommandWork;
}

bool CPU::doSUB(string parm1, string parm2) {
    bool CommandWork = false;
    if (parm1 == "" || parm1 == "")
        CommandWork = false;
    else if (isRegister(parm1) && isRegister(parm2)) {
        int parm1Num = convertToint(parm1[1]);
        int parm2Num = convertToint(parm2[1]);
        setReg(parm1Num, getReg(parm1Num) - getReg(parm2Num));
        CommandWork = true;

    }
    else if (isRegister(parm1) && isMemoryAddress(parm2)) {
        int parm1Num = convertToint(parm1);
        int parm2Num = convertToint(parm2);
        setReg(parm1Num, getReg(parm1Num) - memories.getMem(parm2Num));

        CommandWork = true;
    }
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int constant = convertToint(parm2);
        int reg1Num = convertToint(parm1[1]);
        setReg(reg1Num, getReg(reg1Num) - constant);
        CommandWork = true;
    }
    if (getOption() >= 1)
        cout << "SUB " << parm1 << "," << parm2 << endl;
    return CommandWork;
}

bool CPU::doPRN(string parm1) {
    bool CommandWork = false;
    if (isRegister(parm1)) {
        int parm1Num = convertToint(parm1[1]);
        cout << getReg(parm1Num) << endl;
        CommandWork = true;
    }
    else if (isMemoryAddress(parm1)) {
        int parm1Num = convertToint(parm1);
        cout << memories.getMem(parm1Num) << endl;
        CommandWork = true;
    }
    else {
        cout << parm1 << endl;
        CommandWork = true;
    }
    if (getOption() >= 1)
        cout << "PRN " << parm1 << endl;
    return CommandWork;

}

bool CPU::doJMP(string parm1) {
    bool CommandWork = false;
    if (isonlyinteger(parm1)) {
        int linenumber = convertToint(parm1);
        if (linenumber > 0) {
            setPC(linenumber - 1);
            CommandWork = true;

        }
        if (getOption() >= 1)
            cout << "JMP " << parm1 << endl;
    }

    return CommandWork;
}

bool CPU::doJPN(string parm1, string parm2) {
    bool CommandWork = false;
    if (parm1 == "" || parm2 == "")
        CommandWork = false;
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int parm1Num = convertToint(parm1[1]);
        int parm2Num = convertToint(parm2);
        if (parm2Num > 0) {
            if (registers[parm1Num - 1] <= 0) {
                setPC(parm2Num - 1);
            }
            CommandWork = true;
        }

    }
    if (getOption() >= 1)
        cout << "JPN " << parm1 << "," << parm2 << endl;
    return CommandWork;


}

bool CPU::doJMP(string parm1, string parm2) {
    bool CommandWork = false;
    if (isRegister(parm1) && isonlyinteger(parm2)) {
        int parm1Num = convertToint(parm1[1]);
        int parm2Num = convertToint(parm2);
        if (parm2Num > 0) {
            if (getReg(parm1Num) == 0) {
                setPC(parm2Num - 1);

            }
            CommandWork = true;
        }
        if (getOption() >= 1)
            cout << "JMP " << parm1 << "," << parm2 << endl;
    }
    return CommandWork;

}

/*---------------------------Getters------------------------------*/

/*This Return the register value which index -1!!*/
int CPU::getReg(int index) const {
    if (index >= 1 && index <= register_Count)
        return registers[index - 1];
    cerr << "Invalid register index !!" << endl;
    return -9999;

}

/*This return the program counter value*/
int CPU::getPC() const {
    return PC;

}

/*This return the option value*/
int CPU::getOption()const {
    return option;

}

/*This return the halt state*/
bool CPU::gethalted()const {
    return halt;
}

/*-----------------------------------Setters----------------------------------*/

/*set the option but if value is not equal these (0,1,2),
 * the CPU will halt!*/
void CPU::setOption(int opt) {

    if (opt < 3 && opt >= 0)
        option = opt;
    else {
        cerr << "Setting option value is false" << endl;
        return;
        
    }
}

/*set the register which is given index-1!!!*/
void CPU::setReg(int index, int value) {
    if(index>=1 && index<=register_Count)
    {
        registers[index - 1] = value;
    }else
    {
        cerr<<"Register index number is false"<<endl;
        return;
    }
    
}

/*set the program counter value*/
void CPU::setPC(int value) {

    PC = value;
}

/*set the halt value*/
void CPU::setHalt(bool value) {
    halt = value;
}

/*----------------functions */

/*print the all registers value*/
void CPU::print() const {
    cout << "Program Counter=" << getPC() << endl;
    for(int i = 1; i < register_Count + 1; i++) {
        if (i != register_Count)
            cout << "REG" << i << "=" << getReg(i) << ",";
        else
            cout << "REG" << i << "=" << getReg(i) << endl;
    }

}
