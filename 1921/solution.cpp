#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"
#include <queue>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = 0;
        priority_queue<int, vector<int>, greater<int>> timeToHit;
        for (size_t i = 0; i < dist.size(); i++)
        {

            timeToHit.push(ceil(float(dist[i]) / float(speed[i])));
        }

        while (n < dist.size())
        {
            int time = timeToHit.top();
            if (n >= time)
            {
                return n;
            }
            else
            {
                timeToHit.pop();
                n++;
            }
        }

        return n;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{

    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 1, 1};
    int result = solution.eliminateMaximum(dist, speed);
    ASSERT_EQ(3, result);
}

TEST_F(SolutionTest, test_002)
{

    vector<int> dist = {1, 1, 2, 3};
    vector<int> speed = {1, 1, 1, 1};
    int result = solution.eliminateMaximum(dist, speed);
    ASSERT_EQ(1, result);
}

TEST_F(SolutionTest, test_003)
{

    vector<int> dist = {3, 2, 4};
    vector<int> speed = {5, 3, 2};
    int result = solution.eliminateMaximum(dist, speed);
    ASSERT_EQ(1, result);
}
