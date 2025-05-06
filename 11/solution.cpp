#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int M = 0;
        while (l <= r)
        {
            int minHeight = min(height[l], height[r]);
            M = max(minHeight * (r - l), M);
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return M;
    }
};

int main()
{
    Solution solution;
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << solution.maxArea(heights) << endl;
}