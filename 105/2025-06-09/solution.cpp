#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../util/util.h"

#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp, int l, int r, int &t)
    {
        if (l > r || t >= preorder.size())
        {
            return NULL;
        }

        int idx = mp[preorder[t]];
        TreeNode *curr = new TreeNode(preorder[t]);
        t++;
        curr->left = helper(preorder, inorder, mp, l, idx - 1, t);
        curr->right = helper(preorder, inorder, mp, idx + 1, r, t);
        return curr;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int t = 0;
        return helper(preorder, inorder, mp, 0, inorder.size() - 1, t);
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *result = solution.buildTree(preorder, inorder);
    ASSERT_NE(result, nullptr);
    ASSERT_EQ(result->val, 3);
    ASSERT_EQ(result->left->val, 9);
    ASSERT_EQ(result->right->val, 20);
    ASSERT_EQ(result->right->left->val, 15);
    ASSERT_EQ(result->right->right->val, 7);
}
