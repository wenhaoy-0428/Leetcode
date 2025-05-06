#include <iostream>
#include <algorithm>
#include "../util/util.h"
#include <unordered_map>
using namespace std;

vector<int> helper(vector<int> &nums, int idx, unordered_map<int, vector<int>> &dp)
{
    int target = nums[idx];
    if (dp.find(idx) != dp.end())
    {
        return dp[idx];
    }
    vector<int> result;
    for (int i = 1; idx + i < nums.size(); i++)
    {
        if (nums[idx + i] % target == 0)
        {
            vector<int> temp = helper(nums, i + idx, dp);
            if (temp.size() > result.size())
            {
                result = temp;
            }
        }
    }
    result.push_back(target);

    return dp[idx] = result;
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, vector<int>> dp;

    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp = helper(nums, i, dp);
        if (temp.size() > result.size())
        {
            result = temp;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, 7, 8, 9, 10};
    vector<int> result = largestDivisibleSubset(nums);
    printVector(result);
}
