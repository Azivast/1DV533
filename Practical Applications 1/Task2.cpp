// -------------------------------------------------------------------------------------
// File: Task2.cpp  
// Summary:  A program that reads four integers, input by the user. The program calculates the 
//           sum, mean value and product of the four integers. 
// Version : 1  
// Author: Olle Astré
// -------------------------------------------------------------------------------------

// Preprocessor directives 
#include <iostream>
#include <iomanip> //setw fixed setprecision
using namespace std;

const double PERCENT = 2.6;
const double FACTOR = PERCENT/100;

void statistics();
void cls(void);

int main()  
{  
     char answer;

     do 
     {
          statistics();

          cout << "One more time? (y/n?)?\n";
          cin >> answer;
     }
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

void statistics() 
{ 
               // Define variables and initialize variables
               int first = 0, second = 0, third = 0, forth = 0;
               int sum;
               double avarage;
               double product;

               // Input
               cls(); // clear screen
               cout << "STATISTICS\n"
                    << "==========\n"
                    << "Enter four integers: ";
               cin >> first >> second >> third >> forth;

               // Calculations
               sum = first + second + third + forth;
               avarage = sum / 4.0;
               product = first * second * third * forth;

               // Output
               cout << fixed << showpoint; // Decimal form, display trailing zeroes
               cout << "Entered integers " 
                    << setw(8) << first
                    << setw(8) << second
                    << setw(8) << third
                    << setw(8) << forth
                    << endl << endl;

               cout << setw(8) << "Sum" << setw(12) << "Avarage" << setw(12) << "Product\n" 
                    << setw(8) << "---" << setw(12) << "-------" << setw(12) << "-------\n" 
                    << setw(8) << sum
                    << setw(12) << setprecision(2) << avarage
                    << setw(12) << setprecision(0) << product << endl;
     }

// Clear screan in both windows and linux
void cls(void)
{
    system("cls||clear");
    return;
}
