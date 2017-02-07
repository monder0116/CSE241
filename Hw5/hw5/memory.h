/* 
 * File:   memory.h
 * Author: onder
 *
 * Created on October 30, 2016, 1:28 PM
 * 
 *
 */
#include <iostream>

#ifndef MEMORY_H
#define	MEMORY_H
#ifndef memorySize
#define memorySize 50
#endif
#include <iostream>
using namespace std;
class Memory {
    
public:
    /*-----------Constructures---------------*/
    
        /* all memories initialize to zero 
         * and set the option to opt */
    Memory(int opt); 
        /* all memories initialize  with zero 
         * also the option initialized with zero!!*/
    Memory();
    
    /*--------------Getters -------------------*/
        
        /*This return memory value which given index*/
    int getMem(int index) const;
        /*this reurn the option value*/
    int getOption() const;
        /* This control the option , 
         * if the option false  return false*/
    bool controlOption() const;
    /*--------------Setters -------------------*/
        /*set the option but if value is not equal these (0,1,2),
         * the CPU will halt!*/
    void setOption(int value);
        /* set the memory value which given index*/
    void setMem(int index, unsigned int value); 
    /*------------Functions-------------------*/
        /*This print the all memory value*/
    void printAll()const;
private:
    unsigned int memArray[memorySize];
    short int option;


};
#endif	/* MEMORY_H */