// 5. Longest Palindromic Substring
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrom(string &s, int low, int heigh)
{
    while (low < heigh)
    {
        if (s[low] != s[heigh])
        {
            return false;
        }
        low++;
        heigh--;
    }
    return true;
}

string longestPalindrome(string &s) // babad
{
    int l = s.length();
    int maxLen = 1, start = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            if (checkPalindrom(s, i, j) && (j - i + 1) > maxLen)
            {
                start = i;
                maxLen = (j - i + 1);
            }
        }
    }
    return s.substr(start, maxLen);
}
int main()
{
    string s = "babad";
    cout << longestPalindrome(s);
}