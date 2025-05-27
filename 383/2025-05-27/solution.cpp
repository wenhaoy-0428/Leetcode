#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp;
        for (const auto &c : magazine)
        {
            mp[c]++;
        }

        for (const auto &c : ransomNote)
        {
            if (mp.find(c) == mp.end())
            {
                return false;
            }
            mp[c]--;
            if (mp[c] <= 0)
            {
                mp.erase(c);
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
