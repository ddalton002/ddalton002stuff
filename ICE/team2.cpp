/*
 * Team 2 (worse than 1) code
 */
 #include <iostream>
 #include <sstream>
 using namespace std;
 // Line 5 and we already failed
 
 int Average(int array[],int length){
    int total=0, average=0;
    for(int i=0; i<length; i++){
        total+=array[i];
    }
    average = total/length;
    return average;
}
/*
 * Outputs the scores in the array
 * @param int[] scores - The array to fill up
 * @param const int &size - The size of the array
 */
void Output(int scores[], const int &size)
{
    
}
//2.1 Reversing the order of an array(Dustin/Tyler)
void Reversal (int (&input)[100])
{
    int temp[100];
    for (int i=0;i<sizeof(input);i++ )
    {
        temp[i]=input[il
        
    }
    for (int i=sizeof(input);i>=0;i--)
    {
        input[sizeof(input)-i]=temp[i];
    }
}

bool HightoLow(int num_array[])                 // 2.3 High-to-Low (Harris/Knight)
{
    bool check_math = true;                      // Create a boolean variable since return would end the function
    for(int i = 0; i < num_array.size(); i++)    // For loop to check the values of each slot
    {                               
        int first = num_array[i];                // The first variable will hold the current place of the loop (the one that comes right now).
        int next = num_array[i+1];               // The second variable will hold the second place of the loop (the one right after the current place).
        if(first < next)                         //test if the first array slot is less than the array slot after
        {                               
          bool check_math = false;              //if true then the array isnt from Highest to Lowest and assigns false for the bool variable
          i = num_array.size();                               // End the loop as soon as we get a false statement
        }                               
    }                               
    return check_math;                           // Return the boolean
}

// 2.4 Reversible Array Check (Jason/Philip)
bool IsReversible(int[] intArray, unsigned arraySize)
{
    bool Result = true;
    arraySize -= 1;
    unsigned i = 0;

    while (Result && (i < arraySize))
    {
        Result = (intArray[i] == intArray[arraySize - i]);
        i += 1;
    }

    return Result;
}

bool LargestSmallest (int array[])//is this supposed to be a bool function to return a string?
{
    int largest;
    int smallest;
    //int number = array.size();
    stringstream ss;
    for (int i = 0; i < array.size() - 1; i++)//searches for largest number
    {
        if (array[i + 1] < array[i])//checks which array slot the largest
        {
            largest = array[i];//saves largest number
        }
    }
    
    for (int i = 0; i < array.size() - 1; i++)//searches for smallest number
    {
        if (array[i + 1] > array[i])//checks which array slot is the smallest
        {
            smallest = array[i];//saves smallest number
        }
    }
    
    ss << "Largest score: " << largest << " Smallest score: " << smallest;
    string str = ss.str();
    return str;
}
/*
 * Create a main function that uses the following array:
 * int scores[] = { 1, 2, 3, 4, 5 };
 * and uses all of the functions provided (as well as output).
 * 1. Output all values of the array
 * followed by the numbers on your sheets.  Output all returned
 * answers with appropriate verbage.
 */

int main(int argc, char** argv)//really good main function ;)
{
    int scores[] = { 1, 2, 3, 4, 5 };
    int length=5;
    int ScoreAverage = Average(scores, length);
    Reversal(scores);
    bool reversible = IsReversible(scores, length);
    cout << "Score is reversible: " << boolalpha << reversible << endl;
    
    //Team Rocket (blast off at the speed of light, meouth thats right!)
    string largest_smallest = "";
    largest_smallest = LargestSmallest (scores[]);
    cout << largest_smallest;
}