#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            res = max(nums[i], res);
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
    vector<int> word1 = {1, 2, 3, 4, 5};
    int result = solution.maxSubArray(word1);
    ASSERT_TRUE(result == 15);
}
