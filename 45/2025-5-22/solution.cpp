#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution1
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), nums.size());
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j <= nums[i] + i && j < nums.size(); j++)
            {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};

class Solution2
{
public:
    int jump(vector<int> &nums)
    {

        int farthest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
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
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
