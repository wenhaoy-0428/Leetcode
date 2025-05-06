#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> result;
        int idx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (idx == target.size())
            {
                return result;
            }
            int element = target[idx];

            result.push_back("Push");
            if (i != element)
            {
                result.push_back("Pop");
            }
            else
            {
                idx++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> target = {1, 2};
    vector<string> result = solution.buildArray(target, 4);
    printVector(result);
}