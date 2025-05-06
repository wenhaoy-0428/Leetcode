#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    tuple<int, int, int> helper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return tuple<int, int, int>(0, 0, 0);
        }

        auto [lSum, lResult, lNum] = helper(root->left);
        auto [rSum, rResult, rNum] = helper(root->right);
        int total = lSum + rSum + root->val;
        int result = lResult + rResult;
        int num = lNum + rNum + 1;
        if (total / num == root->val)
        {
            result++;
        }

        return tuple<int, int, int>(total, result, num);
    }

    int averageOfSubtree(TreeNode *root)
    {
        auto [dc1, result, dc2] = helper(root);
        return result;
    }
};

int main()
{
    Solution solution;
    // solution.averageOfSubtree()
}