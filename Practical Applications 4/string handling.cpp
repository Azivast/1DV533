// 
// File:    StringHandling.cpp 
// Summary: This program reads two strings from user, to be seen 
// as numeric values. The program performs format checking, then  
// converts the strings to integer values, before it calculates 
// and displays the resulting sum. 
// Version: 1.1 
 
 
#include <iostream> 
#include <cstdlib> // atoi()  
#include <cctype>    // isdigit() 
 
using namespace std; 
 
// Prototypes 
bool stringOk(char s[], int amount); 
 
const int MAXLEN = 100;  // Max length of temp strings 
const int AMOUNT = 4;  // Max amount of digits 
 
int main() 
{ 
 // String for reading the number – always use constant for the size  
 char str[MAXLEN] = {'\0'};  
  
 int number1 = 0, number2 = 0; 
 bool ok; 
 
 cout << "Enter two numbers (max 4-digits).\n\n"; 
 
 do 
 { 
  cout << "Number 1: "; 
  cin.getline(str, MAXLEN, '\n'); 
  // Reads max 99 characters, adds '\0' in the end. 
  // '\n' means that reading is cancelled at the end-of-line character ('\n' is default), 
  // which you get by pressing Enter - '\n' is finally removed from the input stream. 
  ok = stringOk(str, AMOUNT); 
 
  if (!ok) 
   cout << "Try again!" << endl; 
 } while (!ok); 
 
 number1 = atoi(str); // atoi() returns the numerical value of the string 
  
  
do 
 { 
  cout << "Number 2 "; 
  cin.getline(str, MAXLEN); 
  // The third argument to getline can be omitted – default it is '\n' 
  ok = stringOk(str, AMOUNT); 
 
  if (!ok) 
   cout << "Try again!" << endl; 
 } while (!ok); 
 
 number2 = atoi(str); 
    
 cout << "\nThe sum is " << number1 + number2 << endl; 
 
 return 0; 
}   
 
// 
// bool stringOK(char s[], int amount); 
// Returns true if s contains of at least 1 digit and max amount digits, else false 
//  
bool stringOk(char s[], int amount) 
{ 
 int i = 0; 
 
 while (s[i]!= '\0')    // Is often written: while (s[i]) 
 {          // that is, as long as s[i] has a value !=0 
  if (!isdigit(s[i]))   // if no digit 
   return false;    // cancel 
  ++i; 
 } 
  
 return (i > 0 && i <= amount); // true if we have found 1 more digit
 } 