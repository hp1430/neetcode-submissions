class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int>pre(nums.size()), suff(nums.size());
        int ans = 0;
        pre[0]=0;
        suff[nums.size()-1]=0;
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++) {
            pre[i] = maxi;
            if(nums[i]>maxi) maxi=nums[i];
        }
        maxi = nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--) {
            suff[i] = maxi;
            if(nums[i]>maxi) maxi=nums[i];
        }
        for(int i=0; i<nums.size(); i++) {
            int x = min(pre[i], suff[i]) - nums[i];
            if(x>0) ans += x;
        }
        return ans;
    }
};
