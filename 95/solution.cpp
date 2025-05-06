#include <iostream>
#include "../util/util.h"
using namespace std;

int helper(int m, vector<int> &dp)
{
    if (dp[m] != -1)
    {
        return dp[m];
    }

    if (m <= 0)
    {
        return 1;
    }

    int counter = 0;
    for (int i = 0; i < m; i++)
    {
        counter += helper(i - 0, dp) * helper(m - i - 1, dp);
    }

    return dp[m] = counter;
}

int numTrees(int n)
{
    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}

int main()
{
    cout << numTrees(4) << endl;
}
