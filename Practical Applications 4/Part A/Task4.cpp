//------------------------------------------------------------------------------
// File: Task4.cpp  
// Summary: Gets a Social Security Number and find out if it belongs to a man
//          or a woman
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2021-12-18 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
#include <cctype> // isdigit
#include <cstring> // strlen
using namespace std; 

// Prototypes
void cls();
void getInput(char ssn[]);
bool ssnOK(char ssn[]);
void outputGender(char ssn[]);

const int STRINGLENGTH = 20; // Length of tmp strings
const int MAXLENGTH = 11; // Maximum allowed ssn length
const int MINLENGTH = 10; // Minimum allowed ssn length

int main() 
{ 
    char answer; 
    do 
    {
        char ssn[STRINGLENGTH] = {'\0'}; 

        //cls();
        getInput(ssn);
        outputGender(ssn);

        cout << endl << "Want to check another Social Security Number (Y/N)? "; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Validates SSN
bool ssnOK(char ssn[]) 
{
    // Check if only allowed characters
    for (int i = 0; i < strlen(ssn); i++)
    {
        if (!isdigit(ssn[i]))        
        {
            if (i == 6 && ssn[i] == '-' && strlen(ssn) == 11) // Unless hyphen in digit 6 
                continue;     
            else
                return false;
        }
    }

    // Rudimentary validation of months and days.
    if (ssn[2]-'0' > 1 || (ssn[2]-'0' == 1 && ssn[3]-'0' > 2)) // If month is above 12. -'0' to convert char to int
        return false;
    if (ssn[4]-'0' > 3 || (ssn[4]-'0' == 3 && ssn[5]-'0' > 1)) // If day is above 31
            return false;

    return (strlen(ssn) <= MAXLENGTH) && strlen(ssn) >= MINLENGTH;
}

// Get SSN as c-string from user. 
void getInput(char ssn[])
{
    bool valid = false;
    do 
    { 
        cout << "\nPlease enter a Social Security Number: ";
        cin.getline(ssn, STRINGLENGTH, '\n');
        valid = ssnOK(ssn); 
        
        if (!valid) 
            cout << "\nInvalid number, please enter the number in format: YYMMDD-XXXX: " << endl; 
    } while (!valid); 
}

void outputGender(char ssn[])
{
    if (strlen(ssn) == 10)
    {
        if (ssn[MAXLENGTH-3] % 2 == 0) // Second to last digit in ssn is even
            cout << "\nThe SSN " << ssn << " belongs to a woman\n";
        else
            cout << "\nThe SSN " << ssn << " belongs to a man\n";
    }
    else // Must be 11 char
        if (ssn[MAXLENGTH-2] % 2 == 0) // Second to last digit in ssn is even
            cout << "\nThe SSN " << ssn << " belongs to a woman\n";
        else
            cout << "\nThe SSN " << ssn << " belongs to a man\n";
}
// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}