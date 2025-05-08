#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

// https://www.youtube.com/watch?v=agB1LyObUNE
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int zeros = 0, ones = 0;
        unordered_map<int, int> diff_idx;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
            int diff = ones - zeros;
            if (diff_idx.count(diff) == 0)
            {
                diff_idx[diff] = i;
            }

            if (diff == 0)
            {
                res = zeros + ones;
            }
            else
            {
                res = max(res, i - diff_idx[diff]);
            }
        }
        return res;
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
