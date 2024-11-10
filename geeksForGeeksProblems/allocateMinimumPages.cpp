#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int k, int maxAllowedPage)
{
    int std = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPage)
        {
            return false;
        }
        if (pages + arr[i] <= maxAllowedPage)
        {
            pages += arr[i];
        }
        else
        {
            std++;
            pages = arr[i];
        }
    }
    return std > k ? false : true;
}

int findPages(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n < k)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int ans = -1;
    int st = 0, end = sum;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, k, mid))
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
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(arr, k);
}