#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        path += '/';
        vector<string> st;
        int l = 0, r = 1;
        while (r < path.size())
        {
            string token;
            if (path[r] == '/')
            {
                token = path.substr(l + 1, r - l - 1);
                l = r;
                if (token == "..")
                {
                    if (!st.empty())
                    {
                        st.pop_back();
                    }
                }
                else if (token != "" && token != ".")
                {
                    st.push_back(token);
                }
            }
            r++;
        }
        string res;
        for (auto const &token : st)
        {
            res = res + "/" + token;
        }
        return res == "" ? "/" : res;
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
