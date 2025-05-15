#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 2 pointer problem
bool canJump(vector<int> &nums)
{

    size_t position = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        // our position is fallen behind due to incapability to move forward.
        if (position < i)
        {
            return false;
        }

        position = max(nums[i] + i, position);
    }

    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << endl;
}