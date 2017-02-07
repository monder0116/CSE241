#include "dinamicmap.h"
#ifndef DYN
#define DYN
template<class T, class P>
void Dynamicmap<T, P>::addline(const T& ikey, const P& ivalue) {
    if (full())
        resizeArr();
    array[size] = make_pair(ikey, ivalue);
    ++size;
}

template<class T, class P>
int Dynamicmap<T, P>::findindex(const pair<T, P>& search)const {
    for(int i = 0; i < size; i++) {
        if (array[i] == search)
            return i;
    }

    return -1;
}

template<class T, class P>
void Dynamicmap<T, P>::resizeArr(int multiplier) {
    pair<T, P> *temp = array;
    capasity *= multiplier;
    array = new pair<T, P>[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = temp[i];

    }
    delete [] temp;


}

template<class T, class P>
void Dynamicmap<T, P>::removelast() {
    --size;
    resizeArr(1);
}

template<class T, class P>
bool Dynamicmap<T, P>::full()const {
    if (size + 1 == capasity)
        return true;
    else
        return false;

};
template<class T, class P>
const pair<T, P> Dynamicmap<T, P>::operator[](int index) const {
    return array[index];
};

template<class T, class P>
int Dynamicmap<T, P>::getsize()const {
    return size;

}

template<class T, class P>
Dynamicmap<T, P>::Dynamicmap() {
    size = 0;
    capasity = 20;
    array = new pair<T, P>[capasity];


};

template<class T, class P>
Dynamicmap<T, P>::Dynamicmap(int cap) {
    if (cap < 2) {
        cerr << "Array capasity is not valid";
        cap = 20;
    }
    size = 0;
    capasity = cap;
    array = new pair<T, P>[capasity];
}

template<class T, class P>
Dynamicmap<T, P>::Dynamicmap(const Dynamicmap<T, P>& other) {
    capasity = other.capasity;
    size = other.size;
    array = new pair<T, P>[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = other[i];
    }
}

template<class T, class P>
Dynamicmap<T, P>& Dynamicmap<T, P>::operator =(const Dynamicmap<T,P>& other) {
    if (&other == this)
        return *this;
    if (capasity != other.capasity) {
        capasity = other.capasity;
    }
    delete [] array;
    size = other.size;
    array = new pair<T, P>[capasity];
    for(int i = 0; i < size; i++) {
        array[i] = other[i];
    }
}

template<class T, class P>
int Dynamicmap<T, P>::getcapasity()const {
    return capasity;
}

template<class T, class P>
Dynamicmap<T, P>::~Dynamicmap() {
    delete [] array;
}
#endif