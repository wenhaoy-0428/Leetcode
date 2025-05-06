#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> costSum = cost;
        size_t i = 2;
        for (; i < costSum.size(); i++)
        {
            costSum[i] += min(costSum[i - 1], costSum[i - 2]);
        }
        return min(costSum[i - 1], costSum[i - 2]);
    }
};

int main()
{
    Solution solution;
    solution.
}