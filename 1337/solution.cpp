#include <iostream>
#include <queue>
#include "../util/util.h"

using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<int> result;
    using int2 = pair<int, int>;
    priority_queue<int2, vector<int2>, greater<int2>> pq;
    for (size_t i = 0; i < mat.size(); i++)
    {
        int numSoldier = 0;
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] != 1)
            {
                break;
            }
            numSoldier++;
        }
        pq.push({numSoldier, i});
    }
    for (int i = 0; i < k; i++)
    {
        auto [l, idx] = pq.top();
        pq.pop();
        result.push_back(idx);
    }
    return result;
}

int main()
{
    vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    vector<int> result = kWeakestRows(mat, 3);
    printVector(result);
}
