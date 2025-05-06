#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int res = 0, n = nums.size(), total = 0;
        std::vector<std::unordered_map<long long, int>> dp(n);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)nums[i] - nums[j];
                int count = dp[j].count(diff) ? dp[j][diff] : 0;

                dp[i][diff] += count + 1;
                total += count;
            }
        }
        return total;
    }
};

class Solution_slow
{
public:
    int helper(vector<int> &nums, unordered_map<string, int> &dp, long int diff, int i, int j)
    {
        int total = 0;
        if (i == nums.size())
        {
            return 0;
        }
        string key = to_string(diff) + '-' + to_string(i) + '-' + to_string(j);
        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }

        if ((diff >= 0 && nums[i] >= nums[j]) || (diff < 0 && nums[i] < nums[j]))
        {
            long int tmp = (long int)(nums[i]) - (long int)(nums[j]);
            if (tmp == diff)
            {
                total++;
                total += helper(nums, dp, diff, i + 1, i);
            }
        }

        dp[key] = total + helper(nums, dp, diff, i + 1, j);
        return dp[key];
    }

    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int total = 0;
        unordered_map<string, int> dp;

        if (nums.size() < 3)
        {
            return 0;
        }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                long int diff = (long int)(nums[j]) - (long int)(nums[i]);

                total += helper(nums, dp, diff, j + 1, j);
            }
        }
        return total;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {2, 4, 6, 8, 10};
    int result = solution.numberOfArithmeticSlices(nums);
    ASSERT_EQ(7, result);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {7, 7, 7, 7, 7};
    int result = solution.numberOfArithmeticSlices(nums);
    ASSERT_EQ(16, result);
}

TEST_F(SolutionTest, test_003)
{
    vector<int> nums = {0, 2000000000, -294967296};
    int result = solution.numberOfArithmeticSlices(nums);
    ASSERT_EQ(0, result);
}

TEST_F(SolutionTest, test_004)
{
    vector<int> nums = {-2147483648, 0, -2147483648};
    int result = solution.numberOfArithmeticSlices(nums);
    ASSERT_EQ(0, result);
}

TEST_F(SolutionTest, test_005)
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int result = solution.numberOfArithmeticSlices(nums);
    ASSERT_EQ(134217349, result);
}
