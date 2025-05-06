#include <iostream>
#include <queue>
#include <set>

using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
    using int3 = tuple<int, int, int>;
    priority_queue<int3, vector<int3>, greater<int3>> pq;
    vector<tuple<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    pq.push({0, 0, 0});

    vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), 0));

    int minEffort = 10000;
    while (!pq.empty())
    {
        auto [effort, row, col] = pq.top();

        pq.pop();

        if (row == heights.size() - 1 && col == heights[0].size() - 1)
        {
            return effort;
        }

        visited[row][col] = 1;
        for (const auto &[r, c] : directions)
        {
            int newRow = row + r;
            int newCol = col + c;

            if (newRow < 0 || newCol < 0 || newRow == heights.size() || newCol == heights[0].size() || visted[row][col] != 0)
            {
                continue;
            }
            int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));
            pq.push({newEffort, newRow, newCol});
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << minimumEffortPath(heights) << endl;
}
