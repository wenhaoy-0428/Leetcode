#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int past = 0, past2 = 0, curr_tank = 0, idx = 0, n = gas.size();
        for (int i = 0; i < n; i++)
        {
            int temp = gas[i] - cost[i];
            past += temp;
            if (curr_tank + temp < 0)
            {
                idx = i + 1;
                curr_tank = 0;
                past2 = past;
            }
            else
            {
                curr_tank += temp;
            }
        }
        return curr_tank + past2 >= 0 ? idx : -1;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
