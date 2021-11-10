// -------------------------------------------------------------------------------------
// File: Task5.cpp  
// Summary: Calculates remaining travel time using remaining distance and avarage speed.
// Version : 1  
// Author: Olle Astré
// -------------------------------------------------------------------------------------

// Preprocessor directives 
#include <iostream>
using namespace std;

void calculateTime();
void cls();

int main()  
{  
     char answer;

     do
     {
          cls(); // Clear screen
          calculateTime();
          cout << "New calculation (Y/N)?\n";
          cin >> answer;
          cin.ignore(80,'\n'); // Ignore possible debris and line endings 
     } 
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

// Get user input, calculate and output remaining travel time.
void calculateTime() 
{
     int avarageSpeed = 0; // In km/h
     int distanceLeft = 0; // In swedish miles 'mil'.
     int hoursLeft = 0;
     double rest = 0;
     int minutesLeft = 0;


     cout << "TRAVEL TIME\n";
     cout << "===========\n";
     cout << "Input the avarage speed (km/h): ";
     cin >> avarageSpeed;

     cout << "Input the remaining distance (swedish miles): ";
     cin >> distanceLeft;
     cout << endl;

     // Check that input is not zero to avoid dividing by zero.
     if (avarageSpeed == 0) {
          cout << "Aborting: Invalid input.\n"
               << "Make sure speed is not 0.\n\n";
          return;
     }

     // Calculate the remaining time
     hoursLeft = (distanceLeft * 10)/avarageSpeed; // Multiplied by 10 so that both messurments use km.
     rest = (distanceLeft * 10)%avarageSpeed;
     minutesLeft = (rest/avarageSpeed)*60 + 0.5;        

     cout << "You will reach your destination in " << hoursLeft << " hours and " << minutesLeft << " minutes." << endl << endl;
}

// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}