#include <iostream>
#include "../util/util.h"

using namespace std;

ListNode *partition(ListNode *head, int x)
{

    ListNode *newHead = new ListNode(-1, head);
    ListNode *prev = newHead;
    ListNode *injection = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val >= x && injection == NULL)
        {
            injection = prev;
        }

        if (curr->val < x && injection != NULL)
        {
            ListNode *temp = injection->next;
            injection->next = curr;
            prev->next = curr->next;
            curr->next = temp;
            injection = injection->next;
        }

        prev = curr;
        curr = curr->next;
    }

    return newHead->next;
}

int main()
{
    int array[] = {1, 4, 3, 2, 5, 2};
    ListNode *target = createLinkedList(array, 6);
    printLinkedList(target);

    ListNode *newList = partition(target, 3);
    printLinkedList(newList);
}