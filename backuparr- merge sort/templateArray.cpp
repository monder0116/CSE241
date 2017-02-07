#include "templateArray.h"
#ifndef TDA
#define TDA
template <class T>
TempArray<T>::TempArray(const TempArray<T>& other):size(0),capasity(other.capasity){
	arr=new T[capasity];
	for(int i=0;i<other.size;i++)	
	{
		arr[i]=other.arr[i];
		++size;
	}


} 
template <class T>
TempArray<T>::TempArray(const vector<T>& other):TempArray<T>(){
	for (int i = 0; i < other.size(); ++i)
	{
	
		add(other[i]);
	}

}

template<class T>
TempArray<T>& TempArray<T>::operator =(const TempArray<T>& other){
	if(this==&other)
		return *this;
	if(other.capasity!=capasity)
	{
		capasity=other.capasity;
		delete [] arr;
		arr=new T[capasity];
	}
	for(int i=0;i<other.size;i++)
	{
		arr[i]=other.arr[i];
	}
	size=other.size;
}

template <class T>
T& TempArray<T>::operator [](int index) {
	if(index<getSize() && index>=0){
		return arr[index];
	}
	throw Exception("Hatali index");


}
template<class T>
const T TempArray<T>::operator[](int index) const {
	if(index<getSize()&& index>=0){
		return arr[index];
	}
	throw Exception("Hatali index");

}
template<class T>
TempArray<T>& TempArray<T>::operator+=(const T& other){
	add(other);
	return *this;
}

template<class T>
void TempArray<T>::add(const T& other){
	if(full())
		recapasity(2);
	
	arr[size++]=other;
}
template<class T>
void TempArray<T>::recapasity(int mult){
	if(mult>0){
		
		T *temp=arr;
		capasity*=mult;
		arr=new T[capasity];	
		for (int i = 0; i < getSize(); ++i)
		{
			arr[i]=temp[i];
		}

		delete [] temp;

	}
}
template<class T>
const TempArray<T> TempArray<T>::operator --(int ignore){
	TempArray<T> temp(*this);
	--size;
	recapasity(1);
	return temp;
} 
template<class T>
const TempArray<T> TempArray<T>::operator +(const TempArray<T>& other)const{
	TempArray<T> temp(other);
	for (int i = 0; i < getSize(); ++i)
	{
		temp.add(arr[i]);
	}
	return temp;
}
template<class T>
const TempArray<T> TempArray<T>::operator()(int first,int last)const throw(Exception){
	TempArray<T> temp;
	if(first>=0 && first<=last && last>=0 && last<=getSize())
	{
		
		for (int i = first; i < last; ++i)
		{
			temp.add(arr[i]);
		}

	}else
		throw Exception("Geçersiz index aralığı");

	return temp;
}
template<class T>
TempArray<T>::~TempArray()
{
	
	delete [] arr;
}
#endif