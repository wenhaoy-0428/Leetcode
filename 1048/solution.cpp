#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int helper(string target, unordered_map<string, int> &table)
{
    if (table[target] != 0)
    {
        return table[target];
    }
    int maxLen = 0;
    for (int i = 0; i < target.length(); i++)
    {

        string newTarget = target.substr(0, i) + target.substr(i + 1, target.length() - i - 1);
        if (table.find(newTarget) != table.end())
        {
            maxLen = max(1 + helper(newTarget, table), maxLen);
        }
    }
    return table[target] = maxLen;
}

int longestStrChain(vector<string> &words)
{
    unordered_map<string, int> table;
    for (size_t i = 0; i < words.size(); i++)
    {
        table[words[i]] = 0;
    }

    int result = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        result = max(result, 1 + helper(words[i], table));
    }
    return result;
}

int main()
{
    vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << longestStrChain(words) << endl;
}