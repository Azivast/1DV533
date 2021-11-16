// -------------------------------------------------------------------------------------
// File: Task10.cpp  
// Summary: Calculates compound interest. 
// Version : 1  
// Author: Olle Astré
// -------------------------------------------------------------------------------------

// Preprocessor directives 
#include <iostream>
#include <iomanip> //setw, setfill
#include <cmath> // pow
#include <limits>  // numeric_limits
using namespace std;

// Prototypes 

double getUserInput(string promptText);
double calculateInterest(double initialAmount, int years);
void printResult(double result);
void cls();

// Global variables
const int RATE = 3; // Interest rate
double initialAmount = 0;
int years;

int main()  
{  
     char answer;
     do
     {
          cls();
          cout << "COMPOUND INTEREST\n"
               << "==============\n\n";

          initialAmount = getUserInput("Load initial amount: ");
          years = getUserInput("Load number of years: ");
          cout << endl;

          double result = calculateInterest(initialAmount, years);
          printResult(result);

          cout << "One more time (Y/N)? ";
          cin >> answer;
          cin.ignore( numeric_limits<streamsize>::max(),'\n'); // Ignore possible debris and line endings 
     } 
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

double calculateInterest(double initialAmount, int years)
{
     double finalAmount = 0;
     finalAmount = (initialAmount * pow((1 + RATE / 100.0), years));
     return finalAmount;
}

// Print promptText & get input
// Reprompts in case of invalid input
double getUserInput(string promptText)
{
     double input;
     cout << promptText;
     cin >> input;
     
     while (cin.fail())
     {
          cin.clear(); 
          cin.ignore( numeric_limits<streamsize>::max(),'\n');
     
          cout << "\nInvalid input."
               << "\nPlease try again: ";
          cin >> input;
          cout << endl;
     } 

     return input;
}

void printResult(double result)
{
     cout << "The capital with " << RATE << " \% interest rate and after " << years << " years will be: "
     << right << setw(12) << setfill('_') << result << " SEK\n\n"; // Right aligned in 12 character space with fill characters
}


// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}