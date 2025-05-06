#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        size_t i1 = 0, i2 = 0;
        string result;
        while (i1 < word1.length() && i2 < word2.length())
        {
            result += word1[i1];
            result += word2[i2];
            i1++;
            i2++;
        }
        while (i1 < word1.length())
        {
            result += word1[i1];
            i1++;
        }

        while (i2 < word2.length())
        {
            result += word2[i2];
            i2++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.mergeAlternately("abc", "pqr") << endl;
}