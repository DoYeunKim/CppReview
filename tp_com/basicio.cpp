#include <iostream>

using namespace std;

int main ()
{
    char str[] = "Hello C++";
    char name[500];

    // basic output: cout
    cout << "Value of str is: " << str << endl;

    // basic inout: cin
    cout << "Please enter your name: ";
    cin >> name; // multiple data can be requested as such: cin >> name >> age;
    cout << "Your name is: " << name << endl;

    // basic error: cerr
    char err[] = "Unable to read....";
    cerr << "Error message: " << err << endl;

    // basic log: clog
    char log[] = "Unable to read....";
    clog << "Error message: " << log << endl;

    return 0;
}