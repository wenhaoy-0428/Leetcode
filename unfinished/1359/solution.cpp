#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

unsigned long long factorial(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

long long helper(int p, int d, int n, unordered_map<string, long> &dp)
{
    string key = to_string(p) + '-' + to_string(d) + '-' + to_string(n);
    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }
    if (p == 1)
    {
        return factorial(d);
    }

    long long result = 0;

    for (int j = 0; j <= n; j++)
    {
        long temp = helper(p - 1, d - j, n + 1 - j, dp) * factorial(n) * factorial(j) / (factorial(j) * factorial(n - j));
        // cout << temp << '|' << n << "|" << p << '|' << d << endl;
        result += temp;
        result = result % MOD;
    }

    return dp[key] = result * p % MOD;
}

int countOrders(int n)
{
    unordered_map<string, long> dp;
    return helper(n, n, 1, dp);
}

int TT(int n)
{
    long long count = 1;
    for (int i = 2; i <= n; ++i)
    {
        count = (count * (2 * i - 1) * i) % MOD;
    }
    return (int)count;
}

int main()
{
    int target = 13;
    cout << countOrders(target) << endl;
    cout << TT(target) << endl;
}
