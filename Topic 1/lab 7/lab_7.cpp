/*
 * Name        : lab_7.cpp
 * Author      : David Dalton
 * Description : Working with File I/O
 */
#include "lab_7.h"

// CODE HERE -- FUNCTION DEFINITION FOR ProcessFile()
/*
 * Open and read the contents of a text file. Each line of the
 * file will contain a single integer of possible values 10, 20,
 * 30, 40, or 50. Perform the following operations on the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * DON'T FORGET TO CLOSE YOUR FILE BEFORE YOUR FUNCTION ENDS!!!
 * @param string filename - A string containing the name of the file to
 *                          be processed
 * @return bool - True if filename was successfully opened and processed,
 *                else false
 */

bool ProcessFile(string filename) 
{
    string current_line;
    //Opens the file in the file stream
    ifstream fin (filename.c_str());
    /*
    *Uses the if statement to verify the filename and returns false if the 
    *filename is invalid
    */
    if(fin.fail()) 
    {
        return false;
    } else 
    {
        /*
        *Uses a do/while loop to check every line in the file.  It stores the
        *current line in a string then compares the value of the string to
        *set values to determine which counter function to call.  When the 
        *end of the file is reached it returns true.
        */
        do {
                fin >> current_line;
                if(current_line == "10")
                {
                    OnTen();
                } else if(current_line =="20") 
                {
                    OnTwenty();
                } else if(current_line == "30") 
                {
                    OnThirty();
                } else if(current_line == "40") 
                {
                    OnForty();
                } else if(current_line == "50")
                {
                    OnFifty();
                } else 
                {
                    OnError();
                }
            } while(!fin.eof());
        return true;
    }
    //Closes the file
    fin.close();
}

/*
 * Process the argv array (command-line arguments to the program). Ignore
 * argv[0] as that is the program name. Perform the following operations on
 * the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * @param int argc - Contains the number of arguments passed to the program
 *                   on the command-line
 * @param char *argv[] - An array containing the command-line arguments
 */
void ProcessArguments(int argc, char* argv[]) 
{
    int i;
    /*
    *Loops through the argument array and stores the value of the current
    *array location into a string, then compares the string to preset
    *values to determine which counter function to call.
    */
    for(i=1;i<argc;i++)
    {
        string current_argument = argv[i];
        if(current_argument == "10")
        {
            OnTen();
        } else if(current_argument == "20") 
        {
            OnTwenty();
        } else if(current_argument == "30")
        {
            OnThirty();
        } else if(current_argument == "40") 
        {
            OnForty();
        } else if(current_argument == "50") 
        {
            OnFifty();
        } else 
        {
            OnError();
        }
    }
}