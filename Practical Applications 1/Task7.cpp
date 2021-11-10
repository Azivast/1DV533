// -------------------------------------------------------------------------------------
// File: Task7.cpp  
// Summary: Requests a three digit number and outputs the sum of the three digits.
// Version : 1  
// Author: Olle Astré
// -------------------------------------------------------------------------------------

// Preprocessor directives 
#include <iostream>
using namespace std;

void cls();

int main()  
{  
     char answer;

     do
     {
          int number;
          int d1, d2, d3;
          int sum;


          cls(); // Clear screen
          cout << "Input a three digit number: ";
          cin >> number;

          // Split 'number' into individual digits
          d1 = number / 100;
          d2 = (number % 100) / 10;
          d3 = number % 10;

          sum = d1+d2+d3;
          cout << "\nThe sum of the digits in " << number << " is " << sum << endl;

          cout << "New calculation (Y/N)?\n";
          cin >> answer;
     }
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}