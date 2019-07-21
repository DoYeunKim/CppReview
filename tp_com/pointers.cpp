#include <iostream>

using namespace std;

int main ()
{
    // Address
    int var1;
    char var2[10];

    cout << "Address of var1 variable: ";
    cout << &var1 << endl;

    cout << "Address of var2 variable: ";
    cout << &var2 << endl;

    // pointer
    int var = 20; // actual variable
    int *ip; // pointer

    ip = &var; // store address of var in pointer

    cout << "Value of var variable: " << var << endl;

    // print address of var
    cout << "Address of var, as stored in ip: " << ip << endl;

    // proitn value of var, as accessed through pointer
    cout << "Value of var, as pointed at by ip: " << *ip << endl;
    

    return 0;
}