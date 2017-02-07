
#include "BigramDyn.h"

template<class A>
void BigramDyn<A>::readFile(string filename) throw (Exception) {
    fstream file(filename);
    if(!file.is_open())
        throw Exception("File does not opened!");
    
    string input1 = "";
    Dynamicarray<A> temparr;
    int tsize = 0;
    while (file >> input1) {
        if (isdouble(input1) && getDataType() == 3)
            tsize++;
        else if (isint(input1) && getDataType() == 1)
            tsize++;
        else if (getDataType() == 2)
            tsize++;
        else
            throw Exception("Bad data");

    }
    if (tsize < 2)
        throw Exception("Short data for Bigram");
    file.clear();
    file.seekg(0, ios::beg);
    A temp;
    while (file >> temp) {
        temparr.addline(temp);

    }
    for(int i = 0; i < temparr.getsize() - 1; i++) {
        A d1 = temparr[i];
        A d2 = temparr[i + 1];
        pair<A, A> temp(d1, d2);
        int found = keyarr.findindex(temp);
        if (found == -1) {
            keyarr.addline(temp);
            valuearr.addline(1);
        }
        else {
            valuearr.setValue(found,valuearr[found] + 1);
        }
    }

    totalgram = tsize - 1;

}

template<class A>
int BigramDyn<A>::numGrams()const {
    return totalgram;
}

template<class A>
int BigramDyn<A>::numOfGrams(A parm1, A parm2) const {
    int found = keyarr.findindex(make_pair(parm1, parm2));
    if (found != -1) {
        return valuearr[found];

    }
    else {
        return 0;
    }
}

template<class A >
std::pair<A, A> BigramDyn<A>::maxGrams()const {

    int max = valuearr[0];
    int index = 0;
    for(int i = 0; i < valuearr.getsize(); i++) {
        if (valuearr[i] > max) {
            index = i;
        }

    }

    return keyarr[index];

}

template<class A>
void BigramDyn<A>::print(ostream & out) const {
    auto tempkeys=keyarr;
    auto tempvalues=valuearr;
    for(int i = 0; i < tempvalues.getsize(); i++) {
        for(int j = i; j < tempvalues.getsize(); j++) {
            if (tempvalues[i] < tempvalues[j]) {
                int temp1 = tempvalues[i];
                tempvalues.setValue(i , tempvalues[j]);
                tempvalues.setValue(j, temp1);
                auto temp2 = tempkeys[i];
                tempkeys.setValue(i , tempkeys[j]);
                tempkeys.setValue(j, temp2);
            }


        }



    }



    for(int i = 0; i < tempkeys.getsize(); i++) {
        out << tempkeys[i].first << "," << tempkeys[i].second << endl;
    }



}

template<class A>
int BigramDyn<A>::getDataType()const {
    return datatype;


}
