/*
 * Name        : lab_22.cpp
 * Author      : David Dalton
 * Description : Recursive Functions
 * Sources     : Eduardo, Jacob
 */

#include "lab_22.h"


/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value an unsigned integer containing the value for which the factorial will be computed
 * @return an unsigned integer containing the computed factorial of the value
 */
unsigned int Factorial(unsigned int value) 
{
    /**
     * Checks if the paramater is less then or equal to 1 and returns
     * the value if it is
     */ 
	if(value <= 1) 
	{
    	return 1;
    }
    /**
     * If the paramter is not less than or equal to one, calls the 
     * function with the parameter reduced by 1 and multiplies it by
     * the original paramter, then returns it
     */
    else {
        return (value * Factorial(value - 1));
    }
}

/*
 * Return a specified value in a Fibonacci sequence. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue an unsigned integer specifying which value in the Fibonacci sequence to return
 * @return an unsigned integer containing the requested value in the Fibonacci sequence
 */
unsigned int Fibonacci(unsigned int fib_value) 
{
    /**
     * Checks if the paramter is equal to 1, and retuns the value if
     * it is
     */
    if(fib_value == 1) {
		return 1;
	}
	/**
	 * Checks if the parameter is equal to 0, and returns the value if it is
	 */
	else if (fib_value == 0) {
		return 0;
	}
	/**
	 * If the paramter is not equal to 1 or 0, it then calls the function
	 * with the paramter reduced by 1, then calls the function with the
	 * parameter reduced by 2, adds the two values together then returns them
	 */
	else 
		return (Fibonacci(fib_value - 1) + Fibonacci(fib_value - 2));
}

/*
 * Test a single word to see if it is a palindrome. The word must be all in the same case
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word a string containing the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool WordIsPalindrome(string word) 
{
    /**
     * Checks the length of the parameter, if the parameter is less than or 
     * equal to 1 then it returns true
     */
    if(word.length() <= 1) 
    {
        return true;
    }
    /**
     * Checks the character at the first index of the paramter string and
     * compares it to the character at the index of the length of the input
     * paramter minus 1.  If they are the same then it calls the function the
     * function with a input parameter of a substring function of the original
     * parameter to remove the first and last characters and returns it
     */
    else if(word[0] == word[word.length() - 1])
    {
        return WordIsPalindrome(word.substr(1, word.length() -2));
    }
}

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going forward to the end of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the array
 */
string ArrayForwardsAsString(int array[], unsigned int start, unsigned int size)
{
    // Creates the stringstream
    stringstream stream;
    /**
     * Checks if the start parameter is equal to size, if it is then
     * return an empty string
     */
    if (start == size)
    {
        return "";
    }
    /**
     * Checks if the start parameter is less than size, if it is
     * then send the character in the input string located at index size to
     * the stringstream, then send a space character to the stream,
     * then call the function with the start paramter increased by 1 and the
     * original array and size parameters and send the results to the stream
     */
    else if (start < size)
    { 
        stream << array[start] << " " << ArrayForwardsAsString(array, start + 1, size);
    }
    // Returns the contents of the stream
    return stream.str();
}

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going backward to the beginning of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces, in reverse order; returns empty string
 *         if the startIndex is < zero
 */
string ArrayBackwardsAsString(int array[], int start, unsigned int size)
{
    // Creates the stringstream
    stringstream stream;
    /**
     * Checks if the start parameter is less than 0, if it is then
     * return an empty string
     */
    if (start < 0)
    {
        return "";
    }
    /**
     * Checks if the start parameter is less than size, if it is
     * then send the character in the input string located at index size to
     * the stringstream, then send a space character to the stream,
     * then call the function with the start paramter increased by 1 and the
     * original array and size parameters and send the results to the stream
     */
    else if (start >= 0)
    { 
        stream << array[start] << " " << ArrayBackwardsAsString(array, start - 1, size);
    }
    // Returns the contents of the stream
    return stream.str();
}