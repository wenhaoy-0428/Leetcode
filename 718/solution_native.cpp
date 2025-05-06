#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkSame(vector<int> &nums1, vector<int> &nums2, int s1, int s2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (nums1[s1 + i] != nums2[s2 + i])
        {
            return false;
        }
    }
    return true;
}

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    size_t size1 = nums1.size();
    size_t size2 = nums2.size();

    vector<int> *shorterVector = nullptr;
    vector<int> *longerVector = nullptr;

    if (size1 < size2)
    {
        shorterVector = &nums1;
        longerVector = &nums2;
    }
    else
    {
        shorterVector = &nums2;
        longerVector = &nums1;
    }
    size_t minSize = min(size1, size2);
    size_t maxSize = max(size1, size2);

    for (int size = minSize; size >= 0; size--)
    {
        // cout << "minSize: " << size << endl;
        size_t i = 0;
        while (i + size <= minSize)
        {
            size_t j = 0;
            while (j + size <= maxSize)
            {
                // cout << j << '-' << i << '-' << size << endl;
                if (checkSame(*longerVector, *shorterVector, j, i, size))
                {
                    return size;
                }
                j++;
            }
            i++;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    cout << findLength(nums1, nums2) << endl;
}
