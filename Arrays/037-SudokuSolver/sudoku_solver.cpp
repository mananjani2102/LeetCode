// LeetCode 37 - Sudoku Solver
// Approach: Backtracking
// Time: O(9^(n*n)) worst case | Space: O(n*n) recursion stack

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};

void printBoard(vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sol.solveSudoku(board);
    printBoard(board);
    // Expected:
    // 5 3 4 6 7 8 9 1 2
    // 6 7 2 1 9 5 3 4 8
    // 1 9 8 3 4 2 5 6 7
    // 8 5 9 7 6 1 4 2 3
    // 4 2 6 8 5 3 7 9 1
    // 7 1 3 9 2 4 8 5 6
    // 9 6 1 5 3 7 2 8 4
    // 2 8 7 4 1 9 6 3 5
    // 3 4 5 2 8 6 1 7 9

    return 0;
}
