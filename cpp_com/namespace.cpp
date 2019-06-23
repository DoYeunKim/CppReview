#include <iostream>
using namespace std;

// global & namespace scope variables are in "static storage"
// local variables are stored as "automatic storage"
int static_storage; // static storage, thus automatically initalized as 0

namespace first
{
    int x = 5;
    int y = 10;
}

namespace second
{
    double x = 3.1416;
    double y = 2.7183;
}

int main ()
{
    using first::x;
    using second::y;

    cout << x << '\n';
    cout << y << '\n';
    cout << first::y << '\n';
    cout << second::x << '\n';

    int automatic_storage; // automatic, thus initial value not guaranteed to be 0
    cout << static_storage << '\n';
    cout << automatic_storage << '\n';

    return 0;
}