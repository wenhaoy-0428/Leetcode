#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int highest = 0;
        int curr = 0;
        for (auto const g : gain)
        {
            curr += g;
            highest = max(highest, curr);
        }
        return highest;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> gain = {-5, 1, 5, 0, -7};
    int result = solution.largestAltitude(gain);
    ASSERT_EQ(1, result);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> gain = {-4, -3, -2, -1, 4, 3, 2};
    int result = solution.largestAltitude(gain);
    ASSERT_EQ(0, result);
}