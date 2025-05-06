#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {

        if (root == nullptr)
        {
            return 0;
        }
        int sum = 0;
        sum += rangeSumBST(root->left, low, high);
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }
        sum += rangeSumBST(root->right, low, high);
        return sum;
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
