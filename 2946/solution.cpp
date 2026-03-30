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
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        // right shift = (index + k) % l
        // left shift = (index - k + l) % l
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            if (even) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != mat[i][(j + k) % n]) {
                        return false;
                    }
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != mat[i][(j - k + n) % n]) {
                        return false;
                    }
                }
            }
            even = (even + 1) % 2;
            
        }
        return true;
    }
};

TEST_F(SolutionTest,      test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
