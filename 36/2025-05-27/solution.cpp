#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            unordered_set<char> st;
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                if (st.count(board[i][j]))
                {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            unordered_set<char> st;
            for (int j = 0; j < board.size(); j++)
            {
                if (board[j][i] == '.')
                {
                    continue;
                }

                if (st.count(board[j][i]))
                {
                    return false;
                }
                st.insert(board[j][i]);
            }
        }

        unordered_set<char> boxes[9];
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[j][i] == '.')
                {
                    continue;
                }
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(board[j][i]))
                {
                    return false;
                }

                boxes[boxIndex].insert(board[j][i]);
            }
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
