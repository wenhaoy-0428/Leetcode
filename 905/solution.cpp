#include <iostream>
#include <vector>
#include "../util/util.h"
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int l = 0, r = result.size() - 1;
        for (auto const &num : nums)
        {
            if (num % 2 == 0)
            {
                result[l] = num;
                l++;
            }
            else
            {
                result[r] = num;
                r--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> v = {3, 1, 2, 4};
    vector<int> r = solution.sortArrayByParity(v);
    printVector(r);
}
