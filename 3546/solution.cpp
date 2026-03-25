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
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> rowSums(grid.size(), 0);
        vector<long long> colSums(grid[0].size(), 0);
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        }
        
        long long prefixSum = 0;
        long long  allSum = 0;
        for (int i = 0; i < rowSums.size(); i++) {
            allSum += rowSums[i];
        }
        
        for (int i = 0; i < rowSums.size(); i++) {
            prefixSum += rowSums[i];
            allSum -= rowSums[i];
            if (prefixSum == allSum) {
                return true;
            }
        }

        prefixSum = 0;
        allSum = 0;
        for (int j = 0; j < colSums.size(); j++) {
            allSum += colSums[j];
        }
        for (int j = 0; j < colSums.size(); j++) {
            prefixSum += colSums[j];
            allSum -= colSums[j];
            if (prefixSum == allSum) {
                return true;
            }
        }
        return false;
    }
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
