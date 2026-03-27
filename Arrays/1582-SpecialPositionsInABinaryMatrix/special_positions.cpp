// LeetCode 1582 - Special Positions in a Binary Matrix
// Approach: Row and Column Sum Precomputation
// Time: O(m * n) | Space: O(m + n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1) { row[i]++; col[j]++; }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    count++;

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {{1,0,0},{0,0,1},{1,0,0}};
    cout << sol.numSpecial(mat1) << endl;  // 1

    vector<vector<int>> mat2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << sol.numSpecial(mat2) << endl;  // 3

    return 0;
}