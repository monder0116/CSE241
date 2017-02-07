/* 
 * File:   CPU.h
 * Author: onder
 *
 * Created on October 18, 2016, 8:56 PM
 */

#ifndef CPU_H
#define	CPU_H
#define register_Count 5
#include <iostream>
using namespace std;

class CPU
{
    public:
    /*------------constructors----------*/    
    CPU (char* opt);/*this constructor take a option */
    /*-----------getters-----------------*/
    int getReg(int index)const;
    int getPC()const;
    int getOption()const;
    bool gethalted()const;
    /*----------setters-----------------*/
    void setOption(char* value);
    void setHalt(bool value);
    void setReg(int index,int value);
    void setPC(int value);
    /*---------functions ------------------*/
    void print()const;
    void execute(string line);
  
private:
    int option;
    int PC;
    int registers[register_Count];
    bool halt;
    /*instruction functions*/
    /* if functions are work correctly ,return true else false.
     ex; if the instruction has a wrong type return false*/
    bool doMOV(string parm1, string parm2);
    bool doADD(string parm1, string parm2);
    bool doSUB(string parm1,string parm2);
    bool doPRN(string parm1);
    bool doJMP(string parm1);
    bool doJMP(string parm1,string parm2);
    /*helper functions*/
    bool firstLineControl(string line)const;
    bool isonlyinteger(string line)const;
    bool ControlSemicolon(string line)const;
    bool isRegister(string command)const;
    int convertToint(char str) const;
      int convertToint(string str)const;
    int power(int base, int pow)const;
    string parseLine(string line, int *lastpoint)const;
    void convertToUpper(string& line) const;
  
    
};

#endif	/* CPU_H */

