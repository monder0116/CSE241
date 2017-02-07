#ifndef DYN
#define DYN
#include <iostream>
#include <vector>

using namespace std;
class Exception{
public:
	Exception(){

	}
	Exception(string temp):inform(temp){

	}
	string message()const{
		return inform;
	}
private:
	string inform;



};
template <class T>
class TempArray{
public:
	TempArray():TempArray(20){
	}

	TempArray(int cap):size(0),capasity(cap)
	{
		if(cap<=0)
			capasity=20;
		arr=new T[capasity];
	}
	TempArray(const vector<T>& other);
	TempArray(const TempArray<T>& other);
	virtual ~TempArray();
	void add(const T& other);
	void recapasity(int mult);
	bool full()const{
		if(size==capasity)
			return true;
		return false;
	}
	TempArray& operator =(const TempArray<T>& other);
	T& operator[](int index);
	const T operator[](int index)const ;
	TempArray<T>& operator +=(const T& other );
	const TempArray<T> operator --(int ignore);
	const TempArray<T> operator +(const TempArray<T>& other)const;
	const TempArray<T> operator()(int first,int last)const throw(Exception); 
	int getSize()const{
		return size;
	}
	int getCapasity()const{
		return size;
	}
	
	
private:
	T *arr;
	int size;
	int capasity;
	bool isfull()const;



};


#endif




