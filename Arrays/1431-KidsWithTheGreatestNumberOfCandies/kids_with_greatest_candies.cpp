// LeetCode 1431 - Kids With the Greatest Number of Candies
// Approach: Find Max + Compare
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());

        vector<bool> result;

        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> candies1 = {2, 3, 5, 1, 3};
    vector<bool> r1 = sol.kidsWithCandies(candies1, 3);
    for (bool b : r1) cout << b << " ";
    cout << endl; // 1 1 1 0 1

    vector<int> candies2 = {4, 2, 1, 1, 2};
    vector<bool> r2 = sol.kidsWithCandies(candies2, 1);
    for (bool b : r2) cout << b << " ";
    cout << endl; // 1 0 0 0 0

    vector<int> candies3 = {12, 1, 12};
    vector<bool> r3 = sol.kidsWithCandies(candies3, 10);
    for (bool b : r3) cout << b << " ";
    cout << endl; // 1 0 1

    return 0;
}
