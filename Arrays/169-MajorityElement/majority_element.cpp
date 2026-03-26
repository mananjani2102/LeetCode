// LeetCode 169 - Majority Element
// Approach: Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

int main() {
    Solution obj;
    
    vector<int> nums = {2,2,1,1,1,2,2};
    
    cout << "Majority Element: " << obj.majorityElement(nums);
    
    return 0;
}