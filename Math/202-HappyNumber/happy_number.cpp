// LeetCode 202 - Happy Number
// Approach: HashSet to Detect Cycle
// Time: O(log n) | Space: O(log n)

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};

int main() {
    Solution sol;

    cout << sol.isHappy(19) << endl; // 1 (true)
    cout << sol.isHappy(2) << endl;  // 0 (false)

    return 0;
}
