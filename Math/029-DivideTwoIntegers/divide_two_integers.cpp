// LeetCode 29 - Divide Two Integers
// Approach: Bit Shifting (Repeated Doubling)
// Time: O(log^2 n) | Space: O(1)

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dividendL = dividend;
        long long divisorL = divisor;

        long long dvd = (dividendL < 0) ? -dividendL : dividendL;
        long long dvs = (divisorL < 0) ? -divisorL : divisorL;

        long long result = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        bool negative = (dividend < 0) != (divisor < 0);
        return negative ? (int)(-result) : (int)result;
    }
};

int main() {
    Solution sol;

    cout << sol.divide(10, 3) << endl;  // 3
    cout << sol.divide(7, -3) << endl;  // -2
    cout << sol.divide(INT_MIN, -1) << endl; // INT_MAX (2147483647)

    return 0;
}
