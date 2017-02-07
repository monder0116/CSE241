#include "CPU.h"

/*----------------------------constructors--------------------*/
CPU::CPU(char *opt) {

    setOption(opt);
    setPC(1);
    setHalt(false);
    for(int i = 1; i < register_Count + 1; i++) {
        setReg(i, 0);
    }
}

/*---------------------------Getters------------------------------*/
int CPU::getReg(int index) const{
    if (index >= 1 && index <= register_Count)
        return registers[index - 1];
    cerr << "Invalid register index !!" << endl;
    return -9999;

}

int CPU::getPC() const{
    return PC;

}

int CPU::getOption()const {
    return option;

}

bool CPU::gethalted()const {
    return halt;
}

/*-----------------------------------Setters----------------------------------*/
void CPU::setOption(char* optt) {
    int opt = convertToint(optt);
    if (opt < 3 && opt >= 0)
        option = opt;
    else {
        cerr << "The option is false" << endl;
        setHalt(true);
    }
}

/*set the register which is given index-1!!!*/
void CPU::setReg(int index, int value) {
    registers[index - 1] = value;
}

void CPU::setPC(int value) {

    PC = value;
}

void CPU::setHalt(bool value) {
    halt = value;
}

/*functions */
void CPU::print() const{
    for(int i = 1; i < register_Count + 1; i++) {
        if (i != register_Count)
            cout << "REG" << i << "=" << getReg(i) << ",";
        else
            cout << "REG" << i << "=" << getReg(i) << endl;
    }
    cout<<"Program Counter=" <<getPC()<<endl;
}

void CPU::execute(string line) {
    if (!firstLineControl(line)) {
        cerr << getPC() << ".th line is not readable!" << endl;
        setHalt(true);
        return;
    }
    if (line == "") {
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
    else if (command == "MOV" || command == "ADD" || command == "SUB") {
        parm1 = parseLine(line, &lastPoint);
        convertToUpper(parm1);
        if (!ControlSemicolon(&line[lastPoint])) {
            parm2 = parseLine(line, &lastPoint);
            convertToUpper(parm2);
            if (ControlSemicolon(&line[lastPoint])) {
                if (command == "MOV")
                    work = doMOV(parm1, parm2);
                else if (command == "ADD")
                    work = doADD(parm1, parm2);
                else if (command == "SUB")
                    work = doSUB(parm1, parm2);
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
            parm2 = parseLine(line, &lastPoint);
            convertToUpper(parm2);
            if (ControlSemicolon(&line[lastPoint])) {
                work = doJMP(parm1, parm2);

            }
            else
                work = false;
        }
    }/* HLT does not take any parametry*/
    else if (command == "HLT") {
        if (ControlSemicolon(&line[lastPoint])) {
            setHalt(true);
            work = true;
            if (getOption() == 1)
                cout << "HLT " << endl;

        }
        else
            work = false;
    }
    else if (command != "") {
        work = false;
    }
    if (!work) {
        cerr << getPC() << ".th line is not readable!" << endl;
        setHalt(true);
        return;
    }
    else {

        if (getOption() == 1 || command == "HLT")
            print();
    }
    setPC(getPC() + 1);
}

/*----------------------Instruction Functions-------------------------*/

bool CPU::doMOV(string parm1, string parm2) {
    bool CommandWork = false;
    if (parm1 == "" || parm2 == "")
        CommandWork = false;
    else if (isRegister(parm1) && isRegister(parm2)) {
        int parm1Num = convertToint(parm1[1]);
        int parm2Num = convertToint(parm2[1]);
        setReg(parm2Num, getReg(parm1Num));
        CommandWork = true;
        if (getOption() == 1)
            cout << "MOV " << parm1 << "," << parm2 << endl;
    }
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int constant = convertToint(parm2);
        int reg1Num = convertToint(parm1[1]);
        setReg(reg1Num, constant);
        CommandWork = true;
        if (getOption() == 1)
            cout << "MOV " << parm1 << "," << parm2 << endl;
    }
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
        if (getOption() == 1)
            cout << "ADD " << parm1 << "," << parm2 << endl;
    }
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int constant = convertToint(parm2);
        int reg1Num = convertToint(parm1[1]);
        setReg(reg1Num, getReg(reg1Num) + constant);
        CommandWork = true;
        if (getOption() == 1)
            cout << "ADD " << parm1 << "," << parm2 << endl;
    }
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
        if (getOption() == 1)
            cout << "SUB " << parm1 << "," << parm2 << endl;
    }
    else if (isRegister(parm1) && isonlyinteger(parm2)) {
        int constant = convertToint(parm2);
        int reg1Num = convertToint(parm1[1]);
        setReg(reg1Num, getReg(reg1Num) - constant);
        CommandWork = true;
        if (getOption() == 1)
            cout << "SUB " << parm1 << "," << parm2 << endl;
    }
    return CommandWork;
}

bool CPU::doPRN(string parm1) {
    bool CommandWork = false;
    if (isRegister(parm1)) {
        int parm1Num = convertToint(parm1[1]);
        cout << getReg(parm1Num) << endl;
        CommandWork = true;
        if (getOption() == 1)
            cout << "PRN " << parm1 << endl;
    }
    else {
        if (getOption() == 1)
            cout << "PRN " << parm1 << endl;
        cout << parm1 << endl;
        CommandWork = true;
    }
    return CommandWork;

}

bool CPU::doJMP(string parm1) {
    bool CommandWork = false;
    if (isonlyinteger(parm1)) {
        /*find the index which line number is taken number*/
        int linenumber = convertToint(parm1);
        if (linenumber > 0) {
            setPC(linenumber - 1);
            CommandWork = true;

        }
        if (getOption() == 1)
            cout << "JMP " << parm1 << endl;
    }

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
        if (getOption() == 1)
            cout << "JMP " << parm1 << "," << parm2 << endl;
    }
    return CommandWork;

}

/*---------------------------Helper Functions--------------------------------*/
bool CPU::isonlyinteger(string line)const {
    if (line[0] == '-') {
        for(int i = 1; i < line.length(); i++) {
            if (!(line[i] >= '0' && line[i] <= '9'))
                return false;
        }
    }
    else {
        for(int i = 0; i < line.length(); i++) {
            if (!(line[i] >= '0' && line[i] <= '9'))
                return false;
        }
    }
    return true;
}

bool CPU::ControlSemicolon(string line)const {
    bool Semicolon = true;
    for(int i = 0; i < line.length() && Semicolon; i++) {
        if (line[i] == ';') {
            return true;
        }
            /*if the char is not valid to this condition return false*/
        else if ((line[i] != ' ' && line[i] != '\t' && line != "")) {
            Semicolon = false;
            return Semicolon;
        }
    }
    return Semicolon;
}

void CPU::convertToUpper(string& line)const {
    for(int i = 0; i < line.length(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            line[i] -= 'a' - 'A';
        }
    }

}

string CPU::parseLine(string line, int *point)const {
    string seperated = "";
    int a = *point;
    for(int i = a; i <= line.length(); i++) {
        /*until to this characters */
        if (line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == ';' || line[i] == '\0') {
            seperated = line.substr(a, i - *point);
            (*point) = i;
            i = line.length(); /* this is to exit from the loop*/
        }
    }
    if (line[*point] == ';') {
        *point = line.length();
    }
    while ((seperated == " " || seperated == "/t" || seperated == "") && *point <= line.length()) {
        (*point)++;
        return parseLine(line, point);
    }
    return seperated;
}

bool CPU::firstLineControl(string line) const{
    /* the loop return until to find first character which is not the 
     *  equal to condition */
    for(int i = 0; i < line.length(); i++) {
        if (line[i] != '\0' && line[i] != ' ' && line[i] != '\t') {
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') ||
                    line[i] == ';') {
                i = line.length();
            }
            else {
                return false;
            }
        }
    }
    /* find the ';' commend character index */
    int commandIndex = line.length();
    for(int i = 0; i < line.length(); i++) {
        if (line[i] == ';') {
            commandIndex = i;
            i = line.length();
        }
    }
    /* count the ',' character until to command character  */
    int virgulSayi = 0;
    for(int i = 0; i < commandIndex; i++) {
        if (line[i] == ',')
            virgulSayi++;
    }
    if (virgulSayi < 2)
        return true;
    else
        return false;
}

bool CPU::isRegister(string command)const {
    string regNames[5] = {"R1", "R2", "R3", "R4", "R5"};
    for(int i = 0; i < register_Count; i++) {
        if (regNames[i] == command) {
            return true;
        }
    }
    return false;
}

int CPU::convertToint(char str)const {
    if (str >= '0' && str <= '9')
        return str - '0';
    else
        return -1;
}

int CPU::convertToint(string str)const {
    int basamak = 0;
    int sayi = 0;
    int state = +1;
    /* Find the Number of places */
    for(int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            basamak++;
        else if (str[i] == '-')
            state = -1;
    }
    /* turn the char to int if it is number */
    if (basamak != 0) {
        for(int i = 0; i < str.length(); i++) {
            /*ignore the other characters*/
            if (str[i] >= '0' && str[i] <= '9') {
                int rakam = str[i] - '0';
                sayi += power(10, basamak - 1) * rakam;
                basamak--;
            }
        }
    }
    else
        return 0;
    return sayi*state;

}

int CPU::power(int base, int pow) const{
    int result = 1;
    if (base == 0)
        return 0;
    for(int i = 0; i < pow; i++) {
        result *= base;
    }
    return result;
}