/* 
 * File:   CPUPROG.h
 * Author: onder
 *
 * Created on October 18, 2016, 8:57 PM
 */

#ifndef CPUPROG_H
#define	CPUPROG_H
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class CPUProgram {
public:
    /*----------------Constructors------------------*/
    /*the option initialize with opt value */
    CPUProgram(int opt);
    /*the option initialize with zero value and readfile run*/
    explicit CPUProgram(const char *filename);
    /*the option initialize with zero !!*/
    CPUProgram();
    /*copy constructor*/
    CPUProgram(const CPUProgram& other);
    /*------------------Getters--------------*/

    /*This take a line from stored list */
    string getLine(int index) const;
    /*this  return the size of list*/
    int size() const;
    /* this return the option value*/
    int getoption() const;

    /*---------------- Setters ----------*/

    /*this read the file and add the lines to list,
     *if own option is false value,this function does not run!!*/
    void ReadFile(const char *filename);
    /*this set the option*/
    void setoption(int value);

    /*-----------------Operator Overloading----------------*/
    /*that takes an integer and works like the getLine function. 
     * It returns the program line as a string*/
    string operator[] (int index) const;
   
    
    /*that takes a CPUProgram and an instruction line as a string. It returns a new
        CPUProgram that has the original CPUProgram with appended last line from the parameter
        string.*/
    const CPUProgram operator +(string line)const;
   /*same as member operator+*/
    friend const CPUProgram operator +(string line, const CPUProgram& prg);
    
    
    /*takes an instruction line as a string and appends the instruction to the end of
        the program.*/
    CPUProgram& operator +=(string line);
    
    
    /*that takes two programs and returns a new program that appends the second
        programs to the first one*/
    const CPUProgram operator +(const CPUProgram& second)const;
    /*Compare Operators*/

    /*All comparison operators compare the number of
        lines of the CPUProgram*/
    bool operator==(const CPUProgram& second)const;
    bool operator!=(const CPUProgram& second)const;
    bool operator<(const CPUProgram& second)const;
    bool operator>(const CPUProgram& second)const;
    bool operator<=(const CPUProgram& second)const;
    bool operator>=(const CPUProgram& second)const;


    /*ostream operator overloading*/
    /*this print all instruction in insarray*/
    friend ostream& operator<<(ostream& output, const CPUProgram& program);

    /*pre-post deincreament overloading*/
    /*both of them remove the last instruction line in insarray*/
    CPUProgram& operator --();
    const CPUProgram operator --(int ignore);

    /*function call operator overloading*/
    /*that takes two integers and returns a new program that contains the
       instructions between the given integers.*/
    const CPUProgram operator()(int begin, int end) const;
private:

    short int option;

    /*this return the option state 
     * if it is true value return true else false*/
    bool controlOption() const;
    /*this vector stored all lines in given file */
    vector<string> insArray;

};


#endif	/* CPUPROG_H */

