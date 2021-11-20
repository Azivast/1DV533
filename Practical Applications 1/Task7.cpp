// --------------------------------------------------------------------
// File: Task7.cpp  
// Summary: Requests a three digit number and outputs the sum of the three digits.
// Version : 1  
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-09 Created by Olle.
//  
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
using namespace std;

void cls();

int main()  
{  
     char answer;

     do
     {
          int number = 0;
          int hundreds = 0, tens = 0, units = 0;
          int sum = 0;


          cls(); // Clear screen
          cout << "Input a three digit number: ";
          cin >> number;

          // Reprompt user if number is more than three digits or not a number
          while (cin.fail() || number > 999)
          {
               cin.clear();
               cin.ignore(80,'\n'); // Skip any possible debris and line endings

               cout << "\nInvalid input"
                    << "\nInput a three digit number: ";
               cin >> number;
          }

          // Split 'number' into individual digits
          hundreds = number / 100;
          tens = (number % 100) / 10;
          units = number % 10;

          sum = hundreds+tens+units;
          cout << "\nThe sum of the digits in " << number << " is " << sum << endl << endl;

          cout << "New calculation (Y/N)?\n";
          cin >> answer;
     } while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}