/* 
    // Overloading operators
    similar to regular operations, can do class operation.
    e.g.
    struct myclass {
        string product;
        float price;
    } a,b,c;
    a = b + c;

    Some operators can be overloaded in two forms: member function & non-member function
*/

#include <iostream>
using namespace std;

class CVector {
    public:
    int x,y;
    CVector() {};
    CVector(int a, int b) : x(a), y(b) {};
    // syntax for opperator overloading
    // type operator sign (parameters) {}
    CVector operator + (const CVector&);
};

// Member operator overload
CVector CVector::operator+ (const CVector& param)
{
    CVector temp;
    temp.x = x + param.x; // no need to specify struct.x
    temp.y = y + param.y;
    return temp;
}

// Non-member operator overload
CVector operator+ (const CVector& lhs, const CVector& rhs)
{
    CVector temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;
}

class Dummy 
{
    public:
        // class can contain static data/func
        // aka "class variable"
        static int n;
        Dummy () {n++;};
        bool isitme (Dummy& param);
};

int Dummy::n=0;

bool Dummy::isitme (Dummy& param)
{
    if (&param == this) return true;
    else return false;
}

/*
    Constant member func
    const MyClass myobject;

*/

class MyClass 
{
    public:
        int x;
        MyClass (int val) : x(val) {};
        int& get() {return x;};
        /*
            int get() const {return x;} // const member func
            const int& get() {return x;} // member func returning a const&
            const int& get() const {return x;} // const member func returning a const&
        */
        // 
        const int& get() const {return x;}
};


void print (const MyClass& arg)
{
    cout << arg.get() << "\n";
}


int main ()
{
    CVector foo (3,1);
    CVector bar (1,2);
    CVector result;
    result = foo + bar; // result = foo.operator+ (bar);
    cout << result.x << "," << result.y << '\n';

    Dummy a;
    Dummy* b = &a;
    if (b->isitme(a)) cout << "yes, &a is b \n";
    Dummy c[5];
    cout << a.n << '\n';
    Dummy *d = new Dummy;
    cout << Dummy::n << '\n';
    delete d; 

    MyClass mc1(10);
    const MyClass mc2(20);
    mc1.get() = 15;
    // mc2.get() = 25; //not valid as get() returns const int&
    // foo.x = 20 // not valid as x is const
    cout << mc1.get() << '\n';
    cout << mc2.get() << '\n';

    return 0;
}