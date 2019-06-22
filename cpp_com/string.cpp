#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Classical C init
    string mstring = "this is a string \n";
    // Introduced in C++
    string nstring ("this is also a string \n");
    // Introduced in C++ 11
    string ostring {"this too is a string \n"};
    
    cout << mstring << nstring << ostring;
    return 0;
}

