#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class RateLimiter
{
    int n;
    int t;
    queue<int> requests;

public:
    RateLimiter(int n, int t)
    {
        this->n = n;
        this->t = t;
    }

    bool shouldAllow(int timestamp)
    {

        while (requests.size() > 0 && timestamp - requests.front() >= t)
        {
            requests.pop();
        }

        if (requests.size() > n - 1)
        {
            return false;
        }
        requests.push(timestamp);
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
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
