#include <iostream>
using namespace std;

class Polygon
{
    // private: not inherited
    protected:
        int width, height; // inherited
    public:
        Polygon () {}
        Polygon (int a, int b) : width(a), height(b) {}
        void set_values (int a, int b) { width = a; height = b; } // inherited
};

class Output
{
    public: 
        static void print (int i) { cout << i << endl; }
};

// inheritance
/*
    What is inherited from the base class?
    constructor/destructor
    assignment operator members
    friends
    private members
*/

class Square;

class Rectangle : public Polygon, public Output // if protected Polygon: public members of Polygon would turn protected
{
    int width, height;
    public:
        Rectangle () {}
        Rectangle (int a, int b) : Polygon (a,b) {}
        int area() { return width * height; }
        // Friend functions
        friend Rectangle duplicate (const Rectangle&);
        void convert (Square a);
};

class Square : public Polygon, public Output
{
    friend class Rectangle;
    private:
        int side;
    public:
        Square () {}
        Square (int s) : side(s) {}
};

class Triangle : public Polygon, public Output
{
    public:
        Triangle () {}
        Triangle (int a, int b) : Polygon (a,b) {}
        int area () { return width * height / 2; }
};

Rectangle duplicate (const Rectangle& param)
{
    Rectangle res;
    res.width = param.width*2;
    res.height = param.height*2;
    return res;
}

void Rectangle::convert (Square a)
{
    width = a.side;
    height = a.side;
}

class Mother
{
    public:
        Mother () { cout << "Mother: no param \n"; }
        Mother (int a) { cout << "Mother: int param \n"; }        
};

class Daughter : public Mother
{
    public:
        Daughter (int a) { cout << "Dauther: int param \n \n"; }
};

class Son : public Mother 
{
    public:
        // Call parent constructor as well
        // derived_constructor_name (param) : base_constructor_name (param) {}
        Son (int a) : Mother (a) { cout << "Son: int param \n\n"; }
};

int main ()
{
    Rectangle foo;
    Rectangle bar (2,3);
    foo = duplicate (bar);
    cout << foo.area() << '\n';

    Rectangle rect;
    Square sqr(4);
    rect.convert(sqr);
    cout << rect.area() << '\n';

    Triangle trgl (4,5);
    Triangle::print (trgl.area());

    Daughter kelly(0);
    Son tom(0);

    return 0;
}