//---------------------------------------------------------------------
// File: Task1.cpp  
// Summary: Calculates volume of a cube given a certain side length.
// Version: 2  
// Author: ?
//---------------------------------------------------------------------
// Log:  2021-12-05 Rewritten to use functions. //Olle Astré
//
//--------------------------------------------------------------------- 

#include <iostream> 
#include <cctype>   // toupper 
using std::cout; 
using std::cin; 
using std::endl; 

// Prototypes
void getSide(double& side);
double cubeVolume(double volume);
void printVolume(double side); 

int main() 
{ 
    double side = 0.0, volume = 0.0; 
    char answer = 'Y'; 

    cout << "Cubes" << endl; 
    cout << "=====" << endl << endl; 

    do 
    { 
        // Read side 
        getSide(side);

        // Calculate volume & Print volume
        printVolume(side);

        // Re-run
        cout << endl << "One more time (Y/N)? "; 
        cin >> answer; 
    } while (toupper(answer) == 'Y'); 

    return 0; 
}

void getSide(double& side)
{
    cout << "Enter the side length of a cube to be computed: "; 
    cin >> side; 
}

double cubeVolume(double side)
{
    return (side * side * side); 
    side++;
}

void printVolume(double side)
{
    double volume = cubeVolume(side);
    cout << "Volume of the cube is: " << volume << " volume units" << endl; 
}