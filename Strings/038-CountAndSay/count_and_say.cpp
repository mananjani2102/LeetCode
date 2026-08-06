// LeetCode 38 - Count and Say
// Approach: Iterative Run-Length Encoding
// Time: O(n * m) where m = string length | Space: O(m)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; i++) {
            string next = "";
            int j = 0;

            while (j < (int)result.size()) {
                char currentChar = result[j];
                int count = 0;

                while (j < (int)result.size() && result[j] == currentChar) {
                    count++;
                    j++;
                }

                next += to_string(count) + currentChar;
            }

            result = next;
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.countAndSay(4) << endl; // 1211
    cout << sol.countAndSay(1) << endl; // 1

    return 0;
}
