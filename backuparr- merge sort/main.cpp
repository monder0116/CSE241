#include <iostream>
#include <vector>
#include "backuparr.h"
#include "backuparr.cpp"
using namespace std;
template <class T>
TempArray<T> merge(const TempArray<T>& arr);
template<class T>
T findmedyan(const vector<T>& arr);

int main() {
    try {

        vector<int> arr;
        arr.push_back(144);
        arr.push_back(21);
        arr.push_back(122);
        arr.push_back(1322);
        arr.push_back(1);
        TempArray<int> yeni(arr);
        yeni = merge(yeni);
        for(int i = 0; i < yeni.getSize(); i++) {
            cout << yeni[i] << endl;


        }

    } catch (Exception& e) {

        cout << e.message() << endl;
    }

    return 0;
}

template<class T>
T findmedyan(const vector<T>& arr2) {
    std::vector<T> arr(arr2);

    for(int i = 0; i < arr.size(); ++i) {
        for(int j = i; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }

        }
    }
    T temp;
    if (arr.size() % 2 == 0) {
        int index1 = (arr.size() - 1) / 2;
        int index2 = (arr.size() - 1) / 2 + 1;
        temp = arr[index1] + arr[index2];
        temp = temp / 2;
    }
    else
        temp = arr[(arr.size() - 1) / 2];
    return temp;
}

template <class T>
TempArray<T> merge(const TempArray<T>& arr) {
    if (arr.getSize() == 0)
        return TempArray<T>();
    else if (arr.getSize() == 1)
        return arr;

    TempArray<T> left, right;
    left = arr(0, arr.getSize() / 2);
    right = arr(arr.getSize() / 2, arr.getSize());
    left = merge(left);
    right = merge(right);
    TempArray<T> base;

    int r = 0;
    int l = 0;
    while (r < right.getSize() && l < left.getSize()) {
        if (right[r] < left[l]) {
            base.add(right[r]);
            ++r;
        }
        else {
            base.add(left[l]);
            ++l;
        }
    }
    if (l == left.getSize()) {
        for(int i = r; i < right.getSize(); ++i) {
            base.add(right[i]);

        }


    }
    if (r == right.getSize()) {
        for(int i = l; i < left.getSize(); ++i) {
            base.add(left[i]);

        }

    }
    return base;
} 



