#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int> &nums)
	{
		vector<int> e;
		vector<int> o;

		for (auto const &num : nums)
		{
			if (num % 2 == 0)
			{
				e.push_back(num);
			}
			else
			{
				o.push_back(num);
			}
		}
		for (auto const &od : o)
		{
			e.push_back(od);
		}
		return e;
	}
};

int main()
{
	Solution solution;
	solution.
}
