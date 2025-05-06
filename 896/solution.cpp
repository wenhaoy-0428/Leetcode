#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool result1 = true, result2 = true;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                cout << "called1" << endl;
                result1 = false;
            }
            if (-nums[i] < -nums[i - 1])
            {
                cout << "called2" << endl;
                result2 = false;
            }
        }
        return result1 || result2;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {6, 5, 4, 4};
    cout << solution.isMonotonic(nums) << endl;
}