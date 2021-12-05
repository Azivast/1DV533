//---------------------------------------------------------------------
// File: Task8.cpp  
// Summary: Prints all prime numbers between 2 and 100.
// Version : 1  
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-24 Created by Olle.
//
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
using namespace std;

// Prototypes 
void printPrimeNumbers();
void cls();

int main()  
{
    cls(); // Clear screen
    printPrimeNumbers();
} 

// Finds and outputs the sum of all digits in a given number
void printPrimeNumbers() 
{
    const int START = 2;
    const int STOP = 100;

    cout << "The prime numbers between " << START << " and " << STOP << " are as follows:\n";

    for (int i = START+1; i < STOP; i++)
    {
        bool prime = true;

        // Check from 2 to i-1 for divisor
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) // can't be prime if divisor is found
            {
                prime = false;
                break;
            }
        }

        if (prime)
            cout << i << " ";
    }

    cout << endl;
}

// Clear screen in both windows and linux
void cls()
{
    system("cls||clear");
    return;
}