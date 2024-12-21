class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(solve(board)) {
                                return true;
                            }
                            board[i][j] = '.'; // Undo and try next
                        }
                    }
                    return false;  // No valid number found
                }
            }
        }
        return true;  // Solved
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == ch) return false;  // Check column
            if(board[row][i] == ch) return false;  // Check row
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;  // Check 3x3 box
        }
        return true;
    }
};
