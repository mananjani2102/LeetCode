// LeetCode 3499 - Maximize Active Section with Trade I
// Approach: Block Compression + Greedy
// Time: O(n) | Space: O(n)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for (char ch : s) {
            if (ch == '1')
                ones++;
        }

        string t = "1" + s + "1";

        vector<char> blockChar;
        vector<int> blockLen;

        int i = 0;

        while (i < (int)t.size()) {
            char ch = t[i];
            int len = 0;

            while (i < (int)t.size() && t[i] == ch) {
                len++;
                i++;
            }

            blockChar.push_back(ch);
            blockLen.push_back(len);
        }

        int maxGain = 0;

        for (int i = 1; i + 1 < (int)blockChar.size(); i++) {

            if (blockChar[i] == '1' &&
                blockChar[i - 1] == '0' &&
                blockChar[i + 1] == '0') {

                int gain = blockLen[i - 1] + blockLen[i + 1];
                maxGain = max(maxGain, gain);
            }
        }

        return ones + maxGain;
    }
};

int main() {
    Solution sol;

    cout << sol.maxActiveSectionsAfterTrade("01") << endl;      // 1
    cout << sol.maxActiveSectionsAfterTrade("0100") << endl;    // 4
    cout << sol.maxActiveSectionsAfterTrade("1000100") << endl; // 7
    cout << sol.maxActiveSectionsAfterTrade("01010") << endl;   // 4

    return 0;
}
