#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> res;
        if (intervals.size() == 0)
        {
            res.push_back(newInterval);
            return res;
        }

        for (size_t i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (newStart > end)
            {
                res.push_back({start, end});
                continue;
            }
            if (newEnd < start)
            {
                res.push_back({newStart, newEnd});
                res.push_back({start, end});
                newStart = intervals[intervals.size() - 1][1] + 1;
                continue;
            }

            newStart = min(start, newStart);
            newEnd = max(end, newEnd);
        }
        if (newEnd >= intervals[intervals.size() - 1][1])
        {
            res.push_back({newStart, newEnd});
        }

        return res;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     vector<vector<int>> intervals = {{1, 3}, {6, 9}};
//     vector<int> newIntervals = {2, 5};

//     vector<vector<int>> exp = {{1, 5}, {6, 9}};
//     vector<vector<int>> res = solution.insert(intervals, newIntervals);

//     ASSERT_EQ(exp.size(), res.size());
//     for (size_t i = 0; i < exp.size(); i++)
//     {
//         ASSERT_TRUE(compareVectors(exp[i], res[i]));
//     }
// }

// TEST_F(SolutionTest, test_002)
// {
//     vector<vector<int>> intervals = {{1, 3}, {6, 9}};
//     vector<int> newIntervals = {2, 10};

//     vector<vector<int>> exp = {{1, 10}};
//     vector<vector<int>> res = solution.insert(intervals, newIntervals);

//     ASSERT_EQ(exp.size(), res.size());
//     for (size_t i = 0; i < exp.size(); i++)
//     {
//         ASSERT_TRUE(compareVectors(exp[i], res[i]));
//     }
// }

// TEST_F(SolutionTest, test_003)
// {
//     vector<vector<int>> intervals = {{6, 9}};
//     vector<int> newIntervals = {1, 3};

//     vector<vector<int>> exp = {{1, 3}, {6, 9}};
//     vector<vector<int>> res = solution.insert(intervals, newIntervals);

//     ASSERT_EQ(exp.size(), res.size());
//     for (size_t i = 0; i < exp.size(); i++)
//     {
//         ASSERT_TRUE(compareVectors(exp[i], res[i]));
//     }
// }

TEST_F(SolutionTest, test_004)
{
    vector<vector<int>> intervals = {{1, 2}, {6, 9}};
    vector<int> newIntervals = {3, 5};

    vector<vector<int>> exp = {{1, 2}, {3, 5}, {6, 9}};
    vector<vector<int>> res = solution.insert(intervals, newIntervals);

    ASSERT_EQ(exp.size(), res.size());
    for (size_t i = 0; i < exp.size(); i++)
    {
        ASSERT_TRUE(compareVectors(exp[i], res[i]));
    }
}

TEST_F(SolutionTest, test_005)
{
    vector<vector<int>> intervals = {{1, 2}, {6, 9}};
    vector<int> newIntervals = {3, 6};

    vector<vector<int>> exp = {{1, 2}, {3, 9}};
    vector<vector<int>> res = solution.insert(intervals, newIntervals);

    ASSERT_EQ(exp.size(), res.size());
    for (size_t i = 0; i < exp.size(); i++)
    {
        ASSERT_TRUE(compareVectors(exp[i], res[i]));
    }
}

TEST_F(SolutionTest, test_006)
{
    vector<vector<int>> intervals = {{6, 9}, {10, 12}};
    vector<int> newIntervals = {1, 2};

    vector<vector<int>> exp = {{1, 2}, {6, 9}, {10, 12}};
    vector<vector<int>> res = solution.insert(intervals, newIntervals);

    ASSERT_EQ(exp.size(), res.size());
    for (size_t i = 0; i < exp.size(); i++)
    {
        ASSERT_TRUE(compareVectors(exp[i], res[i]));
    }
}