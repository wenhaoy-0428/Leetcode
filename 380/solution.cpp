#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <chrono>
#include <ctime>

#include <gtest/gtest.h>

using namespace std;

class RandomizedSet
{
    unordered_map<int, int> table;
    vector<int> list;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (auto findit = table.find(val); findit != table.end())
        {
            return false;
        }
        table[val] = list.size();
        list.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (auto findit = table.find(val); findit != table.end())
        {
            int idx = findit->second;
            list[idx] = list[list.size() - 1];
            table[list[idx]] = idx;
            table.erase(val);
            list.pop_back();
            return true;
        }

        return false;
    }

    int getRandom()
    {
        int idx = rand() % list.size();
        return list[idx];
    }
};

class SolutionTest : public testing::Test
{
protected:
    RandomizedSet solution;
};

TEST_F(SolutionTest, test_001)
{
    ASSERT_FALSE(solution.remove(0));
    ASSERT_FALSE(solution.remove(0));
    ASSERT_TRUE(solution.insert(0));
    ASSERT_TRUE(solution.remove(0));
    ASSERT_TRUE(solution.insert(0));
}
