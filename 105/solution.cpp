#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    TreeNode *build(vector<int> &preorder, unordered_map<int, int> &mp, int i, int l, int r)
    {
        int val = preorder[i];
        TreeNode *tree = new TreeNode(val);

        int lIdx = i + 1, rIdx = i + mp[val] - l;
        if (lIdx < preorder.size())
        {
            int pLv = preorder[lIdx];
            if (mp[pLv] < mp[val])
            {
                tree->left = build(preorder, mp, lIdx, l, rIdx);
            }
        }
        if (rIdx < r)
        {
            int pRv = preorder[rIdx];
            if (mp[pRv] > mp[val])
            {
                tree->right = build(preorder, mp, rIdx, mp[val], r);
            }
        }
        return tree;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return build(preorder, mp, 0, -1, preorder.size());
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     vector<int> preorder = {1, 2, 3};

//     vector<int> inorder = {3, 2, 1};
//     solution.buildTree(preorder, inorder);
// }

TEST_F(SolutionTest, test_002)
{
    vector<int> preorder = {3, 9, 20, 15, 7};

    vector<int> inorder = {9, 3, 15, 20, 7};
    solution.buildTree(preorder, inorder);
}
