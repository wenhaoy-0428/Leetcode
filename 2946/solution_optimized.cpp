#include <vector>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int m = static_cast<int>(mat.size());
        const int n = static_cast<int>(mat[0].size());
        const int shift = k % n;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int shiftedIndex;
                if (i % 2 == 0) {
                    // Even rows are shifted left.
                    shiftedIndex = (j + shift) % n;
                } else {
                    // Odd rows are shifted right.
                    shiftedIndex = (j - shift + n) % n;
                }

                if (mat[i][j] != mat[i][shiftedIndex]) {
                    return false;
                }
            }
        }

        return true;
    }
};
