#include "BigramMap.h"
#include "dinamicarray.h"

template<class A>
void BigramMap<A>::readFile(string filename) throw (Exception) {
    fstream file(filename);
    if(!file.is_open())
        throw Exception("File does not opened");
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
            throw Exception("Bad Data");

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
        if (arr.find(temp) == arr.end())
            arr.insert(make_pair(temp, 1));
        else {
            arr[temp] += 1;
        }

    }

    totalgram = tsize - 1;

}

template<class A>
int BigramMap<A>::numGrams()const {
    return totalgram;
}

template<class A>
int BigramMap<A>::numOfGrams(A parm1, A parm2) const {
    auto found = arr.find(make_pair(parm1, parm2));
    if (found != arr.cend()) {
        return found->second;

    }
    else {
        return 0;
    }
}

template<class A >
std::pair<A, A> BigramMap<A>::maxGrams()const {

    pair<A, A> temp = (arr.begin()->first);
    int num = arr.begin()->second;
    for(auto i = arr.cbegin(); i != arr.cend(); i++) {
        if(num<i->second)
        {
            num=i->second;
            temp=i->first;
        }

    }
    return temp;
    
}

template<class A>
void BigramMap<A>::print(ostream & out) const {
    auto sorted = arr;
    Dynamicarray < pair<A, A >> temparr;
    for(int i = 0; i < arr.size(); i++) {
        pair<A, A> temp = (sorted.begin()->first);
        int num = sorted.begin()->second;
        for(auto j = sorted.begin(); j != sorted.end(); j++) {
            if (num < j->second) {
                temp = j->first;
                num = j->second;
            }
        }
        temparr.addline(temp);
        sorted.erase(temp);
    }
    for(int i = 0; i < temparr.getsize(); i++) {
        out << temparr[i].first << "," << temparr[i].second << endl;


    }



}

template<class A>
int BigramMap<A>::getDataType()const {
    return datatype;


}
