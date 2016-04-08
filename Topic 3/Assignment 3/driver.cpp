/**
 * Name: driver.cpp
 * Author: David Dalton
 * Sources:
 */
 
/*
driver
  instances of Prize and Box
  menu containing options to exercise all public functions in Prize and Box
classes
*/

#include "CinReader.cpp"
#include "box.h"

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stringstream;

int main()
{
    bool end_program = false;
    do
    {
    CinReader reader;
    bool done = false;
    string name = "";
    string color = "";
    unsigned int prizeNum = 0;
    unsigned int value = 0;
    unsigned int number = 0;
    unsigned int action = 0;
    
    cout << "Lets put together some prizes!" << endl;
    cout << "Enter a number for the box" << endl;
    number = reader.readInt(0);
    cout << "Enter the color of the box" << endl;
    color = reader.readString(false);
    cout << "How many prizes will the box hold?" << endl;
    prizeNum = reader.readInt(0);
    Box newBox(number, color, prizeNum);
    cout << "Here's the prize you can win!" << endl;
    cout << "The box number is: " << number << ".  The color is: " << color
        << ". The number of prizes in the box is: " << prizeNum << ".\n" 
        << endl;
        int change_attribute;
        do
        {
            cout << "Lets get some prizes!\n" << endl;
            cout << "What do you want to do?\n" << endl;
            
            cout << "1 - See what's in the box\n2- Inspect the box\n3 - Change the box\n4 - Quit\n";
            action = 0;
            action = reader.readInt(0,4);
            
            switch(action)
            {
                case 1:
                    cout << "The box contains the following prizes." << endl;
                    for (unsigned int i = 0; i < newBox.getPrizeCount();i++)
                    {
                        cout << "Prize # " << i + 1 << " " 
                            << newBox.getPrize(i).getPrizeName() 
                            << " with a value of $" 
                            << newBox.getPrize(i).getPrizeValue() << ".\n" 
                            << endl;
                    }
                break;
                
                case 2:
                    cout << "Box number: " << newBox.getBoxNumber() 
                    << ". Box Color: " << newBox.getBoxColor() 
                    << ". Prize Capacity: " 
                    << ". " << newBox.getPrizeCapacity() << ".\n" << endl;
                break;
                
                case 3:
                    cout << "What would you like to change?" << endl;
                    cout << "1 - Box Number 2 - Box Color 3 - Add a prize 4 - Remove a prize" << endl;
                    change_attribute = reader.readInt(0, 4);
                    switch(change_attribute)
                    {
                        case 1:
                            cout << "Enter the new number of the box" << endl;
                            number = reader.readInt(0);
                            newBox.setBoxNumber(number);
                            cout << "The box is now the number: " 
                            << number << ".\n" << endl;
                        break;
                        
                        case 2:
                            cout << "Enter the new color of the box" << endl;
                            color = reader.readString(false);
                            newBox.setBoxColor(color);
                            cout << "The box is now the color: " 
                            << color << ".\n" << endl;
                        break;
                        
                        case 3:
                            cout << "Enter the name of the prize you are adding" << endl;
                            name = reader.readString(false);
                            cout << "Enter the prizes value" << endl;
                            value = reader.readFloat();
                            if(value < 0)
                            {
                                value = 0;
                            }
                            if(!newBox.addPrize(Prize(name, value)))
                            {
                                cout << "No more room for prizes, this box is loaded!\n" << endl;
                            }
                        break;
                        
                        case 4:
                            cout << "Which prize will you be keeping for yourself? Enter the prize number now" << endl;
                            number = reader.readInt(0);
                            if (newBox.getPrize(number -1).getPrizeValue() == 0)
                            {
                                cout << "No prize:  You walk away empty-handed" << endl;
                            } else
                            {
                                newBox.removePrize(number);
                            }
                        break;
                    }
                break;
                
                case 4:
                    done = false;
                break;
            }
        }while(!done);
        
        cout << "Do you want to make a new box?  Enter Y or N" << endl;
        char make_new_box;
        make_new_box = reader.readChar("Yy");
        if(make_new_box != 'Y' || make_new_box != 'y')
        {
            end_program = true;
        }
    }while(!end_program);
    return 0;
}