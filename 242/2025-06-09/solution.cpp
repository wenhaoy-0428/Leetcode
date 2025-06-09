#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;
        if (s.size() != t.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second != 0)
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
