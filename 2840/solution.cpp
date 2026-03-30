#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};


class Solution {
    bool isIdentical(vector<char>& v1, vector<char> &v2) {
        

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkStrings(string s1, string s2) {
        int s1_size = s1.size();
        int s2_size = s2.size();
        if (s1_size != s2_size) {
            return false;
        }

        vector<char> s1_e;
        vector<char> s1_o;
        vector<char> s2_e;
        vector<char> s2_o;


        for (int i = 0; i < s1_size; i++) {
            if (i % 2 == 0) {
                s1_e.push_back(s1[i]);
                s2_e.push_back(s2[i]);
            } else {
                s1_o.push_back(s1[i]);
                s2_o.push_back(s2[i]);
            }
        }

        return isIdentical(s1_e, s2_e) && isIdentical(s1_o, s2_o);
    }
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
