#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp = {{NULL, NULL}};

        Node *res, *curr = head;
        while (curr != NULL)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        Node *copy;
        while (curr != NULL)
        {
            copy = mp[curr];
            copy->next = mp[curr->next];
            copy->random = mp[curr->random];
            curr = curr->next;
        }
        return mp[head];
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

TEST_F(SolutionTest, test_001)
{
    string word1 = "";
    string word2 = "";
    bool result = solution.closeStrings(word1, word2);
    ASSERT_TRUE(result);
}
