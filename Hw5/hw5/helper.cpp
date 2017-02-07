#include "helper.h"

/*This namespace has helper global functions*/
namespace hlp {

    int convertToint(char str) {
        if (str != '\0' && str <= '9' && str >= '0')
            return str - '0';
        else
            return -1;
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

    int power(int base, int pow) {
        int result = 1;
        if (base == 0)
            return 0;
        for(int i = 0; i < pow; i++) {
            result *= base;
        }
        return result;
    }

    bool controlCommands(string line) {
        int i = 0;
        string Processes[] = {"MOV", "ADD", "SUB", "JMP", "PRN", "HLT"};
        for(i = 0; i < CommandNumber; i++) {
            if (Processes[i] == line)
                return true;
        }
        return false;
    }

    bool isonlyinteger(string line) {
        if (line[0] == '-') {
            for(int i = 1; i < line.length(); i++) {
                if (!(line[i] >= '0' && line[i] <= '9'))
                    return false;
            }
        }
        else {
            for(int i = 0; i < line.length(); i++) {
                if (!(line[i] >= '0' && line[i] <= '9'))
                    return false;
            }
        }
        return true;
    }

    bool findComma(string line) {
        for(int i = 0; i < line.length(); i++) {
            if (line[i] == ',')
                return true;
            else if (line[i] != ' ' && line[i] != '\t')
                return false;
        }
    }

    bool ControlSemicolon(string line) {
        for(int i = 0; i < line.length() ; i++) {
            if (line[i] == ';') {
                return true;
            }
                /*if the char is not valid to this condition return false*/
            else if ((line[i] != ' ' && line[i] != '\t' && line != "")) {
                return false;
            }
        }
        return true;
    }

    string parseLine(string line, int *point) {
        string seperated = "";
        int a = *point;
        for(int i = a; i <= line.length(); i++) {
            /*until to this characters */
            if (line[i] == ' ' || line[i] == '\t' || line[i] == ',' || line[i] == ';' || line[i] == '\0') {
                seperated = line.substr(a, i - *point);
                (*point) = i;
                i = line.length(); /* this is to exit from the loop*/
            }
        }
        if (line[*point] == ';') {
            *point = line.length();
        }
        while ((seperated == " " || seperated == "/t" || seperated == "") && *point <= line.length()) {
            (*point)++;
            return parseLine(line, point);
        }
        return seperated;
    }

    void convertToUpper(string& line) {
        for(int i = 0; i < line.length(); i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                line[i] -= 'a' - 'A';
            }
        }
    }

    bool firstLineControl(string line) {
        /* the loop return until to find first character which is not the 
         *  equal to condition */
        for(int i = 0; i < line.length(); i++) {
            if (line[i] != '\0' && line[i] != ' ' && line[i] != '\t') {
                if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') ||
                        line[i] == ';') {
                    i = line.length();
                }
                else {
                    return false;
                }
            }
        }
        /* find the ';' commend character index */
        int commandIndex = line.length();
        for(int i = 0; i < line.length(); i++) {
            if (line[i] == ';') {
                commandIndex = i;
                i = line.length();
            }
        }
        /* count the ',' character until to command character  */
        int virgulSayi = 0;

        for(int i = 0; i < commandIndex; i++) {
            if (line[i] == ',')
                virgulSayi++;
        }
        if (virgulSayi < 2)
            return true;
        else
            return false;
    }

    bool isRegister(string command) {
        string regNames[5] = {"R1", "R2", "R3", "R4", "R5"};
        for(int i = 0; i < RegisterNum; i++) {
            if (regNames[i] == command) {
                return true;
            }
        }
        return false;
    }

    bool isMemoryAddress(string line) {
        if (line[0] == '#' && isonlyinteger(&line[1])) {
            int index = convertToint(line);
            if (index < memorySize && index >= 0) {
                return true;
            }
        }
        return false;
    }

}