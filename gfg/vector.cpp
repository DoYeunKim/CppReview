#include <iostream>
#include <vector>


using namespace std;

int main ()
{
    vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";
    
    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend: ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";

    cout << "\nSize: " << g1.size();
    cout << "\nCapacity: " << g1.capacity();
    cout << "\nMax_Size: " << g1.max_size();

    g1.resize(4);
    cout << "\nSize: " << g1.size();

    if (!g1.empty())
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
    
    g1.shrink_to_fit();
    cout << "\nVector elements are: ";
    for (auto it = g1.begin(); it != g1.end(); ++it)
        cout << *it << " ";

    vector<int> g2;
    for (int i = 1; i <= 10; i++)
        g2.push_back(i * 10);

    // reference to element at position [g]
    cout << "\nReference operator [g]: g2[2] = " << g2[2];
    // reference to the element at position g
    cout << "\nat: g2.at(4) = " << g2.at(4);
    // reference to the first element
    cout << "\nfront(): g2.front() = " << g2.front();
    // reference to the last element
    cout << "\nback(): g2.back() = " << g2.back();

    // pointer to the memory array used internally by the vector
    // = pointer to the first element
    int* pos = g2.data();
    cout << "\nThe first element is: " << *pos;

    vector<int> v;
    v.assign(5,10);
    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    v.push_back(15);
    int n = v.size();
    cout << "\nThe last element is: " << v[n-1];

    v.pop_back();
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size() ; i++)
        cout << v[i] << " ";
    
    v.insert(v.begin(), 5);
    cout << "\nThe first element is: " << v[0];

    v.erase(v.begin());

    cout << "\nThe first element is: " << v[0];

    v.emplace_back(20);
    n = v.size();
    cout << "\nThe last element is: " << v[n-1];

    v.clear();
    cout << "\nVector size after erase(): " << v.size();


    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    cout << "\n\nVector 1: " ;
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    
    v1.swap(v2);

    cout << "\nAfter swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";



    return 0;
}