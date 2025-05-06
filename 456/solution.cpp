#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> comp;
        stack<int> Ms;
        size_t i = 0;
        if (nums.size() < 3)
        {
            return false;
        }

        int M = nums[i++];
        Ms.push(M);
        comp.push(nums[i++]);

        for (; i < nums.size(); i++)
        {

            if (comp.size() >= 1 && Ms.size() >= 1 && nums[i] < comp.top() && nums[i] > Ms.top())
            {
                return true;
            }

            while (comp.size() >= 1 && nums[i] > comp.top())
            {
                comp.pop();
                Ms.pop();
                if (comp.size() >= 1 && nums[i] < comp.top() && nums[i] > Ms.top())
                {
                    return true;
                }
            }

            comp.push(nums[i]);

            if (nums[i - 1] < M)
            {
                M = nums[i - 1];
            }
            Ms.push(M);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 5, 0, 3, 4};
    cout << solution.find132pattern(nums) << endl;
}