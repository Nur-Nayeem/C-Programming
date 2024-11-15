// s1 = "ab", s2 = "eidbaooo"
#include <bits/stdc++.h>
using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2)
{
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }
    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};
        while (windIdx < windowSize && idx < s2.length())
        {
            windFreq[s2[idx] - 'a']++;
            windIdx++, idx++;
        }
        if (isFreqSame(windFreq, freq))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool ans = checkInclusion(s1, s2);
    cout << ans;
}