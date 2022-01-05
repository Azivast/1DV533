//------------------------------------------------------------------------------
// File: Task1.cpp  
// Summary: Reads and stores arbitrary number of integers seperated by space or 
//          new line until non-numeric value is encountered.
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-04 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
using namespace std; 

int main() 
{ 
    int* integers = new int[0];
    int counter = 0;
    int input;

    // Input
    cout << "Enter integer numbers to store (Stop by entering any non-numeric value): ";
    while (cin >> input, !cin.fail())
    {
        counter++;

        // Copy to temporary array and store input at end
        int* tmp = new int[counter];
        copy(integers, integers+counter-1, tmp);
        tmp[counter-1] = input;

        // Delete old array and point integers to new one.
        delete integers; 
        integers = tmp;
    }

    // Output
    cout << "you entered " << counter << " numbers: ";
    for (int i = 0; i < counter; i++)
        cout << integers[i] << " ";
    cout << endl;

    // Free up memory
    delete integers;
} 