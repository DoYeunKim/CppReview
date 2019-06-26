/*
    class class_name {
        access_specifier_1:
            member1;
        access_specifier_2:
            member2;
    } object_names;

    // private: accessible only from w/in other members of the same class ("friends")
    // protected: accessible from friends or derived classes
    // public: accessible from anywhere where the object is visible

    class Rectangle {
        int width, height; // private by access
        public:
            void set_values (int, int);
            int area (void);
    } rect;
    
    rect.set_values (3,4);
    myarea = rect.area();
*/

#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
        Rectangle();
        Rectangle(int, int);
        void set_values(int,int);
        int area() {return width*height;}  // inline definition of function
};

// Default constructor
Rectangle::Rectangle()
{
    width = 5;
    height = 5;
    // Can be called as Rectangle rect; instead of Rectangle rect();
}

// Overloading constructor
Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
}

// Public function
void Rectangle::set_values(int x, int y)
{
    width = x;
    height = y;
}


class Circle {
    double radius;
    public:
        Circle(double r) { radius = r; }
        double circum() {return 2*radius*3.14;}
};

int main ()
{
    Rectangle recta, rectb;
    recta.set_values(3,4);
    rectb.set_values(5,6);
    cout << "recta area: " << recta.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;

    Circle foo(10.0); // functional form
    Circle bar = 20.0; // assignment init.
    Circle bas {30.0}; // uniform int. unlike functional, cannot be confused w/ func dec
    Circle qux = {40.0}; // POD-like
    return 0;
}