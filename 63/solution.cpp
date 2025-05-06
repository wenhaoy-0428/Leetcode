#include <vector>
#include <iostream>
#include "../util/util.h"

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    // dimension of the grid
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // dp table with an extra space.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // initialization
    for (auto ot = dp.begin(); ot != dp.end(); ot++)
    {
        for (auto it = ot->begin(); it != ot->end(); it++)
        {
            *it = 0;
        }
    }
    // set base case seed.
    dp[1][1] = 1;
    print2DVector(dp);

    // go over the dp, where each postion [i, j] represents the bottom-right grid with size ij.
    // which can be regarded as a subproblem.
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            // when the top left corner of the subproblem is an obsticle
            // it can't contribute to the next bigger problems.
            // For the original grid, (m - x) where x is the index of the obstacle,
            // gives the size of the subgrid which has the obstacle as topleft cornner, destination
            // at the bottom right corner. Hence, (m - x) = i => x = m - i, the same for j.

            print2DVector(dp);
            if (i <= m && j <= n && obstacleGrid[m - i][n - j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i < m)
            {
                dp[i + 1][j] += dp[i][j];
            }
            if (j < n)
            {
                dp[i][j + 1] += dp[i][j];
            }
        }
    }

    return dp[m][n];
}

int main()
{
    vector<vector<int>> ob = {
        {1},
    };
    cout << uniquePathsWithObstacles(ob) << endl;
}