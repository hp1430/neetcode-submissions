class Solution {
public:
    vector<int>dp;
    int f(vector<int>&cost, int i) {
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = min(cost[i]+f(cost, i+1), cost[i]+f(cost, i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.clear();
        dp.resize(cost.size()+1, -1);
        return min(f(cost, 0), f(cost, 1));
    }
};
