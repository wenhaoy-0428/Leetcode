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

vector<vector<string>> helper(string s, int l, int r)
{
    cout << l << '-' << r << endl;
    if (r == s.length())
    {
        // when reach the end of the string
        cout << l << '-' << r << '-' << s.substr(l, r - l) << endl;
        if (isPalindrome(s.substr(l, r - l)))
        {
            return vector<vector<string>>{{s.substr(l, r - l)}};
        }
        else
        {
            return vector<vector<string>>{};
        }
    }

    string curr = s.substr(l, r - l);
    vector<vector<string>> result;
    // cout << curr << endl;
    if (isPalindrome(curr))
    {
        // break
        vector<vector<string>> t1 = helper(s, r, r + 1);

        // print2DVector(t1);
        for (size_t i = 0; i < t1.size(); i++)
        {
            t1[i].insert(t1[i].begin(), curr);
            result.push_back(t1[i]);
        }
    }

    // continue
    vector<vector<string>> t2 = helper(s, l, r + 1);
    for (size_t i = 0; i < t2.size(); i++)
    {

        result.push_back(t2[i]);
    }

    return result;
}

vector<vector<string>> partition(string s)
{
    return helper(s, 0, 1);
}

int main()
{
    string target = "abbc";
    vector<vector<string>> result = partition(target);
    print2DVector(result);
}