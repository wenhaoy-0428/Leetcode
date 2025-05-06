#include <iostream>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    int len = nums.size() + 1;
    vector<int> count(len + 1, 0);
    for (int i = 0; i < len; i++)
    {
        count[nums[i]]++;
        cout << nums[i] << endl;
        if (count[nums[i]] > 1)
        {
            return nums[i];
        }
    }
    return len;
}

int main()
{
    vector<int> input = {2, 1, 1};
    cout << findDuplicate(input) << endl;
}
