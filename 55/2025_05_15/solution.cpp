#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int far = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= far)
            {
                far = max(far, i + nums[i]);
            }
        }
        return far >= nums.size() - 1;
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
