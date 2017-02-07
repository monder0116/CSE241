#include "backuparr.h"

#ifndef BDA
#define BDA

template<class T>
Backuparr<T>::Backuparr(const Backuparr<T>& other){
	TempArray<T>::operator=(other);
}
template<class T>
Backuparr<T>& Backuparr<T>::operator= (const Backuparr<T>& other){
	if(this==&other)
		return *this;
	TempArray<T>::operator=(other);
	backup=other.backup;
}	
template<class T>
void Backuparr<T>::takeBackup(){
	backup=*this;

}
template<class T>
void Backuparr<T>::loadBackup()
{
	TempArray<T>::operator=(backup);
}
















#endif