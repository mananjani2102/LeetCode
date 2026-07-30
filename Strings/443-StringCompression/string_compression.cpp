// LeetCode 443 - String Compression
// Approach: Two Pointers (Read + Write in-place)
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            chars[write++] = currentChar;

            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};

int main() {
    Solution sol;

    vector<char> chars1 = {'a','a','b','b','c','c','c'};
    int len1 = sol.compress(chars1);
    cout << "Length = " << len1 << " → ";
    for (int i = 0; i < len1; i++) cout << chars1[i];
    cout << endl; // Length = 6 → a2b2c3

    vector<char> chars2 = {'a'};
    int len2 = sol.compress(chars2);
    cout << "Length = " << len2 << " → ";
    for (int i = 0; i < len2; i++) cout << chars2[i];
    cout << endl; // Length = 1 → a

    vector<char> chars3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int len3 = sol.compress(chars3);
    cout << "Length = " << len3 << " → ";
    for (int i = 0; i < len3; i++) cout << chars3[i];
    cout << endl; // Length = 4 → ab12

    return 0;
}
