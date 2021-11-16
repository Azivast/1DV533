//----------------------------------------------------------------------- 
// Object: This program has logical errors. Find and correct them.  
//    There are miscalculations and the program can't be stopped with 'N'. 
//    Document your changes with comments or in log. 
//----------------------------------------------------------------------- 
// File:    LogicalError.cpp 
// Summary: Reads price and number of articles from user. Calculates and prints   
//    number, tax rate and price with tax rate (swedish "moms"). 
// Version: 1.1 
// Owner:   Tommy Löfqvist 
//----------------------------------------------------------------------- 
// Log:  2005-03-09 Created the file, Mats! 
//   2009-08-14 Revised by Tommy. Swedish variable names and output text. 
//     Number of items is now included.  
//     Code for the problem is placed in a separate function  
//     that is iterated in the main function.  
//   2012-10-21 Revised by Anne. Converted to English version and VS 2012 
//   2021-11-09 Revised by Olle. Add RATEFACTOR which represents the rate as a factor on line 55.
//     Canged totalPrice to price on line 75
//     Multipled both rateSEK and totalPrice by nrOfArticles so that result is as expected.
//     Added missing = on first condition of line 40.
//----------------------------------------------------------------------- 

// Preprocessor directives 
#include <iostream> 
#include <iomanip> 
using namespace std; 

// Prototypes 
void priceCalculation(); 

int main() 
{ 
     char answer; 
     do 
     { 
          priceCalculation(); 
          cout << "One more time? (Y/N): "; 
          cin >> answer; 
     }
     while (answer == 'Y' || answer == 'y'); // Added missing = on left condition

     return 0; 
} 


//----------------------------------------------------------------- 
// void priceCalculation() 
// 
// Summary: Reads price and number of articles from user. Calculates and prints 
//    quantity, vat and price with vat 
// Returns: - 
//----------------------------------------------------------------- 

void priceCalculation() 
{
     // Define and initialize constants and variables 
     const int RATE = 25;  // tax rate in percent 
     const double RATEFACTOR = RATE/100.0; // Added tax rate as factor

     double price = 0;  // price per piece 
     int nrOfArticles = 0; // number of articles 
     double rateSEK = 0;   // tax rate in SEK 
     double totalPrice = 0; // price incl. tax rate 

     // Read price and number of articles 
     cout << "Enter the price excl. the tax rate (swedish moms): "; 
     cin >> price; 

     cout << "Enter the number of articles: "; 
     cin >> nrOfArticles; 

     // Calculate total price and tax rate 
     // Changed totalPrice to price since calculation depends on the price before tax
     // Also multiply by nrOfArticles so that tax rate is correct with multiple articles
     rateSEK = nrOfArticles * price * RATEFACTOR;
     totalPrice = nrOfArticles * price *(1 + RATEFACTOR); 

      // Display result with 2 decimals 
     cout << fixed << showpoint << setprecision(2); 

     cout << nrOfArticles << " number of articles cost " << totalPrice << " kr. "  
     << endl << "Of this " << rateSEK << " kr is the tax rate." << endl; 
}