#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> steps(n, 0);
        if (n == 1 || n == 2)
        {
            return n;
        }
        steps[0] = 1;
        steps[1] = 2;
        for (int i = 2; i < n; i++)
        {
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n - 1];
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    int res = solution.climbStairs(2);
    ASSERT_EQ(2, res);
}

TEST_F(SolutionTest, test_002)
{
    int res = solution.climbStairs(3);
    ASSERT_EQ(3, res);
}