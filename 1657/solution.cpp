#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
        {
            return false;
        }
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        vector<char> keys1;
        vector<int> values1;
        vector<char> keys2;
        vector<int> values2;

        for (size_t i = 0; i < word1.length(); i++)
        {
            freq1[word1[i]] += 1;
        }
        for (size_t i = 0; i < word2.length(); i++)
        {
            freq2[word2[i]] += 1;
        }
        for (const auto pair : freq1)
        {
            keys1.push_back(pair.first);
            values1.push_back(pair.second);
        }

        for (const auto pair : freq2)
        {
            keys2.push_back(pair.first);
            values2.push_back(pair.second);
        }

        sort(keys1.begin(), keys1.end());
        sort(keys2.begin(), keys2.end());

        if (keys1 != keys2)
        {
            return false;
        }

        sort(values1.begin(), values1.end());
        sort(values2.begin(), values2.end());

        if (values1 != values2)
        {
            return false;
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
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}

TEST_F(SolutionTest, test_002)
{
    string word1 = "abc";
    string word2 = "bca";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}

TEST_F(SolutionTest, test_003)
{
    string word1 = "a";
    string word2 = "aa";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_FALSE(result);
}

TEST_F(SolutionTest, test_004)
{
    string word1 = "cabbba";
    string word2 = "abbccc";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}

TEST_F(SolutionTest, test_005)
{
    string word1 = "cabbba";
    string word2 = "aabbss";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_FALSE(result);
}

TEST_F(SolutionTest, test_006)
{
    string word1 = "cabbba";
    string word2 = "abbccc";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}