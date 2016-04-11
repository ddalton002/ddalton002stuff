/*
 * Name        : lab_recursion.h
 * Author      : April Browne
 * Description : Header File for Lab Recursion. DO NOT ALTER!
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


/*
 * Convert a decimal number to binary
 * @param number to be converted.
 * @return a stringstream.
 */
stringstream decToBin(int num)
{
	if (num > 1) //note this makes the base case num = 0
	{
		decToBin(num/2); //recursive call
	}

	cout<<(num%2); //outputs in correct order
}

/*
 * Convert a binary number to decimal
 * @param number to be converted
 * @return an unsigned int
 */
unsigned int binToDec(int num);


#endif
