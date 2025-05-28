#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        if (s.size() != t.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp1.find(s[i]) == mp1.end())
            {
                mp1[s[i]] = i;
            }
            if (mp2.find(t[i]) == mp2.end())
            {
                mp2[t[i]] = i;
            }
            if (mp1[s[i]] != mp2[t[i]])
            {
                return false;
            }
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
