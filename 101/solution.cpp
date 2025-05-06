#include <iostream>
#include "../util/util.h"
using namespace std;

bool helper(TreeNode *Tree1, TreeNode *Tree2)
{
    if (Tree1 == nullptr && Tree2 == nullptr)
    {
        return true;
    }
    if (Tree1 == nullptr && Tree2 != nullptr)
    {
        return false;
    }
    if (Tree1 != nullptr && Tree2 == nullptr)
    {
        return false;
    }
    if (Tree1->val != Tree2->val)
    {
        return false;
    }

    return helper(Tree1->left, Tree2->right) && helper(Tree1->right, Tree2->left);
}

bool isSymmetric(TreeNode *root)
{
    return helper(root->left, root->right);
}

int main()
{
}
