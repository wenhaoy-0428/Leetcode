#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
        {
            return s;
        }
        vector<vector<char>> matrix(numRows, vector<char>());

        int idx = 0, n = s.size(), i = 0, j = 0;
        while (idx < n)
        {
            for (int x = 0; x < numRows && idx < n; x++, idx++)
            {
                matrix[i].push_back(s[idx]);
                i++;
            }
            i -= 2;
            for (int x = 1; x < numRows - 1 && idx < n; x++, idx++)
            {
                matrix[i].push_back(s[idx]);
                i--;
            }
        }
        string result;
        for (const auto &row : matrix)
        {
            for (char c : row)
            {
                result += c;
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
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
