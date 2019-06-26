#include <iostream>
using namespace std;

/* 
    Simple examples
*/

template <class T>
class mypair
{
    T a, b;
    public:
        mypair (T first, T second) {a = first, b = second;}
    T getmax ();
};

// def of member function
template <class T>
T mypair<T>::getmax ()
{
    T retval;
    retval = a>b? a : b;
    return retval;
}

/*
    template specialization: diff. implementation for specific type
*/

// class template
template <class T>
class mycontainer
{
    T element;
    public:
        mycontainer (T arg) { element = arg; }
        T increase () { return ++element; }
};

// class template specialization:
/*
    template <> as no template arguments are required for specialization
*/
template <>
class mycontainer <char> // regular template: class mycontainer [no type specification]
{
    char element;
    public:
        mycontainer (char arg) { element = arg; }
        char uppercase ()
        {
            if ((element >= 'a') && (element <= 'z'))
                element += 'A' - 'a';
            return element;
        }
};


int main ()
{
    mypair <int> myobject (100, 75);
    cout << myobject.getmax() << '\n';

    mycontainer <int> myint (7);
    mycontainer <char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;

    return 0;
}