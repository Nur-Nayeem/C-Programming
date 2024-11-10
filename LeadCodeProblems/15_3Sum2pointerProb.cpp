// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

#include <bits/stdc++.h>
using namespace std;

// use 2sum approch to solve 3sum problem : in 2sum -> (l+r = target). in 3sum -> (target-i = l+r)
int sum_of_three(vector<int> nums)
{
    int sum = 0;
    for (int it : nums)
    {
        sum = sum + it;
    }
    return sum;
}

vector<vector<int>> getThreeSum(vector<int> &nums)
{
    vector<vector<int>> setOfVector;
    int n = nums.size();
    if (n < 3)
        return {};
    else if (n == 3 and sum_of_three(nums) == 0)
    {
        setOfVector.push_back(nums);
        return setOfVector;
    }

    sort(nums.begin(), nums.end());

    int i = 0;
    while (i < n - 2)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            i++;
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        int target = 0 - nums[i];
        while (j < k)
        {
            if (j > (i + 1) and (nums[j] == nums[j - 1]))
            {
                j++;
                continue;
            }
            if (k < (n - 1) and (nums[k] == nums[k + 1]))
            {
                k--;
                continue;
            }
            int jkSum = nums[j] + nums[k];
            if (jkSum == target)
                setOfVector.push_back({nums[i], nums[j], nums[k]});
            if (jkSum > target)
                k--;
            else
                j++;
        }
        i++;
    }
    return setOfVector;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // int sum = sum_of_three(nums);
    // cout << sum;
    vector<vector<int>> ans = getThreeSum(nums);
    for (auto it : ans)
    {
        for (int i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}