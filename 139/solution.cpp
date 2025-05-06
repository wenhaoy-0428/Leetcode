#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool helper(string s, vector<string> &wordDict, unordered_map<string, bool> &dp)
{
    if (dp.find(s) != dp.end())
    {
        return dp[s];
    }

    if (s.empty())
    {
        return true;
    }

    for (size_t i = 0; i < wordDict.size(); i++)
    {
        if (s.substr(0, wordDict[i].length()) == wordDict[i])
        {
            string subString = s.substr(wordDict[i].length());
            // cout << s.substr(0, wordDict[i].length()) << endl;
            if (helper(subString, wordDict, dp))
            {
                return dp[s] = true;
            }
        }
    }

    return dp[s] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, bool> dp;
    return helper(s, wordDict, dp);
}

int main()
{
    string s = "catsandog";
    vector<string> wd = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak(s, wd) << endl;
    ;
}
