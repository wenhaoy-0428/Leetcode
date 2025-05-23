#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class RandomizedSet
{
    unordered_map<int, int> mp;
    vector<int> store;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        mp[val] = store.size();
        store.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false;
        }
        int idx = mp[val];
        mp.erase(val);

        if (idx != store.size() - 1)
        {
            swap(store[idx], store[store.size() - 1]);
            mp[store[idx]] = idx;
        }

        store.pop_back();
        return true;
    }

    int getRandom()
    {
        int idx = rand() % store.size();

        return store[idx];
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
