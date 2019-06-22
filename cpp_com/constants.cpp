#include <iostream>

using namespace std;

// Typed constant expressions
const double pi = 3.14159;
const char newline = '\n';
/* using preprocessor definitions
    #define PI 3.14159
    #define NEWLINE '\n' 
*/

// Calculated the circumference of a circle w/ r
int main ()
{
    double r = 5.0;
    double circumference;

    circumference = 2 * pi * r;
    // circumference = 2 * PI * r;
    cout << circumference << newline;
    // cout << circumference << NEWLINE;
    return 0;
}