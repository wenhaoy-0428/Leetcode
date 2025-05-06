#include <vector>
#include <set>
#include <iostream>

using namespace std;

void printVector(const std::vector<int> &vec)
{
    for (const auto &element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void helper(set<vector<int>> &bag, vector<int> input, int n)
{
    if (n == input.size() - 1)
    {
        printVector(input);
        if (bag.count(input) == 0)
        {
            bag.insert(input);
        }
        return;
    }

    // helper(bag, input, n + 1);
    for (int i = n; i < input.size(); i++)
    {
        swap(input[n], input[i]);
        helper(bag, input, n + 1);
    }
}

int main()
{
    set<vector<int>> bag;
    vector<int> input = vector<int>{1, 2, 3, 4};

    helper(bag, input, 0);
}
