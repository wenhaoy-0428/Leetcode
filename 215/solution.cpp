#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (pq.size() < k)
            {
                pq.push(nums[i]);
                continue;
            }
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
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
