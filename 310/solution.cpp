#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
    void helper(unordered_map<int, vector<int>> &graph, int curr, vector<int> &visited, vector<int> &path, vector<int> &longest_path)
    {
        visited[curr] = 1;
        path.push_back(curr);
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (!visited[graph[curr][i]])
            {
                helper(graph, graph[curr][i], visited, path, longest_path);
            }
        }
        if (path.size() > longest_path.size())
        {
            longest_path = path;
        }
        path.pop_back();
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n - 1; i++)
        {
            int l = edges[i][0];
            int r = edges[i][1];
            graph[l].push_back(r);
            graph[r].push_back(l);
        }
        vector<int> path = {};
        vector<int> visited(n, 0);
        vector<int> longest_path;
        helper(graph, 0, visited, path, longest_path);

        int a = longest_path.back();
        visited = vector<int>(n, 0);
        longest_path = {};
        path = {};
        helper(graph, a, visited, path, longest_path);
        vector<int> res;
        int mid = longest_path.size() / 2;
        if (longest_path.size() % 2 == 0)
        {
            res = {longest_path[mid - 1], longest_path[mid]};
        }
        else
        {
            res = {longest_path[mid]};
        }

        return res;
    }
};