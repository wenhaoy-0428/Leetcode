#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, res, curr, nums);
        return res;
    }

private:
    void backtrack(int start, vector<vector<int>> &res, vector<int> &curr, vector<int> &nums)
    {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++)
        {
            if (i - 1 >= start && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            backtrack(i + 1, res, curr, nums);
            curr.pop_back();
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
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
