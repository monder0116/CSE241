

#ifndef DYNAMICARRAY_H
#define	DYNAMICARRAY_H
#include <iostream>

using namespace std;

template <class AnonimType>

class Dynamicarray{
    
    
private:
    AnonimType *array;
    int size;
    int capasity;
public:
    void addline(AnonimType line);
    void resizeArr(int multiplier=2);
    bool full()const;
    void removelast();
    
    AnonimType operator[](int index)const;
    void setValue(int index,const AnonimType& value);
    int getsize()const;
    int getcapasity()const;
    int findindex(const AnonimType& skey)const;
    
    Dynamicarray();
    Dynamicarray(int cap);
    Dynamicarray(const Dynamicarray& other);
    Dynamicarray& operator =(const Dynamicarray& other);
    ~Dynamicarray();
};

#include "dinamicarray.cpp"

#endif	/* DYNAMICARRAY_H */

