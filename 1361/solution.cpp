class Solution
{
public:
    bool helper(int root, vector<int> &left, vector<int> &right, vector<int> &visited)
    {
        if (visited[root])
        {
            return false;
        }
        visited[root] = 1;
        int next = left[root];
        if (next >= 0)
        {
            if (helper(next, left, right, visited) == false)
            {
                return false;
            }
        }

        next = right[root];
        if (next >= 0)
        {
            if (helper(next, left, right, visited) == false)
            {
                return false;
            }
        }

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<bool> pointed(n, false);
        for (size_t i = 0; i < n; i++)
        {
            if (leftChild[i] >= 0)
            {
                pointed[leftChild[i]] = true;
            }
            if (rightChild[i] >= 0)
            {
                pointed[rightChild[i]] = true;
            }
        }

        int root = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (pointed[i] == false)
            {
                root = i;
            }
        }

        vector<int> visited(n, 0);
        bool result = helper(root, leftChild, rightChild, visited);
        return result && accumulate(visited.begin(), visited.end(), 0) == n;
    }
};