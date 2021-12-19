//---------------------------------------------------------------------
// File: Task3.cpp  
// Summary: Power function without cmath that uses default values.
// Version: 1
// Author: Olle Astré
//---------------------------------------------------------------------
// Log:  2021-12-07 Created by Olle Astré.
//
//--------------------------------------------------------------------- 
#include <iostream> 
using std::cout; 
using std::endl; 

// Function declaration (prototype) for power
// y defaults to 2
int power(int x, int y = 2);

int main() 
{ 
    for (int i = 0; i < 10; i++) 
        cout << power(2, i) << " ";   // prints 2 raised to the power of i 
            
    cout << endl;    
    cout << power(3) << endl;    // will print 9 
    cout << power(4) << endl;    // will print 16 
    cout << power(5) << endl;    // will print 25 

    return 0; 
} 

// Returns x to the power of y
int power(int x, int y)
{
    int answer = 1;

    for (int i=0; i<y; i++)
    {
        answer *= x; 
    }

    return answer;
}