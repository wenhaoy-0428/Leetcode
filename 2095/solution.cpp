#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        int n = 0;
        ListNode *curr = head;
        while (curr)
        {
            curr = curr->next;
            n++;
        }
        if (n == 1)
        {
            return nullptr;
        }

        int mid = -1;

        if (n % 2 == 0)
        {
            mid = (n + 1) / 2;
        }
        else
        {
            mid = n / 2;
        }
        curr = head;
        for (int i = 0; i < mid - 1; i++)
        {
            curr = curr->next;
        }
        // ListNode *next = curr->next->next;
        curr->next = curr->next->next;
        return head;
    }
};

class SolutionTest : public testing::Test
{
protected:
    Solution solution;
};

// TEST_F(SolutionTest, test_001)
// {
//     int input[] = {1, 3, 4, 7, 1, 2, 6};
//     int expV[] = {1, 3, 4, 1, 2, 6};
//     ListNode *exp = createLinkedList(expV, 6);
//     ListNode *head = createLinkedList(input, 7);
//     ListNode *result = solution.deleteMiddle(head);

//     ASSERT_TRUE(compareLinkedList(exp, result));
// }

TEST_F(SolutionTest, test_002)
{
    int input[] = {1};
    int expV[] = {};
    ListNode *exp = createLinkedList(expV, 0);
    ListNode *head = createLinkedList(input, 1);
    ListNode *result = solution.deleteMiddle(head);

    ASSERT_TRUE(compareLinkedList(exp, result));
}