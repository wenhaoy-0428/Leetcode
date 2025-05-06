#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int res = 0;
        size_t i = 0, j = 0;

        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                res++;
                j++;
            }
            i++;
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
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    ASSERT_EQ(1, solution.findContentChildren(g, s));
}
