/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.hw8;

import java.util.HashMap;
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author onder
 */
@SuppressWarnings("unchecked")
public class BigramMap<T> implements Bigram<T> {

    private HashMap<Object, Integer> arr = new HashMap<>();
    private int dataype;
    private int bigramcount;

    public BigramMap<T> clone() {
        BigramMap<T> temp = new BigramMap<>(this);

        return temp;

    }

    public BigramMap(int a) {
        dataype = a;
        bigramcount = 0;
    }

   
    public BigramMap(BigramMap<T> other) {
        this.dataype = other.dataype;
        this.bigramcount = other.bigramcount;
        for (Object obj : other.arr.keySet()) {
            arr.put(obj, other.arr.get(obj));

        }

    }
  /**
     *
     * takes a filename as a string parameter, reads the file, calculates all
     * the bigrams. Throws exceptions if there are problems with opening and
     * reading the file.
     *
     * @param fn is filename of file
     * @throws Exception which are the Shortdata and Baddata
     */
    public void readFile(String fn) throws Exception {
        Scanner fileScanner = null;
        File filee = null;
        try {
            filee = new File(fn);
            fileScanner = new Scanner(filee);
        } catch (IOException e) {
            throw e;
        }

        if (dataype == 1) {
            int count = 0;
            while (fileScanner.hasNextInt()) {
                count++;
                fileScanner.next();
            }
            if (count < 2) {
                throw new Exception("Short Data!");
            }
            bigramcount = count - 1;
            fileScanner.close();
            fileScanner = new Scanner(filee);
            GenericArray<Integer> tarr = new GenericArray<>();
            while (fileScanner.hasNextInt()) {
                int a = fileScanner.nextInt();

                tarr.add(a);

            }
            if (fileScanner.hasNext()) {
                fileScanner.close();
                throw new Exception("Bad Data");
            }

            for (int i = 0; i < tarr.size() - 1; i++) {
                PairClass<Integer,Integer> temp =  new PairClass<>(tarr.get(i), tarr.get(i + 1));
                int found = numOfGrams((T)temp.getfirst(), (T)temp.getsecond());
                if (found == 0) {
                    arr.put(temp, 1);
                } else {
                    increaseValue((PairClass<T,T>)temp);
                }
            }
        } else if (dataype == 2) {

            int count = 0;
            while (fileScanner.hasNext()) {
                count++;
                fileScanner.next();
            }
            if (count < 2) {
                throw new Exception("Data is not Valid!");
            }
            bigramcount = count - 1;
            fileScanner.close();
            fileScanner = new Scanner(filee);
            GenericArray<String> tarr = new GenericArray<>();
            while (fileScanner.hasNext()) {
                String input = fileScanner.next();

                tarr.add(input);

            }
            if (fileScanner.hasNext()) {
                fileScanner.close();
                throw new Exception("Bad Data");
            }

            for (int i = 0; i < tarr.size() - 1; i++) {
                PairClass<T, T> temp = (PairClass<T, T>) (Object) new PairClass<>(tarr.get(i), tarr.get(i + 1));
                int found = numOfGrams(temp.getfirst(), temp.getsecond());
                if (found == 0) {
                    arr.put(temp, 1);

                } else {
                    increaseValue(temp);

                }
            }
        } else if (dataype == 3) {
            int count = 0;
            while (fileScanner.hasNextDouble()) {
                count++;
                fileScanner.next();
            }
            if (count < 2) {
                throw new Exception("Data is not Valid!");
            }
            bigramcount = count - 1;
            fileScanner.close();
            fileScanner = new Scanner(filee);
            GenericArray<Double> tarr = new GenericArray<>();
            while (fileScanner.hasNextDouble()) {
                Double input = fileScanner.nextDouble();

                tarr.add(input);

            }
            if (fileScanner.hasNext()) {
                fileScanner.close();
                throw new Exception("Bad Data");
            }

            for (int i = 0; i < tarr.size() - 1; i++) {
                PairClass<T, T> temp = (PairClass<T, T>) (Object) new PairClass<>(tarr.get(i), tarr.get(i + 1));
                int found = numOfGrams(temp.getfirst(), temp.getsecond());
                if (found == 0) {
                    arr.put(temp, 1);

                } else {
                    increaseValue(temp);

                }
            }
        }
        fileScanner.close();
    }

    /* Return  the total bigram numbers*/
    public int numGrams() {
        return bigramcount;
    }

    /* if the key found in map ,value will increase */
    private void increaseValue(PairClass<T, T> key) {
        for (Object obj : arr.keySet()) {

            if (key.equals(obj)) {
                arr.replace(obj, arr.get(obj) + 1);
            }
        }

    }

    /* Return the pair of parameter count in map*/
    public int numOfGrams(T p1, T p2) {
        PairClass<T, T> obj = new PairClass<>(p1, p2);
        for (Object key : arr.keySet()) {
            if (obj.equals(key)) {
                return arr.get(key);
            }
        }
        return 0;

    }

    /* Return a string contain of the pair and counts*/
    public String toString() {

        ArrayList<Integer> tarr = new ArrayList<>();
        ArrayList<PairClass<T, T>> tkeys = new ArrayList<>();
        tarr.addAll(arr.values());
        Collections.sort(tarr, Collections.reverseOrder());
        String temp = "";
        for (int i = 0; i < tarr.size(); i++) {
            for (Object key : arr.keySet()) {
                PairClass<T, T> obj = (PairClass<T, T>) key;

                if (arr.get(key) == tarr.get(i) && !tkeys.contains(key)) {
                    if (dataype == 1) {
                        temp += String.format("%d,%d -> %d times\n", obj.getfirst(), obj.getsecond(), arr.get(obj));
                    } else if (dataype == 2) {
                        temp += String.format("%s,%s -> %d times\n", obj.getfirst(), obj.getsecond(), arr.get(obj));
                    } else if (dataype == 3) {
                        temp += String.format("%f,%f -> %d times\n", obj.getfirst(), obj.getsecond(), arr.get(obj));

                    }
                    tkeys.add(obj);
                }

            }

        }
        return temp;
    }
}
