#include <iostream>
#include <unordered_map>
using namespace std;

int helper(string &word1, string &word2, int i1, int i2, unordered_map<string, int> &dp)
{
    string key = to_string(i1) + '_' + to_string(i2);

    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }

    if (i1 == word1.length() && i2 == word2.length())
    {
        return 0;
    }
    else if (i1 >= word1.length() || i2 >= word2.length())
    {
        return (word1.length() + word2.length()) - i1 - i2;
    }

    if (word1[i1] == word2[i2])
    {

        return dp[key] = helper(word1, word2, i1 + 1, i2 + 1, dp);
    }
    // insert a new one at current position
    int ins = helper(word1, word2, i1, i2 + 1, dp) + 1;
    // del current position
    int del = helper(word1, word2, i1 + 1, i2, dp) + 1;
    // replace current position
    int rep = helper(word1, word2, i1 + 1, i2 + 1, dp) + 1;

    return dp[key] = min(min(ins, del), rep);
}

int minDistance(string word1, string word2)
{
    unordered_map<string, int> dp;
    return helper(word1, word2, 0, 0, dp);
}

int main()
{
    string word1 = "intention";
    string word2 = "execution";
    cout << minDistance(word1, word2) << endl;
}
