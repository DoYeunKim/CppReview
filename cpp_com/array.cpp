// int foo[] = {1,2,3} is the same as int foo[] {1,2,3}
// int foo[5] = {1,2,3} is the same as int foo[5]{1,2,3,0,0} where 0 is the default value
#include <iostream>
#include <array>

int foo[] = {16, 2, 77, 40, 12071};
int n, result = 0;

// declaring as array type w/ empty parameter allows to use array as a parameter for a function
void printarray (int arg[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << arg[i] << ' ';
    }
    std::cout << '\n';
}

int main ()
{
    for (n = 0; n < 5; ++n)
    {
        result += foo[n];
    }
    std::cout << result << '\n';

    int firstarray[] {5, 10, 15};
    int secondarray[] {2,4,6,8,10};
    printarray(firstarray, 3);
    printarray(secondarray, 5);

    // Using array library instead of native array
    std::array<int, 3> myarray {1,2,3};
    for (int j = 0; j < myarray.size(); ++j)
        ++myarray[j];
    for (int elem : myarray)
        std::cout << elem << '\n';

    return 0;
}