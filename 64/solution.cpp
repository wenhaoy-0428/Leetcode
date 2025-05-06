#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Each time, we reduce the problem into subproblems where, m, n indicates
 * the top left corner of the new subproblem. We find the minimum path sum in the subproblem.
 * In subproblems, we can find overlaps with the same m, n. Hence, we store the result using memoization.
 * @param grid
 * @param m: row index of the top left corner of the subproblem.
 * @param n column index of the top left corner of the subproblem.
 * @param dp
 * @return int
 */
int helper(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
{
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    int sum = 0;
    if (m == grid.size() - 1)
    {
        for (int i = n; i < grid[0].size(); i++)
        {
            sum += grid[m][i];
        }
        return sum;
    }
    else if (n == grid[0].size() - 1)
    {
        for (int i = m; i < grid.size(); i++)
        {
            sum += grid[i][n];
        }
        return sum;
    }

    dp[m][n] = min(helper(grid, m, n + 1, dp), helper(grid, m + 1, n, dp)) + grid[m][n];
    return dp[m][n];
}

int main()
{
    vector<vector<int>> target = {
        {1, 2, 3},
        {4, 5, 6},
    };

    vector<vector<int>> dp(target.size(), vector<int>(target[0].size()));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << helper(target, 0, 0, dp) << endl;
}