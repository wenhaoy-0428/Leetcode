#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> &ratings)
{
    int minTotal = 0;
    int prevCost = 1;
    size_t size = ratings.size();
    for (size_t i = 0; i < size;)
    {
        // calculate the number continuous decreasing ratings
        int j = 1;
        while (i + j < size && ratings[i + j] < ratings[i + j - 1])
        {
            minTotal += j;
            j++;
        }

        // for 12345421, when iterating, 5421, the cost the same as 5 + 3 + 2 + 1
        // which is the same as 1 + 2 + 3, hence, the above iteration is a backwards of the actual cost.

        int cost = 0;
        // for current rate greater than the previous block
        if (i > 1 && ratings[i] > ratings[i - 1])
        {
            cost = max(prevCost + 1, j);
        }
        else
        {
            // for current rate is less than or equal to teh prev rate.
            // actually, this code snippet will only run when current rate is equal
            // to the prev one.
            cost = max(1, j);
        }
        // cout << cost << endl;
        minTotal += cost;

        // when we actually have some continuous decreasing block, since we skip all of them
        // all the way to cost 1.
        if (j > 1)
        {
            prevCost = 1;
        }
        else
        {
            prevCost = cost;
        }

        // we always skip the number of continuous decreasing block.
        i += j;
    }
    return minTotal;
}

int main()
{
    vector<int> ratings = {1, 0, 2};
    cout << candy(ratings) << endl;
}
