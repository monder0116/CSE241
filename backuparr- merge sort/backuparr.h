#include <iostream>
#include "templateArray.h"
#include "templateArray.cpp"


using namespace std;
#ifndef BACKUPH
#define BACKUPH
template<class T>
class Backuparr:public TempArray<T>{
public:

	Backuparr():TempArray<T>(),backup(){

	}
	Backuparr(int cap):TempArray<T>(cap),backup(){
		if(cap<=0 )
			throw Exception("hata");

	}
	Backuparr(const vector<T> other){
		for (int i = 0; i < other.size(); ++i)
		{
			TempArray<T>::add(other[i]);
		}
	}
	Backuparr(const Backuparr<T>& other);
	Backuparr& operator =(const Backuparr<T>& other);

	void takeBackup();
	void loadBackup();



	virtual ~Backuparr(){
		
	}

private:
	TempArray<T> backup;




};
#endif