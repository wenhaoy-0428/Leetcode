#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string shorter, longer;
        if (str1.length() < str2.length())
        {
            shorter = str1;
            longer = str2;
        }
        else
        {
            shorter = str2;
            longer = str1;
        }

        for (int i = 0)
    }
};

int main()
{
    Solution solution;
    solution.gcdOfStrings("", "");
}