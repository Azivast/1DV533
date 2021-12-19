//------------------------------------------------------------------------------
// File: Task2.cpp  
// Summary: Calculate diving score from seven judges. Highest and lowest scores
//          are excluded. Remainder summed and multiplied by difficulty & 0.6
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2021-12-17 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
using namespace std; 

// Prototypes
void cls();
double getInput(double rangeStart, double rangeStop);
void getScores(double [], double &difficulty);
double calculateScore(double [], double difficulty);
void printScore(double finalScore);

const int JUDGES = 7;

int main() 
{ 
    char answer; 
    do 
    {
        double scores[JUDGES] = { 0 };
        double difficulty = 0;
        double finalScore = 0;

        cls();
        getScores(scores, difficulty);
        finalScore = calculateScore(scores, difficulty);
        printScore(finalScore);


        cout << endl << "\nOne more time (Y/N)? "; 
        cin >> answer; 
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Get user input and verify if it's in range and valid
double getInput(double rangeStart, double rangeStop)
{
    double input;
    cin >> input;
    
    // Verify if input is number and fits in range
    while (cin.fail() || input < rangeStart || input > rangeStop)
    {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
        cerr << "Error: That is not valid input. Try again: ";
        cin >> input;
    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return input;
}

// Get scores and difficulty from player
void getScores(double scores[], double &difficulty) 
{
    cout << "Enter the degree of difficulty for the dive (1.0 - 4.0): ";
    difficulty = getInput(1.0, 4.0);

    for (int i = 0; i < JUDGES; i++)
    {
        cout << "Enter score for judge " << i+1 << " (0-10): ";
        scores[i] = getInput(0.0, 10.0);
    }
}

// Calculate the final score
double calculateScore(double scores[], double difficulty)
{
    double sum = 0;
    double highest = scores[0];
    double lowest = scores[0];

    // Sum up scores and find highest and lowest
    for (int i = 0; i < JUDGES; i++)
    {
        sum += scores[i];

        if (scores[i] > highest)
            highest = scores[i];
        else if (scores[i] < lowest)
            lowest = scores[i];
    }

    // Subtract highest and lowest score
    sum = sum - highest - lowest;

    // Multiple sum of remaining scores with difficulty of dive and 0.6
    sum *= difficulty*0.6;

    return sum;
}

// Output the final score to the user
void printScore(double finalScore)
{
    cout << "\nThe diver's final score is " << finalScore;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}