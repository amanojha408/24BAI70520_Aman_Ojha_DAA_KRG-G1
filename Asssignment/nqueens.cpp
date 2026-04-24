#include <bits/stdc++.h>
using namespace std;

class NQueens {
public:
    int n;
    vector<vector<string>> solutions;
    vector<int> col, diag1, diag2;

    void solve(int row, vector<string>& board) {
        // Base case: all queens placed
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            // Check if position is safe using hashing arrays (O(1))
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            // Place queen
            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

            // Recursive call for next row
            solve(row + 1, board);

            // Backtrack
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }

    void solveNQueens(int N) {
        n = N;
        vector<string> board(n, string(n, '.'));

        // Initialize hashing arrays
        col.resize(n, 0);
        diag1.resize(2*n, 0);
        diag2.resize(2*n, 0);

        solve(0, board);

        cout << "Total solutions: " << solutions.size() << endl;

        for (auto &sol : solutions) {
            for (auto &row : sol)
                cout << row << endl;
            cout << endl;
        }
    }
};

int main() {
    NQueens obj;
    obj.solveNQueens(4);
}

/*
TIME COMPLEXITY:
- Worst case: O(N!)
  Reason: For each row, we try up to N columns and recursively explore possibilities.
  This forms a permutation tree (factorial growth).

- Safety check: O(1) due to hashing (col, diag arrays)

SPACE COMPLEXITY:
- O(N) recursion stack depth
- O(N) for hashing arrays (col, diag1, diag2)
- O(N^2) for storing board (each solution)

Overall auxiliary space: O(N)
(Excluding output storage)
*/
