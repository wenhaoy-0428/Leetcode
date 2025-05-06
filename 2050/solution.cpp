#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {

        unordered_map<int, set<int>> depEd;
        unordered_map<int, int> dep;

        for (auto relation : relations)
        {
            int prev = relation[0], next = relation[1];

            depEd[prev].insert(next);
            dep[next] += 1;
        }

        for (int i = 1; i <= n; i++)
        {
            depEd[0].insert(i);
        }

        for (int i = 1; i <= n; i++)
        {
            if (dep.find(i) == dep.end())
            {
                depEd[-1].insert(i);
            }
        }

        int totalTime = 0;
        while (depEd[-1].size() != 0)
        {
            int minTime = 9999;
            for (auto course : depEd[-1])
            {
                if (time[course - 1] < minTime)
                {
                    minTime = time[course - 1];
                }
            }
            totalTime += minTime;
            vector<int> toBeAdd;
            vector<int> toBeDel;

            for (auto a : depEd[-1])
            {

                time[a - 1] -= minTime;
                if (time[a - 1] == 0)
                {
                    toBeDel.push_back(a);
                    for (auto b : depEd[a])
                    {
                        dep[b]--;
                        if (dep[b] == 0)
                        {
                            toBeAdd.push_back(b);
                        }
                    }
                }
            }

            for (auto add : toBeAdd)
            {
                depEd[-1].insert(add);
            }
            for (auto del : toBeDel)
            {
                depEd[-1].erase(del);
            }
        }

        return totalTime;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> relations = {};
    vector<int> time = {1};
    cout << solution.minimumTime(1, relations, time) << endl;
}