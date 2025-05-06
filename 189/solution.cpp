#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
        {
            return;
        }
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int> &nums, int start, int end)
    {
        int i = start, j = end;

        while (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 4;
    vector<int> exp = {5, 6, 7, 1, 2, 3, 4};
    solution.rotate(nums, k);
    bool res = true;
    ASSERT_TRUE(nums.size() == exp.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != exp[i])
        {
            res = false;
        }
    }
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    vector<int> exp = {6, 7, 1, 2, 3, 4, 5};
    solution.rotate(nums, k);
    bool res = true;
    ASSERT_TRUE(nums.size() == exp.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != exp[i])
        {
            res = false;
        }
    }
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_003)
{
    vector<int> nums = {-1, -100, 3, 99};
    int k = 2;
    vector<int> exp = {3, 99, -1, -100};
    solution.rotate(nums, k);
    bool res = true;
    ASSERT_TRUE(nums.size() == exp.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != exp[i])
        {
            res = false;
        }
    }
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_004)
{
    vector<int> nums = {1, 2};
    int k = 0;
    vector<int> exp = {1, 2};
    solution.rotate(nums, k);
    bool res = true;
    ASSERT_TRUE(nums.size() == exp.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != exp[i])
        {
            res = false;
        }
    }
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_005)
{
    vector<int> nums = {1, 2};
    int k = 3;
    vector<int> exp = {2, 1};
    solution.rotate(nums, k);
    bool res = true;
    ASSERT_TRUE(nums.size() == exp.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != exp[i])
        {
            res = false;
        }
    }
    ASSERT_TRUE(res);
}