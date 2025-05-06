#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <numeric>
#include <stack>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution_slow
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        size_t n = arr.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0] = arr;

        int m = 1e9 + 7;
        int sum = accumulate(arr.begin(), arr.end(), 0);

        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 0; j < n - i; j++)
            {
                dp[1][j] = min(dp[0][j], dp[0][j + 1]);
                sum = (sum + dp[1][j]) % m;
            }
            dp[0] = dp[1];
        }
        return sum;
    }
};

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        size_t n = arr.size();
        int MOD = 1e9 + 7;
        vector<tuple<int, int>> stack;
        int sum = 0;
        for (size_t i = 0; i < n; i++)
        {
            while (stack.size() && arr[i] < get<1>(stack[stack.size() - 1]))
            {
                auto [j, m] = stack[stack.size() - 1];
                stack.pop_back();
                int left = stack.size() ? j - get<0>(stack[stack.size() - 1]) : j + 1;
                int right = i - j;
                sum = (sum + m * left * right) % MOD;
            }
            stack.push_back(make_tuple(i, arr[i]));
        }

        for (size_t i = 0; i < stack.size(); i++)
        {
            auto [j, m] = stack[i];
            int left = i > 0 ? j - get<0>(stack[i - 1]) : j + 1;
            int right = n - j;
            sum = (sum + m * left * right) % MOD;
        }

        return sum;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> arr = {3, 1, 2, 4};
    int exp = 17;
    int res = solution.sumSubarrayMins(arr);
    ASSERT_EQ(exp, res);
}

TEST_F(SolutionTest, test_002)
{
    vector<int> arr = {11, 81, 94, 43, 3};
    int exp = 444;
    int res = solution.sumSubarrayMins(arr);
    ASSERT_EQ(exp, res);
}
