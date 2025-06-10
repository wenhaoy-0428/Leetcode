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
        int l = 1, r = x;
        while (l <= r)
        {
            long m = (long(l) + long(r)) / 2;
            if (m * m == x)
            {
                return m;
            }
            if (m * m < x)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return r;
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
