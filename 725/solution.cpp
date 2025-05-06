#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 0;
        while (curr != nullptr)
        {
            len++;
            curr = curr->next;
        }

        curr = head;

        vector<ListNode *> result;
        int remain = k;
        while (result.size() != k)
        {
            int size = 0;
            if (len > remain)
            {
                size = len / remain + 1 * (len % remain != 0);
            }
            else
            {
                size = 1;
            }
            len -= size;
            remain--;

            ListNode *tempHead = curr;
            for (int i = 0; i < size - 1; i++)
            {
                if (curr)
                {
                    curr = curr->next;
                }
            }
            if (curr)
            {
                ListNode *temp = curr;
                curr = curr->next;
                temp->next = nullptr;
            }
            result.push_back(tempHead);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int nums[] = {1, 2, 3, 4};
    ListNode *head = createLinkedList(nums, 4);
    vector<ListNode *> result = solution.splitListToParts(head, 5);
    for (auto const &node : result)
    {
        printLinkedList(node);
    }
}