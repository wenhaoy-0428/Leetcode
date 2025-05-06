#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{

public:
    int helper(vector<int> &nums, int start, int end)
    {
        int res = nums[start], l = 1, maxLen = 1;
        int ref = nums[start], j = start + 1;
        while (j < end)
        {
            if (nums[j] == ref)
            {
                l++;
                if (l > maxLen)
                {
                    res = ref;
                    maxLen = l;
                }
            }
            else
            {
                l = 1;
                ref = nums[j];
            }
            j++;
        }
        return res;
    }

    int majorityElement(vector<int> &nums)
    {
        if (nums.size() % 2 == 0)
        {
            return helper(nums, 0, nums.size());
        }

        int cand1 = helper(nums, 0, nums.size() / 2);
        int cand2 = helper(nums, nums.size() / 2 + 1, nums.size());

        return cand1 == cand2 ? cand1 : nums[nums.size() / 2];
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {3, 2, 3};
    int res = solution.majorityElement(nums);
    ASSERT_EQ(3, res);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = solution.majorityElement(nums);
    ASSERT_EQ(2, res);
}

TEST_F(SolutionTest, test_003)
{
    vector<int> nums = {1, 2, 1, 2, 1};
    int res = solution.majorityElement(nums);
    ASSERT_EQ(1, res);
}

TEST_F(SolutionTest, test_004)
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 2};
    int res = solution.majorityElement(nums);
    ASSERT_EQ(2, res);
}

TEST_F(SolutionTest, test_005)
{
    vector<int> nums = {2, 2, 1, 1, 2, 2};
    int res = solution.majorityElement(nums);
    ASSERT_EQ(2, res);
}

TEST_F(SolutionTest, test_006)
{
    vector<int> nums = {2, 2, 1, 3, 1, 1, 4, 1, 1, 5, 1, 1, 6};
    int res = solution.majorityElement(nums);
    ASSERT_EQ(1, res);
}