#include <iostream>
using namespace std;

class A {};

class B
{
    public:
    // implicit conversion of classes
        // implicit conversion from A (constructor);
        B (const A& x) {}
        // explicit conversion of classes
        // explicit B (const A& x) {}
        // conversion from A (assignment);
        B& operator= (const A& x) { return *this; }
        // conversion to A (type-cast oeprator)
        operator A() { return A(); }        
};

// Takes B as arg
void fn (B x) {}

int main ()
{
    A foo;
    B bar = foo; // call constructor, does not work when explicit (assignment-like syntax doesn't work)
    bar = foo; // call assignment
    foo = bar; // call type-cast operator

    // fn (foo);    // not allowed for explicit conversion
    fn (bar);

    return 0;
}