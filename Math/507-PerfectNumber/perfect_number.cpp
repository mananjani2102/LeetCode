// LeetCode 507 - Perfect Number
// Approach: Divisor Pairs (sqrt optimization)
// Time: O(sqrt(n)) | Space: O(1)

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;

        int sum = 1;

        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};

int main() {
    Solution sol;

    cout << sol.checkPerfectNumber(28) << endl; // 1 (true)
    cout << sol.checkPerfectNumber(7) << endl;  // 0 (false)

    return 0;
}
