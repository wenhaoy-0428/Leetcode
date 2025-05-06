#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int dp[text1.length() + 1][text2.length() + 1];
        memset(dp, 0, sizeof dp);

        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    string text1 = "abcde";
    string text2 = "ace";
    int exp = 3;
    int num = solution.longestCommonSubsequence(text1, text2);
    ASSERT_EQ(exp, num);
}

TEST_F(SolutionTest, test_002)
{
    string text1 = "abc";
    string text2 = "abc";
    int exp = 3;
    int num = solution.longestCommonSubsequence(text1, text2);
    ASSERT_EQ(exp, num);
}
