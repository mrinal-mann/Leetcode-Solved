class Solution {
public:
    // Helper function to generate subsets
    void helper(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        // Iterate through the array starting from the current index
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicates to ensure unique subsets
            if (i != index && arr[i] == arr[i - 1])
                continue;

            // Include the current element in the subset
            current.push_back(arr[i]);

            // Recursive call to build subsets starting from the next index
            helper(arr, i + 1, current, result);

            // Backtrack by removing the last added element
            current.pop_back();
        }
    }
    
    // Main function to return all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result; // Stores all subsets
        vector<int> current;       // Stores the current subset being built
        
        // Sort the array to group duplicates together
        sort(nums.begin(), nums.end());
        
        // Start generating subsets
        helper(nums, 0, current, result);
        
        return result;
    }
};
