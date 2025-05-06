#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum - x;
    if (target < 0)
    {
        return -1;
    }

    if (target == 0)
    {
        return nums.size();
    }

    cout << target << endl;

    int total = 0;
    int maxLen = -1;
    for (int l = 0, r = 0; r < nums.size();)
    {
        while (total < target && r < nums.size())
        {
            total += nums[r];
            r++;
        }

        cout << "l: " << l << " r: " << r << " total: " << total << endl;

        while (total >= target)
        {
            if (target == total)
            {
                maxLen = max(maxLen, (r - l));
            }
            total -= nums[l];
            l++;
        }
    }
    if (maxLen < 0)
    {
        return -1;
    }
    return nums.size() - maxLen;
}

int main()
{
    vector<int> nums = {5, 1, 4, 2, 3};
    int target = 6;
    cout << minOperations(nums, target) << endl;
}
