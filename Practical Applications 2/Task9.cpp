//---------------------------------------------------------------------
// File: Task9.cpp  
// Summary: Calculates the sum of the digits in a given integer.
// Version : 1  
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-24 Created by Olle.
//
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
#include <limits> // numeric_limits
#include <climits> // INT_MAX
using namespace std;

// Prototypes 
int getInput(string promptText);
void sumOfDigits(int number);
void cls();

int main()  
{  
    char answer;

    do
    {
        cls(); // Clear screen
        int number = getInput("Enter a positive and arbitrarily big integer number: ");
        sumOfDigits(number);
        
        cout << "\nNew calculation (Y/N)? ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignore remainder of stream
    } 
    while (answer == 'Y' || answer == 'y');
    
    return 0;
} 

// Get user input and verify its validity
int getInput(string promptText)
{
    double raw_input;
    int final_input;
    cout << promptText;
    cin >> raw_input;
    
    // Verify if input is number and fits in int
    while (cin.fail() || raw_input > INT_MAX || raw_input < 0)
    {
        cin.clear(); 
        cin.ignore( numeric_limits<streamsize>::max(),'\n'); // Ignore remainder of stream
    
        cout << "\nError: Invalid input, please try again.\n"
            << promptText;
        cin >> raw_input;
    }

    final_input = raw_input;

    return final_input;
}


// Calculates and outputs the sum of all digits in a given number
void sumOfDigits(int number) 
{
    int sum = 0;

    for (int i = number; i > 0; i=i/10)
    {
        sum += (i % 10); // Adds last digit in i
    }

    cout << "\nThe sum in the digits in " << number << " is " << sum << "." << endl;
}

// Clear screen in both windows and linux
void cls()
{
    system("cls||clear");
    return;
}