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
public interface Bigram<T> {
    void readFile(String fn) throws Exception;
    int numGrams();
    int numOfGrams(T p1, T p2);
    String toString();
}
