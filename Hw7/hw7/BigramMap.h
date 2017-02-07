/* 
 * File:   BigramMap.h
 * Author: onder
 *
 * Created on December 12, 2016, 7:55 PM
 */

#ifndef BIGRAMMAP_H
#define	BIGRAMMAP_H
#include <fstream>
#include <iostream>
#include <map>
#include "dinamicarray.h"
#include "Bigram.h"
#include "helper.h"
using namespace hlp;
using namespace std;

template<class A>
class BigramMap : public Bigram<A> {
public:

    BigramMap(int tdatatype) : datatype(tdatatype) ,totalgram(0){
    }

    virtual ~BigramMap() {

    }
    BigramMap(const BigramMap<A>& other) = default;
    virtual void readFile(string filename) throw (Exception);
    virtual int numGrams()const;
    virtual int numOfGrams(A parm1, A parm2)const;
    virtual pair<A, A> maxGrams()const;
    virtual void print(ostream& out)const;
    int getDataType()const;
private:
    map<pair<A, A>, int> arr;
    int datatype;
    int totalgram;

};


#endif	/* BIGRAMMAP_H */

