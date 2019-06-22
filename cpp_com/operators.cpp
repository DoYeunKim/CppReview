#include <iostream>

using namespace std;

int main ()
{
    // compound assignment
    int a, b = 3;
    a = b;
    a += 2;
    cout << a << "\n";

    // increments
    int x, y = 3;
    x = ++y;
    cout << x << " " << y << "\n";

    x = y = 3;
    y = x++;
    cout << x << " " << y << "\n";

    // conditional ternary
    // if 7 eqals 5, then output 4. else, output 3
    cout << (7 == 5 ? 4 : 3) << "\n";

    // comma operator
    // Here, f = g+4 where g = 4
    int f, g;
    f = (g = 4, g+4);
    cout << f << " is 4 plus " << g << "\n";
}