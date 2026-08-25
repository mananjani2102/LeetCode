// LeetCode 498 - Diagonal Traverse
// Approach: Diagonal Direction Simulation
// Time: O(m*n) | Space: O(1) extra (excluding output)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int row = 0, col = 0;
        bool up = true;

        while ((int)result.size() < m * n) {
            if (up) {
                while (row >= 0 && col < n) {
                    result.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                if (col == n) { row += 2; col--; }
                else { row++; }
            } else {
                while (col >= 0 && row < m) {
                    result.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                if (row == m) { col += 2; row--; }
                else { col++; }
            }
            up = !up;
        }

        return result;
    }
};

void printResult(vector<int>& res) {
    for (int v : res) cout << v << " ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    auto r1 = sol.findDiagonalOrder(m1);
    printResult(r1); // 1 2 4 7 5 3 6 8 9

    vector<vector<int>> m2 = {{1,2},{3,4}};
    auto r2 = sol.findDiagonalOrder(m2);
    printResult(r2); // 1 2 3 4

    return 0;
}
