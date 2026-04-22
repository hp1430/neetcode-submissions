class Solution {
public:
    int fbu(int num) {
        vector<int>dp(num+1, 0);
        dp[0]=1;
        for(int n=1; n<=num; n++) {
            int a=0, b=0;
            if(n-1>=0) a=dp[n-1];
            if(n-2>=0) b=dp[n-2];
            dp[n]=a+b;
        }
        return dp[num];
    }
    int climbStairs(int n) {
        return fbu(n);
    }
};
