/*
 * Name        : chairs.cpp
 * Author      : David Dalton
 * Description : Program to musical chairs list programs
 */
 
/**
 * Your driver will be tested against a series of input files. The input file 
 * will include a list of students playing the game. Then a list of numbers for 
 * how long the song plays each round. Use this number to go through the list 
 * to determine which player is eliminated from this round of the game 
 * starting at the player currently at the front of the list. The player after 
 * the eliminated player becomes the front of the list. Eliminated players are 
 * removed from the list.
 * Output the following:
 * A list of the players in the sorted order of input.
 * For each round until there is a winner
 * -  The ordinal number of the player eliminated and their name
 * -  A space separate list of the players still playing with the current front 
 *    player first.
 * The name of who won.
 */

#include "CinReader.cpp"
#include "dl_list.h"

#include <typeinfo>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;

int main()
{
    CinReader reader;
    bool end_program = false;
    bool done = false;
    // Asks the user for the name of the file
    cout << "Enter the name of the file being used including the file extension" 
        << endl;
    string filename = reader.readString(false);
    // Opens the file to the stream
    ifstream fin (filename.c_str());
    string current_line;
    string players;
    int games[4];
    int iterator_players = 0;
    int iterator_games = 0;
    /**
     * Loops through the file and sorts the lines into either a string array
     * or an integer array based on the contents of the lines
     */
    do {
            fin >> current_line;
            if(current_line[0] > 9)
            {
                players[iterator_players] = current_line;
                iterator_players = iterator_players + 1;
            } else
            {
                games[iterator_games] = current_line;
                iterator_games = iterator_games + 1;
            }
        } while(!fin.eof());
    /**
     * Creates the list of players using a node list where the contents
     * of each node equals the index of the player array + 1;
     */
     
    DLList list;
    for(int i = 0; i < 4; i++)
    {
        list.insert(i+1);
    }
    do
    {
        cout << "End game?" << endl;
        int end = reader.readChar();
        if(end == 'Y' || end == 'y')
        {
            end_program = true;
        }
    }while(!end_program);
}