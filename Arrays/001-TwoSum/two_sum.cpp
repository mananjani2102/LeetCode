// LeetCode 1 - Two Sum
// Approach: Brute Force (Nested Loops)
// Time Complexity: O(n²)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1 ; j < nums.size() ; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};