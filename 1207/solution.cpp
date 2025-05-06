#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        set<int> visited;

        for (auto const &ele : arr)
        {
            freq[ele]++;
        }

        for (auto const &pair : freq)
        {
            if (visited.count(pair.second) != 0)
            {
                return false;
            }
            visited.insert(pair.second);
        }
        return true;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> input = {1, 2, 2, 1, 1, 3};

    bool result = solution.uniqueOccurrences(input);
    ASSERT_TRUE(result);
}
