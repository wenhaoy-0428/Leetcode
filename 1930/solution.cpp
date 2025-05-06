#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <unordered_set>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);

        for (int i = 0; i < s.size(); i++)
        {
            int curr = s[i] - 'a';
            if (first[curr] == -1)
            {
                first[curr] = i;
            }

            last[curr] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            int start = first[i];
            int end = last[i];
            unordered_set<char> us;
            for (int j = start + 1; j < end; j++)
            {
                us.insert(s[j]);
            }
            ans += us.size();
        }
        return ans;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    string input = "aabca";
    int result = solution.countPalindromicSubsequence(input);
    ASSERT_EQ(3, result);
}
