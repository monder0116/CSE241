/* 
 * File:   BigramDyn.h
 * Author: onder
 *
 * Created on December 25, 2016, 11:35 AM
 */

#ifndef BIGRAMDYN_H
#define	BIGRAMDYN_H
#include <iostream>
#include <fstream>
#include "Bigram.h"
#include "helper.h"
#include "dinamicarray.h"
using namespace std;
using namespace hlp;
template<class A>
class BigramDyn  : public Bigram<A>{
    public:

    BigramDyn(int tdatatype) : datatype(tdatatype) ,totalgram(0){
    }

    virtual ~BigramDyn() {

    }
    BigramDyn(const BigramDyn<A>& other) = default;
    virtual void readFile(string filename) throw (Exception);
    virtual int numGrams()const;
    virtual int numOfGrams(A parm1, A parm2)const;
    virtual pair<A, A> maxGrams()const;
    virtual void print(ostream& out)const;
    int getDataType()const;

private:
    Dynamicarray < pair<A,A> > keyarr;
    Dynamicarray<int> valuearr;
    
    int datatype;
    int totalgram;

    
    
    
};


#endif	/* BIGRAMDYN_H */

