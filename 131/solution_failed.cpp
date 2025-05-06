#include <iostream>
#include <vector>
#include "../util/util.h"

using namespace std;

bool isPalindrome(const std::string &s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // Compare the characters (case-insensitive)
        if (s[left] != s[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

vector<vector<string>> partition(string s)
{
    int size = s.length() + 1;
    vector<vector<vector<string>>> dp(size);
    dp.push_back(vector<vector<string>>{{}});

    for (int i = 1; i < size; i++)
    {
        vector<vector<string>> prev = dp[i - 1];
        // copy
        dp[i] = prev;
        // break 1 word
        for (size_t j = 0; j < prev.size(); j++)
        {
            string curr(1, s[i - 1]);

            dp[i][j].push_back(curr);
        }

        // break current substr
        string sub = s.substr(0, i);
        if (isPalindrome(sub))
        {
            dp[i].push_back(vector<string>{sub});
        }

        // don't break, continue;
    }

    return dp[size - 1];
}

int main()
{
    string target = "cdda";
    vector<vector<string>> result = partition(target);
    print2DVector(result);
}
