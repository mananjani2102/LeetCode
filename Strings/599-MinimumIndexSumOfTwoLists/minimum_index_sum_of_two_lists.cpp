// LeetCode 599 - Minimum Index Sum of Two Lists
// Approach: HashMap Index Tracking
// Time: O(n+m) | Space: O(n)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;

        for (int i = 0; i < (int)list1.size(); i++) {
            indexMap[list1[i]] = i;
        }

        vector<string> result;
        int minSum = INT_MAX;

        for (int j = 0; j < (int)list2.size(); j++) {
            if (indexMap.count(list2[j])) {
                int sum = indexMap[list2[j]] + j;

                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(list2[j]);
                }
                else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> list1a = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2a = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> r1 = sol.findRestaurant(list1a, list2a);
    for (string s : r1) cout << s << " ";
    cout << endl; // Shogun

    vector<string> list1c = {"happy", "sad", "good"};
    vector<string> list2c = {"sad", "happy", "good"};
    vector<string> r3 = sol.findRestaurant(list1c, list2c);
    for (string s : r3) cout << s << " ";
    cout << endl; // sad happy

    return 0;
}
