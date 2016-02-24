/*
 * Name        : lab_6.cpp
 * Author      : David Dalton
 * Description : Working with Arrays
 */

#include "lab_6.h"

/*
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3".
 * @uses stringstream
 * @param int values[] - An array of integers
 * @param int size - The size of the integer array
 * @param char separator - The separator character to use in the returned
 *                         string.
  *                        Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
string PrepareForDisplay(int values[], int size, char separator) {
    /*
    Uses a for loop to add separating character between each number in an integer
    array and then stores the result into a string using stringstream, then
    returns the string
    */
    stringstream returnedString;
    int i=0;
    for(i=0;i<(size - 1);i++) {
    returnedString << values[i] << separator;
    }
    returnedString << values[i];
    return returnedString.str();
}

/*
 * Test to see if an array contains a specified value.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int value - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
bool HasValue(int values[], int size, int value) {
    /*
    uses a for loop to check each value in an array and compares it to a specific
    value to see if the specified value is present in the array.  If the value
    is not present it returns a false value, if the value is found it returns
    a true value
    */
    bool value_present = false;
    int i=0;
    for(i=0;i<size;i++) {
        if(values[i] == value) {
            value_present = true;
        }
    }
    
    if(value_present == true) {
        return true;
    } else {
        return false;
    }
}

/*
 * Return the value from an array at a specified index.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int index - The position in the array from which to return a value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                      the array, else it will be set to false
 * @return int - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns 0 and sets error to true
 */
int ValueAt(int values[], int size, int index, bool &error) {
    /*
    checks an array at a specified index and retrieves the value from the array
    if no value is present it returns null
    */
    if (index < size) {
        error = false;
        return values[index];
    } else {
        error = true;
        return 0;
    }
    
}

/*
 * Return the sum of the values in an integer array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @return int - The sum of the values in the array
 */
int Sum(int values[], int size) {
    /*
    Takes an array and adds all of the values together and stores the value
    into an integer, then returns the integer to the user
    */
    int sum = 0;
    int i=0;
    for(i=0;i<size;i++) {
        sum += values[i];
    }
    return sum;
}

/*
 * Swap the positions of two values in an integer array. The two
 * index values must be valid for the array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @param int index1 - The position of the first value to be swapped
 * @param int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
bool SwapValues(int values[], int size, int index1, int index2) {
    /*
    Takes two specified positions within an array and swaps the values stored
    at those positions, then returns a true value when the swap is complete.  If
    the specified locations are not valid indexes it returns false
    */
    if(((index1 < size) && (index1 >= 0)) && ((index2 < size) && (index2 >= 0))) 
    {
        int tempVar = values[index1];
        values[index1] = values[index2];
        values[index2] = tempVar;
        return true;
    } else {
        return false;
    }
    
}