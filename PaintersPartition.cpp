#include <bits/stdc++.h>
using namespace std;

bool isPosibleUnit(vector<int> &nums, int n, int m, int maxAllowedUnit)
{
    int pnter = 1, unit = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxAllowedUnit)
        {
            return false;
        }
        if (unit + nums[i] <= maxAllowedUnit)
        {
            unit += nums[i];
        }
        else
        {
            pnter++;
            unit = nums[i];
        }
    }
    return pnter <= m;
}

int getMinimumUnit(vector<int> &nums, int m)
{
    int n = nums.size();
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    int st = max, end = sum;
    int ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPosibleUnit(nums, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // 40, 30,10,20
    vector<int> nums = {40, 30, 10, 20};
    int m = 2;
    cout << getMinimumUnit(nums, m);
}