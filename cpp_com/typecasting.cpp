#include <iostream>
#include <exception>
using namespace std;

class Dummy
{
    double i, j;
};

class Addition
{
    int x,y;
    public:
        Addition (int a, int b) : x(a), y(b) {}
        int result() { return x + y; }
};

class Base { virtual void dummy() {} };
class Derived: public Base { int a; };

int main ()
{
    // type casting
    Dummy d;
    Addition *padd;
    padd = (Addition*) &d; // pointer padd reassigned to Dummy reference
    cout << padd->result() << '\n';

    // dynamic casting
    /*
        only w/ pointers & references to classes or w/ void*
        ensures that result of type conversion points to a valid complete object of destination pointer type

        pointer upcast: pointer-to-derived to pointer-to-base 
        pointer downcast: pointer-to-base to pointer-to-derived (virtual members)
    */
    try {
        Base * pba = new Derived;
        Base * pbb = new Base;
        Derived *pd;

        pd = dynamic_cast<Derived*>(pba);
        if (pd == 0) cout << "Null pointer on first type-cast. \n";

        pd = dynamic_cast<Derived*>(pbb);
        if (pd == 0) cout << "Null pointer on second type-cast. \n";
    } catch (exception& e) { cout << "Exception: " << e.what(); }

    return 0;
}

/*
    static cast: pointers to related classes (upcast & downcast)
    no checks
    
    e.g.
    class Base {};
    class Derived: public Base {};
    Base * a = new Base;
    Derived * b = static_cast<Derived*>(a);
*/

/*
    reinterpret_cast: converts pointer type to any other pointer type
    const_cast: manipulated the constness of object pointed by a pointer
    e.g.
    void print (char * str) { cout << str << '\n'; }
    int main () 
    {
        const char * c = "sample text";
        print (const_cast <char*> (c) ); // allows passing const variable to non-const func
        return 0;
    }
*/