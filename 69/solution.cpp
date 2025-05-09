#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = x;
        int m;
        while (l <= r)
        {
            m = (l + r) / 2;
            long long sq = (long long)(m) * (long long)(m);
            long long sq1 = (long long)(m + 1) * (long long)(m + 1);
            if (sq <= x && sq1 > x)
            {
                return m;
            }
            if (sq < x)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return m;
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
