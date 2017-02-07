/* 
 * File:   Bigram.h
 * Author: onder
 *
 * Created on December 12, 2016, 7:28 PM
 */

#ifndef BIGRAM_H
#define	BIGRAM_H
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

class Exception:public exception{
public:
    Exception(string temp):inform(temp){
        
    }
     virtual const char* what() const throw(){
         return inform.c_str();
     }
    
private:
    string inform;
    
};
template <class A >
class Bigram
{
    public:
   virtual ~Bigram(){
   }
   virtual void readFile(string filename) throw(Exception)=0;
   virtual int numGrams() const=0;
   virtual int numOfGrams(A parm1,A parm2 )const=0;
   virtual pair<A,A> maxGrams()const =0;
   virtual void print(ostream& out)const=0;
   friend ostream& operator <<( ostream& out, const Bigram& obj){
       obj.print(out);   
       return out;
   }
   
};


#endif	/* BIGRAM_H */

