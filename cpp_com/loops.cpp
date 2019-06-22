#include <iostream>
#include <string>

using namespace std;

int main ()
{

    // while loop
    // do while loop
    // for loop

    // range-based for loop
    string str {"Hello!"};
    // for (auto c: str)
    for (char c : str)
    {
        cout << "[" << c << "]";
    }
    cout << '\n';

    // jumps: break, continue, goto
    for (int n = 10; n > 0; n--)
    {
        if (n == 8)
        {
            // skips when n == 8
            continue;
        }

        cout << n << ", ";

        if (n == 3) 
        {
            // breks out of the current loop
            cout << "countdown aborted! \n";
            break;
        }
    }

    int k = 4;
    cout << "Using goto now: \n";
label:
    cout << k << ", ";
    k--;
    if (k > 0) goto label;
    cout << "liftoff! \n";

}
