/*
cin: std input
cout: std output
cerr: std error 
clog: std log
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
    int i, j;
    cout << "Please enter two integer values: ";
    cin >> i >> j;
    cout << "The values you entered are " << i << " and " << j;
    cout << " and their product is " << i * j << "." << endl;

    // Using getline to have the user input strings
    string mystr;
    cout << "What is your name? ";
    getline (cin, mystr);
    cout << "Hello " << mystr << ".\n";
    cout << "What is your favorite team? ";
    getline (cin, mystr);
    cout << "I like " << mystr << " too! \n";

    // Using stringstream which allows string to be treated as a stream string nstr;
    string nstr;
    float price = 0;
    int quantity = 0;

    cout << "Enter price: ";
    getline(cin, nstr);
    stringstream(nstr) >> price;
    cout << "Enter quantity: ";
    getline(cin, nstr);
    stringstream(nstr) >> quantity;
    cout << "Total price: " << price * quantity << endl;

    return 0;
}