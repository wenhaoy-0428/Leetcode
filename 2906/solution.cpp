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
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m, 1));

        long long prefix = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[i][j] = static_cast<int>(prefix);
                prefix = (prefix * (grid[i][j] % MOD)) % MOD;
            }
        }

        long long suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                result[i][j] = static_cast<int>((result[i][j] * suffix) % MOD);
                suffix = (suffix * (grid[i][j] % MOD)) % MOD;
            }
        }
        return result;
    }
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
