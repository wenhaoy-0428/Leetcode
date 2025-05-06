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

		vector<int> vA, vB;

		while (curr != nullptr)
		{
			vA.push_back(curr->val);
			curr = curr->next;
		}
		curr = headB;
		while (curr != nullptr)
		{
			vB.push_back(curr->val);
			curr = curr->next;
		}
		int len = 0;
		int idxA = vA.size() - 1, idxB = vB.size() - 1;
		while (idxA >= 0 && idxB >= 0)
		{
			if (vA[idxA] != vB[idxB])
			{
				break;
			}
			idxA--;
			idxB--;
		}
		cout << idxA << "-" << idxB << endl;

		if (idxA < 0)
		{
			return headA;
		}
		if (idxB < 0)
		{
			return headB;
		}
		curr = headA;

		for (int i = 0; i < idxA + 1; i++)
		{
			curr = curr->next;
		}
		return curr;
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
