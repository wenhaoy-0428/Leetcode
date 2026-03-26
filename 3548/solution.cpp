#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool hasElement(const unordered_map<int, set<int>>& freq, long long key, int l, int r) {
        if (key < numeric_limits<int>::min() || key > numeric_limits<int>::max()) {
            return false;
        }
        int k = static_cast<int>(key);
        if (freq.count(k) == 0) {
            return false;
        }
        for (int v : freq.at(k)) {
            if (v >= l && v <= r) {
                return true;
            }
        }
        return false;
    }

    bool canDiscountInRowSection(const vector<vector<int>>& grid,
                                 const unordered_map<int, set<int>>& freqRow,
                                 long long diff,
                                 int top,
                                 int bottom,
                                 int n) {
        if (top > bottom) {
            return false;
        }

        int h = bottom - top + 1;
        int w = n;

        if (h == 1 && w == 1) {
            return false;
        }
        if (h == 1) {
            return grid[top][0] == diff || grid[top][w - 1] == diff;
        }
        if (w == 1) {
            return grid[top][0] == diff || grid[bottom][0] == diff;
        }
        return hasElement(freqRow, diff, top, bottom);
    }

    bool canDiscountInColSection(const vector<vector<int>>& grid,
                                 const unordered_map<int, set<int>>& freqCol,
                                 long long diff,
                                 int left,
                                 int right,
                                 int m) {
        if (left > right) {
            return false;
        }

        int h = m;
        int w = right - left + 1;

        if (h == 1 && w == 1) {
            return false;
        }
        if (w == 1) {
            return grid[0][left] == diff || grid[h - 1][left] == diff;
        }
        if (h == 1) {
            return grid[0][left] == diff || grid[0][right] == diff;
        }
        return hasElement(freqCol, diff, left, right);
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rowSums(m, 0);
        vector<long long> colSums(n, 0);
        unordered_map<int, set<int>> freqRow;
        unordered_map<int, set<int>> freqCol;
        long long totalSum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
                freqRow[grid[i][j]].insert(i);
                freqCol[grid[i][j]].insert(j);
                totalSum += grid[i][j];
            }
        }

        long long prefixSum = 0;
        for (int i = 0; i < m - 1; i++) {
            prefixSum += rowSums[i];
            long long rest = totalSum - prefixSum;
            if (rest == prefixSum) {
                return true;
            }
            
            if (rest > prefixSum) {
                long long diff = rest - prefixSum;
                if (canDiscountInRowSection(grid, freqRow, diff, i + 1, m - 1, n)) {
                    return true;
                }
            } else {
                long long diff = prefixSum - rest;
                if (canDiscountInRowSection(grid, freqRow, diff, 0, i, n)) {
                    return true;
                }
            }            
        }
        prefixSum = 0;
        for (int j = 0; j < n - 1; j++) {
            prefixSum += colSums[j];
            long long rest = totalSum - prefixSum;
            if (rest == prefixSum) {
                return true;
            }

            if (rest > prefixSum) {
                long long diff = rest - prefixSum;
                if (canDiscountInColSection(grid, freqCol, diff, j + 1, n - 1, m)) {
                    return true;
                }
            } else {
                long long diff = prefixSum - rest;
                if (canDiscountInColSection(grid, freqCol, diff, 0, j, m)) {
                    return true;
                }
            }            
        }

        return false;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };
    bool result = solution.canPartitionGrid(grid);
    ASSERT_TRUE(result);
}
