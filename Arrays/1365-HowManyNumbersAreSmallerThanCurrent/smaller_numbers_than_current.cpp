// LeetCode 1365 - How Many Numbers Are Smaller Than the Current Number
// Approach: Counting Sort + Prefix Sum
// Time: O(n) | Space: O(1) fixed 101 size

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans;

        for (int num : nums) {
            if (num == 0)
                ans.push_back(0);
            else
                ans.push_back(freq[num - 1]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {8, 1, 2, 2, 3};
    vector<int> r1 = sol.smallerNumbersThanCurrent(n1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 4 0 1 1 3

    vector<int> n2 = {6, 5, 4, 8};
    vector<int> r2 = sol.smallerNumbersThanCurrent(n2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 2 1 0 3

    vector<int> n3 = {7, 7, 7, 7};
    vector<int> r3 = sol.smallerNumbersThanCurrent(n3);
    for (int x : r3) cout << x << " ";
    cout << endl; // 0 0 0 0

    return 0;
}
