// LeetCode 67 - Add Binary
// Approach: Bit by Bit Addition with Carry
// Time: O(max(n,m)) | Space: O(max(n,m))

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.addBinary("11", "1") << endl;     // 100
    cout << sol.addBinary("1010", "1011") << endl; // 10101

    return 0;
}
