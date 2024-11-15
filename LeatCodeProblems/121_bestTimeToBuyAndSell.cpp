#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(vector<int> &prices) // 7, 1, 5, 3, 6, 4
{
    int n = prices.size();
    int maxProfit = 0;
    int bestBuy = prices[0]; // 7

    for (int i = 1; i < n; i++)
    {
        if (bestBuy < prices[i])
        {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxProfit = getMaxProfit(prices);
    cout << maxProfit << endl;
}