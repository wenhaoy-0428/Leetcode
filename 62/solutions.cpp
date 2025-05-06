#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(int m, int n, vector<vector<int>> &dp)
{

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m <= 0 || n <= 0)
    {
        return 0;
    }

    dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    dp[n][m] = dp[m][n];
    return dp[m][n];
}

int uniquePaths(int m, int n)
{
    int size = max(m, n) + 1;
    vector<vector<int>> dp(size, vector<int>(size));
    for (auto outerIt = dp.begin(); outerIt != dp.end(); outerIt++)
    {
        for (auto innerIt = outerIt->begin(); innerIt != outerIt->end(); innerIt++)
        {
            *innerIt = -1;
        }
    }

    return helper(m, n, dp);
}

int main()
{

    cout << uniquePaths(3, 7) << endl;
}