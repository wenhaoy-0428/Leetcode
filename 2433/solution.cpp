#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> result;
        result.push_back(pref[0]);
        for (size_t i = 1; i < pref.size(); i++)
        {
            result.push_back(pref[i] ^ pref[i - 1]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> pref = {5, 2, 0, 3, 1};
    vector<int> result = solution.findArray(pref);
    printVector(result);
}