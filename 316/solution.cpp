#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> oc;
        stack<char> stk;
        set<char> visited;
        for (int i = 0; i < s.length(); i++)
        {
            oc[s[i]]++;
        }
        for (size_t i = 0; i < s.length(); i++)
        {
            if (visited.find(s[i]) != visited.end())
            {
                oc[s[i]]--;
                continue;
            }
            while (stk.size() != 0)
            {
                char prev = stk.top();
                cout << s[i] << "-" << prev << endl;
                if (s[i] <= prev && oc[prev] > 0)
                {
                    stk.pop();
                    visited.erase(prev);
                    cout << "deled" << endl;
                }
                else
                {
                    break;
                }
            }
            stk.push(s[i]);
            visited.insert(s[i]);
            oc[s[i]]--;
        }

        string result = "";

        while (!stk.empty())
        {

            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.removeDuplicateLetters("bcabc") << endl;
}
