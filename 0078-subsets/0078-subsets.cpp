class Solution {
public:
    // Recursive function to generate subsets
    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        // Base case: if we've processed all elements in the array
        if (index == nums.size()) {
            res.push_back(subset);  // Add the current subset to the result
            return;
        }

        // **Include the current element in the subset**
        subset.push_back(nums[index]);            // Add the current element
        createSubset(nums, index + 1, res, subset);  // Recurse to process the next element

        // **Exclude the current element from the subset**
        subset.pop_back();                        // Remove the current element
        createSubset(nums, index + 1, res, subset);  // Recurse to process the next element
    }

    // Function to generate all subsets of a given array
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // To store all subsets
        vector<int> subset;          // A temporary vector to store the current subset
        createSubset(nums, 0, result, subset);  // Start recursion from the first element
        return result;  // Return the list of all subsets
    }
};
