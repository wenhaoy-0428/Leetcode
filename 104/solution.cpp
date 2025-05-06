#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    Solution solution;

    // solution.maxDepth()
}