#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int numFlowers = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (size_t i = 1; i < flowerbed.size() - 1; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                numFlowers++;
            }
        }
        return numFlowers >= n;
    }
    t
};

int main()
{

    Solution solution;
    vector<int> flower = {0, 0, 1, 0, 0};

    cout << solution.canPlaceFlowers(flower, 1) << endl;
}