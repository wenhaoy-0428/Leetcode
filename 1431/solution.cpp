#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> result;

        auto maxElement = *max_element(begin(candies), end(candies));

        for (size_t i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= maxElement)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> candies = {2, 3, 5, 1, 3};

    vector<bool> result = solution.kidsWithCandies(candies, 3);
    printVector(result);
}