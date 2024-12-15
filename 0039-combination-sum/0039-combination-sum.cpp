class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // Add valid combination to the result.
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return; // Stop recursion if target is negative or index is out of bounds.
        }

        // Include the current candidate.
        current.push_back(candidates[index]);
        helper(candidates, target - candidates[index], index, current, result); // Recursive call with the same index.
        current.pop_back(); // Backtrack.

        // Exclude the current candidate.
        helper(candidates, target, index + 1, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        helper(candidates, target, 0, current, result);
        return result;
    }
};
