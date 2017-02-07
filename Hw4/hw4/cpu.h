/* 
 * File:   cpu.h
 * Author: onder
 *
 * Created on October 30, 2016, 1:34 PM
 */

#ifndef CPU_H
#define	CPU_H
#ifndef register_Count
#define register_Count 5
#endif
#include <iostream>
#include "helper.h"
#include "memory.h"
using namespace std;

class CPU{
  public:
    /*------------constructors----------*/   
        /*both of constructor initialize
         * memory member value with zero*/
      
        /*this take a option and initialize 
         * the memory option with that*/
    CPU (int opt);
        /*this does not take any parameters and the cpu and memory
         * option initialize with zero*/
    CPU();
    
    /*-----------getters-----------------*/
         /*this return the register value which index-1*/
    int getReg(int index)const;
        /*this return the program counter value*/
    int getPC()const;
        /*this return the option value*/
    int getOption()const;
        /*this return the halt state*/
    bool gethalted()const;
    /*----------setters------------s-----*/
    
        /*set the option but if value is not equal these (0,1,2),
         * the CPU will halt!*/
    void setOption(int value);
        /*this set the halt value */
    void setHalt(bool value);
         /*set the register which is given index-1!!*/
    void setReg(int index,int value);
        /*set the program counter value with for 
         * only 0,1,2 */
    void setPC(int value);
    /*---------functions ------------------*/
    
        /*Print the all registers value*/
    void print()const;
         /*if the memory or cpu option is false value 
          * the execute does not run,else the instruction run 
          *and work the commands depend on option*/
    void execute(string line,Memory& memArray);
private:
    int option;
    int PC;
    int registers[register_Count];
        /*when the execute function run the halt instruction 
          the bool set with true*/
    bool halt;
        /*when execute function run ,
         *this is initialize with reference memory ,
         *end of function the reference initialize with this */
    Memory memories;
    /*-------------------instruction functions---------------------------*/
         /* if functions are work correctly ,return true else false.
          * ex; if the instruction has a wrong type return false*/
    bool doMOV(string parm1, string parm2);
    bool doADD(string parm1, string parm2);
    bool doSUB(string parm1,string parm2);
    bool doPRN(string parm1);
    bool doJMP(string parm1);
    bool doJMP(string parm1,string parm2);
    bool doJPN(string parm1, string parm2);
         /* this control the option , if the option false 
            return false else true*/
    bool controlOption() const;

};


#endif	/* CPU_H */
