#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    void backtrack(vector<string> &res, string &curr, int open_p, int close_p, int n)
    {
        if (open_p == close_p && open_p == n)
        {
            res.push_back(curr);
        }
        if (open_p < n)
        {
            curr.push_back('(');
            backtrack(res, curr, open_p + 1, close_p, n);
            curr.pop_back();
        }
        if (open_p > close_p)
        {
            curr.push_back(')');
            backtrack(res, curr, open_p, close_p + 1, n);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string curr = "";
        backtrack(res, curr, 0, 0, n);
        return res;
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
