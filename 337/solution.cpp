#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    int size = target + 1;
    vector<int> dp(size, 0);
    dp[0] = 1;

    for (int i = 0; i < size; i++)
    {
        // cout << dp[i] << endl;
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (i + nums[j] < size)
            {
                cout << dp[i] << endl;
                dp[i + nums[j]] += dp[i];
            }
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums = {10, 20};

    cout << combinationSum4(nums, 500) << endl;
}
