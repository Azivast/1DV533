//---------------------------------------------------------------------
// File: Task5.cpp  
// Summary: Calculates cost depending on different discount rates.
// Version: 1.1
// Author: ?
//---------------------------------------------------------------------
// Log:  2021-12-07 Missing functions implemented by Olle Astré.
//
//--------------------------------------------------------------------- 

// Include the standard libraries needed!   DONE //Olle
#include <iostream> 
#include <iomanip> //setw setfill fixed setprecision
#include <cmath> // round
#include <limits> // numeric_limits 
#include <cctype>   // toupper 
using namespace std; 

// Remember to declare all functions (prototypes)!  DONE //Olle
void cls();
void load(double& sum);
int discount(double sum);
void print(double sum, double discountKr); 

int main() 
{ 
    double sum = 0.0, discountKr = 0.0; 
    char answer; 
    do { 
        // write a statement to Clear Console Screen    DONE //Olle
        cls(); // Function for portability since it's platform specific
        cout << "Discount" << endl; 
        cout << "========" << endl << endl; 

        load(sum); 
        // To read the input sum from user – complete this function call,   DONE //Olle
        // by writing the necessary function definition! 

        discountKr = sum * discount(sum) / 100;  
        // To calculate the discount – complete the function call ("discount(sum)")
        // with a function definition   DONE //Olle

        sum = sum - discountKr; 
            
        print(sum, discountKr); 
        cout << endl << "One more time (Y/N)? "; 
        cin >> answer; 
    } while (toupper(answer) == 'Y'); 

    return 0; 
} 

// Add necessary function definitions here   DONE //Olle

// Get user input
void load(double& sum)
{
    cout << "Enter the sum: ";
    cin >> sum;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Ignore remainder of stream
}

// Return discount as percentage
int discount(double sum)
{
    if (sum < 500)
        return 0;

    else if (sum < 1000)
        return 5;

    else if (sum < 5000)
        return 10;

    else // (sum >= 5000)
        return 15;

}

// Print discount and net sum rounded to nearest "krona"
void print(double sum, double dKr) 
{  
    // Round output
    sum = round(sum);
    dKr = round(dKr);

    // Print output
    cout << right << setfill('.') << fixed << showpoint << setprecision(2)     // Right aligned, fillcharacter, decimal form with hundredths
        << "------------------------------------\n"
        << "Discount       : " //TODO: setw to prevent issues when using non-mono fonts?
        << setw(12) << dKr
        << " kr\n"
        << "Net sum        : " 
        << setw(12) << sum
        << " kr\n"
        << "------------------------------------";
} 

// Clear screen in windows and *nix systems
void cls()
{
    system("cls||clear");
}