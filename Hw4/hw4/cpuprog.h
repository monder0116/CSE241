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
class CPUProgram
{
    public:
    /*----------------Constructors------------------*/
    
        /*the option initialize with opt value */
    CPUProgram(int opt);
       /*the option initialize with zero value and readfile run*/
    CPUProgram(char *filename);
        /*the option initialize with zero !!*/
    CPUProgram();
    
    /*------------------Getters--------------*/  
    
        /*This take a line from stored list */
    string getLine(int index) const;
        /*this  return the size of list*/
    int size() const;   
        /* this return the option value*/
    int getoption() const; 
    
    /*---------------- setters ----------*/
    
        /*this read the file and add the lines to list,
         *if own option is false value,this function does not run!!*/
     void ReadFile (char *filename); 
        /*this set the option*/
     void setoption(int value);
    
private:
    
    short int option;
        /*this return the option state 
        * if it is true value return true else false*/
    bool controlOption() const;
    /*this vector stored all lines in given file */
    vector<string> insArray;

};


#endif	/* CPUPROG_H */

