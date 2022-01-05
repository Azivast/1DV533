#include <iostream>
#include <ctime>
using namespace std;

enum Coin {Tails, Heads};

int main()
{
    int frequency0 = 0, frequency1 = 0;
    Coin face;

    srand(time(0)); // Moved from line 15
    for (int counter = 1; counter <= 10; ++counter)
    {
        // ---- Line 15 ----
        face = Coin(rand()% 2);

        switch (face)
        {
            case Tails: ++frequency0;
            break;
            case Heads: ++frequency1;
            break;
        }
    }
    cout << "Tails were rolled " << frequency0 << " times" << endl;
    cout << "Heads were rolled " << frequency1 << " times" << endl;

    cin.get();
    return 0;
}