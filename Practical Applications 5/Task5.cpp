//---------------------------------------------------------------------
// File: Task5.cpp  
// Summary: Sorts a given list of names in alphabetical order.
// Version: 1
// Author: Unknown
//---------------------------------------------------------------------
// Log:  2022-01-05 Implemented missing functions and logic.
//                  "WRITE CODE" comments have been kept for the sake 
//                  of demonstrating what has been added. //Olle Astré
//--------------------------------------------------------------------- 
#include <iostream>
#include <cstring>
using namespace std;

const int BUFLEN = 100; // Max length of reading buffer

void sort(char *friendList[], int n); // n is the number of elements
void print(char *friendList[], int n); // n is the number of elements
void terminate(char *friendList[], int n); // n is the number of elements

const int AMOUNT = 5;

int main()
{
    char* friends[AMOUNT]; // Dynamic array with AMOUNT pcs of string pointers
    char buff[BUFLEN] = {""}; // Creates a string buffer (null terminated)
    int count = 0;

    while (count < AMOUNT) // enter AMOUNT number of friends
    {
        cout << "Name a friend: ";
        cin.getline(buff, BUFLEN); // Temporary reading into string buffer

        friends[count] = new char[strlen(buff)+1 * sizeof(char)]; // WRITE CODE allocating memory to the string. //DONE

        // WRITE CODE that adds loaded name to current location in the dynamic array. //DONE
        memcpy(friends[count], buff, (strlen(buff)+1 * sizeof(char)));

        ++ count;
    }
    sort(friends, count); // Sorts the ‘count’ strings
    print(friends, count); // Prints the ‘count’ first names
    terminate(friends, count);// Releases all allocated memory space

    return 0;
}

// Sorts all dynamic arrays pointed to in friendsList in alphabetical order
void sort(char *friendList[], int n)
{
    // WRITE FUNCTION that sorts the strings in the friendList in alphabetical order! //DONE

    // Bubble sort
    char *temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(strcmp(friendList[i], friendList[j]) > 0) // if j should comes earlier in alphabetical order
            {
                // then swap the pointers i and j
                temp = friendList[i];
                friendList[i] = friendList[j];
                friendList[j] = temp;
            }
        }
    }
}

// Print all dynamic arrays pointed to in friendsList
void print(char *friendList[], int n)
{
    // WRITE FUNCTION that prints ‘n’ names from the friendList on screen! //DONE
    cout << "\nYour friends in alphabetical order:\n";
    for (int i = 0; i < n; i++)
    {
        cout << friendList[i] << endl;
    }
}

// Delete all dynamic arrays pointed to in friendsList
void terminate(char *friendList[], int n)
{
    // WRITE FUNCTION that releases all dynamically allocated memory! //DONE
    for (int i = 0; i < n; i++)
    {
        delete [] friendList[i];
    }
}