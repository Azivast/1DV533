//------------------------------------------------------------------------------
// File: Task3.cpp  
// Summary: Trim leading and trailing spaces in a cstring. Removes more than one
//          spaces between words.
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
char *trim(char* string);

const int MAXLENGTH = 100; // Maximum length of strings

int main() 
{ 
    char answer; 
    do 
    {
        char string[MAXLENGTH] = {'\0'}; 

        // Input
        cls();
        cout << "Enter a text: ";
        cin.getline(string, MAXLENGTH);

        // Output
        cout << "\nCleared text: _" << trim(string) << "_" << endl;

        // Re-run
        cout << endl << "\nOne more time (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Trims leading and trailing spaces and removes any more than one space between words.
char *trim(char* string)
{
    // Remove duplicate whitespaces
    bool nothingDone = true;
    for (int i = 0; i < strlen(string)-2; i++)
    {
        if (isgraph(string[i-1]) && isgraph(string[i+1]))
        {
            continue;
        }
        else
        {
            strcpy(string+i-1, string+i+1);
            nothingDone = false;
        }
    }
    if (!nothingDone)
        trim(string);
    else break;

    return string;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}