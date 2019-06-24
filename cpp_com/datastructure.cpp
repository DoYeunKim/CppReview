#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t
{
    string title;
    int year;
} films [3];

void printmovie (movies_t movie);

int main ()
{
    string mystr;
    int n;

    for (n = 0; n < 3; n++)
    {
        cout << "Enter title: ";
        getline (cin, films[n].title);
        cout << "Enter year: ";
        getline (cin, mystr);
        stringstream (mystr) >> films[n].year;
    }

    mine.title = "2001 A Space Odyssey";
    mine.year = 1968;

    cout << "Enter title: ";
    getline (cin, yours.title);
    cout << "Enter year: ";
    getline (cin, mystr);
    stringstream(mystr) >> yours.year;

    cout << "My favorite movie is: \n";
    printmovie (mine);
    cout << "And yours is: \n";
    printmovie (yours);
    return 0;
}

void printmovie (movies_t movie)
{
    cout << movie.title;
    cout << " (" << movie.year << ")\n";
}