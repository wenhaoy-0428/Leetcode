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
        int l = 0, r = 0, n = nums.size(), res = nums.size() + 1, curr = 0;
        while (r < n)
        {
            curr += nums[r];
            r++;
            while (curr >= target)
            {
                res = min(res, r - l);
                curr -= nums[l];
                l++;
            }
        }
        return res == n + 1 ? 0 : res;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
