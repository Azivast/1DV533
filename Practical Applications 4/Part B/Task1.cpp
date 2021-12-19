//------------------------------------------------------------------------------
// File: Task1.cpp  
// Summary: Reverses and stores a c-string
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2021-12-18 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
#include <cstring> // strlen
using namespace std; 

// Prototypes
void cls();
char *reverseString(char* inputString, char* outputString);

const int MAXLENGTH = 100; // Maximum length of strings

int main() 
{ 
    char answer; 
    do 
    {
        char str[MAXLENGTH] = {'\0'}; 
        char reversedStr[MAXLENGTH] = {'\0'}; 

        // Input
        cls();
        cout << "Enter a text: ";
        cin.getline(str, MAXLENGTH);

        // Output
        cout << "\nThe text backwards: " << reverseString(str, reversedStr) << endl;

        // Re-run
        cout << endl << "\nOne more time (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Makes a reversed copy of inputString and stores it in outputString
// Also returns outputString
char *reverseString(char* inputString, char* outputString)
{
    char *start = outputString;
    char *end = inputString + strlen(inputString) - 1;

    while (end >= inputString) 
    { 
        // Last char of input is set to the first char of output, then step "inwards" one character
        *start++ = *end--; 
    } 

    return outputString;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}