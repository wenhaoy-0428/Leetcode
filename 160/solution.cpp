#include <iostream>
#include <vector>
#include "../util/util.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curr = headA;
        int lenA = 0, lenB = 0;

        while (curr != nullptr)
        {
            curr = curr->next;
            lenA++;
        }

        curr = headB;
        while (curr != nullptr)
        {
            curr = curr->next;
            lenB++;
        }

        int diff = abs(lenB - lenA);
        ListNode *l, *s;
        if (lenB > lenA)
        {
            l = headB;
            s = headA;
        }
        else
        {
            l = headA;
            s = headB;
        }
        for (int i = 0; i < diff; i++)
        {
            l = l->next;
        }

        while (l != s)
        {
            l = l->next;
            s = s->next;
        }

        return l;
    }
};

int main()
{
    Solution solution;
    int a[] = {4, 1, 8, 4, 5};
    int b[] = {5, 6, 1, 8, 4, 5};
    ListNode *LA = createLinkedList(a, 5);
    ListNode *LB = createLinkedList(b, 6);
    cout << solution.getIntersectionNode(LA, LB)->val << endl;
}
