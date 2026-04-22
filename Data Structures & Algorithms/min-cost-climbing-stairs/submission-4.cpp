class Solution {
public:
    int fbu(vector<int>&cost) {
        int n = cost.size();
        vector<int>dp(n+2);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1; i>=0; i--) {
            dp[i] = min(cost[i]+dp[i+1], cost[i]+dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return fbu(cost);
    }
};
