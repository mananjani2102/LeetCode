// LeetCode 54 - Spiral Matrix
// Approach: Boundary Tracking (Top, Bottom, Left, Right)
// Time: O(m*n) | Space: O(1) excluding output

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> r1 = sol.spiralOrder(matrix1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 1 2 3 6 9 8 7 4 5

    vector<vector<int>> matrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> r2 = sol.spiralOrder(matrix2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 1 2 3 4 8 12 11 10 9 5 6 7

    return 0;
}
