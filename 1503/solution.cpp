#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        auto leftMax = max_element(left.begin(), left.end());
        auto rightMin = min_element(right.begin(), right.end());
        if (leftMax == left.end())
        {
            return n - *rightMin;
        }
        if (rightMin == right.end())
        {
            return *leftMax;
        }

        return max(*leftMax, n - *rightMin);
    }
};

int main()
{
    Solution solution;
    int n = 0;
    vector<int> left = {4, 3};
    vector<int> right = {0, 1};
    cout << solution.getLastMoment(n, left, right) << endl;
}