/*
 * Name        : lab_12.cpp
 * Author      : David Dalton
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include "lab_12.h"

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
int* MakeDynoIntArray(unsigned int size) 
{
    //Creates a dynamic array of a specified size
    int *dyno_array;
    dyno_array = new int[size];
}

/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Sum(int* the_array, unsigned int array_size) 
{
    //Checks to see if the array is null and throws an error if it is
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";   
    } else {
        //Creates the variable that holds the sum of the array
        int sum = 0;
        /*
        *Loops through each index in the array and adds it to the sum variable
        */
        for(int i = 0; i < array_size; i++)
        {
            sum += the_array[i];
        }
        //Returns the value of sum
        return sum;
    }
}

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size) 
{
    //Checks to see if the array is null and throws an error if it is
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";   
    } else {
        //Creates the variable that holds the maximum value of the array
        int max_value = the_array[0];
        /*
        *Loops through each index in the array and compares the value of the 
        *current location to the value of max_value.  If it is greater it stores
        *it into max value, otherwise it continues looping through the array
        */
        for(int i = 0;i < array_size;i++)
        {
            if(the_array[i] > max_value)
            {
                max_value = the_array[i];
            }
        }
        //Returns the highest value of the array
        return max_value;
    }
}

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size) 
{
    //Checks to see if the array is null and throws an error if it is
    if(the_array == NULL)
    {
        throw "NULL ARRAY REFERENCE";   
    } else {
        //Creates the variable that holds the minimum value of the array
        int min_value = the_array[0];
        /*
        *Loops through each index in the array and compares the value of the 
        *current location to the value of min_value.  If it is smaller it stores
        *it into max value, otherwise it continues looping through the array
        */
        for(int i = 0;i < array_size;i++)
        {
            if(the_array[i] < min_value)
            {
                min_value = the_array[i];
            }
        }
        //Returns the smallest value of the array
        return min_value;
    }
}