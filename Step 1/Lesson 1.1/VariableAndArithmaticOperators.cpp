#include <iostream> 
using namespace std; 
 
int main() 
{
 // Definition of (local) variables
 int days;
 double miles;
 double cost;

 // Input
 cout << "Rent-cost\n";
 cout << "=========\n\n";
 cout << "Input number of days: ";
 cin >> days;
 cout << "Input number of miles: ";
 cin >> miles;

 // Calculation
 cost = days * 100 + miles * 25; // per day cost is 100 kr and per mile cost is 25 kr.
 
 // Output
 cout << "======================\n";
 cout << "Calculated cost : " << cost << " kr" << endl;
  
 return 0;
}