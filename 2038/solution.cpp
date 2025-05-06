#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include "../util/util.h"

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        vector<int> alice;
        vector<int> bob;
        int bob_l = -1, bob_r = 0;
        int alice_l = -1, alice_r = 0;
        int alice_len = 0, bob_len = 0;
        for (size_t i = 0; i < colors.length(); i++)
        {
            if (colors[i] == 'A')
            {
                alice_r = i;

                bob_len = bob_r - bob_l;
                if (bob_len >= 3)
                {
                    bob.push_back(bob_len);
                }

                bob_l = i;
                bob_r = i;
            }
            else
            {
                bob_r = i;

                alice_len = alice_r - alice_l;
                if (alice_len >= 3)
                {
                    alice.push_back(alice_len);
                }
                alice_l = i;
                alice_r = i;
            }
        }
        if (bob_r - bob_l >= 3)
        {
            bob.push_back(bob_r - bob_l);
        }
        if (alice_r - alice_l >= 3)
        {
            alice.push_back(alice_r - alice_l);
        }

        while (bob.size() != 0 && alice.size() != 0)
        {
            alice.back() -= 1;
            if (alice.back() <= 2)
            {
                alice.pop_back();
            }
            bob.back() -= 1;
            if (bob.back() <= 2)
            {
                bob.pop_back();
            }
        }
        return alice.size() > 0;
    }
};

int main()
{
    Solution solution;
    cout << solution.winnerOfGame("AAAABBBB") << endl;
}