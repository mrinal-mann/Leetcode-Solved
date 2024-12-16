class Solution {
public:
    // Recursive function to solve the N-Queens problem
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        // Base case: If we have placed a queen in each column, we have found a solution
        if(col == n) {
            ans.push_back(board); // Add the current board configuration as a solution
            return;
        }

        // Try placing a queen in each row of the current column
        for(int row = 0;row<n;row++) {
            // Check if the current position is safe (no other queen attacks it)
            if(leftRow[row] == 0 && upperDiagonal[n-1 + col - row] == 0 && lowerDiagonal[row + col] == 0) {
                // Place a queen on the board
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;

                // Recursively solve the problem for the next column
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack by removing the queen from the current position
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }

public:
    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Vector to store all solutions
        vector<string> board(n, string(n, '.')); // Initialize the board with empty squares
        vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0); // Vectors to track occupied positions
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // Call the recursive solve function
        return ans; // Return the vector of all solutions
    }
};