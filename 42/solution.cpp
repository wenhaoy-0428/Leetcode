#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int> &height)
{
    int size = height.size();
    int lidx = 0, ridx = size - 1;
    int lmax = height[lidx], rmax = height[ridx];
    int result = 0;

    while (lidx <= ridx)
    {
        if (lmax < rmax)
        {
            result += max(lmax - height[lidx], 0);
            lmax = max(lmax, height[lidx]);
            lidx++;
        }
        else
        {
            result += max(rmax - height[ridx], 0);
            rmax = max(rmax, height[ridx]);
            ridx--;
        }

        // cout << result << "-" << height[lidx] << "-" << height[ridx] << endl;
    }
    return result;
}

int main()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(heights) << endl;
}
