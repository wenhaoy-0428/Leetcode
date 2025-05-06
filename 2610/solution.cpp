#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (auto const &num : nums)
        {
            freq[num]++;
        }
        int total = 0;
        vector<vector<int>> res;
        while (total != nums.size())
        {
            vector<int> v;
            for (auto &pair : freq)
            {
                if (pair.second != 0)
                {
                    v.push_back(pair.first);
                    total++;
                    pair.second--;
                }
            }
            res.push_back(v);
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
