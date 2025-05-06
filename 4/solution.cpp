#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int idx1 = 0, idx2 = 0;
    int md = (nums1.size() + nums2.size()) / 2;

    double mid1 = 0;
    double mid2 = 0;
    while (idx1 != nums1.size() && idx2 != nums2.size() && idx1 + idx2 <= md)
    {
        if (nums1[idx1] < nums2[idx2])
        {
            mid2 = mid1;
            mid1 = nums1[idx1];

            idx1++;
        }
        else
        {
            mid2 = mid1;
            mid1 = nums2[idx2];

            idx2++;
        }
    }

    cout << idx1 << "-" << idx2 << endl;
    while (idx1 + idx2 <= md)
    {
        if (idx1 < nums1.size())
        {
            mid2 = mid1;
            mid1 = nums1[idx1];

            idx1++;
        }
        if (idx2 < nums2.size())
        {
            mid2 = mid1;
            mid1 = nums2[idx2];

            idx2++;
        }
    }
    if ((nums1.size() + nums2.size()) % 2 == 0)
    {
        cout << "called" << mid1 << " " << mid2 << endl;

        return (mid1 + mid2) / 2;
    }

    return mid1;
}

int main()
{
    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {3, 5};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}
