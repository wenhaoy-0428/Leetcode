#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class MinStack
{
    vector<int> st;
    vector<int> minST;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push_back(val);
        if (minST.empty() || val <= minST.back())
        {
            minST.push_back(val);
        }
    }

    void pop()
    {
        if (st.back() == minST.back())
        {
            minST.pop_back();
        }
        st.pop_back();
    }

    int top()
    {
        return st.back();
    }

    int getMin()
    {
        return minST.back();
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
