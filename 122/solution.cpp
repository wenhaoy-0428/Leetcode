#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int result = 0;
    for (size_t i = 0; i < prices.size() - 1; i++)
    {
        int profit = prices[i + 1] - prices[i];
        if (profit > 0)
        {
            result += profit;
        }
    }
    return result;
}

int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
}
