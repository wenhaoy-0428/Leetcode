#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

/**
You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

The grid contains a value coins[i][j] in each cell:

If coins[i][j] >= 0, the robot gains that many coins.
If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

Note: The robot's total coins can be negative.

Return the maximum profit the robot can gain on the route.
**/

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int m = static_cast<int>(coins.size());
        const int n = static_cast<int>(coins[0].size());
        const int NEG_INF = INT_MIN / 4;

        // dp[i][j][k]: max coins at (i, j) after using k neutralizations (k in [0,2]).
        vector<vector<array<int, 3>>> dp(
            m, vector<array<int, 3>>(n, {NEG_INF, NEG_INF, NEG_INF}));
        

        // We'll fill transitions next.
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = 0;
        }

        for (int i = 1; i < m; i++) {
            if (coins[i][0] >= 0) {
                dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
                dp[i][0][1] = dp[i - 1][0][1] + coins[i][0];
                dp[i][0][2] = dp[i - 1][0][2] + coins[i][0];
            } else {
                dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];
                dp[i][0][1] = max(dp[i - 1][0][1] + coins[i][0], dp[i - 1][0][0]);
                dp[i][0][2] = max(dp[i - 1][0][2] + coins[i][0], dp[i - 1][0][1]);
            } 
        }

        for (int i = 1; i < n; i++) {
            if (coins[0][i] >= 0) {
                dp[0][i][0] = dp[0][i - 1][0] + coins[0][i];
                dp[0][i][1] = dp[0][i - 1][1] + coins[0][i];
                dp[0][i][2] = dp[0][i - 1][2] + coins[0][i];
            } else {
                dp[0][i][0] = dp[0][i - 1][0] + coins[0][i];
                dp[0][i][1] = max(dp[0][i - 1][1] + coins[0][i], dp[0][i - 1][0]);
                dp[0][i][2] = max(dp[0][i - 1][2] + coins[0][i], dp[0][i - 1][1]);
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (coins[i][j] >= 0) {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j];
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) + coins[i][j];
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]) + coins[i][j];
                } else {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j];
                    dp[i][j][1] = max(
                        max(dp[i-1][j][1], dp[i][j-1][1]) + coins[i][j],
                        max(dp[i-1][j][0], dp[i][j-1][0]));
                    dp[i][j][2] = max(
                        max(dp[i-1][j][2], dp[i][j-1][2]) + coins[i][j],
                        max(dp[i-1][j][1], dp[i][j-1][1]));
                }
            }
        }
        return max(max(dp[m-1][n-1][0], dp[m-1][n-1][1]), dp[m-1][n-1][2]);
    }
};



class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> coins = {{0}};
    int result = solution.maximumAmount(coins);
    ASSERT_EQ(result, 0);
}
