#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        queue<int> q;
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<int> visied(n + 1, 0);
        // Build the graph
        for (const auto &time : times)
        {
            graph[time[0]].emplace_back(time[1], time[2]);
        }
        // Distance vector initialized to infinity
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; // Distance to the starting node is 0
        q.push(k);

        while (!q.empty())
        {
            int node = q.front();
            visied[node] = 1; // Mark the node as visited
            q.pop();

            for (const auto &neighbor : graph[node])
            {
                int nextNode = neighbor.first;
                int time = neighbor.second;
                if (visied[nextNode] == 1 && dist[nextNode] <= dist[node] + time)
                {
                    continue; // Skip if already visited and not a better path
                }
                q.push(nextNode);
                dist[nextNode] = min(dist[nextNode], dist[node] + time);
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INT_MAX)
            {
                return -1; // If any node is unreachable, return -1
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime; // Return the maximum time taken to reach all nodes
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int result = solution.networkDelayTime(times, n, k);
    ASSERT_EQ(result, 2);
}

TEST_F(SolutionTest, test_002)
{
    vector<vector<int>> times = {{2, 2, 1}, {2, 1, 3}};
    int n = 2;
    int k = 2;
    int result = solution.networkDelayTime(times, n, k);
    ASSERT_EQ(result, 3);
}