#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        size_t l = 0, r = 0;
        string result = "";
        while (r != s.length())
        {

            if (s[r] == ' ')
            {
                size_t temp = r;
                while (temp != l)
                {
                    temp--;
                    result += s[temp];
                }
                result += ' ';
                l = r + 1;
            }
            r++;
        }

        while (r != l)
        {
            r--;
            result += s[r];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.reverseWords("Let's take LeetCode contest") << endl;
}