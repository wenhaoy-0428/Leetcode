#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> st;
        int l, r, res;
        for (const auto &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                r = st.back();
                st.pop_back();
                l = st.back();
                st.pop_back();

                if (token == "+")
                {
                    res = l + r;
                }
                else if (token == "-")
                {
                    res = l - r;
                }
                else if (token == "*")
                {
                    res = l * r;
                }
                else if (token == "/")
                {
                    res = l / r;
                }
                st.push_back(res);
            }
            else
            {
                st.push_back(stoi(token));
            }
        }
        return st.back();
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
