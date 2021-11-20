// --------------------------------------------------------------------
// File: Task8.cpp  
// Summary: Calculates the effective temperature given a wind speed and temperature. 
// Version : 1  
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-11-10 Created by Olle.
//  
//--------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream>
#include <cmath> // pow() and round()
using namespace std;

const double LIMIT = 0.5; // Lowest accepted wind speed. Formula becomes innacurate below this number

int effectiveTemperature(int degreesCelsius, int windSpeed);
void cls();

int main()  
{  
     char answer;
     do
     {
          int degreesCelsius = 0;
          int windSpeed = 0;

          cls(); // Clear screen

          // Get input
          cout << "Input the messured temperature (degrees Celsius): ";
          cin >> degreesCelsius;
          cout << "\nInput the wind speed (m/s): ";
          cin >> windSpeed;

          // Make sure input is not outside of values suitable for formula
          while (windSpeed < LIMIT)
          {
               cin.clear(); 
               cin.ignore(80,'\n'); // Skip any possible debris and line endings

               cout << "\nThe formula is innacurate below wind speeds of " << LIMIT << " m/s.\n"
                    << "Please enter a new wind speed (m/s): ";
               cin >> windSpeed;
          }

          // Calculate and print result
          cout << "\nThe effective temperature is " << effectiveTemperature(degreesCelsius, windSpeed) << " degrees celsius.\n\n";

          cout << "New calculation (Y/N)?: ";
          cin >> answer;
          cin.clear(); 
          cin.ignore(80,'\n'); // Skip any possible debris and line endings
     } 
     while (answer == 'Y' || answer == 'y');
     
     return 0;
} 

// Returns effective temperature roundend to nearest integer
int effectiveTemperature(int degreesCelsius, int windSpeed) 
{
     // Osczevskis and Bluesteins formula for effective wind temperature
     // Formula is only accurate for wind speeds >= 0.5
     int effectiveTemp = round(13.126667 + 0.6215 * degreesCelsius - 13.924748 * pow(windSpeed, 0.16) + 0.4875195 * degreesCelsius * pow(windSpeed, 0.16));
     return effectiveTemp;
}

// Clear screen in both windows and linux
void cls()
{
     system("cls||clear");
     return;
}