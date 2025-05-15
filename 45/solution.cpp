#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int current_end = 0, farthest = 0, step = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(nums[i] + i, farthest);
            if (i == current_end)
            {
                current_end = farthest;
                step++;
            }
        }

        return step;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {2, 3, 1, 1, 4};
    int expected = 2;
    int result = solution.jump(nums);
    EXPECT_EQ(result, expected);
}
