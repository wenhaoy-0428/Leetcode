#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int di = 0;
        int dl = 0;
        int ref = nums[0], j = 0, l = 0;
        while (j < nums.size())
        {
            if (ref == nums[j])
            {
                if (l == 2)
                {
                    dl++;
                    j++;
                    continue;
                }
                swap(nums[j], nums[di]);
                j++;
                di++;
                l++;
            }
            else
            {
                ref = nums[j];
                l = 0;
            }
        }
        return nums.size() - dl;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3};
    vector<int> exp = {1, 1, 2, 2, 3, 3};
    ASSERT_EQ(6, solution.removeDuplicates(nums));
    bool com = true;
    for (int i = 0; i < 6; i++)
    {
        if (nums[i] != exp[i])
        {
            com = false;
            break;
        }
    }
    ASSERT_TRUE(com);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> exp = {1, 1, 2, 2, 3};
    int n = 5;
    ASSERT_EQ(n, solution.removeDuplicates(nums));
    bool com = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != exp[i])
        {
            com = false;
            break;
        }
    }
    ASSERT_TRUE(com);
}

TEST_F(SolutionTest, test_003)
{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> exp = {0, 0, 1, 1, 2, 3, 3};
    int n = 7;
    ASSERT_EQ(n, solution.removeDuplicates(nums));
    bool com = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != exp[i])
        {
            com = false;
            break;
        }
    }
    ASSERT_TRUE(com);
}
