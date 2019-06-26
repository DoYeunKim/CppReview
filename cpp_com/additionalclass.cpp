/*
    default constructor 
        C::C();
    destructor      
        C::~C();
    copy constructor
        C::C (const C&);
    copy assignment
        C& operator = (const C&);
    move constructor
        C::C (C&&);
    move assignment
        C& operator = (C&&);

    //  Can select which member function to use as-is
    function_declaration = default;
    function_declaration = delete;
*/

#include <iostream>
#include <string>
using namespace std;

class Example
{
    string* ptr;
    public:
        // Constructors
        Example () : ptr(new string) {}
        Example (const string& str) : ptr(new string(str)) {}
        // Destructor
        ~Example () { delete ptr; }
        // Copy constructor
        Example (const Example& x) : ptr(new string(x.content())) {}
        // Copy assignment
        Example& operator= (const Example& x) { *ptr = x.content(); return *this; };
        // Move Constructor
        Example (Example&& x) : ptr(x.ptr) { x.ptr = nullptr; }
        // Move assignment
        /*
        Example& operator= (Example&& x)
        {
            delete ptr;
            ptr = x.ptr;
            x.ptr = nullptr;
            return *this;
        }
        */
        const string& content() const { return *ptr; }
        // Addition
        Example operator+ (const Example& rhs)
        {
            return Example(content() + rhs.content());
        }
};

int main ()
{
    Example foo ("Example");
    Example bar = foo;

    cout << "bars content: " << bar.content() << "\n";
    
    return 0;
}
