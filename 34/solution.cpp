#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    int BinarySearchLess(vector<int> &nums, int l, int r, int target)
    {

        if (r > nums.size() || l < 0 || l > r)
        {
            return -1;
        }
        int m = (r - l) / 2 + l;

        if (nums[m] < target)
        {
            if (m < nums.size() - 1 && nums[m + 1] == target)
            {
                return m + 1;
            }
            return BinarySearchLess(nums, m + 1, r, target);
        }

        return BinarySearchLess(nums, l, m - 1, target);
    }

    int BinarySearchMore(vector<int> &nums, int l, int r, int target)
    {
        if (r > nums.size() || l < 0 || l > r)
        {
            return -1;
        }
        int m = (r - l) / 2 + l;

        if (nums[m] > target)
        {
            if (m > 0 && nums[m - 1] == target)
            {
                return m - 1;
            }
            return BinarySearchMore(nums, l, m - 1, target);
        }
        return BinarySearchMore(nums, m + 1, r, target);
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        int l = BinarySearchLess(nums, 0, nums.size() - 1, target);
        int r = BinarySearchMore(nums, 0, nums.size() - 1, target);
        if (l == -1 && nums.size() > 0 && nums[0] == target)
        {
            l = 0;
        }
        if (r == -1 && nums.size() > 0 && nums[nums.size() - 1] == target)
        {
            r = nums.size() - 1;
        }
        result.push_back(l);
        result.push_back(r);
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1, 3};
    int target = 1;
    vector<int> result = solution.searchRange(nums, target);
    printVector(result);
}