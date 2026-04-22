class Solution {
   public:
    vector<int> dp;
    int f(vector<int>& nums, int i) {
        int n = nums.size();
        if (i >= n) return 0;
        if (i == n - 1) return nums[i];
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(f(nums, i + 1), nums[i] + f(nums, i + 2));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size() + 2, -1);
        return f(nums, 0);
    }
};