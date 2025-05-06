#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    void helper(TreeNode *root, vector<int> leaf)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            leaf.push_back(root->val);
            return;
        }
        if (root->left)
        {
            helper(root->left, leaf);
        }
        if (root->right)
        {
            helper(root->right, leaf);
        }
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> l1, l2;
        helper(root1, l1);
        helper(root2, l2);
        if (l1.size() != l2.size())
        {
            return false;
        }

        for (int i = 0; i < l1.size(); i++)
        {
            if (l1[i] != l2[i])
            {
                return false;
            }
        }
        return true;
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
