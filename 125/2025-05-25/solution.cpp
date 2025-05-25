#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            while (!isalnum(s[l]) && l < r)
            {
                l++;
            }
            while (!isalnum(s[r]) && r > l)
            {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }

            l++;
            r--;
        }
        return true;
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
