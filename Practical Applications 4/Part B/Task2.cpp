//------------------------------------------------------------------------------
// File: Task2.cpp  
// Summary: Abbreviates first name to a single character while keeping last name
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2021-12-18 Created by Olle.
//       2021-12-23 Use memmove instead of strcpy to prevent undefined behavior.
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
#include <cstring> // strlen
using namespace std; 

// Prototypes
void cls();
char *abbreviateName(char* name);

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
        cout << "\nOne more time (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Abbreviates the first name when provided with a 'Firstname Lastname' c-string
// Also returns the c-string
char *abbreviateName(char* name)
{
    int space = 0;

    // Find space that separates first and last name
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ')
        {
            space = i;
            break;
        }
    }

    // Remove everything between first letter and space
    //strcpy(name + 1, name + space); Not using this. Overlapping memory = undefined behavior
    memmove(name + 1, name + space, strlen(name) - space + 1); // Last "+ 1" includes null termination character

    return name;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}