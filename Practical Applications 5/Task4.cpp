//---------------------------------------------------------------------
// File: Task4.cpp  
// Summary: Rock paper scissors played against computer.
// Version: 1
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2022-01-05 Created by Olle.
//
//--------------------------------------------------------------------- 
#include <iostream> 
#include <cctype>   // toupper 
#include <limits> // numeric_limits 
using namespace std; 

const int WINLIMIT = 10; // Limit to win 
int userScore = 0, computerScore = 0;
enum Choices { ROCK, SCISSORS, PAPER };
string choiceNames[3] = { "Rock", "Scissors", "Paper"};

// Prototypes
void cls();
Choices getInput();
void decidedWinner(Choices userChoice, Choices ComputerChoice);
void newTurn();

int main() 
{ 
    char answer; 
    do 
    {
        srand(time(0));
        userScore = 0, computerScore = 0; // Reset scores
        cls();

        cout << "STONE SCISSORS PAPPER\n"
             << "=====================\n";
        
        while(true)
        {
            newTurn();

            // Check if any winner
            if (userScore >= WINLIMIT)
                {
                    cout << "You won with " << userScore << "-" << computerScore;
                    break;
                }
            else if (computerScore >= WINLIMIT)
                {
                    cout << "Computer won with " << computerScore << "-" << userScore;
                    break;
                }
        }

        cout << endl << "One more time (Y/N)? "; 
        cin >> answer; 
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Get input from user and validate it
Choices getInput()
{
    int input;
    cout << "Your choice (Stone=0/Scissors=1/Paper=2): ";

    cin >> input;
    while (cin.fail() || (input != 0 && input != 1 && input != 2))
    {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
        cerr << "Error: Invalid input. Try again: ";
        cin >> input;
    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return static_cast<Choices>(input);
}

// Print the winner and increases their score
void decidedWinner(Choices userChoice, Choices ComputerChoice)
{
    if (userChoice == ComputerChoice)
        {
            cout << "Equal!\n";
        }
    else if (userChoice == Choices::ROCK && ComputerChoice == Choices::SCISSORS)
        {
            cout << "You won!\n";
            userScore++;
        }
    else if (userChoice == Choices::SCISSORS && ComputerChoice == Choices::PAPER)
        {
            cout << "You won!\n";
            userScore++;
        }
    else if (userChoice == Choices::PAPER && ComputerChoice == Choices::ROCK)
        {
            cout << "You won!\n";
            userScore++;
        }
    else
        {
            cout << "Computer won!\n";
            computerScore++;
        }

}

// Handles a single turn.
void newTurn()
{
    Choices userChoice = getInput();
    Choices computerChoice = static_cast<Choices>(rand() % 3); // 0 to 2
    cout << "Computer choose " << choiceNames[computerChoice] << endl;

    decidedWinner(userChoice, computerChoice);
    
    cout << "Score (you - computer): " << userScore << " - " << computerScore << endl;
}

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}