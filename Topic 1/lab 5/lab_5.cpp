/*
 * Name        : lab_5.cpp
 * Author      : David Dalton
 * Description : Practicing Functions. Use this file to write your
 *               Function Definitions (what goes below main()).
 */

#include "lab_5.h"

/*
 * Function Name: Hello
 *
 * Displays "Hello world!" to stdout (cout) (no newline character after)
 */
void Hello() {
    cout << "Hello world!";
}

/*
 * Function Name: PrintMessage
 *
 * Displays the string parameter to stdout (no newline character)
 * @param const string& - The string to display to stdout
 */
string PrintMessage(const string& kMessage) {
    cout << kMessage;
    return kMessage;
}

/*
 * Function Name: GetAnswer
 *
 * Returns the integer value 42.
 * @return int - The value 42
 */
int GetAnswer(){
    return 42;
}

/*
 * Function Name: FindLarger
 *
 * Returns the larger of the two parameter values. Should work correctly
 * if the values are equivalent (returns either one)
 * @param int - The first value
 * @param int - The second value
 * @return int - The larger of the two values, or either one if they are equal
 */
int FindLarger(int first_value, int second_value) {
    /*Compares the values of the two ints, then returns an int depending on the
    results
    */
    if(first_value > second_value) {
        return first_value;
    } else if(first_value < second_value) {
        return second_value;
    } else {
        return first_value;
    }
}

/*
 * Function Name: BuildMessage
 *
 * Return the string "Message: STRING", where STRING is replaced by the value of
 * the first parameter (string). If second parameter (bool) is true, convert
 * first parameter (string) to all uppercase letters before concatenating it
 * with "Message: ". If first parameter is the empty string, return
 * "Message: empty".
 * @param string - A message.
 *               - Defaults to "" (empty string)
 * @param bool - To indicate if we should uppercase letters or not
 *             - Defaults to false
 */
string BuildMessage(string message, bool upper_case) {
    /*checks to see if the message string is empty
    If string is empty then it stores "empty", then concatenates it into the
    the variable and returns the concatenated string
    */
    if(message == "") {
        message = "empty";
        stringstream returnedString;
        returnedString << "Message: " << message;
        return returnedString.str();
    /*
    If string is not empty then it checks to see if the bool is set to true
    If it is, then it changes the string to uppercase
    */
    } else {
        if (upper_case == true) {
            int i;
            int length = message.length();
            for (i=0; i<length;i++){
                message[i] = toupper(message[i]);
            }
        //Concatenates the strings together and returns them
        }
        stringstream returnedString;
        returnedString << "Message: " << message;
        return returnedString.str();
    }
}
