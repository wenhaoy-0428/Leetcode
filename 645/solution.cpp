#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        size_t n = nums.size();
        vector<int> res;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]] += 1;
        }
        int rep = 0, mis = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (freq[i] > 1)
            {
                rep = i;
            }
            if (freq[i] == 0)
            {
                mis = i;
            }
        }
        res = {rep, mis};

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
    vector<int> nums = {1, 2, 2, 4};
    vector<int> exp = {2, 3};
    vector<int> res = solution.findErrorNums(nums);

    ASSERT_TRUE(compareVectors(exp, res));
}
