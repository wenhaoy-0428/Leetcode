#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    int MOD = 1e9 + 7;

public:
    int helper(int maxMove, int i, int j, int &m, int &n, unordered_map<string, int> &cache)
    {
        if (i < 0 || i == m || j < 0 || j == n)
        {
            return 1;
        }
        if (maxMove == 0)
        {
            return 0;
        }
        string key = to_string(i) + '-' + to_string(j) + '-' + to_string(maxMove);
        if (cache.count(key))
        {
            return cache[key];
        }

        cache[key] = ((helper(maxMove - 1, i - 1, j, m, n, cache) +
                       helper(maxMove - 1, i, j - 1, m, n, cache)) %
                          MOD +
                      (helper(maxMove - 1, i, j + 1, m, n, cache) +
                       helper(maxMove - 1, i + 1, j, m, n, cache)) %
                          MOD) %
                     MOD;
        return cache[key];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        unordered_map<string, int> cache;
        return helper(maxMove, startRow, startColumn, m, n, cache);
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    int exp = 12;
    ASSERT_EQ(exp, solution.findPaths(1, 3, 3, 0, 1));
}
