#include <iostream>
#include <vector>
#include <format>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() == 0)
        {
            return res;
        }
        int start = nums[0];
        int end = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != end + 1)
            {
                if (start == end)
                {
                    res.push_back(to_string(start));
                }
                else
                {
                    res.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
            }
            end = nums[i];
        }
        if (start == end)
        {
            res.push_back(to_string(start));
        }
        else
        {
            res.push_back(to_string(start) + "->" + to_string(end));
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
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> exp = {"0->2", "4->5", "7"};
    vector<string> res = solution.summaryRanges(nums);
    ASSERT_TRUE(compareVectors<string>(exp, res));
}
