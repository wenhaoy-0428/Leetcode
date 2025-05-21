#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    string helper(int i, string &s)
    {
        int l = i - 1, r = i + 1, res1 = 1, res2 = 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
            res1 += 2;
        }
        if (i + 1 < s.size() && s[i + 1] == s[i])
        {
            l = i - 1;
            r = i + 2;
            res2 = 2;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
                res2 += 2;
            }
        }
        if (res1 >= res2)
        {
            return s.substr(i - (res1 / 2), res1);
        }
        else
        {
            return s.substr(i - (res2 / 2) + 1, res2);
        }
    }

public:
    string longestPalindrome(string s)
    {
        string mx = "";
        ` for (int i = 0; i < s.size(); i++)
        {
            string temp = helper(i, s);
            if (temp.size() > mx.size())
            {
                mx = temp;
            }
        }
        return mx;
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
