// LeetCode 374 - Guess Number Higher or Lower
// Approach: Binary Search
// Time: O(log n) | Space: O(1)

#include <iostream>
using namespace std;

// Simulated pre-defined API for local testing
int pickedNumber;
int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0) {
                return mid;
            }
            else if (result == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    pickedNumber = 6;
    cout << sol.guessNumber(10) << endl; // 6

    pickedNumber = 1;
    cout << sol.guessNumber(1) << endl; // 1

    pickedNumber = 1;
    cout << sol.guessNumber(2) << endl; // 1

    return 0;
}
