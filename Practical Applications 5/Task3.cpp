//------------------------------------------------------------------------------
// File: Task3.cpp  
// Summary: Demonstrates various functions that work with time structures.
// Version: 1
// Author: Olle Astré
//------------------------------------------------------------------------------
// Log:  2022-01-05 Created by Olle.
//
//------------------------------------------------------------------------------
#include <iostream> 
#include <limits> // numeric_limits 
#include <iomanip> // setw setfill
#include <cstdlib> // rand abs
using namespace std; 

struct TimeType
{
    int hour;
    int min;
};

// prototypes
int toMinutes(TimeType time);
TimeType toTime(int minutes);
TimeType timeDifference(TimeType a, TimeType b);
TimeType dynamicTimes();

int main() 
{ 
    srand(time(0)); // Seed random number generator
    cout << setfill('0'); // Leading 0 for displaying time

    // A) Example of toMinutes
    int minutes;
    TimeType timeA = {10, 15};
    minutes = toMinutes(timeA);
    cout << "Part A:\n" << "Invoking toMinutes with " 
         << setw(2) << timeA.hour << ":" << setw(2) << timeA.min 
         << " returns:" << endl
         << minutes << " (minutes)\n\n"; // Should write: 615 minutes

    // B) Example of toTime
    minutes = 124;
    TimeType time = toTime(minutes);
    cout << "Part B:\n" << "Invoking toTime with " 
         << minutes << " minutes returns:\n"
         << setw(2) << time.hour << ":" << setw(2) << time.min << endl << endl;

    // C) Example of timeDifference
    TimeType timeB = {10, 30}, timeC = {13, 20}, difference;
    difference = timeDifference(timeB, timeC);
    cout << "Part C:\n" << "Invoking timeDifference with " 
         << setw(2) << timeB.hour << ":" << setw(2) << timeB.min << " and "
         << setw(2) << timeC.hour << ":" << setw(2) << timeC.min
         << " returns:\n"
         << setw(2) << difference.hour << ":" << setw(2) << difference.min << endl << endl;

    // D) Example of dynamicTimes
    TimeType maxDiff = dynamicTimes();
    cout << "Part D:\n" << "Invoking dynamicTimes this time resulted in a difference of:\n"
         << setw(2) << maxDiff.hour << ":" << setw(2) << maxDiff.min << endl;

    return 0;
}

// Returns given time struct as minutes only
int toMinutes(TimeType time) 
{
    return (time.hour*60 + time.min);
}

// Converts minutes into time struct
TimeType toTime(int minutes)
{
    TimeType time = {minutes/60, minutes%60};
    return time;
}

// Returns the difference in time between b and a as a time struct
TimeType timeDifference(TimeType a, TimeType b)
{
    int minutesA = toMinutes(a);
    int minutesB = toMinutes(b);
    return toTime(abs(minutesB-minutesA));
}

// Generates an array with 200 random times. Picks out the highest and lowest
// and returns the difference between them.
TimeType dynamicTimes()
{
    const int nrOfTimes = 200;
    TimeType* times = new TimeType[nrOfTimes];
    int lowestIndex = 0;
    int highestIndex = 0;

    // Populate array
    for (int i = 0; i < nrOfTimes; i++)
    {
        int min = rand() % 60; // 0 to 59
        int hour = rand() % 24; // 0 to 23
        TimeType tmp = {hour, min};

        times[i] = tmp;

        // Pick out highest and lowest
        if (toMinutes(tmp) < toMinutes(times[lowestIndex]))
            lowestIndex = i;
        else if (toMinutes(tmp) > toMinutes(times[highestIndex]))
            highestIndex = i;
    }

    TimeType difference = timeDifference(times[lowestIndex], times[highestIndex]);
    delete [] times;
    return difference;
}
