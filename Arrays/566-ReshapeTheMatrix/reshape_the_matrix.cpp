// LeetCode 566 - Reshape the Matrix
// Approach: Flatten Index Mapping
// Time: O(m*n) | Space: O(r*c) for output

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c) return mat;

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            result[i / c][i % c] = mat[i / n][i % n];
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    vector<vector<int>> r1 = sol.matrixReshape(mat1, 1, 4);
    for (auto& row : r1) {
        for (int x : row) cout << x << " ";
    }
    cout << endl; // 1 2 3 4

    vector<vector<int>> mat2 = {{1, 2}, {3, 4}};
    vector<vector<int>> r2 = sol.matrixReshape(mat2, 2, 4);
    for (auto& row : r2) {
        for (int x : row) cout << x << " ";
        cout << "| ";
    }
    cout << endl; // 1 2 | 3 4 | (unchanged, invalid reshape)

    return 0;
}
