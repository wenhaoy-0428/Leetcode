#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    int helper(TreeNode *root, int maxN, int minN)
    {

        if (root->left == nullptr && root->right == nullptr)
        {
            return max(abs(maxN - root->val), abs(minN - root->val));
        }
        maxN = max(maxN, root->val);
        minN = min(minN, root->val);
        int l, r;
        if (root->left)
        {
            l = helper(root->left, maxN, minN);
        }
        if (root->right)
        {
            r = helper(root->right, maxN, minN);
        }

        return max(l, r);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        return helper(root, root->val, root->val);
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
