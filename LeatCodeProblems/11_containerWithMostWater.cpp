// 11. Container With Most Water leadcode

#include <bits/stdc++.h>
using namespace std;

// 2 pointer Approch (Optimal solution):
int mostWater(vector<int> &height)
{
    int maxWater = 0;
    int n = height.size();
    int lp = 0, rp = n - 1;
    while (lp < rp)
    {
        int wt = rp - lp;
        int ht = min(height[lp], height[rp]);
        int area = wt * ht;
        maxWater = max(maxWater, area);
        height[lp] < height[rp] ? lp++ : rp--;
    }
    return maxWater;
}

// brute force approch:
// int mostWater(vector<int> &height) //{1, 8, 6, 2, 5, 4, 8, 3, 7};
// {
//     int maxWater = 0;
//     int n = height.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int wt = j - 1;
//             int ht = min(height[i], height[j]);
//             int curr_Area = wt * ht;
//             maxWater = max(maxWater, curr_Area);
//         }
//     }
//     return maxWater;
// }

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = mostWater(height);
    cout << ans << endl;
}