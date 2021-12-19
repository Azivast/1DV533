//------------------------------------------------------------------------------
// File: Task2.cpp  
// Summary: Abbreviates first name to a single character while keeping last name
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
void abbreviateName(char* name);

const int MAXLENGTH = 100; // Maximum length of strings

int main() 
{ 
    char answer; 
    do 
    {
        char name[MAXLENGTH] = {'\0'}; 

        // Input
        cls();
        cout << "Enter a full name: ";
        cin.getline(name, MAXLENGTH);

        // Abbreviate
        abbreviateName(name);

        // Output
        cout << "\nTreated name: " << name << endl;

        // Re-run
        cout << endl << "\nOne more time (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Abbreviates the first name when provided with a 'Firstname Lastname' cstring
// Also returns the 
void abbreviateName(char* name)
{
    int space = 0;

    // Find space that separetes first and last name
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ')
        {
            space = i;
            break;
        }
    }
    int i = 2;
    strcpy(name + 1, name + space); 
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}