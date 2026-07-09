// LeetCode 412 - Fizz Buzz
// Approach: Modulo Check
// Time: O(n) | Space: O(1) extra (excluding output)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> r1 = sol.fizzBuzz(15);
    for (string s : r1) cout << s << " ";
    cout << endl; // 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz

    return 0;
}
