#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<vector<string>> array1 = {{"c", "c", "a", "a", "c", "a", "b", "a", "c", "b"}, {"cc", "a", "a", "c", "a", "b", "a", "c", "b"}, {"cc", "aa", "c", "a", "b", "a", "c", "b"}, {"cc", "aa", "c", "aba", "c", "b"}, {"cc", "aa", "cabac", "b"}, {"cc", "a", "aca", "b", "a", "c", "b"}, {"cc", "a", "a", "c", "aba", "c", "b"}, {"cc", "a", "a", "cabac", "b"}, {"cc", "aa", "cabac", "b"}, {"c", "c", "aa", "c", "a", "b", "a", "c", "b"}, {"cc", "aa", "c", "a", "b", "a", "c", "b"}, {"cc", "aa", "c", "aba", "c", "b"}, {"cc", "aa", "cabac", "b"}, {"c", "caac", "a", "b", "a", "c", "b"}, {"c", "caac", "aba", "c", "b"}, {"c", "c", "aa", "c", "aba", "c", "b"}, {"c", "c", "aa", "cabac", "b"}, {"c", "c", "a", "aca", "b", "a", "c", "b"}, {"c", "c", "a", "a", "c", "aba", "c", "b"}, {"c", "c", "a", "a", "cabac", "b"}, {"c", "c", "aa", "cabac", "b"}, {"cc", "aa", "cabac", "b"}};

    vector<vector<string>> array2 = {{"c", "c", "a", "a", "c", "a", "b", "a", "c", "b"}, {"c", "c", "a", "a", "c", "aba", "c", "b"}, {"c", "c", "a", "a", "cabac", "b"}, {"c", "c", "a", "aca", "b", "a", "c", "b"}, {"c", "c", "aa", "c", "a", "b", "a", "c", "b"}, {"c", "c", "aa", "c", "aba", "c", "b"}, {"c", "c", "aa", "cabac", "b"}, {"c", "caac", "a", "b", "a", "c", "b"}, {"c", "caac", "aba", "c", "b"}, {"cc", "a", "a", "c", "a", "b", "a", "c", "b"}, {"cc", "a", "a", "c", "aba", "c", "b"}, {"cc", "a", "a", "cabac", "b"}, {"cc", "a", "aca", "b", "a", "c", "b"}, {"cc", "aa", "c", "a", "b", "a", "c", "b"}, {"cc", "aa", "c", "aba", "c", "b"}, {"cc", "aa", "cabac", "b"}};

    for (auto ele1 : array1)
    {
        int found = 0;
        for (auto ele2 : array2)
        {
            if (ele1 == ele2)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            string s;
            s += '[';
            for (auto a : ele1)
            {
                s += '"' + a + '"' + ',';
            }
            s[s.length() - 1] = ']';
            cout << s << " is not found in array2" << endl;
        }
    }

    for (auto ele2 : array2)
    {
        int found = 0;
        for (auto ele1 : array1)
        {
            if (ele2 == ele1)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            string s;
            s += '[';
            for (auto a : ele2)
            {
                s += '"' + a + '"' + ',';
            }
            s[s.length() - 1] = ']';
            cout << s << " is not found in array1" << endl;
        }
    }
}