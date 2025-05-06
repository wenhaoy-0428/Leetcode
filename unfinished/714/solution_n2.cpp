#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int size = prices.size() + 1;
    vector<int> dp(size, 0);

    for (int i = 2; i < size; i++)
    {
        int profit = 0;
        for (int j = i - 1; j > 0; j--)
        {
            profit = max(prices[i - 1] - prices[j - 1] - fee, profit);
            dp[i] = max(dp[j] + profit, dp[i]);
        }

        // cout << prices[i - 1] << ' ' << dp[i] << endl;
    }
    return dp[size - 1];
}

int main()
{
    vector<int> prices = {1, 4, 6, 2, 8, 3, 10, 14};
    cout << maxProfit(prices, 3) << endl;
}
