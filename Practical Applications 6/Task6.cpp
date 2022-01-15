//------------------------------------------------------------------------------
// File: Task6.cpp  
// Summary: Reads surface measurements from surfacedata.txt and calculates
//          arithmetic mean value, root mean square average, and maximum
//          roughness height.
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-15 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <fstream> // fstream
#include <cmath> // abs sqrt
#include <iomanip> // setw

using namespace std; 

int main() 
{ 
    double max = 0, min = 0;
    double roughness = 0;   // maximum roughness height
    double Ra = 0;          // arithmetic mean value
    double Rq = 0;          // root mean square average


    // Create stream
    ifstream infile("surfacedata.txt");
    if (!infile)
    {
        cerr << "Error: Could not open file 'surfacedata.txt'\n";
        return 1;
    }

    // Read infile
    double current = 0;
    int count = 0;
    while(infile >> current)
    {
        // Get max and min values
        if (count == 0) // Give max and min initial values
            max = min = current; 
        if (current > max)
            max = current;
        else if (current < min)
            min = current;

        // Begin calculations. Ra and Rq will after this contain the numerator for their formulas
        Rq += current*current;
        Ra += abs(current);

        count++;
    }

    // Finish calculations
    Ra = Ra/count;
    Rq = sqrt(Rq/count);
    roughness = max-min;

    // Output
    cout << fixed << showpoint << setprecision(3)
         << left << setw(21) << "Ra" << "=" << right << setw(11) << Ra << endl
         << left << setw(21) << "Rq" << "=" << right << setw(11) << Rq << endl
         << left << setw(21) << "Max Roughness height" << "=" << right << setw(11) << roughness << endl
         << left << setw(21) << "Number of values" << "=" << right << setw(11) << count << endl
         << "Done!\n";

    // Close stream and exit
    infile.close();
    return 0; 
} 