class Solution {
public:
    vector<int>dp;
    int f(int n) {
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int a=0, b=0;
        if(n-1>=0) a = f(n-1);
        if(n-2>=0) b = f(n-2);
        return dp[n] = a+b;
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(n+1, -1);
        return f(n);
    }
};
