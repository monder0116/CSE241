#include "dinamicarray.h"

void Dynamicstr::addline(string line) {
    if (full())
        reCapasity();
    array[size] = line;
    ++size;
}

void Dynamicstr::reCapasity(int multiplier) {
    string *temp = array;
    capasity *= multiplier;
    array = new string[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = temp[i];

    }
    delete [] temp;


}

void Dynamicstr::removelast() {
   --size;
   reCapasity(1);  
}

bool Dynamicstr::full()const {
    if (size + 1 == capasity)
        return true;
    else
        return false;

}
string Dynamicstr::operator[](int index) const {
    if(index>=0 && index <size) 
        return array[index];
    else
    {
        cerr<<"Instructor array index is false"<<endl;
        return "";
    }
}

int Dynamicstr::getsize()const {
    return size;

}

Dynamicstr::Dynamicstr() {
    size = 0;
    capasity = 20;
    array = new string[capasity];


}

Dynamicstr::Dynamicstr(int cap) {
    if (cap > 1) {
        size = 0;
        capasity = cap;
        array = new string[capasity];
    }
    else {
        cerr << "Array capasity is not valid"<<endl;
        capasity = 20;
        size = 0;
        array = new string[capasity];
    }

}

Dynamicstr::Dynamicstr(const Dynamicstr& other) {
    capasity = other.capasity;
    size = other.size;
    array = new string[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = other[i];
    }
}

Dynamicstr& Dynamicstr::operator =(const Dynamicstr& other) {
    if (&other == this)
        return *this;
    if (capasity != other.capasity) {

        capasity = other.capasity;
    }
    delete [] array;
    size = other.size;
    array = new string[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = other[i];
    }
    return *this;
}

int Dynamicstr::getcapasity()const {
    return capasity;
}

Dynamicstr::~Dynamicstr() {
    delete [] array;
}
