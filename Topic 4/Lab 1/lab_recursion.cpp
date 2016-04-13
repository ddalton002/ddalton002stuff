/*
 * Name        : lab_recursion.cpp
 * Author      : David Dalton
 * Description : Recursive Functions
 */

#include "lab_recursion.h"

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

// CODE FUNCTION DEFINITIONS HERE


/*
 * Convert a binary number to decimal
 * @param number to be converted
 * @return an unsigned int
 */
unsigned int binToDec(int num) 
{
	
	string convert_int = num;
	int byte_size = convert_int.length();

	unsigned int i = 0;
	unsigned int total = 0;
	if(i < byte_size)
	{
		total = pow(2, i);
		return total + binTodec(num);
	}
	return total;
}
