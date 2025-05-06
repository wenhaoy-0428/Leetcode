#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        // m: row, n: col
        int m = matrix.size(), n = matrix[0].size(), x = 0, y = 0;

        while (res.size() < m * n)
        {
            // top
            for (int i = y; i < n - y; i++)
            {
                int tmp = matrix[x][i];
                res.push_back(tmp);
            }

            // right
            for (int i = 1 + x; i < m - x; i++)
            {
                int tmp = matrix[i][n - 1 - y];
                res.push_back(tmp);
            }

            if ((m - 1 - x) > x)
            {
                // bottom
                for (int i = n - 2 - y; i >= y; i--)
                {
                    int tmp = matrix[m - 1 - x][i];
                    res.push_back(tmp);
                }
            }
            if (y < (n - 1 - y))
            {
                // left
                for (int i = m - 2 - x; i > x; i--)
                {
                    int tmp = matrix[i][y];
                    res.push_back(tmp);
                }
            }

            // TODO:
            x++;
            y++;
        }

        return res;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     // input
//     vector<vector<int>> matrix = {{1, 2}, {3, 4}};
//     // exp
//     vector<int> exp = {1, 2, 4, 3};
//     // res
//     vector<int> res = solution.spiralOrder(matrix);

//     // Assertion
//     ASSERT_EQ(exp.size(), res.size());

//     for (int i = 0; i < res.size(); i++)
//     {
//         if (exp[i] != res[i])
//         {
//             FAIL();
//         }
//     }
// }

// TEST_F(SolutionTest, test_002)
// {
//     // input
//     vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     // exp
//     vector<int> exp = {1, 2, 3, 6, 9, 8, 7, 4, 5};
//     // res
//     vector<int> res = solution.spiralOrder(matrix);

//     // Assertion
//     ASSERT_EQ(exp.size(), res.size());

//     for (int i = 0; i < res.size(); i++)
//     {
//         if (exp[i] != res[i])
//         {
//             FAIL();
//         }
//     }
// }

// TEST_F(SolutionTest, test_003)
// {
//     // input
//     vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     // exp
//     vector<int> exp = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
//     // res
//     vector<int> res = solution.spiralOrder(matrix);

//     // Assertion
//     ASSERT_EQ(exp.size(), res.size());

//     for (int i = 0; i < res.size(); i++)
//     {
//         if (exp[i] != res[i])
//         {
//             FAIL();
//         }
//     }
// }

TEST_F(SolutionTest, test_004)
{
    // input
    vector<vector<int>> matrix = {{2, 5, 8}, {4, 0, -1}};
    // exp
    vector<int> exp = {2, 5, 8, -1, 0, 4};
    // res
    vector<int> res = solution.spiralOrder(matrix);

    // Assertion
    ASSERT_EQ(exp.size(), res.size());

    for (int i = 0; i < res.size(); i++)
    {
        if (exp[i] != res[i])
        {
            FAIL();
        }
    }
}
