#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
    int quickSelect(int l, int r, vector<int> &nums, int &k)
    {
        int pivot = r;
        int pointer = l;
        for (int i = l; i < r; i++)
        {
            if (nums[i] < nums[pivot])
            {
                swap(nums[pointer], nums[i]);
                pointer++;
            }
        }
        swap(nums[pointer], nums[pivot]);

        if (nums.size() - pointer < k)
        {
            return quickSelect(l, pointer - 1, nums, k);
        }
        else if (nums.size() - pointer > k)
        {
            return quickSelect(pointer + 1, r, nums, k);
        }
        else
        {
            return nums[pointer];
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0, r = nums.size() - 1;
        return quickSelect(l, r, nums, k);
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = solution.findKthLargest(nums, k);
    ASSERT_EQ(5, result);
}
