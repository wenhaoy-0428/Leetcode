#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> pwd;
        for (auto const &log : logs)
        {
            string dir = log.substr(0, log.length() - 1);
            if (dir == ".")
            {
                continue;
            }

            if (dir == "..")
            {
                if (pwd.size() > 0)
                {
                    pwd.pop();
                }

                continue;
            }

            pwd.push(dir);
        }
        return pwd.size();
    }
};

int main()
{
    Solution solution;
    vector<string> logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    cout << solution.minOperations(logs) << endl;
}