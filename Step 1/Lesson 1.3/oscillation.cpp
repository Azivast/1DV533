#include <iostream>
#include <iomanip> // Fixed, setprecision()
#include <cmath> // sqrt()

using namespace std;

const double G = 9.82; // Gravitational acceleration g

//Funciton prototypes
double getOscillationTime(double len);
void print(double len);

int main()
{
    double length;

    // Read input
    cout << "Oscillation time" << endl;
    cout << "==============" << endl << endl;

    cout << "Enter length of a pendulum: ";
    cin >> length;

    print(length);

    return 0;
}

double getOscillationTime(double len)
{
    const double PI = 4 * atan(1.0); // Mathematical trick to calculate PI

    return  2 * PI * sqrt(len / G);      // sqrt calculates the square root of the evaluated
                                    // argument in the parameter list
                                    // Added '2*' for proper formula, misisng in example
}

void print(double len)
{
    cout << "=====================" << endl;
    cout << fixed << setprecision(2) << showpoint; // Rounding to 2 decimals

    cout << "Oscillation Time = " << getOscillationTime(len) << " s" << endl; // The time period of
                                // oscillation is printed by the call to function getOscillationTime 
}
