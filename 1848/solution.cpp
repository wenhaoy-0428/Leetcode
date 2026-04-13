#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};


class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int s = nums.size();
        int i = 0;
        while(i + start < s || start - i >= 0) {
            if (i + start < s && nums[start + i] == target) {
                return i;
            }
            if (start - i >= 0 && nums[start - i] == target) {
                return i;
            }
            i++;
        }
        return i;
    }
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
