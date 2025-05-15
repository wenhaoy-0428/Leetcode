#include <vector>
#include <iostream>

using namespace std;

bool canJump(vector<int> &nums)
{
    // using DP tabulation to solve this problem.

    if (nums.size() == 1)
    {
        return true;
    }

    /**
     * @brief  Find the inital table based on the shrinking input
     */

    // After each jump, we get into the next postion
    // which shrinks the size of the array giving us a subproblem.
    vector<bool> dp(nums.size() + 1, false);

    // initialize seed
    dp[0] = true;

    for (size_t i = 0; i < dp.size(); i++)
    {
        if (!dp[i])
        {
            continue;
        }
        int maxJump = nums[i]; // todo: outofbound
        for (int j = 1; j <= maxJump && j + i < dp.size(); j++)
        {
            dp[i + j] = true;
        }
    }
    return dp[nums.size()];
}

int main()
{
    vector<int> nums = {};
    cout << canJump(nums) << endl;
}