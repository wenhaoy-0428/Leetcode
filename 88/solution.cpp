#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int l = 0, r = 0, i = 0;
        vector<int> nums;
        nums.assign(nums1.begin(), nums1.begin() + m);
        while (l < m && r < n)
        {
            if (l < m && nums[l] <= nums2[r])
            {
                nums1[i] = nums[l];
                l++;
            }
            else
            {
                nums1[i] = nums2[r];
                r++;
            }
            i++;
        }

        while (l < m)
        {
            nums1[i] = nums[l];
            l++;
            i++;
        }
        while (r < n)
        {
            nums1[i] = nums2[r];
            r++;
            i++;
        }
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
