// LeetCode 121 - Best Time to Buy and Sell Stock
// Approach: Track Min Price + Max Profit
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices1) << endl; // 5

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices2) << endl; // 0

    return 0;
}
