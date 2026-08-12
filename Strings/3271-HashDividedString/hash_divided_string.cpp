// LeetCode 3271 - Hash Divided String
// Approach: Chunk Processing with Sum and Modulo
// Time: O(n) | Space: O(n/k) for output

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int n = s.size();

        for (int i = 0; i < n; i += k) {
            int sum = 0;

            for (int j = i; j < i + k; j++) {
                sum += (s[j] - 'a');
            }

            int hashedChar = sum % 26;
            result += (char)('a' + hashedChar);
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.stringHash("abcd", 2) << endl; // bf
    cout << sol.stringHash("mxz", 3) << endl;   // i

    return 0;
}
