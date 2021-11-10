// -------------------------------------------------------------------------------------
// File: Task10.cpp  
// Summary: Calculates compound interest. 
// Version : 1  
// Author: Olle Astré
// -------------------------------------------------------------------------------------

// Preprocessor directives 
#include <iostream>
#include <cmath> // pow
using namespace std;

void getUserInput();
double calculateInterest(double initialAmount, int years);
void printResult(double result);
void cls();

const int RATE = 3; // Interest rate
double initialAmount = 0;
int years;

int main()  
{  
     char answer;
     do
     {
          cls();
          cout << "COMPOUND INTEREST\n";
          cout << "==============\n\n";
          getUserInput();
          double result = calculateInterest(initialAmount, years);
          printResult(result);


          cout << "One more time (Y/N)? ";
          cin >> answer;
          cin.ignore(80,'\n'); // Ignore possible debris and line endings 
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

void getUserInput()
{
    // TODO: sanetize user input
     cout << "Load initial amount: ";
     cin >> initialAmount;

     cout << "\nLoad number of years: ";
     cin >> years;
     cout << endl;
}

void printResult(double result)
{
     // TODO: Right align 12 characters
     cout << "The capital with " << RATE << " \% interest rate and after " << years << " years will be: " << result << " SEK\n\n";
}


// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}