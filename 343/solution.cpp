#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n <= 3)
        {
            return n - 1;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
            cout << i << ": " << dp[i] << endl;
        }
        return dp[n];
    }
};

int main()
{
    Solution solution;
    cout << solution.integerBreak(20) << endl;
}