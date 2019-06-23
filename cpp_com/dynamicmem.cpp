/*
    two standard mechanisms of dynamic malloc
    1. exceptions (bad_alloc) thrown when alloc fails
    2. nothrow (pointer returned by new is a null pointer instead of throwing an error)

    *** nothrow can be less efficient as we are checking once more instead of just accepting an error
*/

/*
    new <--> delete
*/

#include <iostream>
#include <new>
using namespace std;

int main ()
{
    int i, n;
    int *p;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p = new (nothrow) int[i];
    if (p == nullptr)
        cout << "Error: memory could not be allocated";
    else
    {
        for (n = 0; n < i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
        {
            cout << p[n] << ((n == i - 1) ? "\n" : ", ");
        }
    delete[] p;
    }
    return 0;
}