#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the four directions
                    if (i == 0 || grid[i - 1][j] == 0)
                        perimeter++; // Up
                    if (i == grid.size() - 1 || grid[i + 1][j] == 0)
                        perimeter++; // Down
                    if (j == 0 || grid[i][j - 1] == 0)
                        perimeter++; // Left
                    if (j == grid[0].size() - 1 || grid[i][j + 1] == 0)
                        perimeter++; // Right
                }
            }
        }
        return perimeter;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> grid = {

        {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}}

    };

    int result = solution.islandPerimeter(grid);
    ASSERT_EQ(result, 16);
}
