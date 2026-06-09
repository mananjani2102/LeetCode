// LeetCode 1748 - Sum of Unique Elements
// Approach: Frequency Array
// Time: O(n) | Space: O(1) fixed 101 size

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;
        }

        int sum = 0;

        for (int i = 1; i <= 100; i++) {
            if (freq[i] == 1) {
                sum += i;
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {1, 2, 3, 2};
    cout << sol.sumOfUnique(n1) << endl; // 4

    vector<int> n2 = {1, 1, 1, 1, 1};
    cout << sol.sumOfUnique(n2) << endl; // 0

    vector<int> n3 = {1, 2, 3, 4, 5};
    cout << sol.sumOfUnique(n3) << endl; // 15

    return 0;
}
