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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }

        int n = q.size();
        TreeNode *curr;
        while (q.size() != 0)
        {
            curr = q.front();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            q.pop();
            n--;
            if (n == 0)
            {
                result.push_back(curr->val);
                n = q.size();
            }
        }
        return result;
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
