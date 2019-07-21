/*
    strcpy(s1, s2): copy s2 to s1
    strcat(s1, s2): concant s2 onto s1
    strlen(s1): length of s1
    strcmp(s1, s2): 0 if s1 == s2, -n if s1 < s2, +n if s1 > s2
    strchr(s1, ch): pointer to first occurrence of ch in s1
    strstr(s1, s2): pointer to first occurrence of s2 in s1
*/

#include <iostream>
#include <cstring> // using cstring
#include <string> // using c++ std sting library

using namespace std;

int main ()
{
    char str1[10] = "Hello"; 
    char str2[10] = "World";
    char str3[10];
    int len;

    // copy str1 into str3
    strcat(str3, str1);
    cout << "strcpy(str3, str1): " << str3 << endl;

    // concat str1 and str2
    strcat(str1, str2);
    cout << "strcat(str1, str2): " << str1 << endl;

    // total len of str1 after concat
    len = strlen(str1);
    cout << "strlen(str1): " << len << endl;

    return 0;
}