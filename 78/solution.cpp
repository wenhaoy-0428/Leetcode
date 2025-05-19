#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {{}};
        }
        int n = nums.size();
        int last = nums.back();
        nums.pop_back();
        vector<vector<int>> result = subsets(nums);
        int s = result.size();
        for (int i = 0; i < s; i++)
        {
            vector<int> temp = result[i];
            temp.push_back(last);
            result.push_back(temp);
        }
        return result;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> expected = {
        {},
        {3},
        {2},
        {2, 3},
        {1},
        {1, 3},
        {1, 2},
        {1, 2, 3}};
    vector<vector<int>> result = solution.subsets(nums);
}
