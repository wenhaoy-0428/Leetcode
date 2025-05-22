#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int temp = prices[i] - prices[i - 1];
            if (temp > 0)
            {
                res += temp;
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
