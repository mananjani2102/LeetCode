// LeetCode 1260 - Shift 2D Grid
// Approach: Flatten Index Mapping with Modulo
// Time: O(m*n) | Space: O(m*n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        k = k % total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int oldIndex = i * n + j;

                int newIndex = (oldIndex + k) % total;

                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> r1 = sol.shiftGrid(grid1, 1);
    for (auto& row : r1) {
        for (int x : row) cout << x << " ";
        cout << "| ";
    }
    cout << endl; // 9 1 2 | 3 4 5 | 6 7 8 |

    vector<vector<int>> grid2 = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    vector<vector<int>> r2 = sol.shiftGrid(grid2, 4);
    for (auto& row : r2) {
        for (int x : row) cout << x << " ";
        cout << "| ";
    }
    cout << endl; // 12 0 21 13 | 3 8 1 9 | 19 7 2 5 | 4 6 11 10 |

    return 0;
}
