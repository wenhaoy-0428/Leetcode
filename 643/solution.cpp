#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 0;

        double average = 0;

        for (; j < nums.size() && j < k; j++)
        {
            average += nums[j];
        }

        average /= k;
        double ans = average;

        for (; j < nums.size(); j++, i++)
        {
            double diff = (double(nums[j]) - double(nums[i])) / k;
            average += diff;

            ans = max(ans, average);
        }
        return ans;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> v = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double exp = 12.75000;
    ASSERT_EQ(exp, solution.findMaxAverage(v, k));
}
