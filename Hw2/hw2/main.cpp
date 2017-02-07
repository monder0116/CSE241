/* 
 * File:   main.cpp
 * Author: MEHMET ÖNDER
 * School Number:131044076
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#define CommandNumber 6
#define RegisterNum 5
#define structSize 200
#define memorySize 50
using namespace std;
struct CommandType {
    string Cname;
    int ParmNum;
    string parm1;
    string parm2;
    int line;

};
/* This function take the power which given as parametry*/
int power(int base, int pow);
/*This function compare the command with register names*/
bool isRegister(string command);
/* this function control the string to valid for a memory address  */
bool isMemoryAddress(string line);
/*this function control the line to find many unexpected characters for example 
       mov r1 ,,r2 or 'mov r1,r2  if the line unvalid return false else true  */
bool FirstLineControl(string line);
/* this function compare the instruction names which are named in file and
        static declared names*/
bool controlCommandS(string line);
/* this function control the subline to find ';' char or '' , 
 * if find this return true else there is a character return false */
bool ControlSemicolon(string line);
/* this function  take the world until to ',' ';' ' ' characters ,this is 
  run as recursive when return string is null or "\t"   */
string parseLine(string line, int *lastpoint);
/* this function convert the string to integer based on the value ignore the 
 other characters*/
int convertToint(string str);
/* this function convert the char to integer based on the value ignore the 
  other characters*/
int convertToint(char str);
/* this function read the instruction and registers from the file 
   and fiil the array which is given by the main and keep the array size
 * with *size then return the array*/
CommandType* TakeCommands(CommandType *array, int *size, char *filename);
/* this function do the instructions which taken from array */
void DoJobs(CommandType *array, int size, int option, int *regs, unsigned int *memories);
/* this function Convert the string to uppercase*/
void convertToUpper(string& line);
/* this function find the comma character if it is found return true else false*/
bool findComma(string line);
/* this function control the string to each character is integer , 
 * if it isnt return false else return true   */
bool isonlyinteger(string line);
/*this function print the registers*/
void printRegs(int *arr);
/*this function print the memories*/
void printMem(unsigned int *arr);
/*
 * 
 */
int main(int argc, char **argv) {
    CommandType array[structSize];
    CommandType *newArray;
    int arraySize = 0;
    int regs[5];
    unsigned int memories[memorySize];
    if(argc!=3)
    {
       cerr << "The parameters are not valid"<<endl;
       return -1;
    }
    for(int i = 0; i < RegisterNum; i++) {
        regs[i] = 0;
    }
    for(int i = 0; i < memorySize; i++) {
        memories[i] = 0;
    }
    newArray = TakeCommands(array, &arraySize, argv[1]);
    int option = convertToint(argv[2]);
    if (newArray != NULL)
        DoJobs(newArray, arraySize,option, regs, memories);
    return 0;
}

/*This function compare the command with register names*/
bool isRegister(string command) {
    string regNames[5] = {"R1", "R2", "R3", "R4", "R5"};
    for(int i = 0; i < RegisterNum; i++) {
        if (regNames[i] == command) {
            return true;
        }
    }
    return false;
}
/*this function control the line to find many unexpected characters for example 
               mov r1 ,,r2 or 'mov r1,r2  if the line unvalid return false else true  */
bool FirstLineControl(string line) {
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

/* this function do the instructions which taken from array */
void DoJobs(CommandType *array, int size, int option, int *regs, unsigned int *memories) {
    bool CommandWork = true;
    /* if the jump instruction run, the index will be change so this control the
     * statement */
    bool jump = false;
    /* keep the jump index  when it run*/
    int jumpIndex = 0;
    /* the halt instruction run , the loop will stop*/
    bool halt = false;

    if (option < 0 || option > 2) {
        cerr << "The option is false" << endl;
        return;
    }
    for(int i = 0; i < size && CommandWork && !halt; i++) {
        CommandWork = false;
        jump = false;
        halt = false;
        jumpIndex = 0;
        if (array[i].Cname == "PRN") {
            if (isRegister(array[i].parm1)) {
                int parm1Num = convertToint(array[i].parm1[1]);
                cout << regs[parm1Num - 1] << endl;
                CommandWork = true;
            }
            else if (isMemoryAddress(array[i].parm1)) {
                int parm1Num = convertToint(array[i].parm1);
                cout << memories[parm1Num] << endl;
                CommandWork = true;
            }
            else {
                cout << array[i].parm1 << endl;
                CommandWork = true;
            }
        }
        else if (array[i].Cname == "ADD") {
            if (array[i].parm1 == "" || array[i].parm2 == "")
                CommandWork = false;
            else if (isRegister(array[i].parm1) && isRegister(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1[1]) - 1;
                int parm2Num = convertToint(array[i].parm2[1]) - 1;
                regs[parm1Num ] += regs[parm2Num ];
                CommandWork = true;
            }
            else if (isRegister(array[i].parm1) && isMemoryAddress(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1) - 1;
                int parm2Num = convertToint(array[i].parm2);
                regs[parm1Num] += memories[parm2Num];
                CommandWork = true;
            }
            else if (isRegister(array[i].parm1) && isonlyinteger(array[i].parm2)) {
                int constant = convertToint(array[i].parm2);
                int reg1Num = convertToint(array[i].parm1[1]);
                regs[reg1Num - 1] += constant;
                CommandWork = true;
            }
        }
        else if (array[i].Cname == "SUB") {
            if (array[i].parm1 == "" || array[i].parm2 == "")
                CommandWork = false;
            else if (isRegister(array[i].parm1) && isRegister(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1[1]) - 1;
                int parm2Num = convertToint(array[i].parm2[1]) - 1;
                regs[parm1Num] -= regs[parm2Num ];
                CommandWork = true;
            }
            else if (isRegister(array[i].parm1) && isMemoryAddress(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1) - 1;
                int parm2Num = convertToint(array[i].parm2);
                regs[parm1Num] -= memories[parm2Num];
                CommandWork = true;
            }
            else if (isRegister(array[i].parm1) && isonlyinteger(array[i].parm2)) {
                int constant = convertToint(array[i].parm2);
                int reg1Num = convertToint(array[i].parm1[1]);
                regs[reg1Num - 1] -= constant;
                CommandWork = true;
            }
        }
        else if (array[i].Cname == "JPN") {
            if (array[i].parm1 == "" || array[i].parm2 == "")
                CommandWork = false;
            else if (isRegister(array[i].parm1) && isonlyinteger(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1[1]);
                int parm2Num = convertToint(array[i].parm2);
                if (parm2Num > 0) {
                    if (regs[parm1Num - 1] <= 0) {
                        for(int j = 0; j < size; j++) {
                            if (array[j].line == parm2Num) {
                                jumpIndex = j;
                                jump = true;
                            }
                        }
                    }
                    CommandWork = true;
                }
            }
        }
        else if (array[i].Cname == "JMP") {
            if (array[i].ParmNum == 1 && isonlyinteger(array[i].parm1) &&
                    array[i].parm1 != "") {
                /*find the index which line number is taken number*/
                int line = convertToint(array[i].parm1);
                if (line > 0) {
                    for(int j = 0; j < size; j++) {
                        if (array[j].line == line) {
                            jumpIndex = j;
                            jump = true;
                        }
                    }
                    CommandWork = true;
                }

            }
            else if (array[i].ParmNum == 2 && isRegister(array[i].parm1) &&
                    isonlyinteger(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1[1]);
                int parm2Num = convertToint(array[i].parm2);
                if (parm2Num > 0) {
                    if (regs[parm1Num - 1] == 0) {
                        for(int j = 0; j < size; j++) {
                            if (array[j].line == parm2Num) {
                                jumpIndex = j;
                                jump = true;
                            }
                        }
                    }
                    CommandWork = true;
                }
            }
        }
        else if (array[i].Cname == "MOV") {
            if (array[i].parm1 == "" || array[i].parm2 == "")
                CommandWork = false;
            else if (isRegister(array[i].parm1) && isMemoryAddress(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1) - 1;
                int parm2Num = convertToint(array[i].parm2);
                memories[parm2Num] = regs[parm1Num];
                CommandWork = true;

            }
            else if (isMemoryAddress(array[i].parm1) && isRegister(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1);
                int parm2Num = convertToint(array[i].parm2) - 1;
                regs[parm2Num] = memories[parm1Num];
                CommandWork = true;
            }
            else if (isMemoryAddress(array[i].parm1) && isonlyinteger(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1);
                int parm2Num = convertToint(array[i].parm2);
                if (parm2Num >= 0) {
                    memories[parm1Num] = parm2Num;
                    CommandWork = true;
                }
                else
                    CommandWork = false;

            }
            else if (isRegister(array[i].parm1) && isRegister(array[i].parm2)) {
                int parm1Num = convertToint(array[i].parm1[1]);
                int parm2Num = convertToint(array[i].parm2[1]);
                regs[parm2Num - 1] = regs[parm1Num - 1];
                CommandWork = true;
            }
            else if (isRegister(array[i].parm1) && isonlyinteger(array[i].parm2)) {
                int constant = convertToint(array[i].parm2);
                int reg1Num = convertToint(array[i].parm1[1]);
                regs[reg1Num - 1] = constant;
                CommandWork = true;
            }
        }
        else if (array[i].Cname == "HLT") {
            halt = true;
            CommandWork = true;
            printRegs(regs);
            printMem(memories);
            
        }
        if ((option == 1 || option == 2 ) && CommandWork ) {
            if (array[i].ParmNum == 0)
                cout << array[i].Cname << " -";
            else if (array[i].ParmNum == 1)
                cout << array[i].Cname << " " << array[i].parm1 << "-";
            else
                cout << array[i].Cname << " " << array[i].parm1 << "," << array[i].parm2 << "-";
            printRegs(regs);
            /* we subtraction 1 because 
             *'i' will be incremented at the begin of the loop*/
        }
        if (option == 2 && CommandWork)
            printMem(memories);
            
        /*jump index will increase at the begin of the loop so i decrease that*/
        if (jump)
            i = jumpIndex - 1;
        if (!CommandWork) {
            cerr << array[i].line << "th line parameters are not valid!!" << endl;
            return;
        }
    }
}
void printMem(unsigned int *arr)
{
    for(int i = 0; i < memorySize; i++) {
                cout << "Mem" << i << "=" << arr[i] <<"," ;
                if((i+1)%5==0)
                    cout <<endl;
                
            }
              for(int i=0;i<6;i++)
                cout<< "-------";
            cout <<endl;
}
void printRegs(int *arr){
    
            for(int reg = 0; reg < RegisterNum; reg++) {
                cout << "Reg" << reg + 1 << "=" << arr[reg];
                if (reg != RegisterNum - 1)
                    cout << ",";
                else
                    cout << endl;
            }
    
}
/* this function convert the char to integer based on the value ignore the 
  other characters*/
int convertToint(char str) {
    if (str != '\0')
        return str - '0';
    else
        return -1;
}

/* this function convert the string to integer based on the value ignore the 
   other characters*/
int convertToint(string str) {
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
        int basamakson = basamak;
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

/*this function take the power */
int power(int base, int pow) {
    int result = 1;
    if (base == 0)
        return 0;
    for(int i = 0; i < pow; i++) {
        result *= base;
    }
    return result;
}

/* this function compare the instruction names which are named in file and
        static declared names*/
bool controlCommandS(string line) {
    int i = 0;
    string Processes[] = {"MOV", "ADD", "SUB", "JMP", "PRN", "HLT"};
    for(i = 0; i < CommandNumber; i++) {
        if (Processes[i] == line)
            return true;
    }
    return false;
}

/* this function Convert the string to uppercase*/
void convertToUpper(string& line) {
    for(int i = 0; i < line.length(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            line[i] -= 'a' - 'A';
        }
    }
}

/* this function read the instruction and registers from the file 
   and fiil the array which is given by the main and keep the array size
 * with *size then return the array, if there is a wrong things return null*/
CommandType* TakeCommands(CommandType *array, int *arraySize, char *filename) {
    string line = "";
    string command = "";
    string parm1 = "", parm2 = "";
    int lastPoint = 0;
    int lineNumber = 1;
    bool error = false;
    bool firstControl = true;
    fstream file(filename);
    if (!file.is_open()) {
        cerr << "File was not opened" << endl;
        return NULL;
    }
    while (getline(file, line) && !error) {
        lastPoint = 0;
        firstControl = FirstLineControl(line);
        command = parseLine(line, &lastPoint);
        convertToUpper(command);
        error = false;
        /* if the command is valid , take the parametries then fiil it to array*/
        if (!firstControl) {
            error = true;
        }/* prn instruction take only a paramety*/
        else if (command == "PRN") {
            parm1 = parseLine(line, &lastPoint);
            convertToUpper(parm1);
            if (ControlSemicolon(&line[lastPoint])) {
                array[*arraySize].ParmNum = 1;
                array[*arraySize].Cname = command;
                array[*arraySize].parm1 = parm1;
                array[*arraySize].parm2 = "";
                array[*arraySize].line = lineNumber;
                (*arraySize)++;
            }
            else
                error = true;
        }/* This instructions are take two parametry*/
        else if (command == "MOV" || command == "ADD" || command == "SUB"
                || command == "JPN") {
            parm1 = parseLine(line, &lastPoint);
            convertToUpper(parm1);
            if (!ControlSemicolon(&line[lastPoint]) && findComma(&line[lastPoint])) {
                parm2 = parseLine(line, &lastPoint);
                convertToUpper(parm2);
                if (ControlSemicolon(&line[lastPoint])) {
                    array[*arraySize].ParmNum = 2;
                    array[*arraySize].Cname = command;
                    array[*arraySize].parm1 = parm1;
                    array[*arraySize].parm2 = parm2;
                    array[*arraySize].line = lineNumber;
                    (*arraySize)++;
                }
                else {
                    error = true;
                }
            }
            else {
                error = true;
            }

        }/* jmp instruction take one or two parametry*/
        else if (command == "JMP") {
            parm1 = parseLine(line, &lastPoint);
            convertToUpper(parm1);

            if (ControlSemicolon(&line[lastPoint])) {
                array[*arraySize].ParmNum = 1;
                array[*arraySize].Cname = command;
                array[*arraySize].parm1 = parm1;
                array[*arraySize].parm2 = "";
                array[*arraySize].line = lineNumber;
                (*arraySize)++;
            }
            else {
                parm2 = parseLine(line, &lastPoint);
                convertToUpper(parm2);
                if (ControlSemicolon(&line[lastPoint])) {
                    array[*arraySize].ParmNum = 2;
                    array[*arraySize].Cname = command;
                    array[*arraySize].parm1 = parm1;
                    array[*arraySize].parm2 = parm2;
                    array[*arraySize].line = lineNumber;
                    (*arraySize)++;
                }
                else {
                    error = true;
                }
            }
        }/* hlt does not take any parametry*/
        else if (command == "HLT") {
            if (ControlSemicolon(&line[lastPoint])) {
                array[*arraySize].ParmNum = 0;
                array[*arraySize].Cname = command;
                array[*arraySize].parm1 = "";
                array[*arraySize].parm2 = "";
                array[*arraySize].line = lineNumber;
                (*arraySize)++;
            }
            else
                error = true;
        }
        else if (command != "") {
            error = true;
        }
        if (error) {
            cerr << lineNumber << "th. line is not readable" << endl;
            return NULL;
        }

        lineNumber++;
    }
    file.close();
    return array;
}

/* this function  take the world until to ',' ';' ' ' characters,this is 
 *run as recursive when return string is null or "\t" */
string parseLine(string line, int *point) {
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

/* this function control the subline to find ';' char or end of line 
 * if find this return true else there is a character return false */
bool ControlSemicolon(string line) {
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

bool isMemoryAddress(string line) {
    if (line[0] == '#' && isonlyinteger(&line[1])) {
        int index = convertToint(line);
        if (index < memorySize) {
            return true;
        }
    }
    return false;
}
bool isonlyinteger(string line) {
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
bool findComma(string line) {
    for(int i = 0; i < line.length(); i++) {
        if (line[i] == ',') 
            return true;
        else if (line[i] != ' ' && line[i] != '\t') 
            return false;
    }
}