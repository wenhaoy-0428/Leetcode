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
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result)
    {
        // Add the current subset to the result
        result.push_back(current);

        // Explore further by including each element from 'start' onwards
        for (int i = start; i < nums.size(); ++i)
        {
            // Include nums[i] in the current subset
            current.push_back(nums[i]);
            // Recurse with the next index
            backtrack(nums, i + 1, current, result);
            // Backtrack: exclude nums[i] from the current subset
            current.pop_back();
        }
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
