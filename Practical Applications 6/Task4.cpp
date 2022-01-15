//------------------------------------------------------------------------------
// File: Task4.cpp  
// Summary: Extracts lower and uppercase characters from abcfile.dat
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-12 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <fstream> // fstream
#include <cctype> // islower isupper

using namespace std; 

int main() 
{ 
    // Create streams
    ofstream lower("lower.txt");
    ofstream upper("upper.txt");
    ifstream infile("abcfile.dat", ios::binary);
    if (!infile)
    {
        cerr << "Error: Could not open file 'abcfile.dat'\n";
        return 1;
    }
    if (!lower)
    {
        cerr << "Error: Could not write file 'lower.txt'\n";
        return 1;
    }
    if (!upper)
    {
        cerr << "Error: Could not write file 'upper.txt'\n";
        return 1;
    }

    // Read and write
    cout << "Content of input file:\n\n";
    char ch;
    while (infile.get(ch)) // gets 0 when Eof found
    {
        cout << ch; // print abcfile to console.

        // write lower
        if (islower(ch)) // Spaces could be included with '|| isspace (ch)'
            lower << ch;

        // write upper
        if (isupper(ch))
            upper << ch;
    }
    cout << "\n\nWriting complete. See lower.txt and upper.txt for output.\n";

    // Close streams & Exit
    infile.close();
    lower.close();
    upper.close();
    return 0; 
} 