#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    int traverse(TreeNode *root, int start, int &maxDepth)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int depth = 0;

        int leftDepth = traverse(root->left, start, maxDepth);
        int rightDepth = traverse(root->right, start, maxDepth);

        if (root->val == start)
        {
            maxDepth = max(leftDepth, rightDepth);
            depth = -1;
        }
        else if (leftDepth >= 0 && rightDepth >= 0)
        {
            depth = max(leftDepth, rightDepth) + 1;
        }
        else
        {
            int diff = abs(leftDepth) + abs(rightDepth);
            maxDepth = max(maxDepth, diff);
            depth = min(leftDepth, rightDepth) - 1;
        }
        return depth;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        int maxDepth = 0;
        traverse(root, start, maxDepth);
        return maxDepth;
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
