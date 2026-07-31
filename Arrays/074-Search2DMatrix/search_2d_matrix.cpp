// LeetCode 74 - Search a 2D Matrix
// Approach: Binary Search (treat matrix as flattened 1D array)
// Time: O(log(m*n)) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << sol.searchMatrix(matrix1, 3) << endl;  // 1 (true)
    cout << sol.searchMatrix(matrix1, 13) << endl; // 0 (false)

    return 0;
}
