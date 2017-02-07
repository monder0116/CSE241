/* 
 * File:   main.cpp
 * Author: onder
 *
 * Created on November 16, 2016, 8:05 PM
 */

#include <iostream>
#include <vector>
using namespace std;
int count(const vector<int>& arr, int search);
void reverse(int* arr, int size);
int len(int sayi);
int reverseint(int sayi);
int pow(int base, int power);
void printreverse(int sayi);
int searchinvector(vector<int> arr, int search);
int fibonatci(int n);
template<class AnonimType>
vector<AnonimType> meshsort(vector<AnonimType> arr);
vector<int> meshsort(vector<int>arr);
int findmax(vector<int> arr);
int swap(int& a, int& b);
template<class T>
bool searchtemp(vector<T> arr,const T& search);
/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(32);
    arr.push_back(188);
    arr.push_back(22);
    int narr[] = {114, 22, 43, 45, 5};
//    printreverse(1513260);
//    cout << "/////////////////////" << endl;
//    cout << reverseint(1453) << endl;
//    cout << "/////////////////////" << endl;
//
//    cout << searchinvector(arr, 5) << endl;
//    cout << "/////////////////////" << endl;
//    
    arr= meshsort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<endl;


    }
    cout<<"-------------------------"<<endl;
    int i=findmax(arr);
    cout<<i<<endl;
    cout<<"------------------------------"<<endl;
    cout<<searchtemp(arr,362)<<endl;
//    cout<<fibonatci(3)<<endl;
    return 0;
}
int count(const vector<int>& arr, int search) {
    if (arr.size() == 1)
        return (search == arr[0] ? 1 : 0);
    else if (arr.size() == 0)
        return 0;
    else {
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < arr.size() / 2; i++) {
            left.push_back(arr[i]);

        }
        for(int i = arr.size() / 2; i < arr.size(); i++) {
            right.push_back(arr[i]);
        }
        return count(left, search) + count(right, search);
    }

}

void reverse(int* arr, int size) {
    if (size == 0 || size == 1) {
        return;
    }
    else if (size >= 2) {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        reverse(arr + 1, size - 2);
        return;
       
    }
}
int reverseint(int sayi) {
    if (sayi < 10 && sayi > 0) {
        return (sayi);
    }
    else {
        int rakam = sayi % 10;
        return (rakam * pow(10, len(sayi) - 1) + reverseint(sayi / 10));
    }
}

int fibonatci(int n)
{
    if(n==0|| n==1)
    {
         return 1;
    }
    else{
        return fibonatci(n-1)+fibonatci(n-2);  
    }
}
int pow(int base, int power) {
    if (power == 0)
        return 1;
    else if (power == 1)
        return base;
    else {
        return base * pow(base, power - 1);
    }
}

int len(int sayi) {
    if (sayi < 0)
        sayi = -sayi;
    if (sayi < 10 && sayi > 0) {
        return 1;
    }
    else {
        return 1 + len(sayi / 10);
    }


}

void printreverse(int sayi) {
    if (sayi < 10) {
        cout << sayi << endl;
    }
    else {

        printreverse(sayi / 10);
        int temp = sayi % 10;
        cout << temp << endl;
    }
}

int swap(int& a, int& b)
{
    int t=a;
    a=b;
    b=t;
}
int findmax(vector<int> arr){
    if(arr.size()<=0)
        return -1;
    else if(arr.size()==1)
        return arr[0];
    else if(arr.size()>=2)
    {
       if(arr[arr.size()-2]>arr[arr.size()-1])
       {
           arr.pop_back();
           return findmax(arr);
           
       }
       else{
           swap(arr[arr.size()-2],arr[arr.size()-1]);
           arr.pop_back();
           return findmax(arr);
       }
    }
}


int searchinvector(vector<int> arr, int search) {
    if (arr.size() == 0)
        return 0;
    else if (arr.size() == 1)
        return (arr[0] == search ? 1 : 0);
    else {
        int temp = arr[arr.size() - 1];
        arr.pop_back();
        return (temp == search ? 1 : 0)+searchinvector(arr, search);
    }
}
template<class T>
bool searchtemp(vector<T> arr,const T& search)
{
    if(arr.size()==0)
    {
        return false;
    }
    else{
        if(arr[arr.size()-1]==search)
            return true;
        else
        {
            arr.pop_back();
            return searchtemp(arr,search);
            
        }
        
    }
    
}
template<class AnonimType>
vector<AnonimType> meshsort(vector<AnonimType> arr)
{
    if(arr.size()== 0)
    {
        vector<AnonimType> temp;
        return temp;
    }
       
    else if( arr.size()==1)
    {
        return arr;
        
    }
    else{
        vector<AnonimType> right;
        vector<AnonimType> left;
        for(int i = 0; i < arr.size()/2; i++) {
            left.push_back(arr[i]);
           
        }
        for(int i =arr.size()/2; i <arr. size(); i++) {
            right.push_back(arr[i]);
        }
        left=meshsort(left);
        right=meshsort(right);
        int r=0,l=0;
        vector<AnonimType> base(0);
        while(l<left.size() && r<right.size())
        {
            if(left[l]<right[r])
            {
                base.push_back(left[l]);
                ++l;
                
            }
            else
            {
                base.push_back(right[r]);
                ++r;
            }
        }
       if(l==left.size()){
            for(int i = r; i < right.size(); i++) {
                base.push_back(right[i]);
       
            }
        }
         if(r==right.size()){
            for(int i = l; i < left.size(); i++) {
                base.push_back(left[i]);
            }
        }
                

        return base;
    }
    
}




vector<int> meshsort(vector<int>arr) {
    if(arr.size()<1)
    {
        vector<int> empty;
        return empty;
    }else if(arr.size()==1)
    {
        vector<int> sub;
        sub.push_back(arr[0]);
        return sub;
    }
    else{
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < arr.size()/2; i++) {
            left.push_back(arr[i]);
        }
         for(int i = arr.size()/2; i < arr.size(); i++) {
            right.push_back(arr[i]);
        }
           
        left=meshsort(left);
        right=meshsort(right);
        vector<int> base;
        int l=0,r=0;
        while(l<left.size() && r<right.size()){
            if(left[l]<=right[r])
            {
                base.push_back(left[l]);
                l++;
              
            }else{
                 base.push_back(right[r]);
                 r++;
              
            }
        }
        if(l==left.size()){
            for(int i = r; i < right.size(); i++) {
                base.push_back(right[i]);
       
            }
        }
         if(r==right.size()){
            for(int i = l; i < left.size(); i++) {
                base.push_back(left[i]);
            }
        }
        return base;
    }
}