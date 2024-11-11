#include <bits/stdc++.h>
using namespace std;

bool isPosible(vector<int> &arr, int minimumAllocateDistance, int n, int c)
{
    int cows = 1, stallPos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - stallPos) >= minimumAllocateDistance)
        {
            cows++;
            stallPos = arr[i];
        }
        if (cows == c)
        {
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &arr, int n, int c)
{
    sort(arr.begin(), arr.end());
    int st = 1, end = arr[n - 1] - arr[0];
    int ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPosible(arr, mid, n, c))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << getDistance(arr, n, c);
    }
}