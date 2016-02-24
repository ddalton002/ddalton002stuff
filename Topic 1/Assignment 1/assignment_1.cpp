/*
 * Name        : assignment_1.cpp
 * Author      : David Dalton
 * Description : A program that performs operations on strings and arrays.
 * Sources     : Dustin Miner lines 116, 117, 199, 200
 */

#include "assignment_1.h"

// Declare Function Prototypes Here (What goes above main)
/*
*This function will check to make sure all characters in a given string are
*alphabetic.  It returns true if the string is all alphabetic, otherwise it
*returns false.  The empty string should also return false.
*/
bool CheckAlphabetic (const string& kAlphabetic) 
{
    bool is_alphabetic = false;
    int i;
    int currentLetter;
    int length = kAlphabetic.length();
    /*
    *Loops through the array and gets the ascii value of the character at the
    *specified location in the string then compares it to the ascii value range
    *of both upper and lower case letters and returns a true if the value falls
    *within those ranges.  If the value doesn't fall in those ranges then it 
    *returns false
    */
    for(i = 0; i<length;i++) {
        currentLetter = kAlphabetic[i];
        if (((currentLetter > 64) && (currentLetter < 91))
        || ((currentLetter > 96) && (currentLetter < 123)))
      {
          is_alphabetic = true;
      } else 
      {
          is_alphabetic = false;
          return is_alphabetic;
      }
    }
    return is_alphabetic;
}

/*
*This function will count the number of words (delimited by space characters) in
*a string.  Assume the parameter will never have multiple spaces back-to-back and will
*never begin or end with spaces).
*/
int CountWords(string words) 
{
    int counter = 0;
    if(words == "")
    {
        return counter;
    } else 
    {
        char delimiter = ' ';
        int i;
        int currentLetter;
        int length = words.length();
        /*
        *Loops through a string and checks each character in the string.  When
        *it encounters a character that is equal to the delimiter character
        *then it increases the word counter by 1.  When the loop has finished 
        *running then increments the counter by 1 to indicate the end of the
        *string.
        */
        for(i=0;i<length;i++) 
        {
            if(words[i] == delimiter) 
            {
                counter = (counter + 1);
            }
        }
        counter = (counter + 1);
        return counter;
    }
}

/*
*This function will perform a Caesar Cipher Shift.  If the string contains any 
*non-alpha characters do not perform the encryption and return false.  Otherwise
*perform the encryption and return true.
*/
bool EncryptString(string& string_encrypted, int characters_shifted) 
{
    bool encrypted = false;
    int i;
    int currentLetter;
    int length = string_encrypted.length();
    char alphabet_upper[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                            'M','N','O','P','Q','R','S','T','U','V','W','X',
                            'Y','Z'};
    char alphabet_lower[] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                            'm','n','o','p','q','r','s','t','u','v','w','x',
                            'y','z'};
    /*
    *Uses the CheckAlphabetic function on the string to verify that all
    *characters in the string are alpha characters.  If the string contains
    *non-alpha characters then returns false
    */
    if(CheckAlphabetic(string_encrypted) == true) 
    {
        /*
        *Loops through a string and checks the ascii value of the specified
        *character
        */
        for(i=0; i<length; i++) 
        {
            /*
            *Checks to see if the value of the characters_shifted is below
            *0.  If it is it converts it to a positive value and subtracts 2
            */
            if(characters_shifted < 0)
            {
                characters_shifted = (characters_shifted * -1);
                characters_shifted = (characters_shifted - 2);
                
            }
                /*
                *If the ascii value of the specified character is uppercase
                *then it subtracts 65.  If it is lower case then it subrtracts 
                *97.  It then adds the value to characters_shifted.  If the 
                *value of the specified character is outside of the range of 0 
                *and 25 then it subracts 26.  It then divides the value by 
                *modulus 26 to get the value of the index of the upper or lower 
                *case alphabet array to set the specified character t then 
                *returns true.
                */
                currentLetter = string_encrypted[i];
                if((currentLetter > 64) && (currentLetter < 91))
                {
                    currentLetter = (string_encrypted[i] - 65);
                    currentLetter = (currentLetter + characters_shifted);
                    if((currentLetter > 25) || (currentLetter <0))
                    {
                        currentLetter = ((currentLetter - 26) % 26);
                    } else
                    {
                        currentLetter = (currentLetter % 26);
                    }
                    string_encrypted[i] = alphabet_upper[currentLetter];
                } else if((currentLetter > 96) && (currentLetter < 123))
                {
                    currentLetter = (string_encrypted[i] - 97);
                    currentLetter = (currentLetter + characters_shifted);
                    if((currentLetter > 25) || (currentLetter <0))
                    {
                        currentLetter = ((currentLetter - 26) % 26);
                    } else
                    {
                        currentLetter = (currentLetter % 26);
                    }
                    string_encrypted[i] = alphabet_lower[currentLetter];
                }
        }
        encrypted = true;
    }
    return encrypted;
}

/*
*This function decrypts a Caesar Cipher shift.  If the string contains any
*non-alpha characters do not perform the encryption and return false.
*Otherwise perform the encryption and return true.
*/
bool DecryptString(string& string_unencrypted, int characters_shifted) 
{
    bool decrypted = false;
    int i;
    int currentLetter;
    int length = string_unencrypted.length();
    char alphabet_upper[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                            'M','N','O','P','Q','R','S','T','U','V','W','X',
                            'Y','Z'};
    char alphabet_lower[] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                            'm','n','o','p','q','r','s','t','u','v','w','x',
                            'y','z'};
    /*
    *Uses the CheckAlphabetic function on the string to verify that all
    *characters in the string are alpha characters.  If the string contains
    *non-alpha characters then returns false
    */
    if(CheckAlphabetic(string_unencrypted) == true)
    {
        /*
        *Loops through a string and checks the ascii value of the specified
        *character
        */
        for(i=0; i<length; i++) 
        {
            /*
            *Checks to see if the value of the characters_shifted is greater
            *than 999999.  If it is it converts it to a positive value and 
            *adds 2
            */
            if(characters_shifted > 999999)
            {
                characters_shifted = (characters_shifted * -1);
                characters_shifted = (characters_shifted + 2);
                
            }
                /*
                *If the ascii value of the specified character is uppercase
                *then it subtracts 65.  If it is lower case then it subrtracts 
                *97.  It then subracts characters_shifted from the value.  If 
                *the value of the specified character is outside of the range 
                *of 0 and 25 then it subracts 26.  It then divides the value by 
                *modulus 26 to get the value of the index of the upper or lower 
                *case alphabet array to set the specified character t then 
                *returns true.
                */
                currentLetter = string_unencrypted[i];
                if((currentLetter > 64) && (currentLetter < 91))
                {
                    currentLetter = (string_unencrypted[i] - 65);
                    currentLetter = (currentLetter - characters_shifted);
                    if((currentLetter > 25) || (currentLetter <0))
                    {
                        currentLetter = ((currentLetter + 26) % 26);
                    } else
                    {
                        currentLetter = (currentLetter % 26);
                    }
                    string_unencrypted[i] = alphabet_upper[currentLetter];
                } else if((currentLetter > 96) && (currentLetter < 123))
                {
                    currentLetter = (string_unencrypted[i] - 97);
                    currentLetter = (currentLetter - characters_shifted);
                    if((currentLetter > 25) || (currentLetter <0))
                    {
                        currentLetter = ((currentLetter + 26) % 26);
                    } else
                    {
                        currentLetter = (currentLetter % 26);
                    }
                    string_unencrypted[i] = alphabet_lower[currentLetter];
                }
        }
        decrypted = true;
    }
    return decrypted;
}

/*
*This function will compute the mean average of the values in the array.  The 
*array will always be at least size of 1.
*/
double ComputeAverage(double input_array[], unsigned int array_size) 
{   
    /*
    *Adds together all the values in an array using a for loop then returns the 
    *value
    */
    double sum = 0;
    double average = 0;
    int i;
    for(i=0;i<array_size;i++) {
        sum += input_array[i];
    }
    average = (sum/array_size);
    return average;
}

/*
*This function will find and return the smallest value in an array.  The array
*will always be at least of size 1.
*/
double FindMinValue(double input_array[], unsigned int array_size) 
{
    int i;
    double min_value = input_array[i];
    /*
    *Uses a for loop to loop through an array and compare each value
    to determine the lowest value in the array then returns that value
    */
    for(i = 0; i<array_size;i++) {
        if(input_array[i] < min_value) 
        {
            min_value = input_array[i];
        }
    }
    return min_value;
}

/*
*This function will find and return the largest value in an array.  The array
*will always be at least of size 1.
*/
double FindMaxValue(double input_array[], unsigned int array_size) 
{
    int i;
    double max_value = input_array[i];
    /*
    *Uses a for loop to loop through an array and compare each value
    to determine the greatest value in the array then returns that value
    */
    for(i = 0; i<array_size;i++) {
        if(input_array[i] > max_value) 
        {
            max_value = input_array[i];
        }
    }
    return max_value;
}