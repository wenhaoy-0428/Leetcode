#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        pair<int, int> bestCandidate(0, 0);
        // try every element as the center of the palindrome
        for (size_t i = 0; i < s.length(); i++)
        {
            int l = i, r = i;
            while (1)
            {
                if (l < 0 || r >= s.length() || s[l] != s[r])
                {
                    break;
                }

                if (r - l > (bestCandidate.second - bestCandidate.first))
                {
                    bestCandidate = pair<int, int>(l, r);
                }
                l--;
                r++;
            }
            // try 2 elements as the center of the palindrome
            l = i, r = i + 1;
            while (1)
            {
                if (l < 0 || r >= s.length() || s[l] != s[r])
                {
                    break;
                }
                if (r - l > (bestCandidate.second - bestCandidate.first))
                {
                    bestCandidate = pair<int, int>(l, r);
                }
                l--;
                r++;
            }
        }
        string result = s.substr(bestCandidate.first, bestCandidate.second - bestCandidate.first + 1);
        return result;
    }
};

int main()
{
    Solution solution;
    solution.longestPalindrome("aaaa");
}