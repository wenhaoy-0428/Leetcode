#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *h1 = l1, *h2 = l2;
        ListNode *res = new ListNode();
        ListNode *curr = res;
        while (h1 && h2)
        {
            int sum = h1->val + h2->val + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            h1 = h1->next;
            h2 = h2->next;
        }

        while (h1)
        {
            int sum = h1->val + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            h1 = h1->next;
        }

        while (h2)
        {
            int sum = h2->val + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            h2 = h2->next;
        }
        if (carry)
        {
            curr->next = new ListNode(carry);
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
