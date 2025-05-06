#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int num1 = 0, num2 = 0, i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (vowels.count(s[i]))
            {
                num1++;
            }
            if (vowels.count(s[j]))
            {
                num2++;
            }
            i++;
            j--;
        }
        return num1 == num2;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{

    string s = "book";
    bool res = solution.halvesAreAlike(s);
    ASSERT_TRUE(res);
}

TEST_F(SolutionTest, test_002)
{

    string s = "textbook";
    bool res = solution.halvesAreAlike(s);
    ASSERT_FALSE(res);
}
