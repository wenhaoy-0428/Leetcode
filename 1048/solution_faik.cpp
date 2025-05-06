#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int MAX = 0;
size_t maxLen = 0;

bool isPredecessor(string s, string l)
{
    int idxL = 0, idxS = 0;
    if (s.length() + 1 != l.length())
    {
        return false;
    }

    while (idxL != l.length())
    {
        if (s[idxS] == l[idxL])
        {
            idxS++;
        }
        idxL++;
    }
    return idxS == s.length();
}

int helper(string target, int len, unordered_map<int, vector<string>> &table)
{
    if (len == maxLen)
    {
        return 0;
    }

    if (table.find(len) == table.end())
    {
        return helper("", len + 1, table);
    }

    vector<string> candidates = table[len];
    int result = 0;

    for (size_t i = 0; i < candidates.size(); i++)
    {
        if (isPredecessor(target, candidates[i]))
        {
            result = 1 + max(result, helper(candidates[i], len + 1, table));
        }
    }
    MAX = max(MAX, result);
    return result;
}

int longestStrChain(vector<string> &words)
{
    unordered_map<int, vector<string>> table;
    size_t minLen = 10000;
    // size_t maxLen = 0;
    for (auto const &word : words)
    {
        minLen = min(minLen, word.length());
        maxLen = max(maxLen, word.length());
        table[word.length()].push_back(word);
    }
    helper("", minLen, table);
    return MAX;
}

int main()
{
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << longestStrChain(words) << endl;
}
