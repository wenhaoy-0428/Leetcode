#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1, i = 0;
        while (i <= r)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[l]);
                i++;
                l++;
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[r]);
                r--;
            }
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
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    vector<int> expected = {0, 0, 1, 1, 2, 2};
    solution.sortColors(nums);
    ASSERT_EQ(nums.size(), expected.size());
    for (int i = 0; i < nums.size(); i++)
    {
        ASSERT_EQ(nums[i], expected[i]);
    }
}
