#include <iostream>

using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        string result;
        int idx = 0;
        while (result.length() < k)
        {
            if (isdigit(s[idx]))
            {

                string temp = result;
                // cout << "temp: " << temp << "-" << s[idx] << endl;
                for (int i = 0; i < s[idx] - '1'; i++)
                {
                    for (int i = 0; i < temp.length(); i++)
                    {
                        result += temp[i];
                        // cout << result << endl;
                        if (result.length() == k)
                        {
                            return string(1, temp[i]);
                        }
                    }
                }
                // cout << result << endl;
            }
            else
            {
                result += s[idx];
            }
            idx++;
        }
        // cout << result << endl;
        return string(1, result[k - 1]);
    }
};

int main()
{
    Solution solution;
    cout << solution.decodeAtIndex("a23", 6) << endl;
}
