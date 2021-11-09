#include <iostream>  // For the use of cin, cout 
#include <iomanip>  // For the use of setfill, setw 
using namespace std; 
 
int main() 
{ 
  int time;          // input 
  int hours, min, sec;    // output 
  int rest; 
 
  // Input  
  cout << "Times" << endl;        // endl inserts a newline character into the  
  cout << "=====" << endl << endl; // output sequence and flush the output buffer 
  cout<< "Input time in sec: "; 
  cin >> time; 
 
  // Calculation 
  hours = time / 3600; 
  rest = time % 3600; // Gives the remaining seconds
 
  min = rest / 60; 
  rest = rest % 60;         // Can also be written: rest %= 60 
 
  sec = rest; 
 
  // Output 
  cout << "==============================" << endl; 
  cout << setfill('0');          // Set padding characters = 0 
  cout << time << " sec = " << hours << ':'  
        << setw(2) << min << ':'     // Set column width = 2 characters 
       << setw(2) << sec << endl; 
  cout << setfill(' ');          // Reset padding character to whitespaces 
 
  return 0; 
}