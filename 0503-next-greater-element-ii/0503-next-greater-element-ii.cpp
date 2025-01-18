class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, -1); // Initialize the result with -1
        stack<int> st;         // Monotonic decreasing stack

        for (int i = 2 * N - 1; i >= 0; i--) {
            // Ensure stack only contains greater elements
            while (!st.empty() && st.top() <= nums[i % N]) {
                st.pop();
            }
            // Update the result for the first pass (i < N)
            if (i < N) {
                ans[i] = st.empty() ? -1 : st.top();
            }
            // Push current element into the stack
            st.push(nums[i % N]);
        }

        return ans;
    }
};
