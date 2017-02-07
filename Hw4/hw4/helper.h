/* 
 * File:   helper.h
 * Author: onder
 *
 * Created on October 30, 2016, 1:40 PM
 */

#ifndef HELPER_H
#define	HELPER_H
#include <iostream>
using namespace std;
/*This class have functions which need to other classes*/
class Helper
{
public:
  
    /*This function control the line to find 
     * many unexpected characters
     * for example mov r1 ,,r2 or 'mov r1,r2  
     * if the line unvalid return false else true  */
    static bool firstLineControl(string line);
    /* This convert the string to integer
     *  but the string must be only integer number!!*/
    static bool isonlyinteger(string line);
    /*this control the line if the line is command 
     *return true else false*/
    static bool ControlSemicolon(string line);
    /*This control the str to it is a registor or not
     *if it is register return true else false*/
    static bool isRegister(string str);
   /* this function convert the char to int
      * if only if str is number value*/
    static int convertToint(char str) ;
   /* this function convert the string to integer 
    * based on the value ignore the other characters*/
    static int convertToint(string str);/* this function convert the string to                     * other characters*/
    /*This function take the power */
    static int power(int base, int pow);
    /* this function  take the world until to ',' ';' ' ' characters,
     * if taken world is null ,the function run again
     * and will take new world*/
    static string parseLine(string line, int *lastpoint);
    /* this function Convert the string to uppercase*/
    static void convertToUpper(string& line) ;
    /*This find the comma character until to a character 
     * which is not space or tab ,
     * if find the comma return true ,else false*/
    static bool findComma(string line);
    /* this function compare the instruction names which are named in file and
        static declared names*/ 
    static bool controlCommands(string line);
    /*this control the str to is it memory adress
     *if it is memory adress return true else false*/
    static bool isMemoryAddress(string str) ;
    
};


#endif	/* HELPER_H */

