// LeetCode 401 - Binary Watch
// Approach: Brute Force + Bit Count
// Time: O(1) (fixed 12*60 iterations) | Space: O(1)

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                int bits = __builtin_popcount(hour) + __builtin_popcount(minute);

                if (bits == turnedOn) {
                    string minStr = (minute < 10) ? "0" + to_string(minute) : to_string(minute);
                    result.push_back(to_string(hour) + ":" + minStr);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> r1 = sol.readBinaryWatch(1);
    for (string s : r1) cout << s << " ";
    cout << endl;

    vector<string> r2 = sol.readBinaryWatch(9);
    cout << "Size: " << r2.size() << endl; // 0

    return 0;
}
