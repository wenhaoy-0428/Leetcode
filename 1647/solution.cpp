#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../util/util.h"

using namespace std;

int minDeletions(string s)
{
    // gather all frequency of each char
    unordered_map<char, int> freqTable;
    for (size_t i = 0; i < s.length(); i++)
    {
        char curr = s[i];
        if (freqTable.find(curr) != freqTable.end())
        {
            freqTable[curr]++;
        }
        else
        {
            freqTable[curr] = 1;
        }
    }
    // gather the all the frequencies.
    vector<int> freq;
    for (const auto &pair : freqTable)
    {
        freq.push_back(pair.second);
    }

    // sort in descending order.
    sort(freq.begin(), freq.end(), greater<int>());

    // printVector(freq);

    int result = 0;

    for (size_t i = 0; i < freq.size(); i++)
    {
        if (freq[i] == 0)
        {
            break;
        }
        size_t j = i + 1;
        while (j < freq.size() && freq[j] == freq[i])
        {
            j++;
        }

        for (size_t n = i + 1; n < j; n++)
        {
            freq[n]--;
            result++;
        }
    }

    return result;
}

int main()
{
    cout << minDeletions("bbcebab") << endl;
}
