#include <iostream>
#include <string>
using namespace std;

// protofunction
void odd (int x);
void even (int x);
long factorial (long a);

// Using references
void duplicate (int &a, int& b, int&c)
{
    a *= 2;
    b *= 2;
    c *= 2;
}

// By qualifying the two references as const, avoid modification of the values
// We are using reference here for frugality's sake
// Making the function inline makes it an inserted function
inline string concatenate (const string &a, const string &b)
{
    return a + b;
}

// Default values in functions
// Here, b has a default value, meaning that we don't have to pass in the value
// if we are planning to use the default value
int divide (int a, int b= 2)
{
    int r;
    r = a/b;
    return (r);
}

int main ()
{
    int x = 1, y = 3, z = 7;
    string a = "Doubling ", b = "the values: ";
    duplicate (x, y, z);
    cout << concatenate(a, b) << "x=" << x << ", y=" << y << ", z=" << z << "\n";
    
    cout << divide (12) << '\n';
    cout << divide (20, 4) << '\n';

    int i;
    do {
        cout << "Please, enter number (0 to exit): ";
        cin >> i;
        odd(i);
    } while (i != 0);

    long number = 9;
    cout << number << "! = " << factorial(number) << '\n';
    return 0;
}

void odd (int x)
{
    if ((x%2) != 0) cout << "It's odd.\n";
    else even (x);
}

void even (int x)
{
    if ((x%2) == 0) cout << "It's even.\n";
    else odd (x);
}

// Recursive factorial
long factorial (long a) {
    if (a > 1)
        return (a * factorial(a - 1));
    else
        return 1;       
}