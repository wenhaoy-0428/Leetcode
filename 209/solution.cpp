#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        int sum = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans, i - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};

class Solution_
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0, sum = 0;
        int minL = nums.size();

        while (j <= nums.size() && i < nums.size())
        {

            if (sum == target)
            {
                minL = min(j - i, minL);
                // sum += nums[j];
            }
            if (sum > target)
            {
                sum -= nums[i];
                i++;
            }
            else
            {
                if (j == nums.size())
                {
                    break;
                }
                sum += nums[j];
                j++;
            }
        }
        if (sum != target && minL == nums.size())
        {
            return 0;
        }
        return minL;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     vector<int> nums = {2, 3, 1, 2, 4, 3};
//     int target = 7;
//     int res = solution.minSubArrayLen(target, nums);
//     ASSERT_EQ(2, res);
// }

// TEST_F(SolutionTest, test_002)
// {
//     vector<int> nums = {1, 4, 4};
//     int target = 4;
//     int res = solution.minSubArrayLen(target, nums);
//     ASSERT_EQ(1, res);
// }

// TEST_F(SolutionTest, test_003)
// {
//     vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
//     int target = 11;
//     int res = solution.minSubArrayLen(target, nums);
//     ASSERT_EQ(0, res);
// }

TEST_F(SolutionTest, test_004)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 11;
    int res = solution.minSubArrayLen(target, nums);
    ASSERT_EQ(3, res);
}