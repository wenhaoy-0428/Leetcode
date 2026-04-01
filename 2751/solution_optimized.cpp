class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = static_cast<int>(positions.size());
        vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = i;
        }

        sort(order.begin(), order.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> rightMoving;

        for (int idx : order) {
            if (directions[idx] == 'R') {
                rightMoving.push_back(idx);
                continue;
            }

            while (!rightMoving.empty() && healths[idx] > 0) {
                int rightIdx = rightMoving.back();
                if (healths[rightIdx] < healths[idx]) {
                    healths[idx] -= 1;
                    healths[rightIdx] = 0;
                    rightMoving.pop_back();
                } else if (healths[rightIdx] == healths[idx]) {
                    healths[rightIdx] = 0;
                    healths[idx] = 0;
                    rightMoving.pop_back();
                } else {
                    healths[rightIdx] -= 1;
                    healths[idx] = 0;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};