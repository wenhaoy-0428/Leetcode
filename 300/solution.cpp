#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{

    vector<int> nums = {0, 1, 0, 3, 2, 3};
    ASSERT_EQ(4, solution.lengthOfLIS(nums));
}
