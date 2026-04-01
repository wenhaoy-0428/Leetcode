#include <iostream>
#include <vector>
#include <string>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, 'a');
        vector<int> fixed(n + m - 1, 0);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i; j < i + m; j++) {
                    if (fixed[j] == 1 && str2[j - i] != s[j]) {
                        return "";
                    }
                    s[j] = str2[j - i];
                    fixed[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool ok = false;
                int idx = -1;
                for (int j = i + m - 1; j >= i; j--) {
                    if (s[j] != str2[j - i]) {
                        ok = true;
                    }
                    if (idx == -1 && fixed[j] == 0) {
                        idx = j;
                    }
                }
                if (ok) {
                    continue;
                } else if (idx != -1) {
                    s[idx] = 'b';
                } else {
                    return "";
                }
            }
        }

        return s;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    Solution s;
    string result = s.generateString("TTF", "ab");
    string expected = "";
    ASSERT_EQ(result, expected);
}

TEST_F(SolutionTest, test_002)
{
    Solution s;
    string result = s.generateString("T", "abc");
    string expected = "abc";
    ASSERT_EQ(result, expected);
}

TEST_F(SolutionTest, test_003)
{
    Solution s;
    string result = s.generateString("F", "abc");
    ASSERT_EQ(result.length(), 3);
}

TEST_F(SolutionTest, test_004)
{
    Solution s;
    string result = s.generateString("TFTF", "ab");
    string expected = "ababa";
    ASSERT_EQ(result, expected);
}