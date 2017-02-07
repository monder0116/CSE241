/* 
 * File:   dinamicarray.h
 * Author: onder
 *
 * Created on November 26, 2016, 2:05 PM
 */

#ifndef DINAMICARRAY_H
#define	DINAMICARRAY_H
#include <iostream>
using namespace std;
/*this class store the string with dynamic array 
 and there is a big tree and same operator to usage*/

class Dynamicstr{
private:
    string *array;
    int size;
    int capasity;
public:
    /*add the new item*/
    void addline(string line);
    /*replace the capasity of array*/
    void reCapasity(int multiplier=2);
    /*control the array to full or not*/
    bool full()const;
    /*remove the last  item*/
    void removelast();
    /*return the index value*/
    string operator[](int index)const;
    int getsize()const;
    int getcapasity()const;
    
    
    Dynamicstr();
    Dynamicstr(int cap);
    Dynamicstr(const Dynamicstr& other);
    Dynamicstr& operator =(const Dynamicstr& other);
    ~Dynamicstr();
};


#endif	/* DINAMICARRAY_H */

