/*
    Compared to pointers....
    * Cannot have NULL references
    * reference is imutable, whereas pointer can point at other object
    * reference must be initialized upon creation
*/

#include <iostream>
#include <ctime>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues (int i)
{
    return vals[i]; // return ref to the ith element
}

int main ()
{
    // declare simple variables
    int i; 
    double d;

    // declare reference variables;
    int& r = i;
    double& s = d;

    i = 5;
    cout << "Value of i: " << i << endl;
    cout << "Value of i reference: " << r << endl;

    d = 11.7;
    cout << "Value of d: " << d << endl;
    cout << "Value of d reference: " << s << endl;

    cout << "Value before change: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = " << vals[i] << endl;
    }

    setValues(1) = 20.33;
    setValues(3) = 70.8;

    cout << "Value after change: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = " << vals[i] << endl;
    }

    return 0;
}