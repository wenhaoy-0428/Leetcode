#include <iostream>
#include <unordered_map>
using namespace std;

int helper(vector<int> &nums, int x, int l, int r, unordered_map<string, int> &dp)
{
    string key = to_string(l) + "-" + to_string(r);

    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }
    if (x == 0)
    {
        return 0;
    }

    if (l > r || x < 0)
    {
        return -1;
    }

    int rl = helper(nums, x - nums[l], l + 1, r, dp);
    int rr = helper(nums, x - nums[r], l, r - 1, dp);
    // cout << "l: " << l << " r: " << r << " rl: " << rl << " rr: " << rr << endl;

    if (rl == -1 && rr == -1)
    {
        return dp[key] = -1;
    }

    if (rl == -1 || rr == -1)
    {
        return dp[key] = max(rl, rr) + 1;
    }

    return dp[key] = min(rl, rr) + 1;
}

int minOperations(vector<int> &nums, int x)
{
    unordered_map<string, int> dp;
    return helper(nums, x, 0, nums.size() - 1, dp);
}

int main()
{
    vector<int> nums = {3, 2, 20, 1, 1, 3};
    int target = 10;

    cout << minOperations(nums, target) << endl;
}
