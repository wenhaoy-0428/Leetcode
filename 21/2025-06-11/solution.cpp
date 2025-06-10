#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *res = new ListNode();
        ListNode *l = list1, *r = list2, *curr = res;
        while (l != NULL && r != NULL)
        {
            if (l->val < r->val)
            {
                curr->next = new ListNode(l->val);
                l = l->next;
            }
            else
            {
                curr->next = new ListNode(r->val);
                r = r->next;
            }
            curr = curr->next;
        }
        while (l != NULL)
        {
            curr->next = new ListNode(l->val);
            l = l->next;
            curr = curr->next;
        }
        while (r != NULL)
        {
            curr->next = new ListNode(r->val);
            r = r->next;
            curr = curr->next;
        }
        return res->next;
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
