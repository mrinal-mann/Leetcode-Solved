class Solution {
public:
    // Backtracking helper function to search for the word starting from cell (i, j)
    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        int m = board.size();  // Get the number of rows in the board
        int n = board[0].size();  // Get the number of columns in the board
        
        // If we've matched the entire word, return true
        if(k == word.length()) {
            return true;
        }
        
        // If out of bounds or current cell doesn't match the current character in word, return false
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }
        
        char temp = board[i][j];  // Store the current character
        board[i][j] = '\0';  // Mark the cell as visited (in place)
        
        // Search in all 4 directions (down, up, right, left)
        bool found = backtrack(board, word, i + 1, j, k + 1) ||
                     backtrack(board, word, i - 1, j, k + 1) ||
                     backtrack(board, word, i, j + 1, k + 1) ||
                     backtrack(board, word, i, j - 1, k + 1);
        
        board[i][j] = temp;  // Restore the original character in the cell
        
        // Return whether the word was found in any of the four directions
        return found;
    }

    // Main function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();  // Get the number of rows
        int n = board[0].size();  // Get the number of columns
        
        // Iterate through each cell in the board
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // Start the backtracking search if the word matches at the current cell
                if(backtrack(board, word, i, j, 0)) {
                    return true;  // If word is found, return true
                }
            }
        }
        
        return false;  // If no match is found, return false
    }
};
