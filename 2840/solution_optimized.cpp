#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        int freq1Even[26] = {0}, freq2Even[26] = {0};
        int freq1Odd[26] = {0}, freq2Odd[26] = {0};

        // Count characters at even and odd positions in single loop
        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                freq1Even[s1[i] - 'a']++;
                freq2Even[s2[i] - 'a']++;
            } else {
                freq1Odd[s1[i] - 'a']++;
                freq2Odd[s2[i] - 'a']++;
            }
        }

        // Compare even position frequencies
        for (int i = 0; i < 26; i++) {
            if (freq1Even[i] != freq2Even[i]) return false;
        }

        // Compare odd position frequencies
        for (int i = 0; i < 26; i++) {
            if (freq1Odd[i] != freq2Odd[i]) return false;
        }

        return true;
    }
};