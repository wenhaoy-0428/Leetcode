#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        string result = "";
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto const c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                result += '?';
                q.push(c);
            }
            else
            {
                result += c;
            }
        }
        for (int i = 0; i < result.length(); i++)
        {
            if (result[i] == '?')
            {
                result[i] = q.top();
                q.pop();
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
    string input = "lEetcOde";
    string output = solution.sortVowels(input);
    ASSERT_EQ("lEOtcede", output);
}

TEST_F(SolutionTest, test_002)
{
    string input = "lYmpH";
    string output = solution.sortVowels(input);
    ASSERT_EQ("lYmpH", output);
}
