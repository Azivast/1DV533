#include <iostream>  // for cout and cin 
#include <iomanip>  // fixed, setprecision() and showpoint, which are used to set the decimals 
using namespace std; 
 
// "Constants", or MACRO according to C, are always written in capitals (C-style) 
// #define MILECOST 25     
// #define DAYCOST 100 
 
// Type-defined constants, according to C++ (more SAFE), usually written in UPPERCASE,  
const double MILECOST = 25;       // (sometimes with just initial Upper Case) 
const int DAYCOST = 100; 
 
// Function prototype - Declaration - Tells that a function with this "signature" is located elsewhere 
// The included libraries above contains precisely this kind of declarations of library functions 
double calculateCost(int day, double mile); 
 
int main() 
{ 
  // Local variable definitions 
  int days; 
  double miles; 
 
  // Read input 
  cout << "Rent-cost\n"; 
  cout << "=========\n\n"; 
  cout << "Input number of days: "; 
  cin >> days; 
  cout << "Input number of miles: "; 
  cin >> miles; 
 
  // Print the cost 
  cout << "==============================\n"; 
  cout << fixed << setprecision(2)<< showpoint; // fixed format 2 decimals, show trailing 0's 
  cout << "The rent-cost: " << calculateCost(days, miles) << " kr"; // The function is here called with days and miles  
              // input arguments. The return-value is printed out! 
  return 0;               
} 
 
// Function definition (the function code) The prototype above main is the "declaration". 
double calculateCost(int day, double mile) 
{ 
  double cost = DAYCOST * day + MILECOST * mile; 
  return cost; 
}