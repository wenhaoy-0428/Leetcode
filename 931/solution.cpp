#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int minParent = matrix[i - 1][j];
                if (j - 1 >= 0)
                {
                    minParent = min(minParent, matrix[i - 1][j - 1]);
                }
                if (j + 1 < n)
                {
                    minParent = min(minParent, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += minParent;
            }
        }
        int res = matrix[n - 1][0];
        for (int i = 1; i < n; i++)
        {
            res = min(res, matrix[n - 1][i]);
        }
        return res;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    int res = solution.minFallingPathSum(matrix);
    ASSERT_EQ(13, res);
}

TEST_F(SolutionTest, test_002)
{
    vector<vector<int>> matrix = {{-19, 57}, {-40, -5}};
    int res = solution.minFallingPathSum(matrix);
    ASSERT_EQ(-59, res);
}