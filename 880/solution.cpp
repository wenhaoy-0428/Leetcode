#include <iostream>

using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long decodedLength = 0;

        for (auto const &character : s)
        {
            if (isdigit(character))
            {
                decodedLength *= (character - '0');
            }
            else
            {
                decodedLength++;
            }
        }

        for (size_t i = s.length() - 1; i >= 0; i--)
        {
            if (isdigit(s[i]))
            {
                decodedLength /= (s[i] - '0');
                k %= decodedLength;
            }
            else
            {
                if (k == 0 || k == decodedLength)
                {
                    return string(1, s[i]);
                }
                decodedLength--;
            }
        }

        // cout << result << endl;
        return "";
    }
};

int main()
{
    Solution solution;
    cout << solution.decodeAtIndex("a23", 6) << endl;
}
