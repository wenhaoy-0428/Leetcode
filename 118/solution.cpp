#include <iostream>
#include <vector>
#include "../util/util.h"

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    vector<int> prevRow = {1};
    result.push_back(prevRow);
    for (int i = 1; i < numRows; i++)
    {
        prevRow.insert(prevRow.begin(), 0);
        prevRow.push_back(0);
        vector<int> currRow;
        for (int j = 0; j < i + 1; j++)
        {
            currRow.push_back(prevRow[j] + prevRow[j + 1]);
        }
        result.push_back(currRow);
        prevRow = currRow;
    }

    return result;
}

int main()
{
    vector<vector<int>> result = generate(5);
    print2DVector(result);
}
