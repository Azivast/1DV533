//---------------------------------------------------------------------
// File: Task8.cpp  
// Summary: Game of Dice Thrones. Turn based dice game against computer.
// Version: 1
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-12-07 Created by Olle.
//
//--------------------------------------------------------------------- 
#include <iostream> 
#include <cctype>   // toupper 
#include <limits> // numeric_limits 
using namespace std; 

// Prototypes
int humanTurn(int humanTotalScore);  
int computerTurn(int computerTotalScore);
int rollDice();
void getInput(char character);
char getInput(char character1, char character2);
void cls();

const int WINLIMIT = 100; // Limit to win 
const int TURNWINLIMT = 50; // Limit to win from a single turn

int main() 
{ 
    char answer; 
    do 
    {
        int humanTotalScore = 0;
        int computerTotalScore = 0;
        int turnScore = 0;

        cls();
        cout << "Welcome to the Game of Dice Thrones!\n";
        
        while(true)
        {
            // Human turn
            turnScore = humanTurn(humanTotalScore);
            humanTotalScore += turnScore;
            if (turnScore >= TURNWINLIMT || humanTotalScore >= WINLIMIT)
            {
                cout << "\nCongratulations, you win!\n\n";
                break;
            }

            // Computer turn
            turnScore = computerTurn(computerTotalScore);
            computerTotalScore += turnScore;
            if (turnScore >= TURNWINLIMT || humanTotalScore >= WINLIMIT)
            {
                cout << "\nThough luck, the computer won!\n\n";
                break;
            }
        }


        cout << endl << "One more time (Y/N)? "; 
        cin >> answer; 
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Rolls 6-sided dice
int rollDice()
{
    return rand() % 6 + 1;
}

// Requests 'character' to be input
void getInput(char character)
{
    char input;
    do
    {
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(input) != toupper(character));
}
// Requests one of two characters to be input
char getInput(char character1, char character2)
{
    char input;
    do
    {
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (!(toupper(input) == toupper(character1) || toupper(input) == toupper(character2)));

    return input;
}

// Handles a turn for the human. Returns any new points to be added to the total score.
int humanTurn(int humanTotalScore)
{
    int points = 0;
    char input;

    cout << "It's your turn! Enter 'r' to roll.\n";
    getInput('r');

    while (true)
    {
        int roll = rollDice();
        cout << "You rolled " << roll << endl;

        if (roll == 1)
        {
            cout << "You lost your turn. Enter 'c' to continue.\n";
            getInput('c');
            return 0;
        }
        
        points += roll;

        cout << "Your score this round is: " << points << endl
             << "If you hold, your total score would be: " << (humanTotalScore + points) << endl
             << "Press 'h' to hold or 'r' to roll again.\n";
             
        input = getInput('r', 'h');
        if (input == 'r' || input == 'R')
            continue; // Next iteration of loop
        else if (input == 'h' || input == 'H')
        {
            return points;
        }
    }
}


// Handles a turn for the computer. Returns any new points to be added to the total score.
int computerTurn(int computerTotalScore)
{
    int points = 0;
    char input;

    cout << "It's the computer's turn!\n";
    while (true)
    {
        int roll = rollDice();
        cout << "The computer rolled " << roll << endl;

        if (roll == 1)
        {
            cout << "The computer loses its your turn. Enter 'c' to continue.\n";
            getInput('c');
            return 0;
        }
        
        points += roll;

        cout << "The computer's score this round is: " << points << endl
             << "If the computer holds, its total score would be: " << (computerTotalScore + points) << endl;

        if (points < 10)
        {
            cout << endl;
            continue; // Next iteration of loop
        }
        else
        {
            cout << "The computer holds.\n\n";
            return points;
        }
    }
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}