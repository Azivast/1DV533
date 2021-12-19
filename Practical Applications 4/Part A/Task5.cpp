//------------------------------------------------------------------------------
// File: Task5.cpp  
// Summary: Check if a word is a palindrome
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
bool isPalindrome(char s[]);

const int MAXLENGTH = 100; // Maximum length of temp strings

int main() 
{ 
    char answer; 
    do 
    {
        cls();
        // Input
        char s[MAXLENGTH] = {'\0'}; 
        cout << "Enter a word or phrase: ";
        cin.getline(s, MAXLENGTH);

        // Check if palindrome
        bool palindrome = isPalindrome(s);

        // Output
        if (palindrome)
            cout << "It is a palindorome.\n";
        else 
            cout << "It is not a palindorome.\n";

        // Re-run
        cout << endl << "\nOne more time (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Check if a cstring is equal to it's reversed counterpart.
// Returns true if equal.
bool isPalindrome(char s[])
{
    int left = 0, right = strlen(s) - 1; // left is index of the first, and 
                                         // right is index of the last character 
    while (left < right) 
    { 
        // "Check if first and last character are equal..."
        if (toupper(s[left]) != toupper(s[right]))
            return false;

        // "... then step towards middle" 
        ++left;      
        --right; 
    } 

    return true;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}