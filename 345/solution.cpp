#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        stack<int> v;

        for (int i = 0; i < s.length(); i++)
        {
            if (vowels.find(s[i]) != vowels.end())
            {
                v.push(i);
            }
        }
        string result = "";

        for (int i = 0; i < s.length(); i++)
        {
            int nextIdx = v.top();
            if (vowels.find(s[i]) != vowels.end())
            {
                result += s[nextIdx];
                v.pop();
            }
            else
            {
                result += s[i];
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
    string exp = "holle";
    string input = "hello";
    string result = solution.reverseVowels(input);
    ASSERT_EQ(exp, result);
}
