#include <iostream>
#include <cmath>

using namespace std;

int helper(size_t idx, vector<int> &nums, vector<int> &dp)
{
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    if (idx >= nums.size())
    {
        return 0;
    }

    int target = nums[idx];

    // rob target
    int robProfit = helper(idx + 2, nums, dp) + target;
    // skip target
    int skipProfit = helper(idx + 1, nums, dp);
    return dp[idx] = max(robProfit, skipProfit);
}

int rob_memo(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);

    return helper(0, nums, dp);
}

int rob_tab(vector<int> &nums)
{
    size_t size = nums.size();
    vector<int> dp(size + 1, 0);

    for (size_t i = 0; i < size; i++)
    {
        dp[i] += nums[i];
        if (i + 2 < size + 1 && dp[i] > dp[i + 2])
        {
            dp[i + 2] = dp[i];
        }
        if (i + 3 < size + 1 && dp[i] > dp[i + 3])
        {
            dp[i + 3] = dp[i];
        }
    }

    return max(dp[size], dp[size - 1]);
}

int main()
{
    vector<int> nums = {2, 1, 1, 2};
    cout << rob_tab(nums) << endl;
}
