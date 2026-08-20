// LeetCode 73 - Set Matrix Zeroes
// Approach: In-place Marking using First Row/Column
// Time: O(m*n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRowZero = true;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstColZero = true;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowZero)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};

void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;

    vector<vector<int>> m1 = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(m1);
    printMatrix(m1); // [1,0,1] [0,0,0] [1,0,1]

    cout << "---" << endl;

    vector<vector<int>> m2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(m2);
    printMatrix(m2); // [0,0,0,0] [0,4,5,0] [0,3,1,0]

    return 0;
}
