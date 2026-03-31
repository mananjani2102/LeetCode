// LeetCode 344 - Reverse String
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> s1 = {'h','e','l','l','o'};
    sol.reverseString(s1);
    for (char c : s1) cout << c;
    cout << endl;  

    vector<char> s2 = {'H','a','n','n','a','h'};
    sol.reverseString(s2);
    for (char c : s2) cout << c;
    cout << endl;  

    return 0;
}