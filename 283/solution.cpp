#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int p0 = 0, p1 = 0;
        while (p0 < nums.size() && p1 < nums.size())
        {
            while (p1 < p0 || (p1 < nums.size() - 1 && nums[p1] == 0))
            {
                p1++;
            }
            if (nums[p0] == 0 && p0 < p1)
            {
                swap(nums[p0], nums[p1]);
            }
            p0++;
        }
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     vector<int> input = {0, 1, 0, 3, 12};
//     vector<int> exp = {1, 3, 12, 0, 0};
//     solution.moveZeroes(input);
//     ASSERT_EQ(exp, input);
// }

// TEST_F(SolutionTest, test_002)
// {
//     vector<int> input = {0, 1};
//     vector<int> exp = {1, 0};
//     solution.moveZeroes(input);
//     ASSERT_EQ(exp, input);
// }

// TEST_F(SolutionTest, test_003)
// {
//     vector<int> input = {1, 0};
//     vector<int> exp = {1, 0};
//     solution.moveZeroes(input);
//     ASSERT_EQ(exp, input);
// }

TEST_F(SolutionTest, test_004)
{
    vector<int> input = {1, 0, 1};
    vector<int> exp = {1, 1, 0};
    solution.moveZeroes(input);
    ASSERT_EQ(exp, input);
}