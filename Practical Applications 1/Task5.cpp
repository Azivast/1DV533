//---------------------------------------------------------------------
// File: Task5.cpp  
// Summary: Calculates remaining travel time using remaining distance and average speed.
// Version : 1  
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-10 Created by Olle.
//   2021-11-20 Ignore remainder of stream after input, Olle.
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
using namespace std;

// Prototypes 
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
          cin.ignore(80,'\n'); // Ignore remainder of stream
     } 
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

// Gets user input, calculates and outputs remaining travel time.
void calculateTime() 
{
     int averageSpeed = 0; // In km/h
     int distanceLeft = 0; // In swedish miles 'mil'
     int hoursLeft = 0;
     double rest = 0;
     int minutesLeft = 0;


     cout << "TRAVEL TIME\n";
     cout << "===========\n";
     cout << "Input the avarage speed (km/h): ";
     cin >> averageSpeed;
     cin.ignore(80,'\n'); // Ignore remainder of stream

     cout << "Input the remaining distance (swedish miles): ";
     cin >> distanceLeft;
     cin.ignore(80,'\n');
     cout << endl;

     // Check that input is not zero to avoid dividing by zero.
     if (averageSpeed == 0) 
     {
          cout << "Aborting: Invalid input.\n"
               << "Make sure speed is not 0.\n\n";
          return;
     }

     // Calculate the remaining time
     hoursLeft = (distanceLeft * 10)/averageSpeed; // Multiplied by 10 so that both messurments use km.
     rest = (distanceLeft * 10)%averageSpeed;
     minutesLeft = (rest/averageSpeed)*60 + 0.5;        

     cout << "You will reach your destination in " << hoursLeft << " hours and " << minutesLeft << " minutes." << endl << endl;
}

// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}