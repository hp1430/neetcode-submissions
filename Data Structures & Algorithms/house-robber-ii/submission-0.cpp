class Solution {
public:
    vector<int>dp;
    int f(vector<int>&nums, int i, int end) {
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(f(nums, i+1, end), nums[i]+f(nums, i+2, end));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        dp.clear();
        dp.resize(n+5, -1);
        int case1 = f(nums, 0, n-2);
        dp.clear();
        dp.resize(n+5, -1);
        int case2 = f(nums, 1, n-1);
        return max(case1, case2);
    }
};
