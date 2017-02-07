/* 
 * File:   dinamicarray.h
 * Author: onder
 *
 * Created on November 26, 2016, 2:05 PM
 */

#ifndef DINAMICARRAY_H
#define	DINAMICARRAY_H
#include <iostream>
#include "dinamicmap.h"
using namespace std;
template <class T,class P>
class Dynamicmap{
private:
    pair<T,P> *array;
    int size;
    int capasity;
public:
    void addline(const T& ikey,const P& ivalue);
    void resizeArr(int multiplier=2);
    bool full()const;
    void removelast();
    int findindex(const pair<T,P>& search)const;
    const pair<T,P> operator[](int index)const;
    int getsize()const;
    int getcapasity()const;
    
    Dynamicmap();
    Dynamicmap(int cap);
    Dynamicmap(const Dynamicmap<T,P>& other);
    Dynamicmap& operator =(const Dynamicmap<T,P>& other);
    ~Dynamicmap();

};

#include "dinamicmap.cpp"

#endif	/* DINAMICARRAY_H */

