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
        cout << "\nCleared text: " << trim(string) << endl;

        // Re-run
        cout << "\nOne more time (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Trims leading, trailing, and duplicate spaces
char *trim(char *string)
{
    // Trim any leading space
    char *start = string;
    while(isspace(*start))
        start++;
    if(*start == 0) // No need to proceed if string is all spaces
        return start;
    strcpy(string, start); // Undefined behavior! Strings should not overlap

    // Remove duplicate spaces between words
    for (int i = 1; i < strlen(string)-2; i++) // No need to check first since leading spaces have already been removed
    {
        while (isspace(string[i]))
        {
            if (isspace(string[i]) && isspace(string[i+1]))
                strcpy(string+i, string+i+1); // Move characters "down" one step
            else break;
        }
    }

    // Trim trailing spaces
    char *end = string + strlen(string)-1;
    while((end > string) && isspace(*end))
        end--;
    // Ensure string ends with null terminator
    end[1] = '\0';

    return string;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}