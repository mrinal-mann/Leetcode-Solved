class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minH; // Min heap

        for (int i = 0; i < nums.size(); i++) {
            minH.push(nums[i]);
            if (minH.size() > k)
                minH.pop();
        }
        return minH.top();
    }
};