#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode *l = NULL, *ll = NULL, *r = NULL, *rr = NULL, *curr = head;
        for (int i = 1; i < left; i++)
        {
            ll = curr;
            curr = curr->next;
        }
        l = curr;
        for (int i = left; i < right; i++)
        {
            curr = curr->next;
        }
        r = curr;
        rr = curr->next;
        ListNode *n1 = l, *n2 = l->next, *temp;
        for (int i = left; i < right; i++)
        {
            temp = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = temp;
        }
        if (ll)
        {
            ll->next = r;
        }
        else
        {
            head = r;
        }

        l->next = rr;
        return head;
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
