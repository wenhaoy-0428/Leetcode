#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class SolutionFailed
{
public:
	string removeDuplicateLetters(string s)
	{
		sort(s.begin(), s.end());

		string result = "";
		result += s[0];

		for (size_t i = 1; i < s.length(); i++)
		{
			if (s[i] != s[i - 1])
			{
				result += s[i];
			}
		}
		return result;
	}
};

class Solution
{
public:
	string removeDuplicateLetters(string s)
	{
		unordered_map<char, int> oc;
		priority_queue<char, vector<char>, greater<char>> rank;
		for (int i = 0; i < s.length(); i++)
		{
			oc[s[i]]++;
			if (oc[s[i]] == 1)
			{
				rank.push(s[i]);
			}
		}

		string result;
		for (int i = 0; i < s.length(); i++)
		{
			// unique char with lowest rank
			if (oc[s[i]] <= 0)
			{
				continue;
			}
			char l = rank.top();
			cout << l << s[i] << endl;
			if (s[i] <= l)
			{
				result += s[i];
				cout << "1" << endl;
				oc[s[i]] = 0;

				if (s[i] == l)
				{
					cout << "2" << endl;
				}
			}

			if (oc[s[i]] == 1)
			{
				cout << "3" << endl;
				result += s[i];
			}

			oc[s[i]]--;
		}
		return result;
	}
};

int main()
{
	Solution solution;
	cout << solution.removeDuplicateLetters("cbacdcbc") << endl;
}
