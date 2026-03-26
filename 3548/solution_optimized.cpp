#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
private:
    struct ValueSpan {
        int minRow = numeric_limits<int>::max();
        int maxRow = numeric_limits<int>::min();
        int minCol = numeric_limits<int>::max();
        int maxCol = numeric_limits<int>::min();
    };

    static bool hasValueInRows(const unordered_map<int, ValueSpan>& spanByValue,
                               long long diff,
                               int top,
                               int bottom) {
        if (top > bottom || diff < numeric_limits<int>::min() || diff > numeric_limits<int>::max()) {
            return false;
        }
        auto it = spanByValue.find(static_cast<int>(diff));
        if (it == spanByValue.end()) {
            return false;
        }
        const ValueSpan& span = it->second;
        return span.maxRow >= top && span.minRow <= bottom;
    }

    static bool hasValueInCols(const unordered_map<int, ValueSpan>& spanByValue,
                               long long diff,
                               int left,
                               int right) {
        if (left > right || diff < numeric_limits<int>::min() || diff > numeric_limits<int>::max()) {
            return false;
        }
        auto it = spanByValue.find(static_cast<int>(diff));
        if (it == spanByValue.end()) {
            return false;
        }
        const ValueSpan& span = it->second;
        return span.maxCol >= left && span.minCol <= right;
    }

    static bool canRemoveInRowSection(const vector<vector<int>>& grid,
                                      const unordered_map<int, ValueSpan>& spanByValue,
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
        return hasValueInRows(spanByValue, diff, top, bottom);
    }

    static bool canRemoveInColSection(const vector<vector<int>>& grid,
                                      const unordered_map<int, ValueSpan>& spanByValue,
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
        return hasValueInCols(spanByValue, diff, left, right);
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());

        vector<long long> rowSums(m, 0);
        vector<long long> colSums(n, 0);
        unordered_map<int, ValueSpan> spanByValue;
        long long totalSum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                rowSums[i] += val;
                colSums[j] += val;
                totalSum += val;

                ValueSpan& span = spanByValue[val];
                if (i < span.minRow) {
                    span.minRow = i;
                }
                if (i > span.maxRow) {
                    span.maxRow = i;
                }
                if (j < span.minCol) {
                    span.minCol = j;
                }
                if (j > span.maxCol) {
                    span.maxCol = j;
                }
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
                if (canRemoveInRowSection(grid, spanByValue, diff, i + 1, m - 1, n)) {
                    return true;
                }
            } else {
                long long diff = prefixSum - rest;
                if (canRemoveInRowSection(grid, spanByValue, diff, 0, i, n)) {
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
                if (canRemoveInColSection(grid, spanByValue, diff, j + 1, n - 1, m)) {
                    return true;
                }
            } else {
                long long diff = prefixSum - rest;
                if (canRemoveInColSection(grid, spanByValue, diff, 0, j, m)) {
                    return true;
                }
            }
        }

        return false;
    }
};
