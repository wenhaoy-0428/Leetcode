#include <iostream>

using namespace std;
bool isSubsequence(string s, string t)
{
    int idx1 = 0;

    for (int i = 0; i < t.length(); i++)
    {

        if (t[i] == s[idx1])
        {
            idx1++;
        }
        if (idx1 == s.length())
        {
            return true;
        }
    }
    return idx1 == s.length();
}
int main() {}
