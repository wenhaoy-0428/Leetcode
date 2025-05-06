#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	char findTheDifference(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		int idx1 = 0, idx2 = 0;

		while (s[idx1] == t[idx2])
		{
			idx1++;
			idx2++;
		}

		return t[idx2];
	}
};

int main()
{
	Solution solution;
	string s = "abcd", t = "acbde";
	cout << solution.findTheDifference(s, t) << endl;
}
