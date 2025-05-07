#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{

    bool helper(unordered_map<int, vector<int>> &graph, int current, vector<int> &visited, vector<int> &res)
    {
        if (visited[current] == 1)
            return false; // Already visited
        if (visited[current] == 2)
            return true;      // Already processed
        visited[current] = 1; // Mark as visited
        for (const auto &neighbor : graph[current])
        {
            if (!helper(graph, neighbor, visited, res))
            {
                return false;
            };
        }
        visited[current] = 2;
        res.push_back(current);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> graph;
        for (const auto &prerequisite : prerequisites)
        {
            int course = prerequisite[0];
            int preCourse = prerequisite[1];
            graph[course].push_back(preCourse);
        }

        vector<int> res;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
        {
            if (visited[i] == 0)
            {
                if (!helper(graph, i, visited, res))
                {
                    return {}; // Cycle detected, return empty vector
                };
            }
        }
        return res;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> expectedOrder = {0, 1, 2, 3};
    vector<int> result = solution.findOrder(4, prerequisites);
    EXPECT_EQ(result.size(), expectedOrder.size());
    printVector(result);
}

TEST_F(SolutionTest, test_002)
{
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}}; // Cycle exists
    vector<int> expectedOrder = {};
    vector<int> result = solution.findOrder(2, prerequisites);
    EXPECT_EQ(result.size(), expectedOrder.size());
    printVector(result);
}
