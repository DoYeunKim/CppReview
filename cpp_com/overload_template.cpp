#include <iostream>
using namespace std;

// Overloading "operate" for different type inputs
int operate (int a, int b)
{
    return (a * b);
}

double operate (double a, double b)
{
    return (a/b);
}

template <class T>
T sum (T a, T b)
{
    return (a + b);
}

template <class T, class U>
bool are_equal (T a, U b)
{
    return (a == b);
}

// Non-type template arguments
template <class T, int N>
T fixed_multiply (T val)
{
    return val * N;
}

int main ()
{
    int x = 5, y = 2;
    double n = 5.0, m = 2.0;
    cout << operate (x, y) << '\n';
    cout << operate (n, m) << '\n';

    cout << sum<int> (x, y) << '\n'; // Can drop the type indicator
    cout << sum<double> (n, m) << '\n';

    if (are_equal(10, 10.0))
        cout << "x and y are equal! \n";
    else
        cout << "x and y are not equal! \n";
    
    cout << fixed_multiply<int, 2>(10) << '\n';
    cout << fixed_multiply<double, 3>(10) << '\n';

    return 0;
}