//---------------------------------------------------------------------
// File: Task4.cpp  
// Summary: Estimate height of child using parents' heights.
// Version: 1
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-12-07 Created by Olle Astré.
//
//--------------------------------------------------------------------- 
#include <iostream>
#include <iomanip> // fixed setprecision
#include <limits> // numeric_limits 

using namespace std;

// Prototypes
void cls();
void getInput(double& height, string promptText);
void getInput(char& gender, string promptText);
double childHeight(char gender, double fatherHeight, double motherHeight);
void printHeight(double height);

int main() 
{ 
    double fatherHeight= 0, motherHeight = 0, height = 0;;
    char gender = 'm';

    char answer = 'Y'; 
    do 
    { 
        cls();
        cout << "Estimate Height" << endl; 
        cout << "===============" << endl; 

        // Input
        getInput(fatherHeight, "What is the father's height? (cm): ");
        getInput(motherHeight, "What is the mothers's height? (cm): ");
        getInput(gender, "Is the childe male or female (m/f): ");

        // Calc
        height = childHeight(gender, fatherHeight, motherHeight);

        // Output
        printHeight(height);

        cout << endl << "One more time (Y/N)? "; 
        cin >> answer; 
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignore remainder of stream
    } while (toupper(answer) == 'Y'); 

    return 0; 
}

// Prints promptText and returns input through first variable.
void getInput(double& height, string promptText)
{
    cout << promptText;
    cin >> height; 
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
void getInput(char& gender, string promptText)
{
    cout << promptText;
    cin >> gender; 
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

// Estimates a childs height given gender and parents height.
// Input and output in centimeters.
double childHeight(char gender, double fatherHeight, double motherHeight)
{
    double childHeight = 0;

    if (gender == 'm' || gender == 'M') // Male
    {
        childHeight = ((motherHeight*13.0/12.0) + fatherHeight) / 2.0;
    }
    else if (gender == 'f' || gender == 'F') // Female
    {
        childHeight = ((fatherHeight*12.0/13.0) + motherHeight) / 2.0;
    }
    else
    {
        cerr << "Invalid gender. Please try again and enter only 'm' or 'f'." << endl;
    }

    return childHeight;
}

// Output provided height
void printHeight(double height)
{
    cout << fixed << setprecision(0) // 0 decimals.
         << "\nThe height of the child will be approximately " << height << " cm.\n";
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}