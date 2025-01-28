class Solution {
private:
    int findAtMostK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0;
        int l = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findAtMostK(nums, k) - findAtMostK(nums, k - 1);
    }
};