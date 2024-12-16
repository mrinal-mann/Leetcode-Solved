class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPali(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false; // Not a palindrome if characters don't match
            }
            start++; // Move start pointer forward
            end--;   // Move end pointer backward
        }
        return true; // Return true if the substring is a palindrome
    }
    
    // Recursive function to find all palindrome partitions
    void helper(int index, string s, vector<string>& path, vector<vector<string>>& result) {
        // Base case: if the current index reaches the end of the string
        if (index == s.size()) {
            result.push_back(path); // Add the current partition to the result
            return;
        }
        // Iterate through the string to find palindromic substrings
        for (int i = index; i < s.length(); i++) {
            // Check if the substring from index to i is a palindrome
            if (isPali(s, index, i)) {
                // Add the palindrome substring to the current path
                path.push_back(s.substr(index, i - index + 1));
                // Recur for the remaining substring starting from i + 1
                helper(i + 1, s, path, result);
                // Backtrack: remove the last added substring to try other possibilities
                path.pop_back();
            }
        }
    }
    
    // Main function to return all palindrome partitions of a given string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result; // To store all the partitions
        vector<string> path; // To store the current partition
        helper(0, s, path, result); // Start the recursion from index 0
        return result; // Return the result containing all partitions
    }
};
