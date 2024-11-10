#include <bits/stdc++.h>
using namespace std;

////Brute force approch . O(n^2)
// int findMejority(vector<int>& nums, int moreThen)
// {
//     int n = nums.size();

//     for (int i = 0; i < n; i++)
//     {
//         int currCount = 0;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[i] == nums[j])
//             {
//                 currCount++;
//             }
//         }
//         if (currCount > moreThen)
//         {
//             return i;
//         }
//     }
// }

////using map stl. O(n)
// int findMejority(vector<int> nums)
// {
//     map<int, int> fr;
//     int n = nums.size();
//     for (int num : nums)
//     {
//         fr[num]++;
//     }
//     for (auto it : fr)
//     {
//         if (it.second > n / 2)
//         {
//             return it.first;
//         }
//     }
//     return -1;
// }

//// optimized in sorting data: //O(nlogn)
// int findMejority(vector<int> nums)
// {
//     int n = nums.size();
//     sort(nums.begin(), nums.end()); // 11122
//     int freq = 1, ans = nums[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             freq++;
//         }
//         else
//         {
//             freq = 1;
//             ans = nums[i];
//         }
//         if (freq > n / 2)
//         {
//             return ans;
//         }
//     }
//     return ans;
// }

////Using moores voting algorithm:

int findMejority(vector<int> &nums)
{
    int n = nums.size();
    int freq = 0, ans = 0;
    for (int i = 0; i < n; i++) // 1, 2, 2, 1, 1
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    int count = 0;
    for (int el : nums)
    {
        if (el == ans)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return ans;
    }
    else
        return -1;
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 1};
    int n = nums.size();
    int ans = findMejority(nums);
    cout << ans;
}