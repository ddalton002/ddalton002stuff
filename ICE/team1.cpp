/*
 * Team 1 code
 */
#include<iostream>
#include <array>
/*
 * Outputs the scores in the array
 * @param int[] scores - The array to fill up
 * @param const int &size - The size of the array
 */
void Output(int scores[], const int &size)
{
    for (int i = 0; i < scores[].size; i++)
    {
        cout << scores[i] << endl;
    }
}

 //1.1 (Hunter and Nick)
 void Reverse(int &scores[])
 {
    int length=scores.size();
    
    scoreH[length];
    
    for (int i=0;i<=length;i++)
    {
        scoreH[i]=scores[i];
    }
    
    for (int i=0;i<=length;i++)
    {
        scores[i]=scoreH[length-i];
    }
 }

 //1.2 (Marie)
 void mfunc(int &mlarge, int &msmall, int marray[], int msize)
 {
     int i;
     for (i=0; i<msize; i++)
     {
         if (marray[i] > mlarge)
         {
             mlarge = marray[i];
         }
     }
     for (i=0; i<msize; i++)
     {
         if (marray[i] < msmall)
         {
             msmall = marray[i];
         }
     }
 }
 
 
 //1.3 River and Evan's Bit
 bool HighToLow(int array[])//function declaration
 {
     int size = array.size();
     for (int i = 0; i < size; i++ )//for loop, incriments int i
     {
         if (array[i] < array[i + 1])//checks to ensure that i < i + 1
         {
             return false;//if not it returns false
             exit;
         }
     }P
     return true;//if all passes, it will return true
 }
 
 //Russ and David  1.4
int ReverseArray(int Palendrome)
{
    int i= 0;
    int j = Palendrome.size();
    bool PaleTrue = true;
    while(PaleTrue)
      {
      if(Palendrome[i]==Palendrome[j])
        {
        i++;
    	j--;
    	if (i>j)
    	  {
          cout << "Its a Palendrome"<<endl;
          PaleTrue = false;
          }
       }
       else
       { 
           PaleTrue = false;
           cout << "It's not a Palendrome."<<endl;
        }
}
 //Ends here
 
 
 /*
 * Create a main function that uses the following array:
 * int scores[] = { 1, 2, 3, 4, 5 };
 * and uses all of the functions provided (as well as output).
 * 1. Output all values of the array
 * followed by the numbers on your sheets.  Output all returned
 * answers with appropriate verbage.
 */
 
 
 int main ()
 {
     int large = 0;
     int small =0;
     
     int scores[] = { 1, 2, 3, 4, 5 };
     
     Reverse(scores)
     cout<<"Reversed array is ";
     for (int i=0; i<5; i++)
     {
         cout<<scores[i]<<", ";
     }
     cout<<endl;
     
     mfunc(large, small, scores, 5);
     cout << "Largest: " << large;
     cout << endl << "Smallest: " << small;
     
     
     bool high_to_low_check;
     high_to_low_check = HighToLow(scores[]);
     cout << "High to low check returned : " << high_to_low_check << endl;
     
     cout << ReverseArray(scores)<<"1.4\n";
     
     
     return 0;
 }