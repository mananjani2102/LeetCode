// LeetCode 1502 - Can Make Arithmetic Progression From Sequence
// Approach: Sort + Check Equal Differences
// Time: O(n log n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];

        for (int i = 2; i < (int)arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {3, 5, 1};
    cout << sol.canMakeArithmeticProgression(arr1) << endl; // 1 (true)

    vector<int> arr2 = {1, 2, 4};
    cout << sol.canMakeArithmeticProgression(arr2) << endl; // 0 (false)

    return 0;
}
