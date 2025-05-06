#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class MyHashMap
{

private:
    vector<vector<pair<int, int>>> map;
    const size_t size = 1000;

    int hash(int key)
    {
        return key % size;
    }

public:
    MyHashMap()
    {
        map.resize(size);
    }

    void put(int key, int value)
    {
        int idx = hash(key);

        for (auto &pair : map[idx])
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        map[idx].push_back(pair<int, int>(key, value));
    }

    int get(int key)
    {
        int idx = hash(key);
        for (auto const &pair : map[idx])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int idx = hash(key);
        for (auto it = map[idx].begin(); it != map[idx].end(); it++)
        {
            if (it->first == key)
            {
                map[idx].erase(it);
                return;
            }
        }
    }
};

int main()
{
}