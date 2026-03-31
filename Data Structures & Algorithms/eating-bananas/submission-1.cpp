class Solution {
private:
    int hoursToEatAllTheBananas(vector<int>& piles, int k) {
        int ans=0;
        for(int i=0; i<piles.size(); i++) {
            ans+=piles[i]/k;
            if(piles[i]%k!=0) ans+=1; 
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=0;
        for(int i=0; i<piles.size(); i++) hi=max(hi, piles[i]);
        int ans = INT_MAX;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            int hoursTaken = hoursToEatAllTheBananas(piles, mid);
            if(hoursTaken<=h) {
                ans=min(ans, mid);
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
