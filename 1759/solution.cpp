#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    long long m = 1000000007;
    int countHomogenous(string s)
    {
        int l = 0, r = 0;
        long long result = 0;
        while (r < s.length())
        {
            while (r < s.length() && s[r] == s[l])
            {
                r++;
            }
            int length = r - l;
            l = r;
            result += ((1 + (long long)length) * (long long)length / 2);
            result %= m;
                }
        return int(result);
    }
};
class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    string input = "abbcccaa";
    int result = solution.countHomogenous(input);
    ASSERT_EQ(13, result);
}

TEST_F(SolutionTest, test_002)
{
    string input = "xy";
    int result = solution.countHomogenous(input);
    ASSERT_EQ(2, result);
}
