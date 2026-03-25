#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());

        long long total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                total += grid[i][j];
            }
        }

        // If total is odd, two equal parts are impossible.
        if (total % 2LL != 0) {
            return false;
        }

        long long target = total / 2LL;

        // Try horizontal cuts: cut between row i and i+1, so i in [0, m-2].
        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                topSum += grid[i][j];
            }
            if (topSum == target) {
                return true;
            }
        }

        // Try vertical cuts: cut between col j and j+1, so j in [0, n-2].
        long long leftSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                leftSum += grid[i][j];
            }
            if (leftSum == target) {
                return true;
            }
        }

        return false;
    }
};
