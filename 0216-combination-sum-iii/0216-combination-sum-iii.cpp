class Solution {
public:

    void helper(int start, int k, int target, vector<int>& current, vector<vector<int>>& result) {
        // Base case: If we've selected k numbers and the target is zero, add the current combination
        if (current.size() == k && target == 0) {
            result.push_back(current);
            return;
        }

        // If the target goes below zero or we select too many numbers, stop recursion
        if (target < 0 || current.size() > k) {
            return;
        }

        // Iterate through numbers 1 to 9, starting from the given index
        for (int i = start; i <= 9; i++) {
            current.push_back(i); // Include the current number
            helper(i + 1, k, target - i, current, result); // Recur for the next numbers
            current.pop_back(); // Backtrack to explore other combinations
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result; // To store all valid combinations
        vector<int> current;       // To store the current combination being built
        helper(1, k, n, current, result); // Start the recursion with the first number
        return result;
    }
};