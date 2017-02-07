#include "helper.h"

namespace hlp {

    bool isdouble(string line) {
        bool firstpoint = false;
        for(int i = 0; i < line.size(); i++) {
            if (line[i] != '.') {
                if (!(line[i] >= '0' && line[i] <= '9')) {
                    return false;
                }
            }
            else {
                if (!firstpoint)
                    firstpoint = true;
                else
                    return false;
            }
        }
        return true;
    }

    bool isint(string line) {

        for(int i = 0; i < line.size(); i++) {

            if (!(line[i] >= '0' && line[i] <= '9')) {
                return false;
            }

        }
        return true;
    }

    int power(int base, int pow) {
        int result = 1;
        if (base == 0)
            return 0;
        for(int i = 0; i < pow; i++) {
            result *= base;
        }
        return result;
    }

    int convertToint(string str) {
        int basamak = 0;
        int sayi = 0;
        int state = +1;
        /* Find the Number of places */
        for(int i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9')
                basamak++;
            else if (str[i] == '-')
                state = -1;
        }
        /* turn the char to int if it is number */
        if (basamak != 0) {
            int basamakson = basamak;
            for(int i = 0; i < str.length(); i++) {
                /*ignore the other characters*/
                if (str[i] >= '0' && str[i] <= '9') {
                    int rakam = str[i] - '0';
                    sayi += power(10, basamak - 1) * rakam;
                    basamak--;
                }
            }
        }
        else
            return 0;
        return sayi*state;

    }






}