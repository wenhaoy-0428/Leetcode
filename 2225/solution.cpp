#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, int> lost;
        for (auto const &match : matches)
        {
            int winner = match[0];
            int loser = match[1];
            lost[loser]++;
            if (lost.count(winner) == 0)
            {
                lost[winner] = 0;
            }
        }
        vector<vector<int>> res;
        vector<int> zero;
        vector<int> one;
        for (auto const &pair : lost)
        {
            if (pair.second == 0)
            {
                zero.push_back(pair.first);
            }
            else if (pair.second == 1)
            {
                one.push_back(pair.first);
            }
        }
        res.push_back(zero);
        res.push_back(one);
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
