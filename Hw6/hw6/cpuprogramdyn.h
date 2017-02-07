/* 
 * File:   CPUProgramDynDyn.h
 * Author: onder
 *
 * Created on November 26, 2016, 7:47 PM
 */

#ifndef CPUPROGRAMDYN_H
#define	CPUPROGRAMDYN_H
#include <iostream>
#include <fstream>
#include "dinamicarray.h"
namespace cpu {
    using namespace std;
    class CPUProgramDyn {
    public:
        /*----------------Constructors------------------*/
        /*the option initialize with opt value */
        CPUProgramDyn(int opt);
        /*the option initialize with zero value and readfile run*/
        explicit CPUProgramDyn(const char *filename);
        /*the option initialize with zero !!*/
        CPUProgramDyn();
        /*copy constructor*/
        CPUProgramDyn(const CPUProgramDyn& other);
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


        /*that takes a CPUProgramDyn and an instruction line as a string. It returns a new
            CPUProgramDyn that has the original CPUProgramDyn with appended last line from the parameter
            string.*/
        const CPUProgramDyn operator +(string line)const;
        /*same as member operator+*/
        friend const CPUProgramDyn operator +(string line, const CPUProgramDyn& prg);


        /*takes an instruction line as a string and appends the instruction to the end of
            the program.*/
        CPUProgramDyn& operator +=(string line);


        /*that takes two programs and returns a new program that appends the second
            programs to the first one*/
        const CPUProgramDyn operator +(const CPUProgramDyn& second)const;
        /*Compare Operators*/

        /*All comparison operators compare the number of
            lines of the CPUProgramDyn*/
        bool operator==(const CPUProgramDyn& second)const;
        bool operator!=(const CPUProgramDyn& second)const;
        bool operator<(const CPUProgramDyn& second)const;
        bool operator>(const CPUProgramDyn& second)const;
        bool operator<=(const CPUProgramDyn& second)const;
        bool operator>=(const CPUProgramDyn& second)const;


        /*ostream operator overloading*/
        /*this print all instruction in insarray*/
        friend ostream& operator<<(ostream& output, const CPUProgramDyn& program);

        /*pre-post deincreament overloading*/
        /*both of them remove the last instruction line in insarray*/
        CPUProgramDyn& operator --();
        const CPUProgramDyn operator --(int ignore);

        /*function call operator overloading*/
        /*that takes two integers and returns a new program that contains the
           instructions between the given integers.*/
        const CPUProgramDyn operator()(int begin, int end) const;
    private:

        short int option;

        /*this return the option state 
         * if it is true value return true else false*/
        bool controlOption() const;
        /*this stored all lines in given file with dynamic array*/
        Dynamicstr insArray;

    };
}

#endif	/* CPUPROGRAMDYN_H */

