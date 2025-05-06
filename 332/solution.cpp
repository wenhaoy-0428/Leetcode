#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "../util/util.h"
using namespace std;

vector<string> helper(unordered_map<string, vector<string>> &graph, string currStop, int numTickets)
{

    size_t size = graph[currStop].size();
    vector<string> result;
    result.push_back(currStop);
    cout << currStop << "with" << size << '-' << numTickets << endl;
    for (size_t i = 0; i < graph[currStop].size(); i++)
    {
        string nextStop = graph[currStop][i];
        graph[currStop].erase(graph[currStop].begin() + i);

        vector<string> temp = helper(graph, nextStop, numTickets - 1);
        if (temp.size() == numTickets)
        {
            // graph[currStop].insert(graph[currStop].begin() + i, nextStop);
            result.insert(result.end(), temp.begin(), temp.end());
            return result;
        }
        graph[currStop].insert(graph[currStop].begin() + i, nextStop);
    }

    return result;
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    // construct graph
    unordered_map<string, vector<string>> graph;

    for (size_t i = 0; i < tickets.size(); i++)
    {
        string src = tickets[i][0];
        string dest = tickets[i][1];
        graph[src].push_back(dest);
    }

    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }

    return helper(graph, "JFK", tickets.size());
}

int main()
{
    vector<vector<string>> tickets = {{"JFK", "KUL"},
                                      {"JFK", "NRT"},
                                      {"NRT", "JFK"}};
    vector<string> result = findItinerary(tickets);
    printVector(result);
}
