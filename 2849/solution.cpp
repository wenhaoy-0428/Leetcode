#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int vDiff = abs(fy - sy);
        int hDiff = abs(fx - sx);
        int total = vDiff + hDiff - min(vDiff, hDiff);
        if (total == 0)
        {
            return t != 1;
        }
        return total <= t;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    bool result = solution.isReachableAtTime(2, 4, 7, 7, 6);
    ASSERT_TRUE(result);
}

TEST_F(SolutionTest, test_002)
{
    bool result = solution.isReachableAtTime(3, 1, 7, 3, 3);
    ASSERT_FALSE(result);
}

TEST_F(SolutionTest, test_003)
{
    bool result = solution.isReachableAtTime(1, 2, 1, 2, 1);
    ASSERT_FALSE(result);
}
