/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.hw8;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author onder
 */
@SuppressWarnings("unchecked")
public class BigramDyn<T> implements Bigram<T> {

    private Object arr[];
    private GenericArray<Integer> keyarr = new GenericArray<>();
    private final int dataype;
    private int size;
    private int bigramcount;

    public BigramDyn(BigramDyn<T> other) {
        this.dataype = other.dataype;
        this.size = 0;
        this.bigramcount = other.bigramcount;
        this.keyarr=new GenericArray<>(other.keyarr);
        this.arr=new Object[other.size+1];
        for (int i = 0; i < other.size; i++) {
            arr[size++]=other.arr[i];
        }

    }

    public BigramDyn<T> clone() {
        BigramDyn<T> temp = new BigramDyn<>(this);

        return temp;

    }

    public BigramDyn(int a) throws Exception {

        if (a > 0 && a < 4) {
            dataype = a;
            size = 0;
            bigramcount = 0;
        } else {
            throw new Exception("Invalid Datatype");

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
            arr = new Object[count - 1];

            for (int i = 0; i < tarr.size() - 1; i++) {
                PairClass<Integer, Integer> temp = new PairClass<>(tarr.get(i), tarr.get(i + 1));
                int index = searcharr((PairClass< T, T>) temp);
                if (index == -1) {
                    keyarr.add(1);
                    arr[size++] = temp;

                } else {
                    keyarr.setvalue(index, keyarr.get(index) + 1);
                }
            }

        } else if (dataype == 2) {

            int count = 0;
            while (fileScanner.hasNext()) {
                count++;
                fileScanner.next();
            }
            if (count < 2) {
                throw new Exception("Short Data!");
            }
            bigramcount = count - 1;
            fileScanner.close();
            fileScanner = new Scanner(filee);
            GenericArray<String> tarr = new GenericArray<>();
            while (fileScanner.hasNext()) {
                String a = fileScanner.next();

                tarr.add(a);

            }
            if (fileScanner.hasNext()) {
                fileScanner.close();
                throw new Exception("Bad Data");
            }
            arr = new Object[count - 1];

            for (int i = 0; i < tarr.size() - 1; i++) {
                PairClass<String, String> temp = new PairClass<>(tarr.get(i), tarr.get(i + 1));
                int index = searcharr((PairClass< T, T>) temp);
                if (index == -1) {
                    keyarr.add(1);
                    arr[size++] = temp;

                } else {
                    keyarr.setvalue(index, keyarr.get(index) + 1);
                }
            }

        } else if (dataype == 3) {

            int count = 0;
            while (fileScanner.hasNextDouble()) {
                count++;
                fileScanner.next();
            }
            if (count < 2) {
                throw new Exception("Short Data!");
            }
            bigramcount = count - 1;
            fileScanner.close();
            fileScanner = new Scanner(filee);
            GenericArray<Double> tarr = new GenericArray<>();
            while (fileScanner.hasNextDouble()) {
                Double a = fileScanner.nextDouble();

                tarr.add(a);

            }
            if (fileScanner.hasNext()) {
                fileScanner.close();
                throw new Exception("Bad Data");
            }
            arr = new Object[count - 1];

            for (int i = 0; i < tarr.size() - 1; i++) {
                PairClass<Double, Double> temp = new PairClass<>(tarr.get(i), tarr.get(i + 1));
                int index = searcharr((PairClass< T, T>) temp);
                if (index == -1) {
                    keyarr.add(1);
                    arr[size++] = temp;

                } else {
                    keyarr.setvalue(index, keyarr.get(index) + 1);
                }
            }

        }
        fileScanner.close();
    }

    /**
     *
     * @return total bigram count
     */
    public int numGrams() {
        return bigramcount;
    }

    /**
     * takes two elements as bigrams and returns the number of that bigram read
     * so fa.
     *
     * @param p1 is the T type
     * @param p2 is the T type
     * @return count of the pairs which is p1 and p2
     *
     */
    public int numOfGrams(T p1, T p2) {

        PairClass<T, T> temp = new PairClass<>(p1, p2);
        int index = searcharr(temp);
        if (index != -1) {
            return keyarr.get(index);
        }
        return 0;

    }

    public int searcharr(PairClass<T, T> key) {

        for (int i = 0; i < size; i++) {
            if (key.equals(this.arr[i])) {
                return i;
            }
        }
        return -1;

    }

    /**
     * this sort the dynamic map according to pair count
     */
    private void sortarr() {
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (keyarr.get(i).compareTo(keyarr.get(j)) < 0) {
                    Integer temp = keyarr.get(i);
                    keyarr.setvalue(i, keyarr.get(j));
                    keyarr.setvalue(j, temp);
                    PairClass<T, T> temp2 = (PairClass< T, T>) arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp2;
                }

            }

        }
    }

    /**
     * prints all the bigrams and their occurences in decreasing occurency
     * order.
     *
     * @return A string which contain above
     */
    public String toString() {
        String temp = new String("");

        sortarr();
        for (int i = 0; i < size; i++) {
            if (dataype == 1) {
                PairClass<Integer, Integer> obj = (PairClass<Integer, Integer>) arr[i];
                temp += String.format("%d,%d -> %d times\n", obj.getfirst(),
                        obj.getsecond(), keyarr.get(i));
            } else if (dataype == 2) {
                PairClass<String, String> obj = (PairClass<String, String>) arr[i];

                temp += String.format("%s,%s -> %d times\n", obj.getfirst(),
                        obj.getsecond(), keyarr.get(i));
            } else if (dataype == 3) {
                PairClass<Double, Double> obj = (PairClass<Double, Double>) arr[i];

                temp += String.format("%f,%f -> %d times\n", obj.getfirst(),
                        obj.getsecond(), keyarr.get(i));
            }

        }
        return temp;

    }

}
