#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <stack>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;

        int i = 0;

        while (s[i] == ' ')
        {
            i++;
        }
        int j = i;

        while (i <= j && j < s.size())
        {
            char ci = s[i], cj = s[j];

            if (s[j] == ' ')
            {
                if (s[i] != ' ')
                {
                    string sub = s.substr(i, j - i);
                    st.push(sub);
                }
                i = j + 1;
            }
            j++;
        }
        if (i < s.size() && s[i] != ' ')
        {
            string sub = s.substr(i, j - i);
            st.push(sub);
        }

        string res = "";
        while (true)
        {
            res += st.top();
            st.pop();
            if (!st.empty())
            {
                res += ' ';
            }
            else
            {
                break;
            }
        }

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
    string s = "the sky is blue";
    string t = "blue is sky the";
    string r = solution.reverseWords(s);
    ASSERT_EQ(t, r);
}

TEST_F(SolutionTest, test_002)
{
    string s = "the sky is blue ";
    string t = "blue is sky the";
    string r = solution.reverseWords(s);
    ASSERT_EQ(t, r);
}

TEST_F(SolutionTest, test_003)
{
    string s = "the sky is blue  ";
    string t = "blue is sky the";
    string r = solution.reverseWords(s);
    ASSERT_EQ(t, r);
}

TEST_F(SolutionTest, test_004)
{
    string s = "the  sky is blue  ";
    string t = "blue is sky the";
    string r = solution.reverseWords(s);
    ASSERT_EQ(t, r);
}

TEST_F(SolutionTest, test_005)
{
    string s = " the  sky is blue  ";
    string t = "blue is sky the";
    string r = solution.reverseWords(s);
    ASSERT_EQ(t, r);
}