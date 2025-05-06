#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    size_t s1 = nums1.size();
    size_t s2 = nums2.size();
    vector<vector<int>> dp(s1, vector<int>(s2, 0));
    // compare each element in nums1 with nums2 and store the result in the dp table.
    // if they the same, check if the precious element of each vector is the same.

    int maxLen = 0;
    for (size_t i = 0; i < s1; i++)
    {
        for (size_t j = 0; j < s2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                if (i >= 1 && j >= 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                }
            }
        }
    }
    return maxLen;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    cout << findLength(nums1, nums2) << endl;
}