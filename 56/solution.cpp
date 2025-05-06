#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        struct
        {
            bool operator()(vector<int> a, vector<int> b) { return a[0] < b[0]; }
        } lessThan;

        sort(intervals.begin(), intervals.end(), lessThan);

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            int si = intervals[i][0];
            int ei = intervals[i][1];
            if (si <= end)
            {
                end = max(ei, end);
            }
            else
            {
                vector<int> newV = {start, end};
                res.push_back(newV);
                start = si;
                end = ei;
            }
        }

        vector<int> newV = {start, end};
        res.push_back(newV);

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
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> exp = {{1, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = solution.merge(intervals);
    ASSERT_EQ(exp.size(), res.size());

    for (size_t i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(compareVectors(exp[i], res[i]));
    }
}

TEST_F(SolutionTest, test_002)
{
    vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    vector<vector<int>> exp = {{1, 4}};
    vector<vector<int>> res = solution.merge(intervals);
    ASSERT_EQ(exp.size(), res.size());

    for (size_t i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(compareVectors(exp[i], res[i]));
    }
}

TEST_F(SolutionTest, test_003)
{
    vector<vector<int>> intervals = {{1, 4}, {1, 4}};
    vector<vector<int>> exp = {{1, 4}};
    vector<vector<int>> res = solution.merge(intervals);
    ASSERT_EQ(exp.size(), res.size());

    for (size_t i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(compareVectors(exp[i], res[i]));
    }
}
