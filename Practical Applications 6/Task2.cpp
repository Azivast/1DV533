//------------------------------------------------------------------------------
// File: Task2.cpp  
// Summary: Reads integers from integers.txt and prints the sum, mean, and 
//          max value of the numbers.
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-08 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <fstream> // fstream
#include <string> // getline

using namespace std; 

int main() 
{ 
    int sum = 0, max = 0;
    double mean = 0;

    // Open stream
    ifstream inStream;
    inStream.open("integers.txt");
    if (inStream.fail())
    {
        cerr << "Failed to open the file integers.txt!\n";
        return 1;
    }

    // Read from stream and get sum & max values
    int current = 0, count = 0;
    while(inStream >> current)
    {
        if (current > max)
            max = current;
        sum += current;
        count++;
    }
    // Calc mean value
    mean = float(sum)/count;

    // Output
    cout << "Sum: "        << sum  << endl
         << "Mean value: " << mean << endl
         << "Max: "        << max  << endl;

    // Close stream & Exit
    inStream.close( );
    return 0; 
} 