// LeetCode 3945 - Digit Frequency Score
// Approach: Digit Extraction + Sum
// Time: O(log n) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        int sum = 0;

        while (n) {
            sum += n % 10;
            n = n / 10;
        }

        return sum;
    }
};

int main() {
    Solution sol;

    cout << sol.digitFrequencyScore(122) << endl; // 5
    cout << sol.digitFrequencyScore(101) << endl; // 2

    return 0;
}
