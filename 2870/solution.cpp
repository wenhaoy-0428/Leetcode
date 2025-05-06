#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <map>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> table;

        for (auto const &n : nums)
        {
            table[n]++;
        }
        int res = 0;
        for (const auto &pair : table)
        {
            int n = pair.second;
            if (n == 1)
            {
                return -1;
            }

            int div = n / 3;
            int rem = n % 3;
            res += ceil(n / 3);
            if (n % 3 != 0)
            {
                res += 1;
            }
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
    vector<int> nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};

    int result = solution.minOperations(nums);
    ASSERT_EQ(4, result);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {2, 1, 2, 2, 3, 3};

    int result = solution.minOperations(nums);
    ASSERT_EQ(-1, result);
}
