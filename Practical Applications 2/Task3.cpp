//---------------------------------------------------------------------
// File: Task3.cpp  
// Summary: Calculates the product of all odd numbers between 1 and 15.
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
void productOfOddIntegers();
void cls();

int main()  
{  
    productOfOddIntegers();
} 

// Calculates the product of all odd integers between 1 and 15
void productOfOddIntegers() 
{
    const int START = 1;
    const int STOP = 15;
    
    int product = 1;

    for (int i = START; i <= STOP; i++)
    {
        if (i % 2 == 0) // Next iteration if 'i' is even
            continue;

        product *= i;
    }

    cout << "The product of all odd integers between " << START << " and " << STOP << " is " << product << ".\n";
}