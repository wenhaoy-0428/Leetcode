#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        vector<int> res;
        int sum = 0;
        while (i < j)
        {
            sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }

            if (sum > target)
            {
                j--;
            }
            else
            {
                i++;
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
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = solution.twoSum(nums, target);

    ASSERT_EQ(1, res[0]);
    ASSERT_EQ(2, res[1]);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> nums = {2, 3, 4};
    int target = 6;
    vector<int> res = solution.twoSum(nums, target);

    ASSERT_EQ(1, res[0]);
    ASSERT_EQ(3, res[1]);
}

TEST_F(SolutionTest, test_003)
{
    vector<int> nums = {2, 3, 4, 5};
    int target = 7;
    vector<int> res = solution.twoSum(nums, target);

    ASSERT_EQ(1, res[0]);
    ASSERT_EQ(4, res[1]);
}

TEST_F(SolutionTest, test_004)
{
    vector<int> nums = {0, 2, 3, 4};
    int target = 5;
    vector<int> res = solution.twoSum(nums, target);

    ASSERT_EQ(2, res[0]);
    ASSERT_EQ(3, res[1]);
}
