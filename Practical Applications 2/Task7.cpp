//---------------------------------------------------------------------
// File: Task7.cpp  
// Summary: Reads nine judgment scores for figure skating and outputs final score.
// Version : 1.1 
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-24 Created by Olle.
//  2021-11-27 Don't round input to get a more correct output.
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
#include <iomanip> // fixed setprecision
#include <limits> // numeric_limits
#include <cmath> // round
using namespace std;

// Prototypes 
void calcScore();
void cls();

int main()  
{
    char answer;
    do
    {
        cls(); // Clear screen
        calcScore();

        cout << "One more time (Y/N)? ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignore possible debris and line endings 
    } 
    while (answer == 'Y' || answer == 'y');
    
    return 0;

} 

// Calculate and print score
void calcScore() 
{
    const int JUDGES = 9; // Number of judges
    double finalScore = 0;

    cout << "Input " << JUDGES << " judgments scores (with one decimal precision): ";

    double lowest = 0;
    double highest = 0;

    for (int i = 1; i <= JUDGES; i++)
    {
        double input;
        cin >> input;

        if (i == 1) // Give low an initial value so that below if statement works
            lowest = input;
            
        // Check if input should take the place as lowest or highest score
        if (input < lowest)
            lowest = input;
        else if (input > highest)
            highest = input;

        finalScore += input;
    }

    finalScore -= lowest + highest; // Remove highest and lowest score
    finalScore = finalScore / (JUDGES - 2); // - 2 since low and high are removed

    cout << "Final score: " << fixed << showpoint << setprecision(1) << finalScore << endl;
}

// Clear screen in both windows and linux
void cls()
{
    system("cls||clear");
    return;
}