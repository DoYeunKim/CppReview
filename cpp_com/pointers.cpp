#include <iostream>

int addition (int a, int b);
int subtraction (int a, int b);
int operation (int x, int y, int (*functocall) (int, int)); // using a pointer to function call

void increment_all (int* start, int* stop)
{
    int* current = start;
    while (current != stop)
    {
        ++(*current); // increment the value being pointed at
        ++current; // increment the pointer (i.e. move up one)
    }
}

void print_all (int* start, int* stop)
{
    const int* current = start;
    while (current != stop)
    {
        std::cout << *current << '\n';
        ++current;
    }
}

void increase (void* data, int psize)
{
    if (psize == sizeof(char)) {char* pchar; pchar = (char*) data; ++(*pchar); }
    else if (psize == sizeof(int)) {int* pint; pint = (int*) data; ++(*pint); }
}

int main () 
{
    int firstvalue, secondvalue;
    int* mypointer;

    mypointer = &firstvalue;
    *mypointer = 10;
    mypointer = &secondvalue;
    *mypointer = 20;
    std::cout << "First value is: " << firstvalue << '\n';
    std::cout << "Second value is: " << secondvalue << '\n';

    int thirdvalue = 5, fourthvalue = 15;
    int *p1, *p2;

    p1 = &thirdvalue; // value of p1 is address of thirdvalue
    p2 = &fourthvalue; // value of p2 is address of fourthvalue
    *p1 = 10; // value of the deref of p1 is 10 (thirdvalue is 10)
    *p2 = *p1; // value of the deref of p2 is that of deref of p1 (=10) (fourthvalue is 10)
    p1 = p2; // value of p1 is &fourthvalue. p1 now points to fourthvalue
    *p1 = 20; // value of the deref of p1 is 20 (fourthvalue is 20)

    /*
        Now:
        p1 = &fourthvalue
        p2 = &fourthvalue
        *p1 = 20
        *p2 = 10

        thirdvalue = 10
        fourthvalue = 20
    */

    std::cout << "Third value is: " << thirdvalue << '\n';
    std::cout << "Fourth value is: " << fourthvalue << '\n';

    int numbers[5];
    int *p;
    p = numbers; *p = 10; // numbers[0] = 10
    p++;
    *p = 20; // numbers[1] = 20
    p = &numbers[2]; 
    *p = 30; // numbers[2] = 30
    p = numbers + 3;
    *p = 40; // numbers[3] = 40
    p = numbers;
    *(p + 4) = 50; // numbers[4] = 50

    for (int n = 0; n < 5; n++)
    std::cout << numbers[n] << ((n == 4) ? "" : ",") ;
    std::cout << '\n';

    int myvar;
    int * myptr = &myvar;
    /*
        inherently the same as:
        int myvar;
        int * myptr;
        myptr = &myvar; // &myvar is being assigned to myptr, not *myptr

        Thus not to be confused w/:
        int myvar;
        int * myptr;
        *myptr = &myvar;

        Here, the asterisk only indicates that the variable is a pointer.
        It is not an operator. 
    */

    /*

        *p++ : same as *(p++): increment pointer, and deref unincremented address
        *++p : same as *(++p): increment pointer, and deref incremented address
        ++*p : same as ++(*p): deref pointer, and increment the value it points to
        (*p)++ : deref pointer, and post-increment the value it points to

        e.g.
        *p++ = *q++;
        *p = *q;
        ++p;
        ++q;

    */

    int numbers2[] {10, 20, 30};
    increment_all (numbers2, numbers2 + 3);
    print_all (numbers2, numbers2 + 3);

    /*
    int x;
    int* p1 = &x; // non-const pointer to non-const int
    const int* p2 = &x; // non-const pointer to const int
    int* const p3 = &x; // const pointer to non-const int
    const int* const p4 = &x; // const pointer to const int

    int const * IS THE SAME AS const int *
    */


    // VOID POINTERS: undetermined length and deref properties
    char a = 'x';
    int b = 1602;
    increase (&a, sizeof(a));
    increase (&b, sizeof(b));
    std::cout << a << ", " << b << '\n';

    int c,v;
    int (*minus)(int, int) = subtraction; // alias for the function subtraction

    c = operation (7,5, addition);
    v = operation (20, c, minus);
    std::cout << v << '\n';

    return 0;
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall) (int, int))
{
    int g;
    g = (*functocall) (x,y);
    return (g);
}