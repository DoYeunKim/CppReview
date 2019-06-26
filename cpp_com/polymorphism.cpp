// pointers to base class
// virtual members
#include <iostream>
using namespace std;

class Polygon
{
    protected:
        int width, height;
    public:
        Polygon (int a, int b) : width(a), height(b) {}
        void set_values (int a, int b) { width = a, height = b; }
        // virtual int area () { return 0; } // can be redefined in children classes
        // if abstract class: no need to define the virtual member
        virtual int area () =0; // { definition } is replaced w/ =0
        // if abstract, cannot be used to instantiate objects
        // it can however be used to create pointers
        void printarea () { cout << this->area() << '\n'; }
};

class Rectangle : public Polygon
{
    public:
        Rectangle (int a, int b) : Polygon (a,b) {}
        int area() { return width * height; }
};

class Triangle : public Polygon
{
    public:
        Triangle (int a, int b) : Polygon (a,b) {}
        int area () { return width * height / 2; }
};

int main ()
{
    // Rectangle rect;
    // Triangle trgl;

    // Polygon * ppoly1 = &rect;
    // Polygon * ppoly2 = &trgl;

    Polygon * ppoly1 = new Rectangle (4,5);
    Polygon * ppoly2 = new Triangle (4,5);

    // ppoly1->set_values (4,5);
    // ppoly2->set_values (4,5);

    ppoly1->printarea();
    ppoly2->printarea();

    delete ppoly1, ppoly2;

    return 0;
}