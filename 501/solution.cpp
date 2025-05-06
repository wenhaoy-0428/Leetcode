#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "../util/util.h"

using namespace std;

bool compareByValue(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

class Solution
{
public:
    void search(TreeNode *root, unordered_map<int, int> &hash)
    {
        if (root == nullptr)
        {
            return;
        }
        hash[root->val] += 1;
        search(root->left, hash);
        search(root->right, hash);
    }

    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> freq;
        search(root, freq);
        vector<int> result;

        vector<pair<int, int>> A;
        for (auto &it : freq)
        {
            cout << it.first << "-" << it.second << endl;
            A.push_back(it);
        }
        sort(A.begin(), A.end(), compareByValue);

        auto it = A.begin();
        int mostFreq = it->second;
        result.push_back(it->first);
        it++;

        while (it != A.end() && it->second == mostFreq)
        {

            result.push_back(it->first);
            it++;
        }
        return result;
    }
};
int main()
{
    Solution solution;
    // solution.findMode();
}