#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    int findUnsortedSubarray(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        int left = 0, right = n - 1;

        // Find the first index where order breaks (from left)
        while (left < n - 1 && nums[left] <= nums[left + 1])
        {
            left++;
        }
        if (left == n - 1)
            return 0; // Already sorted

        // Find the last index where order breaks (from right)
        while (right > 0 && nums[right] >= nums[right - 1])
        {
            right--;
        }

        // Find min and max in nums[left..right]
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int i = left; i <= right; i++)
        {
            min_val = std::min(min_val, nums[i]);
            max_val = std::max(max_val, nums[i]);
        }

        // Expand left to include any number > min_val
        while (left > 0 && nums[left - 1] > min_val)
        {
            left--;
        }

        // Expand right to include any number < max_val
        while (right < n - 1 && nums[right + 1] < max_val)
        {
            right++;
        }

        return right - left + 1;
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
