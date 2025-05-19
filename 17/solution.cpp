#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> result;
        if (digits.empty())
            return result;
        string currentCombination;
        backtrack(digits, 0, currentCombination, digitToLetters, result);
        return result;
    }

    void backtrack(const string &digits, int index, string &currentCombination, const unordered_map<char, string> &digitToLetters, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(currentCombination);
            return;
        }
        char digit = digits[index];
        const string &letters = digitToLetters.at(digit);
        for (char letter : letters)
        {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, currentCombination, digitToLetters, result);
            currentCombination.pop_back();
        }
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
