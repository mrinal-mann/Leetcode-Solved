class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {

            // check if the stack holds any values and compare them with array
            // values.
            while (!st.empty() && st.top() <= nums2[i]) {
                // if the values in the stack are less than the array values
                // delete them.
                st.pop();
            }
            // if stack is not empty set the value to the top.
            if (!st.empty())
                mpp[nums2[i]] = st.top();
            else
                mpp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
        vector<int> ans;
        // check for array-1 values in map and store them.
        for (int num : nums1) {
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};