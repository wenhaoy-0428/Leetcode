#include <iostream>

using namespace std;

class Solution
{
public:
	string decodeAtIndex(string s, int k)
	{
		string result;
		for (int i = 0; i < s.length(); i++)
		{
			if (isdigit(s[i]))
			{
				string temp = result;
				for (int j = 1; j < (s[i] - '0'); j++)
				{
					result += temp;
				}
			}
			else
			{
				result += s[i];
			}
		}
		// cout << result << endl;
		return string(1, result[k - 1]);
	}
};

int main()
{
	Solution solution;
	cout << solution.decodeAtIndex("leet2code3", 10) << endl;
}
