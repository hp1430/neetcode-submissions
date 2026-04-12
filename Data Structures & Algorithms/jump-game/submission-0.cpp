class Solution {
    // vector<int>dp;
public:
    bool fbu(vector<int>&nums) {
        vector<bool>dp(nums.size()+1);
        dp[nums.size()-1] = true;
        for(int idx=nums.size()-2; idx>=0; idx--) {
            if(nums[idx]==0) dp[idx]=false;
            for(int i=1; i<=nums[idx]; i++) {
                if(idx+i>=nums.size()) continue;
                dp[idx] = dp[idx] | dp[idx+i];
                if(dp[idx]) break;
            }
        }
        return dp[0];
    }
    // bool jump(vector<int>&nums, int idx) {
    //     // whether we can reach the last index from i or not
    //     if(idx==nums.size()-1) return true;
    //     if(nums[idx]==0) return false;
    //     if(dp[idx]!=-1) return dp[idx];
    //     bool ans = false;
    //     for(int i=1; i<=nums[idx]; i++) {
    //         if(idx+i>=nums.size()) continue;
    //         ans = ans | jump(nums, idx+i);
    //         if(ans) break;
    //     }
    //     return dp[idx] = ans;
    // }
    bool canJump(vector<int>& nums) {
        // dp.clear();
        // dp.resize(nums.size()+1, -1);
        return fbu(nums);
    }
};
