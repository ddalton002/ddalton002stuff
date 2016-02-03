/*
 * Name        : lab_3.cpp
 * Author      : David Dalton
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"


/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  int i;
  int length = input.length();
  int currentLetter;
/*
  Loops through input string and compares the ASCII values of each char to check
  if it is upper or lower case.  If it is upper case then it adds 32
  */
  for (i=0; i<length;i++){
      currentLetter = input.at(i);
      if (( currentLetter > 64) && (currentLetter < 91)) {
        currentLetter = (currentLetter + 32);
      }
  }
  //Takes result of loop and puts it into input variable, then returns input
  input = currentLetter;
  return input;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  int i;
  int length = input.length();
  int currentLetter;
/*
  Loops through input string and compares the ASCII values of each char to check
  if it is upper or lower case.  If it is lower case then it subracts 32
  */
  for (i=0; i<length;i++){
      currentLetter = input.at(i);
      if (( currentLetter > 96) && (currentLetter < 123)) {
        currentLetter = (currentLetter - 32);
      }
  }
  //Takes result of loop and puts it into input variable, then returns input
  input = currentLetter;
  return input;
}

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */

string Goldilocks(string item, int number) {
  ToLower(item);
  string storyLine;
  /*
  Takes user input, number, and uses it as a case for a switch.  It then compares
  the second input, item to determine which string to return
  */
  switch (number) {
    case 1:
    if (item == "porridge") {
      storyLine = "This porridge is too hot";
    } else if (item == "chair"){
      storyLine = "This chair is too big";
    } else if (item == "bed"){
      storyLine =  "This bed is to hard";
    }
    break;
    case 2:
    if (item == "porridge") {
      storyLine = "This porridge is too cold";
    } else if (item == "chair"){
      storyLine = "This chair is too small";
    } else if (item == "bed"){
      storyLine = "This bed is to softt";
    }
    break;
    case 3:
    if (item == "porridge") {
      storyLine = "This porridge is just right";
    } else if (item == "chair"){
      storyLine = "This chair is just right";
    } else if (item == "bed"){
      storyLine = "This bed is just right";
    }
  }
  //Returns value of string stroyLine
  return storyLine;
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalud inputs
 */
 
int RockScissorPaper(char player_one, char player_two) {
  //Takes input param of player_one and player_two and converts them to uppercase
  player_one = toupper(player_one);
  player_two = toupper(player_two);
  /*
  Uses input of player_one as a argument for a switch to determine results.
  Compares input of player_one to input of player_two to determine results and
  return those results.
  */
  switch (player_one) {
      case 'R':
      if ((player_two == 'S') || (player_two == 'L')) {
          return 1;
      } else if ((player_two == 'R')){
          return 3;
      } else if ((player_two == 'P') || (player_two == 'K')){
          return 2;
      } else {
          return 0;
      }
      break;
      case 'P':
      if ((player_two == 'R') || (player_two == 'P')) {
          return 1;
      } else if ((player_two == 'P')){
          return 3;
      } else if ((player_two == 'S') || (player_two == 'L')){
          return 2;
      } else {
          return 0;
      }
      break;
      case 'S':
      if ((player_two == 'P') || (player_two == 'L')) {
          return 1;
      } else if ((player_two == 'S')){
          return 3;
      } else if ((player_two == 'R') || (player_two == 'K')){
          return 2;
      } else {
          return 0;
      }
      break;
      case 'L':
      if ((player_two == 'P') || (player_two == 'K')) {
          return 1;
      } else if ((player_two == 'L')){
          return 3;
      } else if ((player_two == 'R') || (player_two == 'S')){
          return 2;
      } else {
          return 0;
      }
      break;
      case 'K':
      if ((player_two == 'S') || (player_two == 'R')) {
          return 1;
      } else if ((player_two == 'K')){
          return 3;
      } else if ((player_two == 'P') || (player_two == 'L')){
          return 2;
      } else {
          return 0;
      }
      break;
      default:
      return 0;
  }
  
}



//Main for testing purposes only!!!
int main() {
  string lowercase = "lowercase!H";
  ToUpper(lowercase);
  cout << lowercase << endl;
  string uppercase = "UPPERCASE!h";
  ToLower(uppercase);
  cout << uppercase << endl;
  cout << Goldilocks("porridge", 1) << endl;
  cout << Goldilocks("porridge", 2) << endl;
  cout << Goldilocks("porridge", 3) << endl;
  cout << Goldilocks("chair", 1) << endl;
  cout << Goldilocks("chair", 2) << endl;
  cout << Goldilocks("chair", 3) << endl;
  cout << Goldilocks("bed", 1) << endl;
  cout << Goldilocks("bed", 2) << endl;
  cout << Goldilocks("bed", 3) << endl;
  cout << "Lets play Rock, Paper, Scissors, Lizard, Spock!" << endl;
  cout << "Player 1 enter your selection:" << endl;
  cout << "R - Rock P - Paper S - Scissors L - Lizard K - Spock." << endl;
  char player_one;
  cin >> player_one;
  cout << "Player 2 enter your selection:" << endl;
  cout << "R - Rock P - Paper S - Scissors L - Lizard K - Spock." << endl;
  char player_two;
  cin >> player_two;
  cout << RockScissorPaper(player_one, player_two) << endl;
}


  


