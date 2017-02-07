/* 
 * File:   main.cpp
 * Author: onder
 *
 * Created on December 12, 2016, 7:28 PM
 */



/*
 * 
 */
#include "requiredIncs.h"
template <class T>
void testFunc(Bigram<T>* bg, const char* filename, T p1, T p2) {
    //////////////////////////////////////////////////////////////////////////
    //readFile
    bg->readFile(filename);

    //numGrams
    cout <<"total num of gram"<<endl;
    cout << bg->numGrams() << endl;

    //numOfGrams
     cout <<" num of gram"<<endl;
    cout << bg->numOfGrams(p1, p2) << endl;

    //maxGrams
     cout <<"max num of gram"<<endl;
    pair<T, T> retVal = bg->maxGrams();
    cout << retVal.first << "   " << retVal.second << endl;

    //operator<<
    cout << *bg << endl;
    //////////////////////////////////////////////////////////////////////////
}

void testManMap(int datatype, const char* filename) {

    if (1 == datatype) {

        BigramMap<int> myBg(datatype);
        testFunc<int>(&myBg, filename, 3, 4);
    }
    else if (2 == datatype) {

        BigramMap<double> myBg(datatype);
        testFunc<double>(&myBg, filename, 3.0, 4.0);
    }
    else if (3 == datatype) {

        BigramMap<string> myBg(datatype);
        testFunc<string>(&myBg, filename, "qwe", "asd");
    }
}

void testManDyn(int datatype, const char* filename) {

    if (1 == datatype) {

        BigramDyn<int> myBg(datatype);
        testFunc<int>(&myBg, filename, 3, 4);
    }
    else if (2 == datatype) {

        BigramDyn<double> myBg(datatype);
        testFunc<double>(&myBg, filename, 3.0, 4.0);
    }
    else if (3 == datatype) {

        BigramDyn<string> myBg(datatype);
        testFunc<string>(&myBg, filename, "qwe", "asd");
    }
}

int main(int argc, char** argv) {

    //////////////////////////////////////////////////////////////////////////
    //command line parameters
    const char* filename = "dese.txt";
    int dataType =3;
    int classType = 2;
    //////////////////////////////////////////////////////////////////////////


    try {
        //////////////////////////////////////////////////////////////////////////
        //Testing class BigramMap
        if (classType == 1) {
            testManMap(dataType, filename);
        }
        else {

            testManDyn(dataType, filename);
        }
        //////////////////////////////////////////////////////////////////////////
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
