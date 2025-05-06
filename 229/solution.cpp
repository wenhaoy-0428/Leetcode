#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int times = nums.size() / 3;
        unordered_map<int, int> freq;
        vector<int> result;
        for (auto const &num : nums)
        {
            if (freq.find(num) != freq.end() && freq[num] == -1)
            {
                continue;
            }
            freq[num]++;
            if (freq[num] > times)
            {
                result.push_back(num);
                freq[num] = -1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2};
    vector<int> result = solution.majorityElement(nums);

    printVector(result);
}