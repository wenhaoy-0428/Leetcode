#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> freqA, freqB;
        for (auto const &c : s)
        {
            freqA[c]++;
        }

        for (auto const &c : t)
        {
            freqB[c]++;
        }

        int res = 0;
        for (auto const &pair : freqA)
        {
            if (freqB.count(pair.first) == 0)
            {
                res += pair.second;
            }
            else if (freqB[pair.first] < pair.second)
            {
                res += (pair.second - freqB[pair.first]);
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
    string word1 = "bab";
    string word2 = "aba";
    int result = solution.minSteps(word1, word2);
    ASSERT_EQ(1, result);
}

TEST_F(SolutionTest, test_002)
{
    string word1 = "leetcode";
    string word2 = "practice";
    int result = solution.minSteps(word1, word2);
    ASSERT_EQ(5, result);
}
