#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{

    // remove trailing space
    int size = s.size();
    while (size > 1)
    {
        if (s[size - 1] == ' ')
            size--;
        else
            break;
    }
    s.resize(size);

    reverse(s.begin(), s.end());
    // remove trailing space
    size = s.size();
    while (size > 1)
    {
        if (s[size - 1] == ' ')
            size--;
        else
            break;
    }

    s.resize(size);


    return s;
}
int main()
{
    string s = " the sky is blue ";
    string ans = reverseWords(s);
    cout<< ans;

    return 0;
}