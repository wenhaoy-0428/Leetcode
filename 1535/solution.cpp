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
    int getWinner(vector<int> &arr, int k)
    {
        int size = arr.size();
        k = min(k, size);
        arr.insert(arr.end(), arr.begin(), arr.end());
        int winner = *max_element(arr.begin(), arr.begin() + k + 1);
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == winner)
            {
                return winner;
            }
            winner = max(winner, arr[i + k]);
        }
        return winner;
    }
};

class Solution1
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        queue<int> q;

        for (size_t i = 1; i < arr.size(); i++)
        {
            q.push(arr[i]);
        }

        int winner = arr[0];
        int winStreak = 0;
        k = min(k, int(arr.size()));
        while (winStreak != k)
        {
            int contestant = q.front();
            q.pop();
            if (contestant > winner)
            {
                winner = contestant;
                winStreak = 1;
                q.push(winner);
            }
            else
            {
                winStreak++;
                q.push(contestant);
            }
        }
        return winner;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<int> array = {2, 1, 3, 5, 4, 6, 7};
    int k = 2;
    ASSERT_EQ(5, solution.getWinner(array, k));
}
