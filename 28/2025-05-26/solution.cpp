#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        for (int i = 0; i < haystack.size(); i++)
        {
            int j = 0;
            for (; j < j + i < haystack.size() && j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == needle.size())
            {
                return i;
            }
        }
        return -1;
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
