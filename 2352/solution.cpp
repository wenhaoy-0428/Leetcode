#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int result = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t f = 0; f < grid.size(); f++)
            {
                size_t j = 0;
                for (; j < grid.size(); j++)
                {
                    if (grid[i][j] != grid[j][f])
                    {
                        break;
                    }
                }
                if (j == grid.size())
                {
                    result++;
                }
            }
        }
        return result;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    ASSERT_EQ(1, solution.equalPairs(grid));
}

TEST_F(SolutionTest, test_002)
{
    vector<vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    ASSERT_EQ(3, solution.equalPairs(grid));
}