//---------------------------------------------------------------------
// File: Task2.cpp  
// Summary: Converts fahrenheit to celsius.
// Version: 1
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-12-05 Created by Olle Astré.
//
//--------------------------------------------------------------------- 

#include <iostream> 
#include <iomanip> // fixed setprecision
#include <cctype>   // toupper 

using std::cout; 
using std::cin; 
using std::endl; 

void getInput(double& temperature);
bool fahrenheitToCelsius(double input, double& output);
void printTemperature(double celsius, bool isAboveZero); 

int main() 
{ 
    char answer = 'Y'; 

    cout << "Temperature conversion" << endl; 
    cout << "====================" << endl; 

    do 
    { 
        double fahrenheit = 0.0, celsius = 0.0;

        getInput(fahrenheit);
        bool aboveFreezing = fahrenheitToCelsius(fahrenheit, celsius);
        printTemperature(celsius, aboveFreezing);

        cout << endl << "One more time (Y/N)? "; 
        cin >> answer; 
        cout << endl;
    } while (toupper(answer) == 'Y'); 

    return 0; 
}

void getInput(double& temperature)
{
    cout << "Enter temperature in Fahrenheit: "; 
    cin >> temperature; 
}

// Converts fahrenheit to celsius and returns celsius through the seconds parameter
// Function also returns true if temp is above freezing
bool fahrenheitToCelsius(double input, double& output)
{
    output = (input - 32.0) * 5/9; // Formula for converting fahrenheit to celsius
    if (output > 0)
        return true;
    else return false;
}

void printTemperature(double celsius, bool isAboveZero)
{
    cout << std::fixed << std::showpoint << std::setprecision(1) << std::boolalpha // Display 1 decimal with trailing zero, bool as true/false
         << celsius << " degrees Celsius.\n"
         << "Boolean value returned by the conversion function is: " << isAboveZero;
}
