/*
 * Name        : lab_5.h
 * Author      : David Dalton
 * Description : Practicing Functions. Use this file to write your
 *               Function Prototypes (what goes above main()).
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <streambuf>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Function Name: Hello
 *
 * Displays "Hello world!" to stdout (cout) (no newline character after)
 */
void Hello();

/*
 * Function Name: PrintMessage
 *
 * Displays the string parameter to stdout (no newline character)
 * @param const string& - The string to display to stdout
 */
string PrintMessage(const string& kMessage);

/*
 * Function Name: GetAnswer
 *
 * Returns the integer value 42.
 * @return int - The value 42
 */
int GetAnswer();

/*
 * Function Name: FindLarger
 *
 * Returns the larger of the two parameter values. Should work correctly
 * if the values are equivalent (returns either one)
 * @param int - The first value
 * @param int - The second value
 * @return int - The larger of the two values, or either one if they are equal
 */
int FindLarger(int first_value, int second_value);

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
string BuildMessage(string message = "", bool upper_case = false);

#endif
