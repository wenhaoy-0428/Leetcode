#include <iostream>
#include "../util/util.h"

using namespace std;

vector<TreeNode *> generateTrees(int n)
{
    vector<vector<TreeNode *>> dp(n + 1);

    dp[0] = vector<TreeNode *>{};

    for (int i = 1; i < n + 1; i++)
    {

        TreeNode *pt;
        for (int j = 0; j < dp[i - 1].size(); j++)
        {
            pt = dp[i - 1][j];

            TreeNode *newNode1 = new TreeNode(i);
            newNode1->left = pt;
            dp[i].push_back(newNode1);

            TreeNode *newNode2 = new TreeNode(i);
            newNode2->right = pt;
            dp[i].push_back(newNode2);
        }
    }

    return dp[n];
}

int main()
{
}
