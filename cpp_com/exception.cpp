#include <iostream>
#include <exception> // std::exception
using namespace std;

class MyException: public exception
{
    // Return the const string
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
} MyEx;


int main ()
{
    try 
    {
        throw 20;
    }
    catch (int e)
    {
        cout << "An exception ocurred. Exception Nr. " << e << endl;
    }
    /*
    try
    {
    }

    multiple catch statements of diff. types possible
    */

    /*
    try
    {
        // Nested exceptions
        try
        {
        }
        catch ( ... ) // ellipsis: any exception regardless of type
        {   
        }
    }
    */
    
    try
    {
        throw MyEx;
    }
    catch (exception& e) // using exception class
    {
        cout << e.what() << '\n';
    }

    return 0;   
}