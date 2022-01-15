//------------------------------------------------------------------------------
// File: Task1.cpp  
// Summary: Writes user's personal data to a text file.
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-08 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <fstream> // ofstream
#include <limits> // numeric_limits 
#include <string> // getline

using namespace std; 

int main() 
{ 
    cout << "Enter personal information, and it will be saved to file:\nregister.txt\n";

    // Open stream
    ofstream outStream;
    outStream.open("register.txt", ios::app);
    if (outStream.fail())
    {
    cerr << "\nError: Output file opening failed.\n";
    return 1;
    }

    // Input
    char answer; 
    do 
    {
        cout << "Enter a name, phone number, and address, each separated by a comma:\n";

        string tmp;
        getline(cin, tmp);
        outStream << tmp << endl;

        cout << "want to add more information: (y/n)\n"; 
        cin >> answer; 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    } while (toupper(answer) == 'Y'); 

    // Close stream & Exit
    outStream.close( );
    return 0; 
} 