#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *quick = head, *slow = head;

        while (quick != nullptr && quick->next != nullptr)
        {

            quick = quick->next->next;
            slow = slow->next;
            if (quick == slow)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // createLinkedList()
    //     solution.hasCycle();
}