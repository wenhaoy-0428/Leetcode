#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        int result = 0;

        for (auto const &pair : map)
        {
            result += ((pair.second - 1) + 1) * (pair.second - 1) / 2;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 1};
    cout << solution.numIdenticalPairs(nums) << endl;
}