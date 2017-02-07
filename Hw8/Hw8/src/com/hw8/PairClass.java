/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.hw8;

/**
 *
 * @author onder
 */
@SuppressWarnings("unchecked")
public class PairClass <T,P>{
    private T first;
    private P second;
    PairClass(PairClass<T,P> other)
    {
        first=other.first;
        second=other.second;
    }
    public PairClass(T f,P s)
    {
        first=f;
        second=s;
    }
    public PairClass()
    {
        first=null;
        second=null;
        
    }
    public T getfirst(){
        return this.first;
        
    }
    public P getsecond(){
        return this.second;
    }
    public void setfirst(T f){
        this.first=f;
    }
    public void setsecond(P s){
        this.second=s;
    }
    public int hashCode(){
       return super.hashCode();
    }
    
    public boolean equals(Object com){
        PairClass<T,T> temp=(PairClass<T, T>)com;
        return first.equals(temp.getfirst()) && second.equals(temp.getsecond());
    }
    
}
