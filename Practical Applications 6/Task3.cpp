//------------------------------------------------------------------------------
// File: Task3.cpp  
// Summary: Extracts measured data of sensor A from timelog.dat.
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-12 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <fstream>
#include <limits> // numeric_limits 
#include <filesystem> // file_size
#include <ctime> // asctime
#include <iomanip>

using namespace std; 

struct DataRecord
{
    char logger; // Define logging Point A, B, C, ...
    double temp; // Logged Temperature
    time_t locTime; // Local Time
};

int main() 
{ 
    // Set up streams
    ifstream timelog("timelog.dat", ios::binary);
    ofstream a("A.txt");

    if (!timelog)
    {
        cerr << "Error: Could not open file 'timelog.dat'\n";
        return 1;
    }
    if (!a)
    {
        cerr << "Error: Could not write file 'A.txt'\n";
        return 1;
    }

    // Read timelog and output to stream a
    a << "Data A\n";
    DataRecord data;
    for (int i = 0; i < std::filesystem::file_size("timelog.dat"); i += sizeof(DataRecord))
    {
        timelog.read((char*)&data, sizeof(DataRecord));
        if (data.logger == 'A')
        {
            a << fixed << showpoint << setprecision(1) 
              << data.temp << ", "
              << asctime(localtime(&data.locTime));
        }
    }
    cout << "Finished writing to A.txt\n";

    // Close streams and exit
    timelog.close();
    a.close();
    return 0; 
} 