#ifndef DNY
#define DNY
#include "dinamicarray.h"

template <class AnonimType>
void Dynamicarray<AnonimType>::addline(AnonimType line) {
    if (full())
        resizeArr();
    array[size] = line;
    ++size;
}

template <class AnonimType>
void Dynamicarray<AnonimType>::resizeArr(int multiplier) {
    AnonimType *temp = array;
    capasity *= multiplier;
    array = new AnonimType[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = temp[i];

    }
    delete [] temp;


}

template<class AnonimType>
void Dynamicarray<AnonimType>::setValue(int index,const AnonimType& value) {
    if(index>=0 && index<getsize())
    {
        array[index]=value;
    }
}

template<class AnonimType>
int Dynamicarray<AnonimType>::findindex(const AnonimType& skey)const {
    for(int i = 0; i < getsize(); i++) {
        if (array[i] == skey) {
            return i;

        }


    }
    return -1;



}

template <class AnonimType>
void Dynamicarray<AnonimType>::removelast() {
    --size;
    resizeArr(1);
}

template <class AnonimType>
bool Dynamicarray<AnonimType>::full()const {
    if (size + 1 == capasity)
        return true;
    else
        return false;

};
template <class AnonimType>
AnonimType Dynamicarray<AnonimType>::operator[](int index) const {
    return array[index];
};

template <class AnonimType>
int Dynamicarray<AnonimType>::getsize()const {
    return size;

}

template <class AnonimType>
Dynamicarray<AnonimType>::Dynamicarray() {
    size = 0;
    capasity = 20;
    array = new AnonimType[capasity];


};

template <class AnonimType>
Dynamicarray<AnonimType>::Dynamicarray(int cap) {
    if (cap < 2) {
        cerr << "Array capasity is not valid";
        cap = 20;
    }
    size = 0;
    capasity = cap;
    array = new AnonimType[capasity];
}

template <class AnonimType>
Dynamicarray<AnonimType>::Dynamicarray(const Dynamicarray& other) {
    capasity = other.capasity;
    size = other.size;
    array = new AnonimType[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = other[i];
    }
}

template <class AnonimType>
Dynamicarray<AnonimType>& Dynamicarray<AnonimType>::operator =(const Dynamicarray& other) {
    if (&other == this)
        return *this;
    if (capasity != other.capasity) {
        capasity = other.capasity;
    }
    delete [] array;
    size = other.size;
    array = new AnonimType[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = other[i];
    }
}

template <class AnonimType>
int Dynamicarray<AnonimType>::getcapasity()const {
    return capasity;
}

template <class AnonimType>
Dynamicarray<AnonimType>::~Dynamicarray() {
    delete [] array;
}
#endif