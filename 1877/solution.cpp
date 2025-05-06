#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            ans = max(ans, nums[i] + nums[nums.size() - 1 - i]);
        }
        return ans;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {3, 5, 2, 3};
    ASSERT_EQ(7, solution.minPairSum(nums));
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {3, 5, 4, 2, 4, 6};
    ASSERT_EQ(8, solution.minPairSum(nums));
}

TEST_F(SolutionTest, test_003)
{
    vector<int> nums = {4, 1, 5, 1, 2, 5, 1, 5, 5, 4};
    ASSERT_EQ(8, solution.minPairSum(nums));
}
