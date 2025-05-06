#include <iostream>
#include <vector>
using namespace std;

int maxProfit_v1(vector<int> &prices)
{
    size_t size = prices.size();
    int mxProfit = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            int profit = prices[j] - prices[i];
            if (profit > mxProfit)
            {
                mxProfit = profit;
            }
        }
    }
    return mxProfit;
}

int maxProfit(vector<int> &prices)
{
    size_t size = prices.size();
    int mxProfit = 0;
    int buy = 0;
    int sell = 0;
    for (size_t i = 0; i < size; i++)
    {
        int profit = prices[sell] - prices[buy];
        if (profit > mxProfit)
        {
            mxProfit = profit;
        }

        if (profit < 0)
        {
            buy = i;
        }
        sell++;
    }
    return mxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}
