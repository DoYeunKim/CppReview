/*
    The following are the same, where '\0' is a null char, marking the end
    char myword[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char myword[] = "Hello";

    arrays cannot be assigned values, but the individual index can
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    char question1[] = "What is your name? ";
    string question2 = "Where do you live? ";
    char answer1 [80];
    string answer2;
    string holder;
    cout << question1;
    getline(cin, holder);
    stringstream(holder) >> answer1;
    cout << question2;
    getline(cin, holder);
    stringstream(holder) >> answer2;
    cout << "Hello, " << answer1;
    cout << " from " << answer2 << "!\n";

    cout << "This is printed as a library string: " << answer2 << "\n";
    cout << "This is printed as a c-string: " << answer2.c_str() << "\n";

    return 0;
}