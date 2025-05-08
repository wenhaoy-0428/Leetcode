#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
private:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] != x)
        {
            return parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> parent(edges.size() + 1);
        for (int i = 0; i < parent.size(); ++i)
        {
            parent[i] = i;
        }
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // Find the root of the sets for u and v
            int rootU = find(parent, u);
            int rootV = find(parent, v);

            // If they are already in the same set, this edge is redundant
            if (rootU == rootV)
            {
                return {u, v};
            }

            // Union the two sets
            parent[rootU] = rootV;
        }
        return {}; // This line should never be reached if the input is valid
    };
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3}};
    vector<int> expected = {2, 3}; // The redundant connection that forms a cycle
    vector<int> result = solution.findRedundantConnection(edges);
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE((result[0] == expected[0] && result[1] == expected[1]) ||
                (result[0] == expected[1] && result[1] == expected[0]));
}
