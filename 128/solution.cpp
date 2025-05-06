#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    int traverse(int target, unordered_map<int, int> &mp)
    {
        if (mp[target] != -1)
        {
            return mp[target];
        }
        if (mp.count(target - 1))
        {
            mp[target] = traverse(target - 1, mp) + 1;
        }
        else
        {
            mp[target] = 1;
        }
        return mp[target];
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        int maxL = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = -1;
        }

        for (auto &pair : mp)
        {
            if (pair.second != -1)
            {
                continue;
            }
            int len = traverse(pair.first, mp);
            maxL = max(maxL, len);
        }
        return maxL;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int exp = 4;

    int res = solution.longestConsecutive(nums);
    ASSERT_EQ(exp, res);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int exp = 9;

    int res = solution.longestConsecutive(nums);
    ASSERT_EQ(exp, res);
}
