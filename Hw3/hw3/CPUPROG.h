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
private:
    /*this vector stored all lines in given file */
    vector<string> insArray;
public:
    CPUProgram(char *filename);
    /*this func. read the file and add the lines to vector*/
    void readfile (char *filename);
    /*this func. return a line which index is given as parameter*/
    string getline(int index) const;
    /*this func. return the size of vector*/
    int getsize() const;  
};


#endif	/* CPUPROG_H */

