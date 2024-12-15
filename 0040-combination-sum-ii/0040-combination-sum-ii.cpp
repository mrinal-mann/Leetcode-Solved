class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        // If target becomes zero, add the current combination to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break; // Stop if the number exceeds the target

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Include the current candidate
            current.push_back(candidates[i]);

            // Recur with next index as i + 1
            helper(candidates, target - candidates[i], i + 1, current, result);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Sort to handle duplicates and facilitate pruning
        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, current, result);
        return result;
    }
};

