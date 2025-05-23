#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int res = 0;
        int i = s.size() - 1;
        while (s[i] == ' ')
        {
            i--;
        }
        for (; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                res++;
            }
            else
            {
                return res;
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
