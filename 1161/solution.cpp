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
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int levelLength = q.size();
        int result = 1;
        int levelIdx = 1;
        int maxSum = -std::numeric_limits<int>::infinity();
        int levelSum = 0;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            levelSum += curr->val;
            levelLength--;
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            if (levelLength == 0)
            {
                levelLength = q.size();
                if (levelSum > maxSum)
                {
                    maxSum = levelSum;
                    result = levelIdx;
                }
                levelSum = 0;
                levelIdx++;
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
