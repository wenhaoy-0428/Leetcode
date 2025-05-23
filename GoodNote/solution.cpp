#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    vector<string> split(const string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            result.push_back(item);
        }
        return result;
    }

public:
    vector<int> GetRejectedRequests(const vector<string> &requests, int limit_per_second)
    {
        // Your code here
        unordered_map<string, queue<int>> store;
        vector<int> result;
        for (int i = 0; i < requests.size(); i++)
        {
            vector<string> request = split(requests[i], ' ');
            int id = stoi(request[0]);
            string ip = request[1];
            int time = stoi(request[2]);

            if (store.find(ip) == store.end())
            {
                store[ip] = queue<int>();
                // continue;
            }
            queue<int> &q = store[ip];
            while (!q.empty() && time - q.front() > 1000)
            {
                q.pop();
            }

            if (q.size() < limit_per_second)
            {
                q.push(time);
            }
            else
            {
                result.push_back(id);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> requests = {
        // "2 192.168.50.1 50000",
        // "3 192.168.50.1 50900",
        // "4 192.168.50.1 51000",
        // "6 192.168.50.1 51500",
        "30 1 30000",
        "30 1 30000",
        "30 1 30000",
    };

    vector<int> output = solution.GetRejectedRequests(requests, 2);
    for (int id : output)
    {
        cout << id << " ";
    }
    cout << endl;
}