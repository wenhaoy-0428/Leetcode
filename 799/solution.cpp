#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> dp;
        dp.push_back({0, double(poured), 0});
        // print2DVector(dp);
        for (int i = 0; i < query_row + 1; i++)
        {
            printVector(dp[i]);
            dp.push_back({0});
            for (int j = 0; j < dp[i].size() - 1; j++)
            {
                dp[i + 1].push_back(max(0.0, dp[i][j] - 1) / 2.0 + max(0.0, dp[i][j + 1] - 1) / 2.0);
            }
            dp[i + 1].push_back(0);
        }

        return max(1.0, dp[query_row][query_glass + 1]);
    }
};

int main()
{

    Solution solution;
    cout << solution.champagneTower(100000009, 33, 17) << endl;
    // cout << solution.champagneTower(2, 1, 1) << endl;
}