#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename T>
void print2DVector(std::vector<T> &vec)
{
    std::cout << "[\n";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "  [";
        for (size_t j = 0; j < vec[i].size(); ++j)
        {
            std::cout << vec[i][j];
            if (j != vec[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
    std::cout << "]\n";
}

template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "[\n";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

void printLinkedList(ListNode *root)
{
    ListNode *curr = root;
    while (curr != NULL)
    {
        std::cout << curr->val;
        if (curr->next != NULL)
        {
            std::cout << " + ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

ListNode *createLinkedList(int input[], int length)
{
    ListNode *head = NULL;
    ListNode *curr = NULL;

    // int length = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < length; i++)
    {
        ListNode *newNode = new ListNode(input[i]);
        if (head == nullptr)
        {
            head = newNode;
            curr = newNode;
        }
        else
        {
            curr->next = newNode;
            curr = curr->next;
        }
    }
    return head;
}

bool compareLinkedList(ListNode *a, ListNode *b)
{
    ListNode *ca = a, *cb = b;
    while (ca)
    {
        if (!cb)
        {
            return false;
        }
        if (ca->val != cb->val)
        {
            return false;
        }
        ca = ca->next;
        cb = cb->next;
    }
    return !cb;
}

template <typename T>
bool compareVectors(const std::vector<T> &a, const std::vector<T> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

// TreeNode *createBinaryTreeFromVector(vector<int> input)
// {
//     int size = 1;
//     vector<TreeNode *> previousLevel;
//     previousLevel
//     for (size_t i = 0; i < input.size(); i++)
//     {
//         if (input[i] != 999)
//         {
//             TreeNode *newTreeNode = new TreeNode(input[i]);
//         }
//     }
// }