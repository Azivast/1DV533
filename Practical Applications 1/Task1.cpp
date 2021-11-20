// --------------------------------------------------------------------
// File: Task1.cpp  
// Summary: Requests an employee's monthly wage (salary), calculates and prints
//          the retroactive wage for the last 6 months and the new monthly wage
//          given a wage precentage increase.
// Version : 1  
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-09 Created by Olle.
//  
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
#include <iomanip>
using namespace std;

const double PERCENT = 2.6;
const double FACTOR = PERCENT/100;

int main()  
{  
     // Define variables and initialize variables
     int monthlyWage = 0;
     int newMonthlyWage = 0;
     int retroactiveWage = 0;
     char answer;

     do 
     {
          // Input
          system("clear");  // Clear the screen. If on windows use 'cls' instead of 'clear'
          cout << "PAY RAISE\n"
               << "=====================\n"
               << "Please enter your monthly wage: ";
          cin >> monthlyWage;
          cin.ignore(80,'\n'); // Skip any possible debris and line endings
          cout << endl << endl;

          // Calculations
          newMonthlyWage = static_cast<int>(monthlyWage * (1 + FACTOR) + 0.5);
          retroactiveWage = static_cast<int>(monthlyWage * FACTOR * 6 + 0.5);

          // Display results
          cout << "===========================================\n"
               << "Your new monthly wage will be " << newMonthlyWage << " kr." << endl
               << "The retroactive wage for your last 6 months will be " << retroactiveWage << " kr." << endl << endl;

          cout << "New calculation (Y/N)?\n";
          cin >> answer;
     }
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 