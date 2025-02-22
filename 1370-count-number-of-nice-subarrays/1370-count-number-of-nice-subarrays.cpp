class Solution {
public:
int solve(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int sum = 0, cnt = 0,l = 0,r = 0, n = nums.size();
        while(r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
    return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};