// 238. Product of Array Except Self
#include <bits/stdc++.h>
using namespace std;

//// optimal solumton: TC = O(n) and SC: O(1)
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    // prefix
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // sufix
    int sufix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        sufix *= nums[i + 1];
        ans[i] *= sufix;
    }

    return ans;
}

//// optimal solumton: TC = O(n) and SC: O(n)
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans(n, 1);
//     vector<int> prefix(n, 1);
//     vector<int> sufix(n, 1);

//     // prefix
//     for (int i = 1; i < n; i++)
//     {
//         prefix[i] = prefix[i - 1] * nums[i - 1];
//     }

//     // sufix
//     for (int i = n - 2; i >= 0; i--)
//     {
//         sufix[i] = sufix[i + 1] * nums[i + 1];
//     }

//     // ans
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = prefix[i] * sufix[i];
//     }

//     return ans;
// }

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans;
    ans = productExceptSelf(nums);
    for (int el : ans)
    {
        cout << el << " ";
    }
}