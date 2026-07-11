// LeetCode 349 - Intersection of Two Arrays
// Approach: HashSet
// Time: O(n+m) | Space: O(n+m)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution sol;

    vector<int> n1a = {1, 2, 2, 1};
    vector<int> n2a = {2, 2};
    vector<int> r1 = sol.intersection(n1a, n2a);
    for (int x : r1) cout << x << " ";
    cout << endl; // 2

    vector<int> n1b = {4, 9, 5};
    vector<int> n2b = {9, 4, 9, 8, 4};
    vector<int> r2 = sol.intersection(n1b, n2b);
    for (int x : r2) cout << x << " ";
    cout << endl; // 9 4 (any order)

    return 0;
}
