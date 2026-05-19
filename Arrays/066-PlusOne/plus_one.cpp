// LeetCode 66 - Plus One
// Approach: Carry Propagation
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;

    vector<int> d1 = {1, 2, 3};
    vector<int> r1 = sol.plusOne(d1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 1 2 4

    vector<int> d2 = {4, 3, 2, 1};
    vector<int> r2 = sol.plusOne(d2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 4 3 2 2

    vector<int> d3 = {9};
    vector<int> r3 = sol.plusOne(d3);
    for (int x : r3) cout << x << " ";
    cout << endl; // 1 0

    return 0;
}
