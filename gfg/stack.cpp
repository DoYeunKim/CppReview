#include <iostream>
#include <stack>

using namespace std;

void showstack (stack <int> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main ()
{
    stack <int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);

    cout << "The stack is: ";
    showstack(s);

    cout << "\n s.size(): " << s.size();
    cout << "\n s.top(): " << s.top();

    cout << "\n s.pop(): ";
    s.pop();
    showstack(s);

    stack <int> s2;
    s2.push(2);
    s2.push(55);
    s2.push(42);
    s2.push(7);

    cout << "s2 before swap: \n";
    showstack(s2);

    s.swap(s2);
    cout << "s is: \n";
    showstack(s);
    cout << "s2 is: \n";
    showstack(s2);

    s2.emplace(5);
    showstack(s2);
    s2.push(5);
    showstack(s2);

    return 0;
}