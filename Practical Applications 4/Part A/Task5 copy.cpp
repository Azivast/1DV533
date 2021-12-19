//------------------------------------------------------------------------------
// File: Task5.cpp  
// Summary: Check if a word is a palindrome
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2021-12-17 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
#include <cstring> // strlen strcpy
using namespace std; 

// Prototypes
void cls();
bool isPalindrome(char s[]);
char *reverse(char *str);
char *capitalize(char *s);

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

// Reverses a c-string.
char *reverse(char *s) 
{  
    int left = 0, right = strlen(s) - 1; // left is index of the first, and 
                                         // right is index of the last character 
    while (left < right) 
    { 
        // "Swap first and last character ..."
        char temp = s[left];   
        s[left] = s[right]; 
        s[right] = temp; 

        // "... then step towards middle" 
        ++left;      
        --right; 
    } 
    return s; 
}

// Capitalize a c-string.
char *capitalize(char *s) 
{  
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s; 
}

// Check if a cstring is equal to it's reversed counterpart.
// Returns true if equal.
bool isPalindrome(char s[])
{
    // Capitalize so that capitalization doesn't matter
    capitalize(s);
    // Reverse the string
    char reversed[MAXLENGTH] = {'\0'}; 
    strcpy(reversed, s);
    reverse(reversed);
    // Compare if original and reversed are equal
    if (strcmp(s, reversed) == 0)
        return true;
    else
        return false;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}